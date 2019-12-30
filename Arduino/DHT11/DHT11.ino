#include <DHT.h>         
#define DHTPIN  2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 

  Serial.print(F("Nhiet do: "));
  Serial.println(t);
  Serial.print(F("Do am: "));
  Serial.println(h);
  Serial.println();
  delay(2000);
}
