#define POT_PIN A0
#define PERIODE 1000

unsigned long tempsPrecedent = 0;

void setup() {
  pinMode(POT_PIN,INPUT) ;
  Serial.begin(9600);
}

void loop() {
  unsigned long tempsActuel = millis();

  if (tempsActuel - tempsPrecedent >= PERIODE) {
    tempsPrecedent = tempsActuel;

    int valeur = analogRead(POT_PIN);
    Serial.print("ADC value: ");
    Serial.println(valeur);
  }
}
