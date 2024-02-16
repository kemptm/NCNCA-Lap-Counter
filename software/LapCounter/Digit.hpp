///-------------------------------------------------------------------------------------------------
/// <file>	D:\Documents\KiCad\7.0\projects\NCNCA-Lap-Counter\software\LapCounter\Digit.hpp </file>
///
/// <copyright file="Digit.hpp" company="TMKempEngineering.com">
/// 	Copyright (c) 2024 TMKempEngineering.com. All rights reserved.
/// </copyright>
///
/// <summary>	Declares the digit class. </summary>
///-------------------------------------------------------------------------------------------------

#ifndef DIGIT_HPP
#define DIGIT_HPP

#include "constants.h"
#include "Segment.hpp"

///-------------------------------------------------------------------------------------------------
/// <summary>
/// 	@brief This class represents one digit of the display.  It manipulates its seven segments
/// 	to display digits values.
/// </summary>
///
/// <remarks>	Kemp, 2/8/2024. </remarks>
///-------------------------------------------------------------------------------------------------

class Digit
{
    /// <summary>	The digit select. </summary>
    short digitSelect;
    /// <summary>	The segments. </summary>
    Segment *segments;
    /// <summary>	Number of segments. </summary>
    short segCount;

public:
    ///-------------------------------------------------------------------------------------------------
    /// <summary>
    /// 	@brief Initialize the digit.  Can't use a constructor because one of the parameters is an
    /// 	array.
    /// 	@param digSel Is this the tens digit or the units digit.  This is the pin number of the
    /// 	digits select.
    /// 	@param segs An array of segment objects that this digit will be driving.  These will be
    /// 	used to keep the state of the segments.
    /// 	@param ct The size of the segs array.
    /// </summary>
    ///
    /// <remarks>	Kemp, 2/8/2024. </remarks>
    ///
    /// <param name="digSel">	The dig selected. </param>
    /// <param name="segs">  	[in,out] If non-null, the segments. </param>
    /// <param name="ct">	 	The ct. </param>
    ///-------------------------------------------------------------------------------------------------

    void initDigit(short digSel, Segment *segs, short ct)
    {
        digitSelect = digSel;
        segments = segs;
        segCount = ct;
    };

    ///-------------------------------------------------------------------------------------------------
    /// <summary>	@brief Reset digit to all blanks. </summary>
    ///
    /// <remarks>	Kemp, 2/8/2024. </remarks>
    ///-------------------------------------------------------------------------------------------------

    void reset()
    {
        digitalWrite(digitSelect, SELECTED);
        for (int i = 0; i < segCount; i++)
        {
            segments[i].reset();
        }
        digitalWrite(digitSelect, NOT_SELECTED);
    };

    ///-------------------------------------------------------------------------------------------------
    /// <summary>
    /// 	@brief Set digit segments to new Value
    /// 	@param newValue Integer value (0-9) to display.
    /// </summary>
    ///
    /// <remarks>	Kemp, 2/8/2024. </remarks>
    ///
    /// <param name="newValue">	The new value. </param>
    ///-------------------------------------------------------------------------------------------------

    void update(int newValue)
    {
        short val = ((newValue == 0) && (digitSelect == tensDigitPin)) ? 10 : newValue; // select blank for zero if tens digitalWrite
        digitalWrite(digitSelect, SELECTED);
        for (int i = 0; i < NUMBER_OF_SEGMENTS; i++)
        {
            segments[i].update(digitSegments[val][i]);
        }
        digitalWrite(digitSelect, NOT_SELECTED);
    };
};

#endif
