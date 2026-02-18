const int buttonPin = 2; // Pin connected to the pushbutton
const int ledPin = 9;    // Pin connected to the LED

const int buttonPin2 = 3; // Pin connected to the pushbutton
const int ledPin2 = 10;    // Pin connected to the LED

bool ledState = false;   // Boolean flag to track LED state
bool buttonPressed = false; // Tracks the button press state

bool ledState2 = false;   // Boolean flag to track LED state
bool buttonPressed2 = false; // Tracks the button press state

void setup() {
  pinMode(buttonPin, INPUT); // Set button pin as input with pull-up resistor
  pinMode(ledPin, OUTPUT);         // Set LED pin as output

  pinMode(buttonPin2, INPUT); // Set button pin as input with pull-up resistor
  pinMode(ledPin2, OUTPUT);         // Set LED pin as output
}

void loop() {
  // Read the button state
  int buttonState = digitalRead(buttonPin);
  int buttonState2 = digitalRead(buttonPin2);

  // Check if the button is pressed (LOW) and was not already pressed
  if (buttonState == LOW && !buttonPressed) {
    ledState = !ledState;          // Toggle the LED state
    digitalWrite(ledPin, ledState); // Update the LED output
    buttonPressed = true;          // Set the button pressed state to true
  }

  // Check if the button is released (HIGH) to reset the pressed state
  if (buttonState == HIGH) {
    buttonPressed = false;
  }


    // Check if the button is pressed (LOW) and was not already pressed
  if (buttonState2 == LOW && !buttonPressed2) {
    ledState2 = !ledState2;          // Toggle the LED state
    digitalWrite(ledPin2, ledState2); // Update the LED output
    buttonPressed2 = true;          // Set the button pressed state to true
  }

  // Check if the button is released (HIGH) to reset the pressed state
  if (buttonState2 == HIGH) {
    buttonPressed2 = false;
  }
}
