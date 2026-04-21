"""
blinking an LED with blocking timer
    Cannot run other operation during sleep
"""
from machine import Pin
import time

# Create a Pin object for the LED (Pin 25 on Pico)
led1 = Pin(2, Pin.OUT)
led2 = Pin(3, Pin.OUT)
led3 = Pin(4, Pin.OUT)
led4 = Pin(5, Pin.OUT)

leds = [led1, led2, led3, led4]


while True:
    for led in leds:
        led.value(1)
        time.sleep(0.1)
        
    for led in leds:
        led.value(0)
        time.sleep(0.1)
    
    



