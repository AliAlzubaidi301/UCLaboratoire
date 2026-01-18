#define REG_LED_SORTIE PORTB
#define REG_LED_DDR DDRB

#define BIT_LED 7
#define MASQUE_LED (1 << BIT_LED)

#define VECTEUR_INTERRUPTION INT4_vect

void setup() {

  // set the led pin as output (PB7)
  REG_LED_DDR |= MASQUE_LED;

  // configure INT4 to trigger on falling edge
  EICRB |= (1 << ISC41);
  EICRB &= ~(1 << ISC40);

  // enable external interrupt INT4
  EIMSK |= (1 << INT4);

  // enable global interrupts
  sei();
}

ISR(VECTEUR_INTERRUPTION) {

  // toggle the led state
  REG_LED_SORTIE ^= MASQUE_LED;
}

void loop() {
}
