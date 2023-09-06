# NCNCA-Lap-Counter
This is an electronic lap counter for use at the finish line of bike (or other) races.  It has two 9" solenoid activated 7-segment digits. It is run by an Arduino controlled by a little remote control with buttons "A," "B," "C," and "D."   It has a solar panel to charge the batteries, but apparently can be powered by an external power supply. 

![PXL_20230823_163003984](doc/images/PXL_20230823_163003984.jpg)

![PXL_20230822_223443245](doc/images/PXL_20230822_223443245.jpg)

![PXL_20230825_211738056.MP](doc/images/PXL_20230825_211738056.MP.jpg)

Mike's son built it as a college project.  There is no documentation.  It's not new, so some of the parts are obsolete.  If I can get it operational, Mike intends to donate it to the NCNCA. 

Some emails:

From Mike  8/22/2023:

Hi Tim,

I don’t know if I told you, but it’s my intention, if the lap counter can be made to work, to donate it to NCNCA’s equipment stash, after I build a protective transport case for it.  Between Robert’s crew and some technophobic officials, it will get some rough handling at and between races.  It’s pretty important that it gets protection before being released to general use.

Good luck with the puzzle.

Mike

----------------------------------------

To Mike  8/22/2023:

Hi Mike,

I've taken a first look at it. It doesn't look too complicated. The Arduino drives the relays, which power the segment set and reset solenoids. I need to look inside the Arduino to see if I can get it to barf out the code. The solar panel is controlled by a controller that can charge the batteries. The box can also take power through another interface. I haven't figured out the remote control or what the USB input is for. There are a few broken wires that I don't have any ideas about, yet. I'll have to find power supplies, but I probably have something that will work.
I will create a schematic of the thing as I figure it out.  
Before I try to apply any power, I'd like to figure out its current state. Can you remember in what way it is broken? Won't listen to commands? Segment failures on the numbers? Power supply failure? Short? Dead computer?  

Thanks,  
Tim.

----------------------------------------

From Mike   8/22/2023:

Hi Tim,

If I remember right, it was accepting a number, then would click down once and freeze.

I think the remote control was for increment, decrement, double zero, and blank.

Mike

----------------------------------------

To Mike  8/23/2023:

Did it ever work completely?

Tim.

----------------------------------------

From Mike  8/23/2023:

I’m not exactly sure. My son called me happily saying it was finished, then a while later called me again saying it had a problem. He flailed at it for a week or so then gave up.

----------------------------------------
To Mike  9/4/2023:

Hi Mike,

I haven't been idle on the lap counter.  I've been researching the components to be sure that I could replace one if it seems bad.  The Arduino seems to be a model that was discontinued some time before 2016 (How old is this thing??).  The good news is that the current model is pretty much a one-for-one replacement.  The solar controller, buck converter, relay boards and radio all seem to have equivalent models available today.  The stand out are the numbers themselves.  That technology is so obsolete that I can't even find any references to equipment that works that way. I'll have to measure .

I have been looking at the power supply.  As I have been documenting the circuit in a schematic I think that I can see a very good candidate for why the thing froze after a couple of operations.  The way the numbers are wired is that relays are picked for each segment of each digit set or reset.  Then all of the circuits are energized firing 7 solenoids at once.  This whole thing is driven from the 5 volt supply that serves the Arduino.  The 12V-5V converter can source only 3 amps.  Given the current draw of some or all of the relays and a solenoid for each segment of a digit at the same time, that thing has to be stressed, not to mention being subjected to the fly-back current from the coils. I'm not surprised that the Arduino lost its mind.  I think that I am going to separate the power supplies of the relays and solenoids from the electronics.  I'll probably have to beef up the converter as well.

The investigation goes on.

Tim.

----------------------------------------
From MIke 9/4/2023:

Hi Tim,

Somehow, I knew you'd be the guy!

My son is an enthusiastic tinkerer but isn't formally educated in electronics.  He was starting to think about current draw when he got diverted to another project and forgot all about this one.
The arduino came out of his scrap drawer so it may still have some dinosaur blood on it. I bought the numbers in 1991 when there was a really good mail-order (remember that?) deal on them.  They gathered dust for more than 20 years.

It is encouraging to hear progress being made.

Mike
