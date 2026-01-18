#define DelayPeriode 1000   // time between each led toggle in milliseconds

#define LED 13             // led connected to pin 13

unsigned long previousTime = 0;  // the last time the led changed state
bool ledState = false;           // current led state

void setup() {
  pinMode(LED, OUTPUT);          // set the led pin as output
}

void loop() {
  unsigned long currentTime = millis();  // get current time since startup

  // check if the delay time has passed
  if (currentTime - previousTime >= DelayPeriode) {

    previousTime = currentTime;          // update last time
    ledState = !ledState;                // toggle led state

    digitalWrite(LED, ledState);          // apply the new led state
  }
}
