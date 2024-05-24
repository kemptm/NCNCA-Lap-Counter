#include "constants.h"
#include "Segment.hpp"
#include "Digit.hpp"
#include "Key.hpp"
Segment unitsSegments[NUMBER_OF_SEGMENTS];
Segment tensSegments[NUMBER_OF_SEGMENTS];
Digit tensDigit;
Digit unitsDigit;
unsigned long currentTime;
unsigned long lastTime;
unsigned short tens;
unsigned short units;

Key buttons[numberButtons];

void setup()
{
    Serial.println("setup");
    /// Define the onboard LED and shut it off.
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    PRINT_PIN(LED_BUILTIN)

    solenoid_hold = SOLENOID_DELAY; // starting value

    /// Define the pins for selecting a segment and deciding whether to set or reset
    for (int i = 0; i < NUMBER_OF_SEGMENTS; i++)
    {
        unitsSegments[i].initSegment(segEnablePins[i], segSetResetPins[i]);
        tensSegments[i].initSegment(segEnablePins[i], segSetResetPins[i]);

        pinMode(segEnablePins[i], OUTPUT);
        digitalWrite(segEnablePins[i], HIGH);
        PRINT_PIN(segEnablePins[i])

        pinMode(segSetResetPins[i], OUTPUT);
        digitalWrite(segSetResetPins[i], HIGH);
        PRINT_PIN(segSetResetPins[i])
    };
    /// Define the digits
    tensDigit.initDigit(tensDigitPin, tensSegments, NUMBER_OF_SEGMENTS);
    pinMode(tensDigitPin, OUTPUT);
    digitalWrite(tensDigitPin, HIGH);
    PRINT_PIN(tensDigitPin)

    unitsDigit.initDigit(unitsDigitPin, unitsSegments, NUMBER_OF_SEGMENTS);
    pinMode(unitsDigitPin, OUTPUT);
    digitalWrite(unitsDigitPin, HIGH);
    PRINT_PIN(unitsDigitPin)

    /// Define the input pins for the radio remote control and local buttons
    /// local buttons
    for (int i = 0; i < 4; i++)
    {
        buttons[i] = Key(buttonNames[i], buttonPins[i], LOW, 45, IDLE, false);
        pinMode(buttons[i].pin, INPUT_PULLUP);
    }

    // Radio buttons
    for (int i = 4; i < numberButtons; i++)
    {
        // buttons[i] = Key(buttonNames[i],buttonPins[i],HIGH, 45, IDLE, false);
        // pinMode(buttons[i].pin,INPUT);
        //  quick hack to disable radio keys -- make them INPUT_PULLUP instead of INPUT as they
        //  will be when connected.
        buttons[i] = Key(buttonNames[i], buttonPins[i], LOW, 45, IDLE, false);
        pinMode(buttons[i].pin, INPUT_PULLUP);
    }

    // Define the output pin for disconnecting the power
    pinMode(powerDisablePin, OUTPUT);
    digitalWrite(powerDisablePin, LOW);

    lastTime = 0;
    tens = 0;
    units = 0;

    Serial.begin(115200);

    // Power On Self test
    Serial.println("POST");
    digitalWrite(LED_BUILTIN, HIGH);
    PRINT_PIN(LED_BUILTIN)

    tensDigit.reset();
    unitsDigit.reset();
    unitsDigit.update(8);
    tensDigit.update(8);
    delay(3000);
    tensDigit.reset();
    unitsDigit.reset();

    // Signal that we are up and ready
    Serial.println("Initialized");
    digitalWrite(LED_BUILTIN, LOW);
    PRINT_PIN(LED_BUILTIN)
}

void loop()
{

    // read the keys
    for (int i = 0; i < numberButtons; i++)
    {
        buttons[i].updateKey();
    }

    // If A button or 1 button has gone high (different from last read) process it
    if ((buttons[RADIO_A].getKeyState() == HOLD) && (buttons[RADIO_A].getStateChanged()) || ((buttons[LOCAL_1].getKeyState() == HOLD) && (buttons[LOCAL_1].getStateChanged())))
    {
        /// Button A "Above" (and button 1) means increment (select the next above of) the units digit by one. If it
        /// increments from 9, then increment the tens digit by one. You can increment the 10s digit back to zero
        /// from 99.

        Serial.println("1 or A");

        units = ++units % 10;

        if (units == 0)
        {
            tens = (tens + 1) % 10;
        }

        tensDigit.update(tens);
        unitsDigit.update(units);
    };
    // If B button or 2 button has gone high (different from last read) process it
    if ((buttons[RADIO_B].getKeyState() == HOLD) && (buttons[RADIO_B].getStateChanged()) || ((buttons[LOCAL_2].getKeyState() == HOLD) && (buttons[LOCAL_2].getStateChanged())))
    {
        /// Button B "Below" (and button 2) means decrement (select the next below of) the units digit by one. If it
        /// decrements from zero, it will be replaced with 9 and the tens digit will decrement by one. The tens
        /// digit will not decrement from zero.

        Serial.println("2 or B");
        if (units == 0)
        {
            units = 9;
            tens = tens > 0 ? tens - 1 : 0;
        }
        else
        {
            units--;
        }

        tensDigit.update(tens);
        unitsDigit.update(units);
    };
    // If C button or 3 button has gone high (different from last read) process it
    if ((buttons[RADIO_C].getKeyState() == HOLD) && (buttons[RADIO_C].getStateChanged()) || ((buttons[LOCAL_3].getKeyState() == HOLD) && (buttons[LOCAL_3].getStateChanged())))
    {
        /// Reset "Clear" means set all segments to their HIDDEN state.
        Serial.println("3 or C");

        tensDigit.reset();
        unitsDigit.reset();

        solenoid_hold = solenoid_hold * 2;
    };
    // If D button or 4 button has gone high (different from last read) process it
    if ((buttons[RADIO_D].getKeyState() == HOLD) && (buttons[RADIO_D].getStateChanged()) || ((buttons[LOCAL_4].getKeyState() == HOLD) && (buttons[LOCAL_4].getStateChanged())))
    {
        /// Multiply the number by ten, "Decimal".  That is the units digit value will replace the tens
        /// digit value. The tens digit value is lost. The units digit becomes 0.
        Serial.println("4 or D");

        tensDigit.reset();
        unitsDigit.reset();
        
        solenoid_hold = solenoid_hold / 2;
    };
}