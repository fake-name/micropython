Port of MicroPython to Nuvoton NUC970 (and probably 980) MCUs
==========================================

Features:
- REPL over serial port



> Why:

128 MBytes (!) of in-package RAM!  

Also dual RMII network interfaces and a huge number of peripherals, including a LCD driver.

> are the chips widely available to the public and will they be 
> for the foreseeable future?

Digikey carries multiple versions, as does most other common suppliers 
(mouser, arrow, etc..), as well as from nuvoton directly.

> are development boards easily available?

Eval boards are a little less common. Digikey carries several NUC980 boards,
though I'm mostly interested in the 970 series. AFICT, the only difference
between the two series are a coupld peripherals (the 970 has a LCD driver, 
the 980 is a cost optimized(?) version).


> is the toolchain open source (or at least free to obtain)?

Yep, GCC

> are there plans to support multiple MCUs/SoCs?

Not at the moment, though porting within the 970 series should be very easy.

> will there be someone around for the long term to maintain this port?

At the moment, I'm not sure.

> the license (and copyright) must be appropriate.

The nuvoton headers seem to be apache 2.0 licensed.

> support for a new device must be sustainable in the long term (that's a general remark).



> a new port should ideally not touch any files in any directory except the new port directory (and any new sumbodules), so fixes/updates to the core (py/, extmod/, etc) should be in separate PR's



> the new port name should be generic enough in scope to encompass new MCUs from the same family in the future



The documentation is somewhat spotty. Generally, everything is documented, but only for either the 
970 /or/ the 980. Since the parts extremely similar, it's usually possible to generalize from 
one datasheet to the other, but it is confusing.