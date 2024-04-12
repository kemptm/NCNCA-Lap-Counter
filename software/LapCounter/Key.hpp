#ifndef KEY_H
#define KEY_H 1

#define OPEN LOW
#define CLOSED HIGH

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef enum{ IDLE, PRESSED, HOLD, RELEASED } KeyState;

const char NO_KEY = '\0';

class Key {
public:
	// members
	unsigned long delayTime;
	unsigned long holdTime;
	int kcode;
	char kchar;
	KeyState kstate;
	bool stateChanged;
    uint8_t pin;
	uint8_t activeLevel;

	// methods
	Key();
	Key(char userKeyChar);
	Key(char userKeyChar, uint8_t userpin);
	Key(char userKeyChar, uint8_t userPin, uint8_t userActive);
	Key(char userKeyChar, uint8_t userPin, uint8_t userActive, unsigned long userDelay, KeyState userState, bool userStatus);
	void updateKey();
	KeyState getKeyState();
	bool getStateChanged();
	char getChar();

private:

};
#endif