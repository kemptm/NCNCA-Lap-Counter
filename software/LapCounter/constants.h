#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NUMBER_OF_SEGMENTS 7
#define NUMBER_OF_DIGITS 2
#define NUMBER_OF_RADIO_PINS 5

const short segEnablePins[NUMBER_OF_SEGMENTS] = {22, 24, 26, 28, 30, 32, 34 };
const short segSetResetPins[NUMBER_OF_SEGMENTS] = {23, 25, 27, 29, 31, 33, 35};
const short radioPins[NUMBER_OF_RADIO_PINS] = {54, 52, 50, 48,46};
//const short digitSelectPins[NUMBER_OF_DIGITS] = {36, 37};
const short tensDigitPin = 36;
const short unitsDigitPin = 37;
const short powerDisablePin = 55;
const int SOLENOID_DELAY = 100;
const int SELECTED = LOW;
const int NOT_SELECTED = HIGH;
const unsigned long TIMEOUT_MILLISECONDS = 7200000; // two hours

 enum class SegmentStatus{
    HIDDEN,
    SHOWN,
 };

 
   const short BUTTON_A = 0;
   const short BUTTON_B = 1;
   const short BUTTON_C = 2;
   const short BUTTON_D = 3;
   const short BUTTON_VT = 4;

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