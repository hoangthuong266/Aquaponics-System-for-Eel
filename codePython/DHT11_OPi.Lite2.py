from time import sleep
import orangepi.lite2
import OPi.GPIO as gpio
GPIO.setmode(orangepi.lite2.BOARD)

def dht11_read():

print("Interfacing Humidity and Temperature Sensor (DHT11) with Orange Pi Lite 2.")
while True:
    sleep(2)
    dht11_read()