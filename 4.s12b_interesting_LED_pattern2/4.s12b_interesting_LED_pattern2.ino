// LED range and timing
const int FIRST_LED = 2;
const int LAST_LED  = 9;
const int DELAY_MS  = 150;

void setup() {
  for (int pin = FIRST_LED; pin <= LAST_LED; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {

  // Expand from center
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(DELAY_MS);

  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  delay(DELAY_MS);

  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  delay(DELAY_MS);

  digitalWrite(2, HIGH);
  digitalWrite(9, HIGH);
  delay(DELAY_MS);

  // Contract back to center
  digitalWrite(2, LOW);
  digitalWrite(9, LOW);
  delay(DELAY_MS);

  digitalWrite(3, LOW);
  digitalWrite(8, LOW);
  delay(DELAY_MS);

  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  delay(DELAY_MS);

  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(DELAY_MS);

  delay(300);  // Pause before repeating
}
