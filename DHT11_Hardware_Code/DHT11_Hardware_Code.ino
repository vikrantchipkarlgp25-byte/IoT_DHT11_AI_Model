#include <NinjaIoT.h>
#include "DHT.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include "Password.h"  // contains wifiuser, pass, uid

NinjaIoT iot;

#define DHTPIN D3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Replace it with your deployed Google Apps Script Web App URL
const char* GScriptUrl = "https://script.google.com/macros/s/AKfycbwlQNWGXGl6JUOPQXJ0TathtWoYyIjJNZatUCMk4V6iQUxe4dnh-zN0Q2SF92XO4OjX4w/exec"; 

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("=== DHT11 -> Google Sheets (POST) ===");

  WiFi.mode(WIFI_STA);
  Serial.print("Connecting to WiFi");
  WiFi.begin(wifiuser, pass);

  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    if (millis() - start > 20000) {
      Serial.println();
      Serial.println("Retrying WiFi connect...");
      WiFi.disconnect();
      WiFi.begin(wifiuser, pass);
      start = millis();
    }
  }

  Serial.print("\nWiFi connected. IP: ");
  Serial.println(WiFi.localIP());

  dht.begin();

  // connect NinjaIoT once
  Serial.println("Connecting to NinjaIoT...");
  iot.connect(wifiuser, pass, uid);
  Serial.println("NinjaIoT connection attempted.");
}

String urlencode(const String &str) {
  String s = "";
  for (unsigned int i = 0; i < str.length(); i++) {
    char c = str[i];
    if ((c >= '0' && c <= '9') || c == '.' || c == '-') {
      s += c;
    } else {
      char buf[5];
      sprintf(buf, "%%%02X", (uint8_t)c);
      s += buf;
    }
  }
  return s;
}

bool sendToGoogleSheet(float h, float t) {
  if (WiFi.status() != WL_CONNECTED) return false;

  WiFiClientSecure client;
  client.setInsecure(); // ignore SSL certs for ESP

  HTTPClient http;
  if (!http.begin(client, GScriptUrl)) {
    Serial.println("http.begin() failed");
    return false;
  }

  String postData = "h=" + urlencode(String(h, 1)) + "&t=" + urlencode(String(t, 1));
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.addHeader("User-Agent", "ESP8266-DHT11/1.0");

  Serial.print("POST payload: ");
  Serial.println(postData);

  int httpCode = http.POST(postData);
  if (httpCode <= 0) {
    Serial.print("HTTP POST failed, code: ");
    Serial.println(httpCode);
    http.end();
    return false;
  }

  Serial.print("HTTP code: ");
  Serial.println(httpCode);
  String payload = http.getString();
  Serial.print("Google Response: ");
  Serial.println(payload);

  http.end();

  return (payload.indexOf("Success") >= 0);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(2000);
    return;
  }

  // Update NinjaIoT
  iot.WriteVar("Temperature", t);
  Serial.print("WriteVar OK: Temperature=");
  Serial.println(t, 2);
  iot.WriteVar("Humidity", h);
  Serial.print("WriteVar OK: Humidity=");
  Serial.println(h, 2);

  // Send to Google Sheets with retries
  bool ok = false;
  const int MAX_TRIES = 3;
  for (int attempt = 1; attempt <= MAX_TRIES; attempt++) {
    Serial.print("Send attempt ");
    Serial.print(attempt);
    Serial.println(" to Google Sheets...");
    ok = sendToGoogleSheet(h, t);
    if (ok) {
      Serial.println("Sent to Google Sheets ✅");
      break;
    } else {
      Serial.println("Send failed, retrying...");
      delay(1200);
    }
  }

  if (!ok) {
    Serial.println("All attempts failed — check WiFi or Web App deployment.");
  }

  delay(10000); // wait 10 seconds before next reading
}