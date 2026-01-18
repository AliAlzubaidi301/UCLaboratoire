#define LED 13

void setup() {

  pinMode(LED, OUTPUT);

  // Timer1 in CTC mode
  TCCR1A = 0;
  TCCR1B = (1 << WGM12) | (1 << CS12); // CTC and prescaler 256

  OCR1A = 62499;          // ~1 second

  TIMSK1 |= (1 << OCIE1A); // enable compare interrupt
  sei();                  // enable global interrupts
}

ISR(TIMER1_COMPA_vect) {
  digitalWrite(LED, !digitalRead(LED));
}

void loop() {
  // nothing here
}
