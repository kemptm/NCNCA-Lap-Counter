#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "constants.h"

/// @brief This class represents one segment of seven that makes up a digit.
class Segment {
    int segmentPin;
    int setResetPin;
    SegmentStatus status;

    public:
    /// @brief Initialize the segment class. This, unfortunately can't happen in a constructor
    /// @param segp I/O pin number of this segment enable relay
    /// @param srp I/O pin number of the set/reset selection relay
    void initSegment(int segp, int srp) {
        segmentPin = segp;
        setResetPin = srp;
        status = SegmentStatus::SHOWN; // to force an update
        update(SegmentStatus::HIDDEN);
    }
    
    /// @brief Reset the segment, that is hide the segment from view.
    void reset(){
        digitalWrite(setResetPin, HIGH);
        digitalWrite(segmentPin, SELECTED);
        delay(SOLENOID_DELAY);
        digitalWrite(segmentPin, NOT_SELECTED);
        digitalWrite(setResetPin, HIGH);
        
        status = SegmentStatus::HIDDEN;
    };

    /// @brief Update the segment to the parameter value. If the desired status is the current status, no update is done.
    /// @param ss The desired status (SHOWN/HIDDEN) for the segment.
    void update(SegmentStatus ss) {
        if (ss != status) {
            digitalWrite(setResetPin,ss==SegmentStatus::HIDDEN?HIGH:LOW);
            digitalWrite(segmentPin,SELECTED);
            delay(SOLENOID_DELAY);
            digitalWrite(segmentPin,NOT_SELECTED);
            digitalWrite(setResetPin,HIGH);

            status = ss;
        }
    };
};
#endif