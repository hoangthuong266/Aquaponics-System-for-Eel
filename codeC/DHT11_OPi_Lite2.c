#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAX_TIME	83 //2 ready signal and 2*40 data signal
#define PIN			11 //WiringPi pin

uint8_t dht11_val[5] = {0, 0, 0, 0, 0};

void dht11_read()
{
	uint8_t state = HIGH, counter = 0, j = 0, i;
	for(i = 0; i < 5; i++)
		dht11_val[i] = 0;	 
		 
	//Send start signal
	pinMode(PIN, OUTPUT);
	digitalWrite(PIN, LOW);
	delay(20); //At least 18 ms
	digitalWrite(PIN, HIGH);
	delayMicroseconds(30); //20 - 40 us
	
	//Receive ready and data signal
	pinMode(PIN, INPUT);
	
	for(i = 0; i < MAX_TIME; i++)
	{
		counter = 0;
		
		while(digitalRead(PIN) == state)
		{
			counter++;
			delayMicroseconds(1);
			if(counter == 255)
				break;
		}
		
		state = digitalRead(PIN); //i = 0 executes this line only therefore MAX_TIME = 83
		if(counter == 255)
			 break;
			 
		//Top 3 transistions are ignored
		if((i >= 4) && (i % 2 == 0))
		{
			dht11_val[j/8] <<= 1; //Move bits of element dht11_value[j%8] to left by 1 bit
			if(counter > 50) //Bit 0 lasts 26 - 28 us, bit 1 lasts 70 us
				dht11_val[j/8] |= 1;
			j++;
		}
	}
	
	//Verify cheksum and print the verified data.
	if((j = 40) && (dht11_val[4] == (dht11_val[0] + dht11_val[1] + dht11_val[2] + dht11_val[3])))
		printf("Humidity = %d.%d %% Temperature = %d.%d *C\n",dht11_val[0],dht11_val[1],dht11_val[2],dht11_val[3]);
	else
		printf("Invalid Data!\n");
}
	
int main(void)
{
	printf("Interfacing Humidity and Temperature Sensor (DHT11) with Orange Pi Lite 2.\n");
	if(wiringPiSetup() == -1)
		exit(1);
	while(1)
	{
		delay(2000);
		dht11_read();
	}
	return 0;
}
