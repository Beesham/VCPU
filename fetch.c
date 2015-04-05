#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "registersVar.h"

#include "myDefines.h"

/*
	fetch class
	Description: moves the contents of the normal operation registers into the MEMORY ADDRESS REGISTER (maR).
				 moves the contents of maR into MEMORY BUFFER REGISTER (mbR)
				 moves contents of mbR into INSTRUCTION REGISTER (irR)
				 increments the program counter (PC)

*/


void fetch(void *memptr){
	int i;
	
	maR = pc;//PC;
	for(i=0;i<sizeofins;i++){
		mbR = (mbR << 8);
		mbR += ((unsigned char*)memptr)[maR++];
	}
	irR = mbR;
	//maR = PC;
	pc = pc+sizeofins;
	
}//end of fetch class
