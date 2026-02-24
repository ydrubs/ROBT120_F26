#include <LiquidCrystal.h>

// Initialize the LCD (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int numCols = 16;  // Number of columns on your LCD
const char message[] = "Hello, World!";  // The message to scroll

void setup() {
  // Set up the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Print the initial message
  lcd.print(message);
  delay(1000);  // Initial delay before starting the scroll
}

void loop() {
  // Scroll left until the entire message disappears off the screen
  for (int i = 0; i < numCols + strlen(message); i++) {
    lcd.scrollDisplayLeft();
    delay(200);  // Adjust the delay for scroll speed
  }

  delay(500);  // Pause before scrolling right

  // Scroll right to bring the message back fully
  for (int i = 0; i < numCols + strlen(message); i++) {
    lcd.scrollDisplayRight();
    delay(200);  // Adjust the delay for scroll speed
  }

  delay(500);  // Pause before flashing the message

  // Flash the message 3 times
  for (int i = 0; i < 3; i++) {
    lcd.clear();  // Clear the display (turn off the message)
    delay(500);  // Flash off duration
    lcd.setCursor(0, 0);  // Reset the cursor
    lcd.print(message);  // Display the message again
    delay(500);  // Flash on duration
  }

  delay(1000);  // Wait 1 second before repeating the process
}
