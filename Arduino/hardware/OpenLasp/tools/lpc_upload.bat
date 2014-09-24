@echo off
rem
rem Call lpc21isp program to download bin file to LPC810
rem
rem parameters are: path port file.bin

rem Note: %~dp0 get path of this batch file, so path parameter is no longer required

%~dp0lpc21isp.exe -bin "%3" %2 115200 12000





