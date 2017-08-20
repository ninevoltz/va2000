#!/bin/sh

# Replace sdx with the correct device name of your SD Card. (You can use lsblk, for example.)
# Double check if you have the correct device name or risk destroying data on the wrong drive.
target=/dev/sdx

# Write boot block to block 0
dd if=./boot of=$target bs=512
# Write mntsd.device to blocks 2+
dd if=../mntsd.device of=$target bs=512 seek=2
sync

