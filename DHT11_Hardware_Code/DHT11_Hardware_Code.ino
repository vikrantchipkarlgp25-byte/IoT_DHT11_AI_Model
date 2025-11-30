#include <NinjaIoT.h>
#include "DHT.h"
#include "Password.h"

NinjaIoT iot;

//first search "DHT sensor library" in library manager by Adafruit
//and install it

#define DHTPIN D3   // connect DHT11 to pin D3   
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  iot.connect("wifiuser", "pass", "uid");  
  dht.begin();
}

void loop() {
  
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 
 iot.WriteVar("Temperature", t);
 iot.WriteVar("Humidity", h);
 
 delay(1500); 
}