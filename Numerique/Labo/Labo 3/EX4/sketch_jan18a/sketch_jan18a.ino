void timer1Init() {
  // OC1A = PB5 = Arduino pin 11
  DDRB |= (1 << PB5);   // PB5 configured as output
  // toggle OC1A on compare match
  TCCR1A = (1 << COM1A0);
  // CTC mode, prescaler = 8
  TCCR1B = (1 << WGM12) | (1 << CS11);
  // initial compare value
  OCR1A = 1000;
}

void adcInit() {
  // AVcc reference, ADC0 (A0)
  ADMUX = (1 << REFS0);
  // enable ADC, prescaler 128
  ADCSRA = (1 << ADEN)
         | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t lireADC() {
  ADCSRA |= (1 << ADSC);     // start conversion
  while (ADCSRA & (1 << ADSC))
    ;                         // wait for conversion
  return ADC;                // return ADC value
}

void setup() {
  timer1Init();
  adcInit();
  Serial.begin(9600);
}

void loop() {

  uint16_t valeurPot = lireADC();   // read potentiometer

  // frequency between 2 Hz and 100 kHz
  uint32_t frequence = 2 + (valeurPot * 99998UL) / 1023;

  uint32_t diviseur;
  uint16_t bitsPresc;

  // prescaler selection
  if (frequence > 2000) {
    diviseur = 8;
    bitsPresc = (1 << CS11);
  } else {
    diviseur = 64;
    bitsPresc = (1 << CS11) | (1 << CS10);
  }

  // Timer1 CTC formula with toggle OC1A
  uint32_t valeurCompare =
    (16000000UL / (2UL * diviseur * frequence)) - 1;

  // limit to 16-bit range
  if (valeurCompare > 65535) valeurCompare = 65535;
  if (valeurCompare < 1)     valeurCompare = 1;

  // update timer registers
  TCCR1B = (1 << WGM12) | bitsPresc;
  OCR1A = (uint16_t)valeurCompare;

  delay(50);
}
