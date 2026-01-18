#define LED_PWM 9   // PWM pin on Arduino Mega

void setup() {

  // set PWM pin as output
  pinMode(LED_PWM, OUTPUT);
}

void loop() {

  // increase duty cycle from 0 to 255
  for (int duty = 0; duty <= 255; duty++) {
    analogWrite(LED_PWM, duty);
    delay(10);  // slow down variation
  }

  // decrease duty cycle from 255 to 0
  for (int duty = 255; duty >= 0; duty--) {
    analogWrite(LED_PWM, duty);
    delay(10);
  }
}
