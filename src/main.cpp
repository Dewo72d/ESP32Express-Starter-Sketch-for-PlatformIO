#include <Arduino.h>
#include <esp32express.h>
#include <ArduinoJson.h>
#include <esp32/rom/ets_sys.h>

#define LED_PIN 4

// Wi-Fi
const char *ssid = "ssid";
const char *password = "password";
// Server
const uint16_t port = 3000;
const String url = "http://192.168.0.3";
Esp32express server(ssid, password, port, 20);
// Timers
unsigned long prevMillis = 0;

String get_json_data()
{
  JsonDocument data;
  uint32_t heap = esp_get_free_heap_size();
  String ip = server.deviceIP();

  data["ip"] = ip;
  data["heap"] = String(heap);

  String json;
  serializeJson(data, json);

  return json;
}

void setup()
{
  Serial.begin(115200);
  Serial.println();
  pinMode(LED_PIN, OUTPUT);

  server.connectWiFi();
  Serial.println("Program begun!");

  server.on("/ping", [](WebServer &webServer)
            { 
              String payload = get_json_data();
              webServer.send(200, "application/json", payload);
                            Serial.println("SEND"); });

  server.on("/on", [](WebServer &webServer)
            { 
              digitalWrite(LED_PIN, 1);
              String payload = get_json_data();
              webServer.send(200, "application/json", payload); });

  server.on("/off", [](WebServer &webServer)
            { 
              digitalWrite(LED_PIN, 0);
              String payload = get_json_data();
              webServer.send(200, "application/json", payload); });
}

void loop()
{
  server.handleClient();

  unsigned long currMillis = millis();

  if (currMillis - prevMillis >= 3000)
  {
  }
}
