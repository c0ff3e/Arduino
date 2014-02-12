void setup() {
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Serial.begin(9600);
  
}

void ledFlash(int PinMode, int times) {
  for (int x = 0; x< times;x++){
   digitalWrite(13, HIGH);   // turn the 13 on (HIGH is the voltage level)
   delay(1000/(times*2));               // wait for a second
   digitalWrite(13, LOW);
   delay(1000/(times*2));
  }
}

void loop() {
  if ( Serial.available() > 0)
  {
   char letter = Serial.read();
   
   if ( letter == '1' )
   {
    digitalWrite(13,HIGH); 
   }
   else if ( letter == '0' )
   {
     digitalWrite(13,LOW);
   }
   else if ( letter == '3' )
   {
     ledFlash(13,15);
   }
   else if ( letter == '2' )
   {
    ledFlash(13,6);
   }      
 }
  
}
