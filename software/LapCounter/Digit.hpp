#ifndef DIGIT_HPP
#define DIGIT_HPP

#include "constants.h"
#include "Segment.hpp"

/// @brief This class represents one digit of the display.  It manipulates its seven segments to display digits values.
class Digit {
    short digitSelect;
    Segment *segments;
    short segCount;
public:
    /// @brief Initialize the digit.  Can't use a constructor because one of the parameters is an array.
    /// @param digSel Is this the tens digit or the units digit.  This is the pin number of the digits select.
    /// @param segs An array of segment objects that this digit will be driving.  These will be used to keep the state of the segments.
    /// @param ct The size of the segs array.
    void initDigit(short digSel,Segment* segs, short ct){
        digitSelect = digSel;
        segments = segs;
        segCount = ct;
    };
    
    /// @brief Reset digit to all blanks.
    void reset() { 
        digitalWrite(digitSelect,SELECTED);
        for (int i = 0; i < segCount;i++) {
            segments[i].reset();
        }
        digitalWrite(digitSelect,NOT_SELECTED);
    };

    /// @brief Set digit segments to new Value
    /// @param newValue Integer value (0-9) to display
    void update(int newValue) {
        short val = ((newValue == 0) && (digitSelect == tensDigitPin))?10:newValue; // select blank for zero if tens digitalWrite
        digitalWrite(digitSelect,SELECTED);
        for (int i = 0;i < NUMBER_OF_SEGMENTS; i++) {
            segments[i].update(digitSegments[val][i]);
        }
        digitalWrite(digitSelect,NOT_SELECTED);
    };
};
#endif
