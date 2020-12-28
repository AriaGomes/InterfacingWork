#include <Bounce2.h>

byte symbols[] = {

B10000000, // A
B01000000, // B
B00100000, // C
B00010000, // D
B00001000, // E
B00000100, // F
B00000010, // G
B00000001, //(DC)
B11111111, // 8(DC)
B00000000, // CLEAR
};

String letters[] = 
{
  "Segment A",
  "Segment B",
  "Segment C",
  "Segment D",
  "Segment E",
  "Segment F",
  "Segment G",
  "Segment Decimal Point",
  "8.",
  "all segments OFF",
};


int PBSpin = 0;
volatile int SER = 14; //data
volatile int LATCH = 15; //RCLK
volatile int CLOCK = 16; //SRCLK
int i = 0;

Bounce debouncerModeSwitch = Bounce();

//count up first 8-bits

void setup() {
  pinMode(PBSpin, INPUT);
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, HIGH);

  debouncerModeSwitch.attach(PBSpin);
  debouncerModeSwitch.interval(25);

for(unsigned int i=0; i<sizeof(symbols); i++)
    symbols[i] ^= B11111111;

}

void loop()
{ 

if(digitalRead(0) == LOW)
    shiftOut(SER, CLOCK, LSBFIRST, B00000000); // send data
    
    if (i >= 10 )
      i = 0;

    debouncerModeSwitch.update(); // Update the Bounce instance

   if ( debouncerModeSwitch.fell())
   {
    Serial.print("PBS press # ");
    Serial.print(i+1);
    Serial.print(" => ");
    Serial.println(letters[i]);
    digitalWrite(LATCH, LOW); // prepare shift register for data
    shiftOut(SER, CLOCK, LSBFIRST, symbols[i++]); // send data
      
    
    digitalWrite(LATCH, HIGH); // update display
    digitalWrite(LATCH, LOW);
   }

   
}
