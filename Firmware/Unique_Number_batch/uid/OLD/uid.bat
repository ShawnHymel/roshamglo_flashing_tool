
@echo off
for /F "usebackq tokens=1,2 delims==" %%i in (`wmic os get LocalDateTime /VALUE 2^>NUL`) do if '.%%i.'=='.LocalDateTime.' set ldt=%%j
set ldt=%ldt:~0,4%-%ldt:~4,2%-%ldt:~6,2%_%ldt:~8,2%:%ldt:~10,2%:%ldt:~12,6%
echo Datetime: %ldt%

for /F "delims=" %%i in ('\\kentro\work\Production\QC\PRODUCTS\DEV-14107\FIRMWARE\Unique_Number_batch\uid\md5.exe -d%ldt%') do set hash=%%i
echo MD5 hash: %hash%
set uid=%hash:~-6%
set pre=0x
set bone=%uid:~0,2%
set btwo=%uid:~2,2%
set bthree=%uid:~4,2%
echo UID:      %uid%
Rem echo Byte_1:     %bone%
Rem echo Byte_2:     %btwo%
Rem echo Byte_3:     %bthree%

"C:\Program Files (x86)\Atmel\Atmel Studio 6.2\atbackend\atprogram.exe" -t atmelice -i isp -cl 125kHz -d ATtiny84a  write -ee -o -0x00 --values %pre%%UID%

TIMEOUT 5


