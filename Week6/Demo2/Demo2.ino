int redPin =  14;
int greenPin =  17;
int bluePin =  16 ;

void setup()   {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

int redIntensity = 0;

void loop()                     
{
  // read the pot position
  redIntensity = analogRead(21);
  
  // set all 3 pins to the desired intensity
  analogWrite(redPin, redIntensity);
  analogWrite(bluePin, 512 - redIntensity);
  analogWrite(greenPin, 1023 - redIntensity);

  

  // remain at this color, but not for very long
  Serial.println(redIntensity);
  delay(10);
}
