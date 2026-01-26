const int BUTTON_PIN = 2;
const int LED_PIN    = 13;

const unsigned long DEBOUNCE_DELAY = 50;  // milliseconds

int buttonState = HIGH;        // Current stable button state
int lastButtonReading = HIGH;  // Last raw reading

unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);

  // If the button reading has changed, reset the debounce timer
  if (reading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  // If enough time has passed, consider the state stable
  if ((millis() - lastDebounceTime) > DEBOUNCE_DELAY) {

    // If the button state has actually changed
    if (reading != buttonState) {
      buttonState = reading;

      // Button is pressed (LOW because of pull-up)
      if (buttonState == LOW) {
        digitalWrite(LED_PIN, !digitalRead(LED_PIN)); // Toggle LED
      }
    }
  }

  lastButtonReading = reading;
}
