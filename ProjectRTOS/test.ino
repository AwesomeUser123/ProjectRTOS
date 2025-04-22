#include <DHT20.h>
#include <scheduler.h>
#include <Heater.h>
#include <Cooler.h>
#include <Humidifier.h>
#include <LedBlink.h>
#define D3 6
#define D4 7
#define D5 8
#define D6 9
#define D7 10
#define D8 17
#define LED_PIN 48
DHT20 dht20;
void TIMER_ISR(void *pvParameters) {
  while(1) {
    SCH_Update();
    vTaskDelay(10);
  }
}
float temperature;
float humidity;
int LedStatus = 0;
Heater heater(&temperature,&humidity);
Cooler cooler(&temperature,&humidity,23.85);
Humidifier humidifier(&temperature,&humidity,50.9);
LedBlink ledblink(&LedStatus);
void setup() {
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
  pinMode(LED_PIN, OUTPUT);
// Initialize serial communication at 115200 bits per second:
  Serial.begin(115200); 
  Wire.begin(GPIO_NUM_11, GPIO_NUM_12);
  dht20.begin();
  xTaskCreate(TIMER_ISR, "TIMER_ISR", 2048, NULL, 2, NULL);
  SCH_Init();
  SCH_Add_Task(CheckSensor,0,500);
  SCH_Add_Task(runHeaterTask,0,100);
  SCH_Add_Task(runCoolerTask,0,100);
  SCH_Add_Task(runHumidifierTask,0,100);
  SCH_Add_Task(runLedTask,0,100);
}
void runLedTask() {
  ledblink.blink();
}
void runHeaterTask()  {
  heater.Heater_run();
}
void runCoolerTask()   {
  cooler.Cooler_run();
}
void runHumidifierTask()  {
  humidifier.Humidifier_run();
}

void CheckSensor()  {
    dht20.read(); 

  // Reading temperature in Celsius
    temperature = dht20.getTemperature();
  // Reading humidity
    humidity = dht20.getHumidity();

  // Check if any reads failed and exit early
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print the results
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("% Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
}

void loop() {
  SCH_Dispatch_Tasks();
}
