#!/usr/bin/python

# from
# http://midibel.com/flushmagic.py
#
#
# linux comand line usage example:
#
# ./flushmagic.py /dev/ttyUSB0 blinky.bin
#
#
#
# 2013-Jul-25 Lars Ole Belhage, belhage@midibel.com
# A simple script to program a LPC810 via ISP serial interface
# It also calculates the signature and that checks code-read-protection is off

import sys
import serial

tty = sys.argv[1] if len(sys.argv) > 1 else "/dev/ttyUSB0"
flsh = sys.argv[2] if len(sys.argv) > 2 else ""

ser = serial.Serial(tty, baudrate=115200, bytesize=8, parity='N', stopbits=1, timeout=10, xonxoff=0, rtscts=0)

def sendCmd(cmd):
	ser.write(cmd)
	ser.flush()
	ok = ser.readline().rstrip()
	if ok != "0":
		print "Error returned from cmd: " + cmd + " code=" + ok
		quit()

ser.write("?")
ser.flush()
ser.timeout = 1
j = ser.readline().rstrip()
ser.timeout = 3
if j == "Synchronized":
	ser.write("Synchronized\r\n")
	ser.flush()
	ser.readline().rstrip()
	ser.readline().rstrip()
	ser.write("12\r\n")
	ser.flush()
	ser.readline().rstrip()
	ser.readline().rstrip()
	ser.write("A 0\r\n")
	ser.flush()
	ser.readline().rstrip()
	ser.readline().rstrip()
else:
	ser.write("\r\n")
	ser.flush()
	ok = ser.readline().rstrip()
	if ok != "0" and ok != "1":
		print "LPC8xx not in initial ISP-mode..."
		quit()

sendCmd("J\r\n")
print "PartID: " + ser.readline().rstrip()

sendCmd("K\r\n")
print "BootPromVersion: " + ser.readline().rstrip() + "." + ser.readline().rstrip()

sendCmd("N\r\n")
print "UID: " + ser.readline().rstrip() + "-" + ser.readline().rstrip() + "-" + ser.readline().rstrip() + "-" + ser.readline().rstrip()

if flsh == "":
	quit()

f = open(flsh, "rb")
data = bytearray(f.read())
f.close()

dlen = len(data)
rlen = ((dlen + 63) / 64) * 64
data += bytearray(rlen - dlen)

sig = 0
for v in range(0, 7):
	sig += (data[4*v+3] << 24) | (data[4*v+2] << 16) | (data[4*v+1] << 8) | (data[4*v+0])
sig ^= 0xffffffff
sig += 1
data[4*7+0] = (sig >> 0) & 0xff
data[4*7+1] = (sig >> 8) & 0xff
data[4*7+2] = (sig >> 16) & 0xff
data[4*7+3] = (sig >> 24) & 0xff

if rlen >= 0x2ff:
	magic = (data[0x2fc+3] << 24) | (data[0x2fc+2] << 16) | (data[0x2fc+1] << 8) | (data[0x2fc+0])
	if (magic == 0x12345678 or
	    magic == 0x87654321 or
	    magic == 0x43218765 or
	    magic == 0x4E697370):
		print "Error: CRAP-Magic word hit: " + str(magic)
		quit()

sect = str(dlen / 1024)
sendCmd("U 23130\r\n")
sendCmd("P 0 " + sect + "\r\n")
sendCmd("E 0 " + sect + "\r\n")
b = 0
while b < dlen:
	# print "Write block: " + str(b) + "/" + str(dlen)
	sendCmd("P 0 " + sect + "\r\n")
	sendCmd("W " + str(0x10000000) + " 64\r\n")
	ser.write(data[b : b+64])
	sendCmd("C " + str(b) + " " + str(0x10000000) + " 64\r\n")
	b += 64
print str(dlen) + " bytes was written"
