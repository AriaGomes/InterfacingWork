/************************************************************
* Practical Question: Fall 2020
*
* Level Achieved: Level A+
*
* Status: Complete and working Level A+ circuit
*
* @author Aria Gomes (gome0098@algonquinlive.com) <040878659>
**************************************************************/
IntervalTimer injectLow;
IntervalTimer injectHigh;
IntervalTimer timer1;
bool stat = true;
int code;
int inject;
float celsius;
int SER = 14; //data
int LATCH = 16; //RCLK
int CLOCK = 17; //SRCLK
int Thermistor = 15;
int letterIndex = 0;
const double MIN_TEMP = 15.0;     //no student has reported lower than 15 degrees Celsius
const double MAX_TEMP = 33.0;     //no student has reported higher than 33 degrees Celsius
byte letters[3] = {
B01010100,    //0 = n - for normal
B10111000,    //1 = L - for low
B11110110     //2 = H - for high
};                                 

void setup() {
  pinMode(Thermistor, INPUT);
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  digitalWrite(SER, LOW);
  digitalWrite(CLOCK, LOW);
  digitalWrite(LATCH, HIGH);
  injectLow.begin(injectLowVal, 3000000);
  injectHigh.begin(injectHighVal,6000000);
  timer1.begin(voidM, 9000000);

  for(unsigned int i=0; i<sizeof(letters); i++)
    letters[i] ^= B11111111;
}

void loop() 
{

  //Letter Index logic
  if(celsius > MAX_TEMP){
    letterIndex = 2;
  }
  if(celsius < MIN_TEMP){
    letterIndex = 1;
  }
  if(celsius < MAX_TEMP && celsius > MIN_TEMP){
    letterIndex = 0;
  }

  readTemp();
  
  //Update Display
  digitalWrite(LATCH, LOW); // prepare shift register for data
  shiftOut(SER, CLOCK, MSBFIRST, letters[letterIndex]); // send data
  digitalWrite(LATCH, HIGH); // update display
  digitalWrite(LATCH, LOW);
  Serial.print("Temperature: ");
  Serial.print(code);
  Serial.print(" (raw) ");
  Serial.print(celsius);
  Serial.print(" Celsius\n");
  delay(1000);
}

void readTemp()
{
if (stat == true)
{
     //Read Accurate temperature
  code = analogRead(Thermistor);
  if (code <= 289) {celsius = 5 + (code - 289) / 9.82;}
  if (code > 289 && code <= 342) {celsius = 10 + (code - 342) / 10.60;}
  if (code > 342 && code <= 398) {celsius = 15 + (code - 398) / 11.12;}
  if (code > 398 && code <= 455) {celsius = 20 + (code - 455) / 11.36;}
  if (code > 455 && code <= 512) {celsius = 25 + (code - 512) / 11.32;}
  if (code > 512 && code <= 566) {celsius = 30 + (code - 566) / 11.00;}
  if (code > 566 && code <= 619) {celsius = 35 + (code - 619) / 10.44;}
  if (code > 619 && code <= 667) {celsius = 40 + (code - 667) / 9.73;}
  if (code > 667) {celsius = 45 + (code - 712) / 8.90;}
}
else
{
  code = inject;
}
  
 delay(4000);

}

void injectLowVal()
{
   inject = -800;
   Serial.print("INJECT: LOW\n");
   injectLow.end();
     
}

void injectHighVal()
{
  inject = 800;
  Serial.print("INJECT: HIGH\n");
}

void voidM()
{
  timer1.end();
  stat = true;
}
