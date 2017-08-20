#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <windows.h>
#include "ftd2xx.h"


int main ( int argc, char *argv[] ) {
	FT_HANDLE ftHandle; 
	FT_STATUS ftStatus;
	int i;
	WORD buff[128];
	FILE *filePtr;
	int col = 0;
	DWORD devIndex = 0;
	char Buffer[64]; 
	WORD checksum = 0xaaaa;

	// open the EEPROM file
	filePtr = fopen("usb_jtag.bin", "rb");
	
	ftStatus = FT_ListDevices((PVOID)devIndex, Buffer, FT_LIST_BY_INDEX | FT_OPEN_BY_DESCRIPTION);
	if (ftStatus == FT_OK) printf("Found %s\n", Buffer);
	
	ftStatus = FT_OpenEx("Dual RS232-HS B", FT_OPEN_BY_DESCRIPTION, &ftHandle);
	
	if (ftStatus == FT_OK) {
		
		fread(buff, 2, 127, filePtr);
		
		for (i=0; i < 127; i++) {
			
			ftStatus = FT_WriteEE(ftHandle, i, buff[i]);
			
			if (ftStatus == FT_OK) {
				printf("%04X ", buff[i]);
			} else {
				printf("Word %d failed to write\n", i);
			}
			
			col++;
			
			if (col == 8) {
				col = 0;
				printf("\n");
			}
			
			checksum = buff[i]^checksum;
			checksum = (checksum << 1) | (checksum >> 15);
		}
		ftStatus = FT_WriteEE(ftHandle, 127, checksum);
		printf("%04X ", checksum);
		
		FT_Close(ftHandle);
		fclose(filePtr);
	
	if (ftStatus == FT_OK) { 
		printf("EEPROM written.\nYou need to power-cycle the board for the change to take effect\n");
	} else {
		printf("EEPROM write failed.\n");
	}
	
	} else {
		printf("Error! Can't find FTDI chip\n");
	}
}
