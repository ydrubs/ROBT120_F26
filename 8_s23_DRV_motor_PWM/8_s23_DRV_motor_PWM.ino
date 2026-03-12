// Define motor control pins
#define MOTOR_A_IN1 9
#define MOTOR_A_IN2 10
#define MOTOR_B_IN1 5
#define MOTOR_B_IN2 6

void setup() {
  // Set the motor control pins as outputs
  pinMode(MOTOR_A_IN1, OUTPUT);
  pinMode(MOTOR_A_IN2, OUTPUT);
  pinMode(MOTOR_B_IN1, OUTPUT);
  pinMode(MOTOR_B_IN2, OUTPUT);
}

void loop() {
  // Example: Drive motor A forward at half speed
  analogWrite(MOTOR_A_IN1, 127);  // PWM value (0-255) for IN1
  digitalWrite(MOTOR_A_IN2, 0);    // IN2 set to LOW

  // Example: Drive motor B backward at full speed
  analogWrite(MOTOR_B_IN1, 0);    // IN1 set to LOW
  analogWrite(MOTOR_B_IN2, 255);  // PWM value (0-255) for IN2

  delay(2000);  // Wait for 2 seconds

  // Stop both motors
  analogWrite(MOTOR_A_IN1, 0);
  analogWrite(MOTOR_A_IN2, 0);
  analogWrite(MOTOR_B_IN1, 0);
  analogWrite(MOTOR_B_IN2, 0);

  delay(2000);  // Wait for 2 seconds
}