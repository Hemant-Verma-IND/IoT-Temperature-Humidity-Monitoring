#include "WiFi.h"
#include "DHT.h"
#include "ThingSpeak.h"

#define DHTPIN 15     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22 // DHT 22 (AM2302)

const char* ssid = "Wokwi-GUEST";   // Replace with your network SSID
const char* password = "";          // Replace with your network password
const char* writeAPIKey = "7ELOUI06FOW891A8"; // Replace with your ThingSpeak write API key

WiFiClient client;
DHT dht(DHTPIN, DHTTYPE);

unsigned long myChannelNumber = 1;  // Replace with your ThingSpeak channel number
const char* server = "api.thingspeak.com";

void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT22 with ThingSpeak example!"));

  dht.begin();
  
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password, 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  delay(2000);  // Wait a few seconds between measurements.

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Print data to Serial Monitor
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C"));

  // Write data to ThingSpeak
  ThingSpeak.setField(1, t);
  ThingSpeak.setField(2, h);
  int x = ThingSpeak.writeFields(myChannelNumber, writeAPIKey);
  if (x == 200) {
    Serial.println("Channel update successful.");
  } else {
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
}
