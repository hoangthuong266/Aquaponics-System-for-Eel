import orangepi.lite2
import OPi.GPIO as gpio
import time

gpio.setmode(orangepi.lite2.BOARD)
gpio.setup(23, 0)
gpio.output(23, 1)
while 1:
    gpio.output(23, not gpio.input(23))
    time.sleep(5)
gpio.cleanup()
