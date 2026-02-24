/*
  DRV8833-Dual-Motor-Driver-Module
  made on 23 Nov 2020
  by Amir Mohammad Shojaee @ Electropeak
  Home

*/

#define AIN1 10
#define AIN2 9
#define BIN1 6
#define BIN2 5

void setup() {
  Serial.begin(9600);
  
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  
}
 
void loop() {
  
  //Rotate Forward for 1 second 
  digitalWrite(AIN1,HIGH); 
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,HIGH); 
  digitalWrite(BIN2,LOW);

  delay(1000);
  
  //Stop for 1 second
  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,LOW);
  
  delay(1000);
  
  //Rotate Reverse for 1 second 
  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,HIGH);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,HIGH);

  delay(1000);
  
  //Stop for 1 second 
  digitalWrite(AIN1,LOW); 
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,LOW); 
  digitalWrite(BIN2,LOW);
  
  delay(1000);
   
}