#include <LiquidCrystal.h>

//Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);  // Set up the LCD's number of columns and rows (16x2)
  lcd.print("Hello, World!");  // Print the message to be scrolled
  delay(2000);  // Wait for 2 seconds before starting the scroll
}

void loop() {
  lcd.scrollDisplayLeft();  // Scroll the text left
  delay(250);  // Adjust the delay for scroll speed
}
