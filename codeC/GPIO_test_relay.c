#include <stdio.h>
#include <wiringPi.h>
#define LED 16

int main(void)
{
	wiringPiSetup();
	pinMode(LED, OUTPUT);
	while(1)
	{
	digitalWrite(LED, 1);
	delay(3000);
	digitalWrite(LED, 0);
	delay(3000);
	}
	return(0);
}
