// LED range
const int FIRST_LED = 2;
const int LAST_LED  = 9;
const int DELAY_MS  = 150;

void setup() {
  // Configure all LED pins as outputs
  for (int pin = FIRST_LED; pin <= LAST_LED; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  blinkAll();
  delay(500);

  pingPong();
  delay(500);
}

// --------------------
// Pattern 1: All LEDs blink together
// --------------------
void blinkAll() {
  for (int pin = FIRST_LED; pin <= LAST_LED; pin++) {
    digitalWrite(pin, HIGH);
  }

  delay(500);

  for (int pin = FIRST_LED; pin <= LAST_LED; pin++) {
    digitalWrite(pin, LOW);
  }

  delay(500);
}

// --------------------
// Pattern 2: Ping-pong sweep
// --------------------
void pingPong() {
  // Left to right
  for (int pin = FIRST_LED; pin <= LAST_LED; pin++) {
    digitalWrite(pin, HIGH);
    delay(DELAY_MS);
    digitalWrite(pin, LOW);
  }

  // Right to left (skip ends)
  for (int pin = LAST_LED - 1; pin > FIRST_LED; pin--) {
    digitalWrite(pin, HIGH);
    delay(DELAY_MS);
    digitalWrite(pin, LOW);
  }
}
