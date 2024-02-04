#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "constants.h"

class Segment {
    int segmentPin;
    int setResetPin;
    SegmentStatus status;

    public:
    void initSegment(int segp, int srp) {
        segmentPin = segp;
        setResetPin = srp;
        status = SegmentStatus::SHOWN; // to force an update
        update(SegmentStatus::HIDDEN);
    }
    
    void reset(){
        digitalWrite(setResetPin, HIGH);
        digitalWrite(segmentPin, SELECTED);
        delay(SOLENOID_DELAY);
        digitalWrite(segmentPin, NOT_SELECTED);
        digitalWrite(setResetPin, HIGH);
    };

    void update(SegmentStatus ss) {
        if (ss != status) {
            digitalWrite(setResetPin,ss==SegmentStatus::HIDDEN?HIGH:LOW);
            digitalWrite(segmentPin,SELECTED);
            delay(SOLENOID_DELAY);
            digitalWrite(segmentPin,NOT_SELECTED);
            digitalWrite(setResetPin,HIGH);
        }
    };
};
#endif