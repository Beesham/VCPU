
#include "MyLib.h"

/*
	fetch class
	Description: moves the contents of the normal operation registers into the MEMORY ADDRESS REGISTER (maR).
				 moves the contents of maR into MEMORY BUFFER REGISTER (mbR)
				 moves contents of mbR into INSTRUCTION REGISTER (irR)
				 increments the program counter (PC)

*/


void fetch(void *memptr){
	int i;
	
	printf("**Before fetch code**\nPC: %X maR: %X\n",PC,maR);
	maR = PC;
	for(i=0;i<sizeofins;i++){
		mbR = (mbR << 8);
		mbR += ((unsigned char*)memptr)[maR++];
	}
	irR = mbR;
	PC = PC+sizeofins;
	printf("**After fetch code**\nPC: %X maR: %X\n",PC,maR);
	printf(" PC fetch: %08X ",PC);
}//end of fetch class
