@ECHO OFF

REM Parameters
SET comnum=5
SET hexfile=Firmware\Roshamglo_FW\roshamglo_7-25-17.hex

REM Set fuses
avrdude -C avrdude.conf -c arduino -p t84 -P COM%comnum% -b 19200 -U lfuse:w:0xe2:m -U hfuse:w:0xdd:m -U efuse:w:0xfe:m

REM Read fuses to verify
::avrdude -C avrdude.conf -c arduino -p t84 -P COM%comnum% -b 19200 -U lfise:r:-:i -v

REM Flash .hex file
avrdude -C avrdude.conf -c arduino -p t84 -P COM%comnum% -b 19200 -U flash:w:%hexfile%

REM Calculate UID
for /F "usebackq tokens=1,2 delims==" %%i in (`wmic os get LocalDateTime /VALUE 2^>NUL`) do if '.%%i.'=='.LocalDateTime.' set ldt=%%j
set ldt=%ldt:~0,4%-%ldt:~4,2%-%ldt:~6,2%_%ldt:~8,2%:%ldt:~10,2%:%ldt:~12,6%
echo Datetime: %ldt%
for /F "delims=" %%i in ('Firmware\Unique_Number_batch\uid\md5.exe -d%ldt%') do set hash=%%i
echo MD5 hash: %hash%
set uid=%hash:~-6%
set pre=0x
set bone=%uid:~0,2%
set btwo=%uid:~2,2%
set bthree=%uid:~4,2%
echo UID:      %uid%
echo Byte_1:     %bone%
echo Byte_2:     %btwo%
echo Byte_3:     %bthree%

REM Flash EEPROM

REM EEPROM Addresses
REM 0x00 ID High
REM 0x01 ID Mid
REM 0x02 ID Low
REM 0x03 Last played ID high
REM 0x04 Last played ID mid
REM 0x05 Last played ID low
REM 0x06 Num times played last
REM 0x07 Score

avrdude -C avrdude.conf -c arduino -p t84 -P COM%comnum% -b 19200 -U eeprom:w:0x%bone%,0x%btwo%,0x%bthree%,0xFF,0xFF,0xFF,0x00,0x00:m

REM Read EEPROM to verify
::avrdude -C avrdude.conf -c arduino -p t84 -P COM%comnum% -b 19200 -U eeprom:r:-:i
