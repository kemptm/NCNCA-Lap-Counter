// assign LED pin to the array
int ledPin[4]={1,2,3,4};
int delay_t = 500;

void setup() {
  // set pins 1,2,3,4 as output
  for (int i = 0; i <= 4; i++) {
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  // iterate over the pins:
  for (int i = 0; i <= 3; i++) {
      digitalWrite(ledPin[i], HIGH);
      delay(delay_t);
      digitalWrite(ledPin[i], LOW);
      delay(delay_t);
    }
  }