//these teensy pins are PWM capable pins
int greenLED = 16;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
int blueLED = 17;//2.3V, ~111ohm
int redLED = 18;//1.6V, ~189ohm

long dutyCycleRandNumber;

void setup() {
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
//  pinMode(pushButton, INPUT);
  pinMode(A0, INPUT);//use this open circuited pin for a seed to the random number generator
}

// the loop() methor runs over and over again,
// as long as the board has power

void loop() {
  randomSeed(analogRead(A0));
    dutyCycleRandNumber = random(256);
    analogWrite(greenLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(256);
    analogWrite(redLED, dutyCycleRandNumber);
    dutyCycleRandNumber = random(256);
    analogWrite(blueLED, dutyCycleRandNumber);
    delay(500);
}
