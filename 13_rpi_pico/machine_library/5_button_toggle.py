from machine import Pin
import time

led = Pin(2, Pin.OUT)
button = Pin(16, Pin.IN, Pin.PULL_UP)

led_state = 1
last_state = 0  # button not pressed initially

while True:
    current_state = button.value()
    # Detect button press (falling edge)
    if current_state == 1 and last_state == 0:
        led_state = not led_state   # toggle LED
        led.value(led_state)
        time.sleep(0.05)  # debounce delay

    last_state = current_state
