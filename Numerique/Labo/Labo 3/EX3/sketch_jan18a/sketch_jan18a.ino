#define PERIODE 1000  // Time period in milliseconds

volatile uint16_t adc;   // Stores ADC result
volatile bool ready;  // Flag set when conversion is finished

unsigned long t;  // Time reference

void setup() {
  Serial.begin(9600);  // Initialize serial communication

  ADMUX = (1 << REFS0);  // Use AVcc as reference  select ADC0  10-bit result

  ADCSRA = (1 << ADEN)    // Enable ADC
           | (1 << ADIE)  // Enable ADC interrupt
           | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  // Prescaler 128 → ADC clock = 125 kHz

  sei();  // Enable global interrupts
}

void loop() {
  // Check if 1 second has passed
  if (millis() - t >= PERIODE) {
    t = millis();
    ADCSRA |= (1 << ADSC);  // Start ADC conversion
  }

  // If ADC conversion is finished
  if (ready) {
    ready = 0;            // Clear flag
    Serial.println(adc);  // Show ADC value
  }
}

// ADC conversion complete interrupt
ISR(ADC_vect) {
  adc = ADC;  // Read 10 bit ADC result
  ready = 1;  // Set flag to signal end of conversion
}
