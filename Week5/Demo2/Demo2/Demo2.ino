int bitArray[] = {1, 3, 7, 15, 31, 63, 127, 255};
int SER = 14; //data
int LATCH = 15; //RCLK
int CLOCK = 16; //SRCLK

//count up first 8-bits

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  digitalWrite(datapin, LOW);
  digitalWrite(clockpin, LOW);
  digitalWrite(latchpin, LOW);

  delay(1000);
}

void loop()
{
  
for(int i = 0; i < 8; i++)
{
  shiftOut(SER, CLOCK, MSBFIRST, 0);
  shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);
  
  
  digitalWrite(LATCH, HIGH);
  digitalWrite(LATCH, LOW);
  delay(100);
}

//count up second 8-bits

for(int i = 0; i < 8; i++)
{
//shift first 8 bits; ends up in the second SR

shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);

//shift second 8-bits; ends up in the first SR

shiftOut(SER, CLOCK, MSBFIRST, bitArray[7]);

digitalWrite(LATCH, HIGH);
digitalWrite(LATCH, LOW);

delay(100);
}

//count down second 8-bits

for(int i = 7; i > 0; i--)
{

//shift first 8 bits; ends up in the second SR

shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);

//shift second 8-bits; ends up in the first SR

shiftOut(SER, CLOCK, MSBFIRST, bitArray[7]);

digitalWrite(LATCH, HIGH);
digitalWrite(LATCH, LOW);

delay(100);
}
//count down first 8-bits

for(int i = 7; i > 0; i--)
{

//shift first 8 bits; ends up in the second SR

shiftOut(SER, CLOCK, MSBFIRST, 0);
shiftOut(SER, CLOCK, MSBFIRST, bitArray[i]);

//shift second 8-bits; ends up in the first SR



digitalWrite(LATCH, HIGH);
digitalWrite(LATCH, LOW);

delay(100);
}
}

//TODO :: your turn! Apply what you've learned.
