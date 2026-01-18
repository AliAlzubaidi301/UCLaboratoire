#define BIT_LED 7
#define MASQUE_LED (1 << BIT_LED)

// Timer clock = 16 MHz / 256 = 62 500 Hz
#define OCR1A_VALUE 62499

// Timer1 prescaler set to 256
#define PRESCALER_TIMER1 (1 << CS12)

// Timer1 compare match A flag
#define FLAG_COMPARAISON_TIMER1 (1 << OCF1A)


void setup() {

  // set PB7 as output for the LED
  DDRB |= MASQUE_LED;

  // Timer1 configuration:
  // CTC mode
  TCCR1A = 0x00;
  // prescaler 256

  TCCR1B = (1 << WGM12) | PRESCALER_TIMER1;

  // set compare value
  OCR1A = OCR1A_VALUE;
}

void loop() {

  // check if compare match A occurred
  if (TIFR1 & FLAG_COMPARAISON_TIMER1) {

    // clear compare match flag
    TIFR1 |= FLAG_COMPARAISON_TIMER1;

    // toggle LED
    PORTB ^= MASQUE_LED;
  }
}
