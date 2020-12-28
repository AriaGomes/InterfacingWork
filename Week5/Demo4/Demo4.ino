byte ones, tens, symbols[] = {
B11111100, // 0
B01100000, // 1
B11011010, // 2
B11110010, // 3
B01100110, // 4
B10110110, // 5
B10111110, // 6
B11100000, // 7
B11111110, // 8
B11110110, // 9
};
volatile int SER = 14; //data
volatile int LATCH = 15; //RCLK
volatile int CLOCK = 16; //SRCLK
int i , j;
void interrupt();
IntervalTimer myTimer;


//count up first 8-bits

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);

  for(unsigned int i=0; i<sizeof(symbols); i++)
    symbols[i] ^= B11111111;


    myTimer.begin( interrupt, 7000000);
}

void loop()
{
    for(j = 0; j < 10; j++)
    {
      
  for(i = 0; i < 10; i++)
  {
    ones = symbols[i];
    digitalWrite(LATCH, LOW); // prepare shift register for data
    shiftOut(SER, CLOCK, LSBFIRST, symbols[j]); // send data
    shiftOut(SER, CLOCK, LSBFIRST, ones); // send data
    digitalWrite(LATCH, HIGH); // update display
    delay(100);
  }
    tens = symbols[j];
    }
  
 
}

void interrupt()
{
  if(tens >= symbols[7])
  {
    Serial.println("made it");
    shiftOut(SER, CLOCK, LSBFIRST, symbols[0]);
    shiftOut(SER, CLOCK, LSBFIRST, symbols[0]);
    digitalWrite(LATCH, LOW);
    digitalWrite(CLOCK, LOW);
    digitalWrite(SER, LOW);
    tens = 0;
    i = 0;
    j = 0;
  }
}
