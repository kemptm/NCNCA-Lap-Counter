#ifndef DIGIT_HPP
#define DIGIT_HPP

#include "constants.h"
#include "Segment.hpp"

class Digit {
    short digitSelect;
    Segment *segments;
    short segCount;
public:
    void initDigit(short digSel,Segment* segs, short ct){
        digitSelect = digSel;
        segments = segs;
        segCount = ct;
    };

    void reset() { 
        digitalWrite(digitSelect,SELECTED);
        for (int i = 0; i < segCount;i++) {
            segments[i].reset();
        }
        digitalWrite(digitSelect,NOT_SELECTED);
    };

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
