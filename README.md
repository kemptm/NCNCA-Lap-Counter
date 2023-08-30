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
\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
To Mike  8/22/2023:

Hi Mike,

I've taken a first look at it.  It doesn't look too complicated.  The Arduino drives the relays, which power the segment set and reset solenoids. I need to look inside the Arduino to see if I can get it to barf out the code. The solar panel is controlled by a controller that can charge the batteries.  The box can also take power through another interface.  I haven't figured out the remote control or what the USB input is for. There are a few broken wires that I don't have any ideas about, yet. I'll have to find power supplies, but I probably have something that will work.

I will create a schematic of the thing as I figure it out.  

Before I try to apply any power, I'd like to figure out its current state. Can you remember in what way it is broken? Won't listen to commands? Segment failures on the numbers? Power supply failure? Short? Dead computer?  

Thanks,  
Tim.
\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
From Mike   8/22/2023:

Hi Tim,

If I remember right, it was accepting a number, then would click down once and freeze. 

I think the remote control was for increment, decrement, double zero, and blank. 

Mike
\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
To Mike  8/23/2023:

Did it ever work completely?

Tim.
\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
From Mike  8/23/2023:

I’m not exactly sure.  My son called me happily saying it was finished, then a while later called me again saying it had a problem. He flailed at it for a week or so then gave up.
