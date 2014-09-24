#!/bin/sh

# parameters: path port file.bin

python $1/flushmagic.py /dev/$2 $3

echo tools:$1 port:$2 file:$3






