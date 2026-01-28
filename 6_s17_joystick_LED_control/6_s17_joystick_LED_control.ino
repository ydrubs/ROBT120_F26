// Joystick pins
const int X_PIN = A0;
const int Y_PIN = A1;

// LED pins (all PWM)
const int LED_UP    = 9;
const int LED_DOWN  = 10;
const int LED_LEFT  = 11;
const int LED_RIGHT = 6;

// Center dead zone
const int LOW_CENTER  = 400;
const int HIGH_CENTER = 600;

void setup() {
  pinMode(LED_UP, OUTPUT);
  pinMode(LED_DOWN, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);
  pinMode(LED_RIGHT, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(X_PIN);
  int yValue = analogRead(Y_PIN);

  // Default: LEDs off
  analogWrite(LED_UP, 0);
  analogWrite(LED_DOWN, 0);
  analogWrite(LED_LEFT, 0);
  analogWrite(LED_RIGHT, 0);

  // LEFT
  if (xValue < LOW_CENTER) {
    int brightness = map(xValue, 0, LOW_CENTER, 255, 0);
    analogWrite(LED_LEFT, brightness);
  }

  // RIGHT
  if (xValue > HIGH_CENTER) {
    int brightness = map(xValue, HIGH_CENTER, 1023, 0, 255);
    analogWrite(LED_RIGHT, brightness);
  }

  // UP
  if (yValue > HIGH_CENTER) {
    int brightness = map(yValue, HIGH_CENTER, 1023, 0, 255);
    analogWrite(LED_UP, brightness);
  }

  // DOWN
  if (yValue < LOW_CENTER) {
    int brightness = map(yValue, 0, LOW_CENTER, 255, 0);
    analogWrite(LED_DOWN, brightness);
  }

  // Debug output
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" | Y: ");
  Serial.println(yValue);

  delay(50);
}
