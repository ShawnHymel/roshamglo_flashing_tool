:start_over
MODE CON:cols=80 lines=40
COLOR F0
TITLE RoShamGlo Programming
CLS
@echo off
echo.

:auto delete folder from desktop if it exists
:@echo off
:rmdir /s /q "C:\Users\%username%\Desktop\uid"

:auto copy folder to desktop
:@echo off
:xcopy /s Firmware\Unique_Number_batch C:\Users\%username%\Desktop

:start

TITLE RoShamGlo Programming
CLS

set $step1=Program Ro-Sham-Glo
set step1=call "Firmware\Roshamglo_FW\PGM_Firmware_14107 - v20.bat"

set $step2=Program Unique Serial Number
set step2=call "Firmware\Unique_Number_batch\uid\uid - v20.bat"
Rem set step2=call "C:\Users\%username%\Desktop\uid\uid.bat"



:menu
:print out all of the steps so you can see what you'd like to select...

echo.
echo.
echo.
echo 1=%$step1%
echo 2=%$step2%
echo 3=Loop all Programming
echo.

:set the parameter "step" to a number so we can use it later to call that step...
set /p step=Type a number to select a step:

if "%step%" == "1" (CLS & (echo %step1%) & %step1% & TIMEOUT 5)
if "%step%" == "2" (CLS & (echo %step2%) & %step2% & TIMEOUT 5)
if "%step%" == "3" goto loop

CLS

goto menu

:loop
%step1%
%step2%

echo.
set /p step=Type ENTER to continue LOOP, or an "x" to exit:
if "%step%" == "x" CLS & goto menu
goto loop


