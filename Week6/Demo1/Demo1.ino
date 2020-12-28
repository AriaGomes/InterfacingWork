int redPin =  14;
int greenPin =  16;
int bluePin =  17;

void setup()   {

}

float code;
float celsius;
float fahrenheit;

void loop()                     
{
 
  code = analogRead(21);
  celsius = 25 + (code - 512) / 11.3;
  fahrenheit = celsius * 1.8 + 32;
  Serial.print("temperature: ");
  Serial.print(celsius);
  Serial.print(" Celsius, ");
  Serial.print(fahrenheit);
  Serial.println(" Fahrenheit");
  delay(1000);
  
}
