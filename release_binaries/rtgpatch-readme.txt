rtgpatch
--------

This is a little tool that changes 2 bytes in Libs:Picasso96/rtg.library, disabling a subroutine JSR instruction. This subroutine, whose purpose is unknown to me, normally causes pixel junk to be copied to newly opened screens (Examples: DirOpus 4, PC-Task config screen). This little patch fixes that.

Usage: Just start rtgpatch in a Shell. If it finds the correct version of rtg.library (The one supplied with Picasso96.lha from Aminet), it will patch the library. If you start it again, the patch will be reverted.

Source: https://github.com/mntmn/amiga2000-gfxcard/blob/master/drivers/rtgpatch/rtgpatch.c

Cheers
mntmn

