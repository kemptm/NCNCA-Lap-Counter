///-------------------------------------------------------------------------------------------------
/// <file>
/// 	D:\Documents\KiCad\7.0\projects\NCNCA-Lap-Counter\software\LapCounter\constants.h
/// </file>
///
/// <copyright file="constants.h" company="TMKempEngineering.com">
/// 	Copyright (c) 2024 TMKempEngineering.com. All rights reserved.
/// </copyright>
///
/// <summary>	Declares the constants class. </summary>
///-------------------------------------------------------------------------------------------------

#ifndef CONSTANTS_H
/// <summary>	Do not allow inclusion twice. </summary>
#define CONSTANTS_H

///-------------------------------------------------------------------------------------------------
/// <summary>	A macro that defines number of segments. </summary>
///
/// <remarks>	Kemp, 2/8/2024. </remarks>
///-------------------------------------------------------------------------------------------------

#define NUMBER_OF_SEGMENTS 7

///-------------------------------------------------------------------------------------------------
/// <summary>	A macro that defines number of digits. </summary>
///
/// <remarks>	Kemp, 2/8/2024. </remarks>
///-------------------------------------------------------------------------------------------------

#define NUMBER_OF_DIGITS 2

///-------------------------------------------------------------------------------------------------
/// <summary>	A macro that defines number of radio pins. </summary>
///
/// <remarks>	Kemp, 2/8/2024. </remarks>
///-------------------------------------------------------------------------------------------------

#define NUMBER_OF_RADIO_PINS 5

///-------------------------------------------------------------------------------------------------
/// <summary>	A macro that defines number of buttons. </summary>
///
/// <remarks>	Kemp, 4/7/2024. </remarks>
///-------------------------------------------------------------------------------------------------

#define NUMBER_OF_BUTTONS 9
  const byte numberButtons = 9;
  const short buttonPins[numberButtons] = { 49,  47,  53,  51,  52,  50,  48,  46,  42};
  const char buttonNames[numberButtons] = {'1', '2', '3', '4', 'A', 'B', 'C', 'D', 'V'};

/// <summary>	The segment enable pins[ number of segments]. </summary>
const short segEnablePins[NUMBER_OF_SEGMENTS] = {23, 25, 27, 29, 31, 33, 35};

/// <summary>	The segment set reset pins[ number of segments]. </summary>
const short segSetResetPins[NUMBER_OF_SEGMENTS] = {22, 24, 26, 28, 30, 32, 34};

/// <summary>	The tens digit pin. </summary>
const short tensDigitPin = 36;

/// <summary>	The units digit pin. </summary>
const short unitsDigitPin = 37;

/// <summary>	The power disable pin. </summary>
const short powerDisablePin = 44;

/// <summary>	The solenoid delay. </summary>
const int SOLENOID_DELAY = 175;
const unsigned short TENS_HOLDS[NUMBER_OF_SEGMENTS] = {100,100,100,100,100,200,100};
const unsigned short UNITS_HOLDS[NUMBER_OF_SEGMENTS] = {100,100,100,100,100,200,100};

/// <summary>	The selected. </summary>
const int SELECTED = LOW;

/// <summary>	The not selected. </summary>
const int NOT_SELECTED = HIGH;

/// <summary>	two hours. </summary>
const unsigned long TIMEOUT_MILLISECONDS = 60000 * 60 * 2;

///-------------------------------------------------------------------------------------------------
/// <summary>	Values that represent segment status. </summary>
///
/// <remarks>	Kemp, 2/8/2024. </remarks>
///-------------------------------------------------------------------------------------------------

enum class SegmentStatus
{
    HIDDEN,
    SHOWN,
};

/// <summary>	The radio button a. </summary>
#define LOCAL_1 0
/// <summary>	The radio button a. </summary>
#define LOCAL_2 1
/// <summary>	The radio button a. </summary>
#define LOCAL_3 2
/// <summary>	The radio button a. </summary>
#define LOCAL_4 3
/// <summary>	The radio button a. </summary>
#define RADIO_A 4
/// <summary>	The radio button b. </summary>
#define RADIO_B 5
/// <summary>	The radio button c. </summary>
#define RADIO_C 6
/// <summary>	The radio button d. </summary>
#define RADIO_D 7
/// <summary>	The radio button vt. </summary>
#define RADIO_VT 8
/// <summary>   The button 1 (A)

/// <summary>	The digit segments[ 11][ number of segments]. </summary>
const SegmentStatus digitSegments[11][NUMBER_OF_SEGMENTS] =
    {
        {
            SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN // 0
        },
        {
            SegmentStatus::HIDDEN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN // 1
        },
        {
            SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN, SegmentStatus::SHOWN // 2
        },
        {
            SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::SHOWN // 3
        },
        {
            SegmentStatus::HIDDEN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::SHOWN, SegmentStatus::SHOWN // 4
        },
        {
            SegmentStatus::SHOWN, SegmentStatus::HIDDEN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN, SegmentStatus::SHOWN, SegmentStatus::SHOWN // 5
        },
        {
            SegmentStatus::SHOWN, SegmentStatus::HIDDEN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN // 6
        },
        {
            SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN // 7
        },
        {
            SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN // 8
        },
        {
            SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN, SegmentStatus::SHOWN, SegmentStatus::SHOWN // 9
        },
        {
            SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN, SegmentStatus::HIDDEN // ()
        },

};

/// define a macro for logging digital pin state
#define PRINT_PIN(pin) \
Serial.print(pin); \
Serial.println(digitalRead(pin)==HIGH?" HIGH":" LOW"); \

#endif