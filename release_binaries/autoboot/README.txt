How to use the experimental SD Card Auto Boot feature of VA2000
---------------------------------------------------------------

The script install.sh runs "dd" twice to copy a boot block and mntsd.device to blocks 0 and 2+ of the SD card.

Currently, the script is available only for Linux (and possibly BSD, macOS).

Before running, edit the script and fill in the correct device name for your SD card. Make sure you get this right.

Source code for the boot block is here: https://github.com/mntmn/amiga2000-gfxcard/blob/master/drivers/bootrom/boot3.s

Known Bugs:
- Requires 4GB+ SDHC card (SanDisk recommended), but mounts only one 4GB FFS partition.
- Works on 68030 and 68040, but crashes on 68060 and 68000. Reasons yet unknown.

