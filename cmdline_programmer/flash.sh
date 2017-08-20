#!/bin/sh
export LD_PRELOAD=/usr/lib64/libftdi1.so
sudo ./xc3sprog -v -v -c ftdi spiflasherLX25.bit
sudo ./xc3sprog -v -v -c ftdi -I ../HDL/work/z2.bit
sudo ./xc3sprog -v -v -c ftdi ../HDL/work/z2.bit

