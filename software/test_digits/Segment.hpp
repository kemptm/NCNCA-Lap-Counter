///-------------------------------------------------------------------------------------------------
/// <file>
/// 	D:\Documents\KiCad\7.0\projects\NCNCA-Lap-Counter\software\LapCounter\Segment.hpp
/// </file>
///
/// <copyright file="Segment.hpp" company="TMKempEngineering.com">
/// 	Copyright (c) 2024 TMKempEngineering.com. All rights reserved.
/// </copyright>
///
/// <summary>	Declares the segment class. </summary>
///-------------------------------------------------------------------------------------------------

#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "constants.h"

///-------------------------------------------------------------------------------------------------
/// <summary>	@brief This class represents one segment of seven that makes up a digit. </summary>
///
/// <remarks>	Kemp, 2/8/2024. </remarks>
///-------------------------------------------------------------------------------------------------

class Segment
{
    /// <summary>	The segment pin. </summary>
    int segmentPin;
    /// <summary>	The set reset pin. </summary>
    int setResetPin;
    /// <summary>	The status. </summary>
    SegmentStatus status;

public:
    ///-------------------------------------------------------------------------------------------------
    /// <summary>
    /// 	@brief Initialize the segment class. This, unfortunately can't happen in a constructor
    /// 	@param segp I/O pin number of this segment enable relay
    /// 	@param srp I/O pin number of the set/reset selection relay.
    /// </summary>
    ///
    /// <remarks>	Kemp, 2/8/2024. </remarks>
    ///
    /// <param name="segp">	The segp. </param>
    /// <param name="srp"> 	The srp. </param>
    ///-------------------------------------------------------------------------------------------------

    void initSegment(int segp, int srp)
    {
        segmentPin = segp;
        setResetPin = srp;
        status = SegmentStatus::SHOWN; // to force an update
        update(SegmentStatus::HIDDEN);
    }

    ///-------------------------------------------------------------------------------------------------
    /// <summary>	@brief Reset the segment, that is hide the segment from view. </summary>
    ///
    /// <remarks>	Kemp, 2/8/2024. </remarks>
    ///-------------------------------------------------------------------------------------------------

    void reset()
    {
        int segmentVibe = 20;
        digitalWrite(segmentPin, SELECTED);
        for (int i = 0; i < 5; i++)
        {
            delay(segmentVibe);
            digitalWrite(setResetPin, HIGH);
            //PRINT_PIN(setResetPin)
            delay(segmentVibe);
            digitalWrite(setResetPin, LOW);
            //PRINT_PIN(setResetPin)
        }
        digitalWrite(setResetPin, HIGH);
        //PRINT_PIN(setResetPin)
        //PRINT_PIN(segmentPin)
        delay(solenoid_hold);
        digitalWrite(segmentPin, NOT_SELECTED);
        //PRINT_PIN(segmentPin)
        // digitalWrite(setResetPin, HIGH);PRINT_PIN(setResetPin) unnecessary

        status = SegmentStatus::HIDDEN;
    };

    ///-------------------------------------------------------------------------------------------------
    /// <summary>
    /// 	@brief Update the segment to the parameter value. If the desired status is the current
    /// 	status, no update is done.
    /// 	@param ss The desired status (SHOWN/HIDDEN) for the segment.
    /// </summary>
    ///
    /// <remarks>	Kemp, 2/8/2024. </remarks>
    ///
    /// <param name="ss">	The ss. </param>
    ///-------------------------------------------------------------------------------------------------

    void update(SegmentStatus ss)
    {
        int segmentVibe = 10;
        if (ss != status)
            digitalWrite(segmentPin, SELECTED); // PRINT_PIN(segmentPin)
        {
            for (int i = 0; i < 5; i++)
            {
                delay(segmentVibe);
                digitalWrite(setResetPin, ss == SegmentStatus::HIDDEN ? HIGH : LOW); // PRINT_PIN(setResetPin)
                delay(segmentVibe);
                digitalWrite(setResetPin, ss != SegmentStatus::HIDDEN ? HIGH : LOW); // PRINT_PIN(setResetPin)
            }
            digitalWrite(setResetPin, ss == SegmentStatus::HIDDEN ? HIGH : LOW); // PRINT_PIN(setResetPin)
            delay(solenoid_hold);
            digitalWrite(segmentPin, NOT_SELECTED); // PRINT_PIN(segmentPin)
            digitalWrite(setResetPin, HIGH);        // PRINT_PIN(setResetPin)

            status = ss;
        }
    };
};

#endif