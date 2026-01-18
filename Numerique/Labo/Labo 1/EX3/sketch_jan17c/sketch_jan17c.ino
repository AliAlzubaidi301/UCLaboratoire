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

#define DelayAntiRebon 500

bool buttonState = true;  // save the button state

void setup() {

  // set the led pin as output
  REG_LED_DDR |= MASQUE_LED;
}

void loop() {

  // read the button from the input register
  // button is active low so we invert the value
  buttonState = !(REG_BOUTON_LECTURE & MASQUE_BOUTON);

  if (buttonState) {

    // toggle the led using xor
    REG_LED_SORTIE ^= MASQUE_LED;

    //  delay to avoid bouncing
    delay(DelayAntiRebon);
  }
}
