:start_over
MODE CON:cols=80 lines=40
COLOR F0
TITLE RoShamGlo Programming
CLS
@echo off
echo.


:start


"C:\Program Files (x86)\Atmel\Atmel Studio 6.2\atbackend\atprogram.exe" -t atmelice -i isp -cl 125kHz -d ATtiny84a  write -fs --values E2DDFE

"C:\Program Files (x86)\Atmel\Atmel Studio 6.2\atbackend\atprogram.exe" -t atmelice -i isp -cl 125kHz -d ATtiny84a chiperase program -fl -f \\kentro\work\Production\QC\PRODUCTS\DEV-14107\FIRMWARE\Bootloader\t84_roshamglo.hex

"C:\Program Files (x86)\Atmel\Atmel Studio 6.2\atbackend\atprogram.exe" -t atmelice -i isp -d ATtiny84a verify -fl -f \\kentro\work\Production\QC\PRODUCTS\DEV-14107\FIRMWARE\Bootloader\t84_roshamglo.hex

"C:\Program Files (x86)\Atmel\Atmel Studio 6.2\atbackend\atprogram.exe" -t atmelice -i isp -cl 125kHz -d ATtiny84a program -fl -f \\kentro\work\Production\QC\PRODUCTS\DEV-14107\FIRMWARE\Roshamglo_FW\Roshamglo_with_self_test_2-16-17.hex

"C:\Program Files (x86)\Atmel\Atmel Studio 6.2\atbackend\atprogram.exe" -t atmelice -i isp -d ATtiny84a verify -fl -f \\kentro\work\Production\QC\PRODUCTS\DEV-14107\FIRMWARE\Roshamglo_FW\Roshamglo_with_self_test_2-16-17.hex

echo.
TIMEOUT 5
CLS
echo.


