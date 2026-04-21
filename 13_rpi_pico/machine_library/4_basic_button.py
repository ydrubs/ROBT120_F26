from machine import Pin
import time

# LED output
led = Pin(2, Pin.OUT)

# Button input with internal pull-up
pass

while True:
    pass  # Button pressed
        led.value(0)
    else:                     # Button not pressed
        led.value(1)
    
    pass  # Small delay for stability
    
    