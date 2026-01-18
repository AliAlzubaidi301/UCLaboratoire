#define PERIODE 1000

unsigned long t0 = 0;

void setup() {
  Serial.begin(9600);

  ADMUX = (1 << REFS0);          // AVcc, ADC0
  ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

void loop() {
  if (millis() - t0 >= PERIODE) {
    t0 = millis();

    ADCSRA |= (1 << ADSC);       // start ADC
    while (ADCSRA & (1 << ADSC)); // wait

    Serial.println(ADC);
  }
}
