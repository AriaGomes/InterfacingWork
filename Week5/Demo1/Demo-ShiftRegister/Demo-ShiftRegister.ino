/*
 * Demo: Shift Register
 * 
 * Component: SN74HC595N by Texas Instruments (TI)
 * 
 * References:
 *  << (bitwise operator): https://www.arduino.cc/reference/en/language/structure/bitwise-operators/bitshiftleft/
 *  shiftOut(): https://www.arduino.cc/reference/en/language/functions/advanced-io/shiftout/
 *
 * @author: Gerald.Hurdle@AlgonquinCollege.com
 */
int SER = 14; //data
int LATCH = 15; //RCLK
int CLOCK = 16; //SRCLK
int value = 170;


void setup() {
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, LOW);

  delay(1000);
}

void loop() {
//Forwards
byte theBits = 1;
for (int i = 0; i < 8; i++) {
//ground latchPin and hold low for as long as you
// are transmitting
digitalWrite(LATCH, LOW);
shiftOut(SER, CLOCK, MSBFIRST, theBits);
digitalWrite(LATCH, HIGH);

delay(100);

theBits <<= 1;
}

//Backwards
byte theBitsB = 1;
for (int i = 8; i > 0; i--) {
//ground latchPin and hold low for as long as you
// are transmitting
digitalWrite(LATCH, LOW);
shiftOut(SER, CLOCK, LSBFIRST, theBitsB);
digitalWrite(LATCH, HIGH);

delay(100);

theBitsB <<= 1;
}
}
