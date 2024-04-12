#ifndef KEY_CPP
#define KEY_CPP 1
#include <Arduino.h>
#include "Key.h"


// default constructor
Key::Key() {
	delayTime = 0;
	kchar = NO_KEY;
	kcode = -1;
	kstate = IDLE;
	stateChanged = false;
	pin = 0;
	activeLevel = LOW;
}

// constructor
Key::Key(char userKeyChar) {
	delayTime = 0;
	holdTime = 0;
	kchar = userKeyChar;
	kcode = -1;
	kstate = IDLE;
	stateChanged = false;
	pin = 0;
	activeLevel = LOW;
}

Key::Key(char userKeyChar, uint8_t userPin) {
	delayTime = 0;
	holdTime = 0;
	kchar = userKeyChar;
	kcode = -1;
	kstate = IDLE;
	stateChanged = false;
	pin = userPin;
	activeLevel = LOW;
}

Key::Key(char userKeyChar, uint8_t userPin, uint8_t userActive){
	delayTime = 0;
	holdTime = 0;
	kchar = userKeyChar;
	kcode = -1;
	kstate = IDLE;
	stateChanged = false;
	pin = userPin;
	activeLevel = userActive;

}



Key::Key(char userKeyChar, uint8_t userPin, uint8_t userActive, unsigned long userDelay,KeyState userState, boolean userStatus ) {
	delayTime = userDelay;
	holdTime = 0;
	kchar = userKeyChar;
	kcode = -1;
	kstate = userState;
	stateChanged = userStatus;
	pin = userPin;
	activeLevel = userActive;
}

/*
	Key state diagram

	state    stateChanged  keyValue  Debounce delay next State  next StateChanged Action
	IDLE     n/a           OPEN      n/a            IDLE        FALSE             
	IDLE     n/a           CLOSED    n/a            PRESSED     TRUE              Set debounce delay.
	PRESSED  TRUE          OPEN      EXPIRED        RELEASED    TRUE		      
	PRESSED  n/a           n/a       NOT EXPIRED    PRESSED     FALSE             
	PRESSED  n/a           CLOSED    EXPIRED        HOLD        TRUE
    HOLD     n/a           CLOSED    n/a            HOLD        FALSE
	HOLD     n/a           OPEN      n/a            RELEASED    TRUE              Set debounce delay.
	RELEASED n/a           n/a       NOT EXPIRED    RELEASED    FALSE
	RELEASED n/a           OPEN      EXPIRED        IDLE        TRUE
 */
void Key::updateKey() {
	uint8_t keyValue;
	keyValue = digitalRead(pin) == activeLevel ? CLOSED : OPEN;
	if (millis() < holdTime) holdTime = millis();
	bool delayExpired = (millis() - holdTime) > delayTime;
	switch (kstate)
	{
	case IDLE:
		if (keyValue == CLOSED) { // go to PRESSED state and set debounce delay
			kstate = PRESSED;
			holdTime = millis();
			stateChanged = true;
		} else { // OPEN
			kstate = IDLE; // no change
			stateChanged = false;
		}
		break;
	
	case PRESSED:
		if (keyValue == CLOSED) {
			if (delayExpired) { // go to HOLD state
				kstate = HOLD;
				stateChanged = true;
			} else { // delay not expired stay in PRESSED state
				kstate = PRESSED;
				stateChanged = false;
			}
		} else { // key is OPEN go to RELEASED state
			holdTime = millis();
			kstate = RELEASED;
			stateChanged = true;
		} 
		break;

	case HOLD:
		if (keyValue == CLOSED) {
			kstate = HOLD;
			stateChanged = false;
		} else { // key was released go to RELEASED state and set delay timer
			kstate = RELEASED;
			stateChanged = true;
			holdTime = millis();
		}
		break;

	case RELEASED:
		if (keyValue == OPEN) {
			if (delayExpired) { // go to IDLE state
				kstate = IDLE;
				stateChanged = true;
			} else { // delay not expired stay in RELEASED state
				kstate = RELEASED;
				stateChanged = false;
			}
		} else { // key is CLOSED go to PRESSED state
			holdTime = millis();
			kstate = PRESSED;
			stateChanged = true;
		}
		break;

	default:
		break; // this can't happen
	}
}


KeyState Key::getKeyState() {
	return kstate;
}

bool Key::getStateChanged(){
	return stateChanged;
}

char Key::getChar() {
	return kchar;
}
#endif