// LED range
const int FIRST_LED = 2;
const int LAST_LED  = 9;
const int DELAY_MS  = 100;

void setup() {
  // Configure all LED pins as outputs
  for (int pin = FIRST_LED; pin <= LAST_LED; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {

  // Sweep left to right
  for (int pin = FIRST_LED; pin <= LAST_LED; pin++) {
    digitalWrite(pin, HIGH);
    delay(DELAY_MS);
    digitalWrite(pin, LOW);
  }

  // Sweep right to left (skip endpoints to avoid double blink)
  for (int pin = LAST_LED - 1; pin > FIRST_LED; pin--) {
    digitalWrite(pin, HIGH);
    delay(DELAY_MS);
    digitalWrite(pin, LOW);
  }

  delay(300);  // Pause before repeating pattern
}
