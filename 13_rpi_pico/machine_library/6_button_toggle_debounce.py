from machine import Pin
import time

led = Pin(2, Pin.OUT)
button = Pin(16, Pin.IN, Pin.PULL_UP)

led_state = 1
last_state = 0  # your board: NOT pressed = 0

while True:
    current_state = button.value()

    # Detect button press (rising edge for your setup)
    if current_state == 1 and last_state == 0:
        time.sleep(0.02)  # debounce delay

        # Confirm still pressed after delay
        if button.value() == 1:
            led_state = not led_state
            led.value(led_state)

    last_state = current_state