// Pin numbers for the three LEDs
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;

void setup() {
  // Set each LED pin as an output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  // Turn all LEDs ON
  digitalWrite(LED1, HIGH); //Turns on LED 1 
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);

  delay(1000);  // Wait 1 second

  // Turn all LEDs OFF
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  delay(1000);  // Wait 1 second
}

