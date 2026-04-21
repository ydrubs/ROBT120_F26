from picozero import LED
from time import sleep

led1 = LED(19)
led2 = LED(17)
led3 = LED(20)

led = [led1, led2, led3]

while True:
    for brightness in range(100):
        led.brightness = brightness/100
        sleep(0.01)
        
    for brightness in range(100, -1, -1):
        led.brightness = brightness/100
        sleep(0.01)