///-------------------------------------------------------------------------------------------------
/// <file>
/// 	D:\Documents\KiCad\7.0\projects\NCNCA-Lap-Counter\software\LapCounter\constants.h
/// </file>
///
/// <copyright file="constants.h" company="MyCompany.com">
/// 	Copyright (c) 2024 MyCompany.com. All rights reserved.
/// </copyright>
///
/// <summary>	Declares the constants class. </summary>
///-------------------------------------------------------------------------------------------------

#ifndef CONSTANTS_H
/// <summary>	. </summary>
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

/// <summary>	The segment enable pins[ number of segments]. </summary>
const short segEnablePins[NUMBER_OF_SEGMENTS] = {22, 24, 26, 28, 30, 32, 34 };
/// <summary>	The segment set reset pins[ number of segments]. </summary>
const short segSetResetPins[NUMBER_OF_SEGMENTS] = {23, 25, 27, 29, 31, 33, 35};
/// <summary>	The radio pins[ number of radio pins]. </summary>
const short radioPins[NUMBER_OF_RADIO_PINS] = {54, 52, 50, 48,46};
//const short digitSelectPins[NUMBER_OF_DIGITS] = {36, 37};
/// <summary>	The tens digit pin. </summary>
const short tensDigitPin = 36;
/// <summary>	The units digit pin. </summary>
const short unitsDigitPin = 37;
/// <summary>	The power disable pin. </summary>
const short powerDisablePin = 55;
/// <summary>	The solenoid delay. </summary>
const int SOLENOID_DELAY = 100;
/// <summary>	The selected. </summary>
const int SELECTED = LOW;
/// <summary>	The not selected. </summary>
const int NOT_SELECTED = HIGH;
/// <summary>	two hours. </summary>
const unsigned long TIMEOUT_MILLISECONDS = 7200000;

 ///-------------------------------------------------------------------------------------------------
 /// <summary>	Values that represent segment status. </summary>
 ///
 /// <remarks>	Kemp, 2/8/2024. </remarks>
 ///-------------------------------------------------------------------------------------------------

 enum class SegmentStatus{
    HIDDEN,
    SHOWN,
 };

 
   /// <summary>	The button a. </summary>
   const short BUTTON_A = 0;
   /// <summary>	The button b. </summary>
   const short BUTTON_B = 1;
   /// <summary>	The button c. </summary>
   const short BUTTON_C = 2;
   /// <summary>	The button d. </summary>
   const short BUTTON_D = 3;
   /// <summary>	The button vt. </summary>
   const short BUTTON_VT = 4;

 /// <summary>	The digit segments[ 11][ number of segments]. </summary>
 const SegmentStatus digitSegments[11][NUMBER_OF_SEGMENTS] = 
 {
   {
      SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN // 0
   },
   {
      SegmentStatus::HIDDEN,SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::HIDDEN // 1
   },
   {
      SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN,SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN,SegmentStatus::SHOWN  // 2
   },
   {
      SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::SHOWN  // 3
   },
   {
      SegmentStatus::HIDDEN,SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::SHOWN, SegmentStatus::SHOWN  // 4
   },
   {
      SegmentStatus::SHOWN, SegmentStatus::HIDDEN,SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN,SegmentStatus::SHOWN, SegmentStatus::SHOWN  // 5
   },
   {
      SegmentStatus::SHOWN, SegmentStatus::HIDDEN,SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN  // 6
   },
   {
      SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::HIDDEN // 7
   },
   {
      SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN  // 8
   },
   {
      SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::SHOWN, SegmentStatus::HIDDEN,SegmentStatus::SHOWN, SegmentStatus::SHOWN  // 9
   },
   {
      SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::HIDDEN,SegmentStatus::HIDDEN // ()
   },

 };

#endif