#define LED 13
#define BTN 2

bool etatLed = false;   // keep in memory if the led is on or off

void setup() {

  pinMode(LED, OUTPUT);
  // led pin is set as output so we can turn it on or off

  attachInterrupt(digitalPinToInterrupt(BTN), interruptionBouton, FALLING);
  // connect the button to an interrupt
  // FALLING because when i press the button the signal go from HIGH to LOW
}

// function called by the interrupt
void interruptionBouton() {

  // when nothing happen the cpu stay in normal execution
  // when the button is pressed, the falling edge is detected
  // the cpu stop what it was doing and come here
  // after this function it return automatically to normal code

  etatLed = !etatLed;

  digitalWrite(LED, etatLed);
  // send the value to the led pin
}

void loop() {

}
