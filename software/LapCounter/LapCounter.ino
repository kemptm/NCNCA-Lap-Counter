///-------------------------------------------------------------------------------------------------
/// <file>	D:\Documents\KiCad\7.0\projects\NCNCA-Lap-Counter\software\LapCounter\LapCounter.ino </file>
///
/// <copyright file="LapCounter.ino" company="TMKempEngineering.com">
/// 	Copyright (c) 2024 TMKempEngineering.com. All rights reserved.
/// </copyright>
///
/// <summary>	This is where the system initialization and main loop live. </summary>
///-------------------------------------------------------------------------------------------------
#include "constants.h"
#include "Segment.hpp"
#include "Digit.hpp"
#include "Key.hpp"

/// <summary>	The units segments[ number of segments]. </summary>
Segment unitsSegments[NUMBER_OF_SEGMENTS];
/// <summary>	The tens segments[ number of segments]. </summary>
Segment tensSegments[NUMBER_OF_SEGMENTS];
/// <summary>	The tens digit. </summary>
Digit tensDigit;
/// <summary>	The units digit. </summary>
Digit unitsDigit;
/// <summary>	The current time. </summary>
unsigned long currentTime;
/// <summary>	The last time. </summary>
unsigned long lastTime;
/// <summary>	The tens. </summary>
unsigned short tens;
/// <summary>	The units. </summary>
unsigned short units;

/// <summary>   Define the buttons, both membrane and radio. </summary>
  Key buttons[numberButtons];


///-------------------------------------------------------------------------------------------------
/// <summary>
/// 	@brief Setup is called once during the initialization during power up or after a reset.
/// </summary>
///
/// <remarks>	Kemp, 2/8/2024. </remarks>
///-------------------------------------------------------------------------------------------------

void setup()
{   
    Serial.println("setup");
    /// Define the onboard LED and shut it off.
    pinMode(LED_BUILTIN,OUTPUT);
    digitalWrite(LED_BUILTIN,LOW);
    PRINT_PIN(LED_BUILTIN)


    /// Define the pins for selecting a segment and deciding whether to set or reset
    for (int i = 0; i < NUMBER_OF_SEGMENTS; i++)
    {
        unitsSegments[i].initSegment(segEnablePins[i], segSetResetPins[i]);
        tensSegments[i].initSegment(segEnablePins[i], segSetResetPins[i]);

        pinMode(segEnablePins[i], OUTPUT);
        pinMode(segSetResetPins[i], OUTPUT);
    };
    /// Define the digits
    tensDigit.initDigit(tensDigitPin, tensSegments, NUMBER_OF_SEGMENTS);
    pinMode(tensDigitPin, OUTPUT);
    unitsDigit.initDigit(unitsDigitPin, unitsSegments, NUMBER_OF_SEGMENTS);
    pinMode(unitsDigitPin, OUTPUT);

    /// Define the input pins for the radio remote control and local buttons
    /// local buttons
    for (int i = 0; i < 4; i++) {
        buttons[i] = Key(buttonNames[i],buttonPins[i],LOW, 45, IDLE, false);
        pinMode(buttons[i].pin,INPUT_PULLUP);
    }

    // Radio buttons
    for (int i = 4; i < numberButtons; i++) {
        //buttons[i] = Key(buttonNames[i],buttonPins[i],HIGH, 45, IDLE, false);
        //pinMode(buttons[i].pin,INPUT);
        // quick hack to disable radio keys
        buttons[i] = Key(buttonNames[i],buttonPins[i],LOW, 45, IDLE, false);
        pinMode(buttons[i].pin,INPUT_PULLUP);
    }

    // Define the output pin for disconnecting the power
    pinMode(powerDisablePin, OUTPUT);
    digitalWrite(powerDisablePin,LOW);

    lastTime = 0;
    tens = 0;
    units = 0;

    Serial.begin(115200);

    // Power On Self test
    Serial.println("POST");
    unitsDigit.update(8);
    tensDigit.update(8);
    delay(3000);
    tensDigit.reset();
    unitsDigit.reset();

    // Signal that we are up and ready
    Serial.println("Initialized");
    // digitalWrite(LED_BUILTIN,HIGH); PRINT_PIN(LED_BUILTIN)

};

///-------------------------------------------------------------------------------------------------
/// <summary>
/// 	@brief Loop is called repeatedly forever during power up time after setup is run.
/// </summary>
///
/// <remarks>	Kemp, 2/8/2024. </remarks>
///-------------------------------------------------------------------------------------------------

void loop()
{
    // check to see if we should shut down
    currentTime = millis();
    if (currentTime < lastTime)
    {
        // Clock wrapped (really unlikely)
        lastTime = currentTime;
    }
    if (currentTime - lastTime > TIMEOUT_MILLISECONDS)
    {
        // Timed out
        digitalWrite(powerDisablePin, LOW); PRINT_PIN(powerDisablePin)// drop the power
        delay(1000);                        // wait until power dies
    }                                       // doesn't make it out of here
    else
    {
        // read the keys
        for (int i = 0; i < numberButtons; i++){
            buttons[i].updateKey();
        }

        // If A button or 1 button has gone high (different from last read) process it
        if ((buttons[RADIO_A].getKeyState() == HOLD) && (buttons[RADIO_A].getStateChanged())
            || ((buttons[LOCAL_1].getKeyState() == HOLD) && (buttons[LOCAL_1].getStateChanged())))
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

            lastTime = currentTime;
        };
        // If B button or 2 button has gone high (different from last read) process it
        if ((buttons[RADIO_B].getKeyState() == HOLD) && (buttons[RADIO_B].getStateChanged())
            || ((buttons[LOCAL_2].getKeyState() == HOLD) && (buttons[LOCAL_2].getStateChanged())))
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

            lastTime = currentTime;
        };
        // If C button or 3 button has gone high (different from last read) process it
        if ((buttons[RADIO_C].getKeyState() == HOLD) && (buttons[RADIO_C].getStateChanged())
            || ((buttons[LOCAL_3].getKeyState() == HOLD) && (buttons[LOCAL_3].getStateChanged())))
        {
            /// Reset "Clear" means set all segments to their HIDDEN state.
            Serial.println("3 or C");

            tensDigit.reset();
            unitsDigit.reset();

            tens = 0;
            units = 0;

            lastTime = currentTime;
        };
        // If D button or 4 button has gone high (different from last read) process it
        if ((buttons[RADIO_D].getKeyState() == HOLD) && (buttons[RADIO_D].getStateChanged())
            || ((buttons[LOCAL_4].getKeyState() == HOLD) && (buttons[LOCAL_4].getStateChanged())))
        {
            /// Multiply the number by ten, "Decimal".  That is the units digit value will replace the tens
            /// digit value. The tens digit value is lost. The units digit becomes 0.
            Serial.println("4 or D");

            tens = units;
            units = 0;

            tensDigit.update(tens);
            unitsDigit.update(units);

            lastTime = currentTime;
        };
    };
}