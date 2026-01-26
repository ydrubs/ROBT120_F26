// LED range and timing limits
const int FIRST_LED = 2;
const int LAST_LED  = 9;
const int MIN_DELAY = 100;
const int MAX_DELAY = 800;

void setup() {
  // Configure LED pins
  for (int pin = FIRST_LED; pin <= LAST_LED; pin++) {
    pinMode(pin, OUTPUT);
  }

  // Seed the random number generator
  randomSeed(analogRead(A0));
}

void loop() {
  int ledPin = random(FIRST_LED, LAST_LED + 1);
  int waitTime = random(MIN_DELAY, MAX_DELAY + 1);

  digitalWrite(ledPin, HIGH);
  delay(waitTime);
  digitalWrite(ledPin, LOW);
  delay(waitTime);
}
