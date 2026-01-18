#define BROCHE_BOUTON 2
#define BROCHE_LED 13

#define REG_BOUTON_LECTURE PINE
#define REG_LED_SORTIE PORTB

#define REG_BOUTON_DDR DDRE
#define REG_LED_DDR DDRB

#define BIT_BOUTON 4
#define BIT_LED 7

#define MASQUE_BOUTON (1 << BIT_BOUTON)
#define MASQUE_LED (1 << BIT_LED)

#define periode 500


unsigned long previousTime = 0;

void setup() {

  // configure LED (PB7) as output
  REG_LED_DDR |= MASQUE_LED;
}

void loop() {

  unsigned long currentTime = millis();

  if (currentTime - previousTime >= periode) {

    previousTime = currentTime;

    // toggle LED using XOR
    REG_LED_SORTIE ^= MASQUE_LED;
  }
}
