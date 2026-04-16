#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);

  while (!Serial) {
    ; // wait for serial monitor on some boards
  }

  Serial.println("I2C Scanner");
}

void loop() {
  byte error, address;
  int count = 0;

  Serial.println("Scanning...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      count++;
    }
  }

  if (count == 0) {
    Serial.println("No I2C devices found");
  } else {
    Serial.println("Scan complete");
  }

  Serial.println();
  delay(3000);
}