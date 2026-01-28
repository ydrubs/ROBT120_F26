/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-potentiometer-fade-led
 */

int LED_PIN = 9;  // the PWM pin the LED is attached to

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // declare LED pin to be an output:
  pinMode(LED_PIN, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A0);

  // scales it to brightness (value between 0 and 255)
  int brightness = map(analogValue, 0, 1023, 0, 255);

  // sets the brightness LED that connects to  pin 3
  analogWrite(LED_PIN, brightness);

  // print out the value
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(", Brightness: ");
  Serial.println(brightness);
  delay(10);
}
