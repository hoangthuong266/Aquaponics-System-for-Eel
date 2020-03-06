#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <BH1750.h>

#define dhtPin     2
#define dhtType    DHT11
#define soil       A0
#define oneWireBus 3

DHT dht(dhtPin, dhtType);
OneWire oneWire(oneWireBus);
DallasTemperature tempStick(&oneWire);
BH1750 lightMeter;

void setup()
{
  Serial.begin(115200);
  dht.begin();
  pinMode (soil, INPUT);
  tempStick.begin();
  Wire.begin();
  lightMeter.begin();
}

void loop()
{
  String Temp_DHT = (String)dht.readTemperature();
  String Humid_DHT = (String)dht.readHumidity();
  
  int value = analogRead(soil);
  String Soil_Moisture = (String)map(value, 0, 1023, 100, 0);

  tempStick.requestTemperatures();
  String Temp_Stick = (String)tempStick.getTempCByIndex(0);

  String Lux = (String)lightMeter.readLightLevel();
  
  String str_Payload;
  int NData = 5;
  
  str_Payload += NData;
  str_Payload += " " + Temp_DHT;
  str_Payload += " " + Humid_DHT;
  str_Payload += " " + Soil_Moisture;
  str_Payload += " " + Temp_Stick;
  str_Payload += " " + Lux;
  str_Payload += " ";
  
  Serial.print(str_Payload);

  delay(2000);
}
