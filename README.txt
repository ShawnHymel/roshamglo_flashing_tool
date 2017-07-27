Step 1
------
Make flashing rig.

Arduino	Roshamglo
3.3V	3.3V
GND	GND
10	RST
11	6
12	5
13	4

Step 2
------
Flash ArduinoISP firmware to Arduino. Add 10uF capacitor between RST and GND on Arduino.

Step 3
------
Make a copy of a known good Roshamglo badge with:

> avrdude -C avrdude.conf -c arduino -p t84 -P <SERIAL PORT> -b 19200 -U flash:r:roshamglo.hex:r

Copy roshamglo.hex to Firmware/Roshamglo_FW

Step 4
------
Change COM number (comnum) in roshamglo_flash.bat
Change hexfile to filename from step 3 (e.g. roshamglo.hex)

Step 5
------
Run script

> roshamglo_flash.bat