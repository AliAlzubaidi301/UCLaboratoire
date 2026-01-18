#define LED 13
#define BTN 2

#define DelayRebond 500   // little delay to avoid button bouncing (else it toggle many time)

bool etatLed = false;     // save the led state (on or off)

void setup() {
  pinMode(LED, OUTPUT);  // set led pin as output
  pinMode(BTN, INPUT);   // button pin as input
}

void loop() {

  // read the button state
  // when i press the button the pin goes LOW
  if (digitalRead(BTN) == LOW) {

    // change the led state every time the button is pressed
    etatLed = !etatLed;

    // write the new value on the led pin
    digitalWrite(LED, etatLed);

    // delay for debounce
    delay(DelayRebond);
  }
}
