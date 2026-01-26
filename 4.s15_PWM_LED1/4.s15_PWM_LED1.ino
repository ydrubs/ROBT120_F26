const int LED = 9;   // Must be a PWM-capable pin

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {

  // 0% brightness (OFF)
  analogWrite(LED, 0);
  delay(500);

  // 25% brightness
  analogWrite(LED, 64);
  delay(500);

  // 50% brightness
  analogWrite(LED, 128);
  delay(500);

  // 75% brightness
  analogWrite(LED, 191);
  delay(500);

  // 100% brightness (FULL ON)
  analogWrite(LED, 255);
  delay(500);
}
