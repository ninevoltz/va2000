Use this utility to program the FTDI FT2232HL USB JTAG interface to work with Xilinx ISE by masquerading as a Digilent USB JTAG cable.
This requires replacing the EEPROM at location U1 with a 93C56 device. See the photo in this directory for the location.
(The VA2000 Rev. 1.0 comes with a 93C46, which is too small to hold all of the necessary data.)
A replacement EEPROM can be ordered from www.digikey.com for about $0.28. The part number is 93C56BT-I/OT, manufactured by Microchip Technology. It is in an SOT23-6 package.