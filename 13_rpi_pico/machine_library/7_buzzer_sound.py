from machine import Pin, PWM
import time

buzzer = PWM(Pin(16))

notes = [262, 294, 330, 349, 392]  # C D E F G (range from 100 to 5000-ish)
buzzer.duty_u16(30000) # Volume (range from 0 to 65535)

for note in notes:
    buzzer.freq(note)
    time.sleep(0.3)

buzzer.duty_u16(0) # Stop Sound 