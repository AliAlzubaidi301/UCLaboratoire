#define BIT_LED 7
#define MASQUE_LED (1 << BIT_LED)

// value loaded in the timer to get ~1 second
// multiplied by 2 to make the blink slower
#define PRECHARGE_TIMER1 (6072)

// Timer1 prescaler set to 256
#define PRESCALER_TIMER1 (1 << CS12)

// Timer1 overflow flag
#define FLAG_DEBORDEMENT_TIMER1 (1 << TOV1)


void setup() {

  // set PB7 as output for the LED
  DDRB |= MASQUE_LED;

  // Timer1 in normal mode
  TCCR1A = 0x00;

  // start Timer1 with prescaler 256
  TCCR1B = PRESCALER_TIMER1;

  // preload the counter so we don't wait the full overflow
  TCNT1 = PRECHARGE_TIMER1;
}

void loop() {

  // check if the timer has overflowed
  if (TIFR1 & FLAG_DEBORDEMENT_TIMER1) {

    // clear overflow flag 
    TIFR1 |= FLAG_DEBORDEMENT_TIMER1;

    // reload the counter to keep the same timing
    TCNT1 = PRECHARGE_TIMER1;

    // toggle the LED 
    PORTB ^= MASQUE_LED;
  }
}
