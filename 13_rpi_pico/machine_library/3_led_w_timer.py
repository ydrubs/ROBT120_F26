
"""
blinking an LED without blocking timer
    Can perform other operations between blinks
"""
from machine import Pin, Timer

led = Pin(2, Pin.OUT)
tim = Timer()

def tick(timer):
    global led
    led.toggle()

tim.init(freq=5, mode=Timer.PERIODIC, callback=tick)