// Arduino Serial Example #2 Remote Control Blink - Slave
 
char c  = ' ';
byte LED1 = 2;
byte LED2 = 3;
 
void setup() 
{
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
 
   Serial.begin(9600);
   Serial.println("START");
}
 
void loop()
{
   if(Serial.available())
   {
      char c = Serial.read();
      if (c=='0') { digitalWrite(LED1, LOW); }
      if (c=='1') { digitalWrite(LED1, HIGH); }
      if (c=='2') { digitalWrite(LED2, LOW); }
      if (c=='3') { digitalWrite(LED2, HIGH); }
      Serial.println(c);
   }
 
}