#include "constants.h"
#include "Segment.hpp"
#include "Digit.hpp"

Segment segments[NUMBER_OF_SEGMENTS];
Digit tensDigit;
Digit unitsDigit;
unsigned long currentTime;
unsigned long lastTime;
unsigned short tens;
unsigned short units;

short currentRadioPinState[NUMBER_OF_RADIO_PINS] = {LOW, LOW, LOW, LOW, LOW};
short lastRadioPinState[NUMBER_OF_RADIO_PINS] = {LOW, LOW, LOW, LOW, LOW};

/// @brief Setup is called once during the initialization during power up or after a reset
void setup()
{
    /// Define the pins for selecting a segment and deciding whether to set or reset
    for (int i = 0; i < NUMBER_OF_SEGMENTS; i++)
    {
        segments[i].initSegment(segEnablePins[i], segSetResetPins[i]);

        pinMode(segEnablePins[i], OUTPUT);
        pinMode(segSetResetPins[i], OUTPUT);
    };
    // Define the digits
    tensDigit.initDigit(tensDigitPin, segments, NUMBER_OF_SEGMENTS);
    pinMode(tensDigitPin, OUTPUT);
    unitsDigit.initDigit(unitsDigitPin, segments, NUMBER_OF_SEGMENTS);
    pinMode(unitsDigitPin, OUTPUT);

    // Define the input pins for the radio remote control
    for (int i; i < NUMBER_OF_RADIO_PINS; i++)
    {
        pinMode(radioPins[i], INPUT);
    };

    // Define the output pin for disconnecting the power
    pinMode(powerDisablePin, OUTPUT);

    lastTime = 0;
    tens = 0;
    units = 0;

    Serial.begin(115200);
    Serial.println("Initialized");
};

/// @brief Loop is called repeatedly forever during power up time after setup is run.
void loop()
{
    // check to see if we should shut down
    currentTime = millis();
    if (currentTime - lastTime > TIMEOUT_MILLISECONDS)
    { // clock wrapped
        // clock wrapped
        digitalWrite(powerDisablePin, LOW); // drop the power
        delay(1000);                        // wait until power dies
    }                                       // doesn't make it out of here
    else
    {
        // Read the button pins from the receiver
        for (int i = 0; i < NUMBER_OF_RADIO_PINS; i++)
        {
            currentRadioPinState[i] = (radioPins[i]);
        }

        // If A button has gone high (different from last read) process it
        if ((currentRadioPinState[BUTTON_A] == HIGH) && (lastRadioPinState[BUTTON_A] == LOW))
        {
            /// Button A "Above" means increment (select the next above of) the units digit by one. If it 
            /// increments from 9, then increment the tens digit by one. You can increment the 10s digit back to zero
            /// from 99.

            units = ++units % 10;

            if (units == 0) {
                tens = (tens + 1) % 10;
            }
            
            tensDigit.update(tens);
            unitsDigit.update(units);

        };
        // If B button has gone high (different from last read) process it
        if ((currentRadioPinState[BUTTON_B] == HIGH) && (lastRadioPinState[BUTTON_B] == LOW))
        {
            /// Button B "Below" means decrement (select the next below of) the units digit by one. If it
            /// decrements from zero, it will be replaced with 9 and the tens digit will decrement by one. The tens
            /// digit will not decrement from zero.

            if (units == 0) 
            {
                units = 9;
                tens = tens>0?tens--:0;
            }
            else {
                units--;
            }
             
            tensDigit.update(tens);
            unitsDigit.update(units);
        };
        // If C button has gone high (different from last read) process it
        if ((currentRadioPinState[BUTTON_C] == HIGH) && (lastRadioPinState[BUTTON_C] == LOW))
        {
            /// Reset "Clear" means set all segments to their HIDDEN state.
            tensDigit.reset();
            unitsDigit.reset();

            tens = 0;
            units = 0;
        };
        // If D button has gone high (different from last read) process it
        if ((currentRadioPinState[BUTTON_D] == HIGH) && (lastRadioPinState[BUTTON_D] == LOW))
        {
            /// Multiply the number by ten, "Decimal".  That is the units digit value will replace the tens 
            /// digit value. The tens digit value is lost. The units digit becomes 0.

            tens = units;
            units = 0;

            tensDigit.update(tens);
            unitsDigit.update(units);
        };

        for (int i = 0; i < NUMBER_OF_RADIO_PINS; i++) // move current pin state to last pin state
        {
            lastRadioPinState[i] = currentRadioPinState[i];
        }
    };
}