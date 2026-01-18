#define DelayPeriode 500   // delay time in milliseconds

#define LED 13             // led connected to pin 13

void setup() {
  // setup function, executed once at startup

  pinMode(LED, OUTPUT);   // set the led pin as output
}

void loop() {
  // main loop, executed continuously

  digitalWrite(LED, HIGH);  // turn the led ON
  delay(DelayPeriode);      // wait for the defined delay

  digitalWrite(LED, LOW);   // turn the led OFF
  delay(DelayPeriode);      // wait again before next cycle
}
