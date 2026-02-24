//LCD text with incrementing number

//Include the library code:
#include <LiquidCrystal.h>

//Start the time at 0
int time = 0;

//Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup()
{
  //Set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Hi my name is:");
  lcd.setCursor(0,1);
  lcd.print("T-800");
  delay(2000);
  lcd.clear();
}

void loop()
{
  //Move cursor to second line, first position
  lcd.setCursor(0,1);
  //Print Current Time
  lcd.print(time);  
  //Wait 1 second
  delay(1000);
  //Increment the time
  time++; 
}


