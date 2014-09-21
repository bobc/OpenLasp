@echo off
rem
rem Call python program to download bin file to LPC810
rem

set zzzpath=%1
rem port file.bin
python %zzzpath%\flushmagic.py %2 %3

set zzzpath=




