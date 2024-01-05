#include <Arduino_MKRIoTCarrier.h>
#include <WiFiNINA.h>
#include <WiFiClient.h>

MKRIoTCarrier carrier;
WiFiClient client;

const char* ssid = "VODAFONE-1062";
const char* password = "*****";
const char* thingSpeakAPIKey = "*****";

void setup() {
  carrier.noCase();
  carrier.begin();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  
  float temperature = carrier.Env.readTemperature();
  float humidity = carrier.Env.readHumidity();
  float pressure = carrier.Pressure.readPressure();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" kPa");

  // Send to ThingSpeak
  if (client.connect("api.thingspeak.com", 80)) {
    String httpRequest = "GET /update?api_key=";
    httpRequest += thingSpeakAPIKey;
    httpRequest += "&field1=";
    httpRequest += String(temperature);
    httpRequest += "&field2=";
    httpRequest += String(humidity);
    httpRequest += "&field3=";
    httpRequest += String(pressure);
    httpRequest += " HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnection: close\r\n\r\n";

    client.print(httpRequest);
    Serial.println("Data sent to ThingSpeak");
  }
  else {
    Serial.println("Connection to ThingSpeak failed");
  }

  delay(20000); // Wait for 20 seconds before next read
}
