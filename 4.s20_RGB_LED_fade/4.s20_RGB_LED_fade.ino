// RGB LED pins
const int RED_PIN   = 9;
const int GREEN_PIN = 10;
const int BLUE_PIN  = 11;

const int FADE_DELAY = 5;

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {

  // Ramp RED from 0 to 255
  for (int value = 0; value <= 255; value++) {
    analogWrite(RED_PIN, value);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
    delay(FADE_DELAY);
  }

  // Ramp GREEN from 0 to 255
  for (int value = 0; value <= 255; value++) {
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, value);
    analogWrite(BLUE_PIN, 0);
    delay(FADE_DELAY);
  }

  // Ramp BLUE from 0 to 255
  for (int value = 0; value <= 255; value++) {
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, value);
    delay(FADE_DELAY);
  }

  // Turn ALL LEDs off before restarting
  analogWrite(RED_PIN, 0);
  analogWrite(GREEN_PIN, 0);
  analogWrite(BLUE_PIN, 0);

  delay(500);  // Pause before repeating
}
