const int MOTOR_PIN = 9;

void setup() {
  pinMode(MOTOR_PIN, OUTPUT);
  digitalWrite(MOTOR_PIN, LOW);   // motor off to start
}

void loop() {
  digitalWrite(MOTOR_PIN, HIGH);  // motor ON
  delay(2000);

  digitalWrite(MOTOR_PIN, LOW);   // motor OFF
  delay(2000);
}
