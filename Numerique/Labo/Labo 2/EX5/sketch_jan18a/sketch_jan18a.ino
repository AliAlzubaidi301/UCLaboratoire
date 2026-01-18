void setup() {

  // OC1A (PB5 / pin 11) as output
  DDRB |= (1 << 5);

  // Timer1 configuration
  // CTC mode
  // toggle OC1A on compare match
  TCCR1A = (1 << COM1A0);
  TCCR1B = (1 << WGM12) | (1 << CS10); // no prescaler

  // Compare value for 100 kHz
  // f = F_CPU / (2 * (1 + OCR1A))
  // OCR1A = 79 for ~100 kHz
  OCR1A = 79;
}

void loop() {
}
