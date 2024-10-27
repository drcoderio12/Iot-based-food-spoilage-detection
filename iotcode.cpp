#include <WiFi.h>
#include <HTTPClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// WiFi credentials
const char* ssid = "Wi-Fi";
const char* password = "*******";

// Server details
const char* serverURL = "http://....IOE/test.php"; // Change to your server URL

// DS18B20 temperature sensor
#define DS18B20_PIN 4  // GPIO 4 (D4) on ESP32
OneWire oneWire(DS18B20_PIN);
DallasTemperature sensors(&oneWire);

// FC-28 Soil Moisture sensor
#define FC28_PIN 35  // GPIO 35 (A3) on ESP32

// MQ-4 Gas sensor
#define MQ4_ANALOG_PIN 34  // GPIO 34 (A2) on ESP32

// MQ-135 Gas sensor (new)
#define MQ135_ANALOG_PIN 32  // GPIO 32 (A0) on ESP32

float temperature = 0.0;  // Global variable to store temperature
int moisture = 0;         // Global variable to store moisture
int gasValue = 0;         // Global variable to store gas value
int gasValue135 = 0;  // Global variable to store MQ-135 gas value (new)

unsigned long previousMillis = 0;
const long interval = 10000;  // Interval in milliseconds (10 seconds)

void setup() {
  Serial.begin(9600);
  delay(100);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  sensors.begin();  // Initialize DS18B20 sensor
}

void loop() {
  unsigned long currentMillis = millis();  // Get current time

  if (currentMillis - previousMillis >= interval) {  // Check if interval has passed
    previousMillis = currentMillis;  // Save the last time data was sent
    readSensorData();  // Read sensor data
    sendDataToServer();  // Send sensor data to server
  }
}

void readSensorData() {
  // Read temperature from DS18B20 sensor
  sensors.requestTemperatures();  // Send the command to get temperatures
  temperature = sensors.getTempCByIndex(0);

  // Read analog value from FC-28 soil moisture sensor
  moisture = analogRead(FC28_PIN);

  // Read analog value from MQ-4 gas sensor
  gasValue = analogRead(MQ4_ANALOG_PIN);

  // MQ-135 gas (new)
  gasValue135 = analogRead(MQ135_ANALOG_PIN);

  Serial.print("Read sensor data - Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Moisture: ");
  Serial.print(moisture);
  Serial.print(", Gas Value: ");
  Serial.println(gasValue);
  Serial.print(", Gas Value MQ-135: ");
  Serial.println(gasValue135);
}

void sendDataToServer() {
  HTTPClient http;
  http.begin(serverURL);  // Specify the target server
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  String data = "temperature=" + String(temperature) + "&moisture=" + String(moisture) + "&gasValue=" + String(gasValue) + "&gasValue135=" + String(gasValue135);

  int httpResponseCode = http.POST(data);  // Send data to server

  Serial.print("HTTP Response code: ");
  Serial.println(httpResponseCode);  // Print HTTP response code

  if (httpResponseCode > 0) {
    Serial.println("Data sent to server successfully");
  } else {
    Serial.println("Error sending data to server!");
  }

  http.end();
}