#include <LiquidCrystal.h>

// Initialize the LCD (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Define button pins
const int buttonUpPin = 8;
const int buttonDownPin = 9;
const int buttonSelectPin = 10;

// Variables to track menu selection
int menuIndex = 0;  // Start at first item in the menu

// Define menu options
const char* menuItems[] = {"Home", "Play", "Stop", "Settings"};
const int numItems = sizeof(menuItems) / sizeof(menuItems[0]);

void setup() {
  // Set up the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Initialize buttons
  pinMode(buttonUpPin, INPUT_PULLUP);     // Use internal pull-up resistors
  pinMode(buttonDownPin, INPUT_PULLUP);
  pinMode(buttonSelectPin, INPUT_PULLUP);

  // Display the initial menu
  displayMenu();
}

void loop() {
  // Check if the 'up' button is pressed
  if (digitalRead(buttonUpPin) == LOW) {
    menuIndex--;  // Move up in the menu
    if (menuIndex < 0) {
      menuIndex = numItems - 1;  // Wrap to the last item
    }
    displayMenu();  // Update the display
    delay(300);  // Debounce delay
  }

  // Check if the 'down' button is pressed
  if (digitalRead(buttonDownPin) == LOW) {
    menuIndex++;  // Move down in the menu
    if (menuIndex >= numItems) {
      menuIndex = 0;  // Wrap to the first item
    }
    displayMenu();  // Update the display
    delay(300);  // Debounce delay
  }

  // Check if the 'select' button is pressed
  if (digitalRead(buttonSelectPin) == LOW) {
    lcd.clear();  // Clear the display
    lcd.setCursor(0, 0);
    lcd.print(menuItems[menuIndex]);  // Print the selected item
    lcd.setCursor(0, 1);
    lcd.print("Selected");  // Print 'Selected' message
    delay(1000);  // Display the selection for 1 second
    displayMenu();  // Return to the menu
  }
}

// Function to display the menu
void displayMenu() {
  lcd.clear();  // Clear the display

  // Display the current menu selection with a '>' character
  for (int i = 0; i < 2; i++) {
    int index = (menuIndex + i) % numItems;  // Wrap around the menu items
    lcd.setCursor(0, i);  // Set cursor position on the LCD

    if (i == 0) {  // Highlight the first (selected) item with a '>' character
      lcd.print("> ");  // Display arrow to indicate selected item
    } else {
      lcd.print("  ");  // No arrow for the second item
    }

    lcd.print(menuItems[index]);  // Print the menu item
  }
}
