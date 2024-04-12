/*
  
*/
#include <Arduino.h>
#include "Key.h"
  const byte numberButtons = 4;
  const short buttonPins[numberButtons] = {49, 47, 53, 51};
  const char buttonNames[numberButtons] = {'1', '2', '3', '4'};
  Key buttons[numberButtons];

// the setup function runs once when you press reset or power the board
void setup() {

  // Initialize keys
  for (int i = 0; i < numberButtons; i++) {
    buttons[i] = Key(buttonNames[i],buttonPins[i],LOW, 45, IDLE, false);
  }

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // initialize digital pins as pulled up inputs
  for(int i = 0; i < numberButtons; i++) {
      pinMode(buttonPins[i],INPUT_PULLUP);
  }

  Serial.begin(115200);
  Serial.println("Initialized");
  digitalWrite(LED_BUILTIN,LOW);

}

// the loop function runs over and over again forever
void loop() {
  // read the keys
  for (int i = 0; i < numberButtons; i++){
    buttons[i].updateKey();
  }

  for (int i = 0; i < numberButtons; i++){
    if (buttons[i].getStateChanged()) {
      Serial.print(millis());
      Serial.print(" ");
      Serial.print(buttons[i].getChar());
      Serial.print(" ");
      switch (buttons[i].getKeyState()){
        case IDLE:
          Serial.print("IDLE");
          digitalWrite(LED_BUILTIN,LOW);
          break;
        case PRESSED:
          Serial.print("PRESSED");
          break;
        case HOLD:
          Serial.print("HOLD");
          digitalWrite(LED_BUILTIN, HIGH);
          break;
        case RELEASED:
          Serial.print("RELEASED");
          break;
      }
      Serial.println(" ");
    //  Serial.println(buttons[i].getStateChanged());
    }
  }

  // turn on led if any button is being held.
  for (int i = 0; i < numberButtons; i++){
    if (buttons[i].getKeyState() == HOLD){
        digitalWrite(LED_BUILTIN,HIGH);
        break;
    } else {
        digitalWrite(LED_BUILTIN,LOW);
    }
  }


}
