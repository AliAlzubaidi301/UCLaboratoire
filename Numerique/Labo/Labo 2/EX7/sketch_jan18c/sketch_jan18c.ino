#define SORTIE_PWM 9   // PWM pin connected to the RC filter

void setup() {

  // configure PWM pin as output
  pinMode(SORTIE_PWM, OUTPUT);
}

void loop() {

  // increase duty cycle from 0 to 255
  for (int duty = 0; duty <= 255; duty++) {
    analogWrite(SORTIE_PWM, duty);
    delay(20);   // slow variation to observe the filtered voltage
  }

  // decrease duty cycle from 255 to 0
  for (int duty = 255; duty >= 0; duty--) {
    analogWrite(SORTIE_PWM, duty);
    delay(20);
  }
}
