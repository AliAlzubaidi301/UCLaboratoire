#define BIT_LED 7
#define MASQUE_LED (1 << BIT_LED)

// value loaded in the timer to get ~1 second
// Timer clock = 16 MHz / 256 = 62 500 Hz
#define PRECHARGE_TIMER1 3036

// Timer1 prescaler set to 256
#define PRESCALER_TIMER1 (1 << CS12)


void setup() {

  // set PB7 as output for the LED
  DDRB |= MASQUE_LED;

  // Timer1 in normal mode
  TCCR1A = 0x00;
  TCCR1B = PRESCALER_TIMER1;

  // preload counter value
  TCNT1 = PRECHARGE_TIMER1;

  // enable Timer1 overflow interrupt
  TIMSK1 |= (1 << TOIE1);

  // enable global interrupts
  sei();
}

// Timer1 overflow interrupt service routine
ISR(TIMER1_OVF_vect) {

  // reload counter to keep constant period
  TCNT1 = PRECHARGE_TIMER1;

  // toggle LED
  PORTB ^= MASQUE_LED;
}

void loop() {
}
