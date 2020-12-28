#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

const int touchValue = 1400;
int sensorValue = 0;
const int touchPins[] = {0, 1, 23, 18, 17, 16, 15};
const int piezoPin = 20;
const int ledPin = 9;
 
 void setup() {
   Serial.begin(38400);
   pinMode(piezoPin, OUTPUT);
   pinMode(ledPin, OUTPUT);
   digitalWrite(ledPin, LOW);
   pinMode(touchPins[0], INPUT);
   pinMode(touchPins[1], INPUT);
   pinMode(touchPins[2], INPUT);
   pinMode(touchPins[3], INPUT);
   pinMode(touchPins[4], INPUT);
   pinMode(touchPins[5], INPUT);
   pinMode(touchPins[6], INPUT);
 }

  
 void loop()                     
 {


   
for(unsigned int i = 0; i < sizeof(touchPins) / sizeof(touchPins[0]); i++)
{
  sensorValue = touchRead(touchPins[i]);
  if (sensorValue > touchValue)
  {
    Serial.println(sensorValue);
    switch(touchPins[i])
    {
      case 0:
        tone(piezoPin, NOTE_C5, 100);
        digitalWrite(ledPin, HIGH);
        break;
      case 1:
        tone(piezoPin, NOTE_D5, 100);
        digitalWrite(ledPin, HIGH);
        break;
      case 23:
        tone(piezoPin, NOTE_E5, 100);
        digitalWrite(ledPin, HIGH);
        break;
      case 18:
        tone(piezoPin, NOTE_F5, 100);
        digitalWrite(ledPin, HIGH);
        break;
      case 17:
        tone(piezoPin, NOTE_G5, 100);
        digitalWrite(ledPin, HIGH);
        break;
      case 16:
        tone(piezoPin, NOTE_A5, 100);
        digitalWrite(ledPin, HIGH);
        break;
      case 15:
        tone(piezoPin, NOTE_B5, 100);
        digitalWrite(ledPin, HIGH);
        break;
      default:
         digitalWrite(ledPin, LOW);
         break;
    }
  }
  else
  {
    Serial.println("Not Touching");
    digitalWrite(ledPin, LOW);
  }
  
}
}
