//Custom character example


#include <LiquidCrystal.h>

//Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

byte smiley[] = { B11011, 
                  B11011, 
                  B00000, 
                  B00100, 
                  B10001, 
                  B10001, 
                  B01110, 
                  B00000 };



void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, smiley);
  lcd.clear()
  lcd.write(byte(0));
}

void loop() {};