#include <DHT.h>         
#define dhtPin  12
#define dhtType DHT11
#define sD      2
#define sA      A7
#define relay   5

DHT dht(dhtPin, dhtType);

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode (sD, INPUT);
  pinMode (sA, INPUT);
  pinMode (relay, OUTPUT);
}

void loop()
{
  float h = dht.readHumidity(); 
  float t = dht.readTemperature(); 

  Serial.print(F("Nhiet do: "));
  Serial.println(t);
  Serial.print(F("Do am: "));
  Serial.println(h);
  
  int value = analogRead(sA);
  int percent = map(value, 0, 1023, 100, 0);
  Serial.print(F("Do am dat: "));
  Serial.print(percent);
  Serial.println('%');
  Serial.println();
  
  if (percent < 20) digitalWrite(relay, 1);
  else              digitalWrite(relay, 0);
  delay(1000);
}
