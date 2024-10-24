#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is connected to Arduino digital pin 2
#define ONE_WIRE_BUS 2

// Initialize OneWire and Dallas Temperature sensors
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  // Start serial communication
  Serial.begin(9600);
  Serial.println("Dallas Temperature Sensor");
  Serial.println("------------------------");
  
  // Start Dallas Temperature sensor
  sensors.begin();
}

void loop() {
  // Request temperature readings
  sensors.requestTemperatures();
  
  // Get temperature in Celsius
  float tempC = sensors.getTempCByIndex(0);
  
  // Check if reading failed
  if(tempC == -127.00) {
    Serial.println("Error: Could not read temperature data");
    delay(1000);
    return;
  }
  
  // Calculate Fahrenheit
  float tempF = tempC * 9.0 / 5.0 + 32.0;
  
  // Print temperature readings
  Serial.print("Temperature: ");
  Serial.print(tempC, 1);
  Serial.print("°C | ");
  Serial.print(tempF, 1);
  Serial.println("°F");
  
  // Wait 2 seconds between readings
  delay(800);
}
