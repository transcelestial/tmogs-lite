int hertz = 15;       // frequency of blinking, peak to peak
float proportion = 0.5;   // proportion of on to off wave in a cycle. 

int led = 9;           // the pin the LED is attached to

//we can add multiple pullup pins to modify the hertz values
int pullup_15 = 52;

int on_time = 0;
int off_time = 0;

void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(pullup_15, INPUT_PULLUP);
  //add more here
  on_time = (1000/hertz)*proportion;
  off_time = (1000/hertz)*(1-proportion);
  Serial.begin(9600);
  digitalWrite(led, LOW);
}

void loop() {
  // switch on led
  if (digitalRead(pullup_15) == 1){
    digitalWrite(led, HIGH);
    // delay with hertz
    delay(on_time);
    // switch off led
    digitalWrite(led, LOW);
    // delay with hertz
    delay(off_time);
  }
  else {
  }
}
