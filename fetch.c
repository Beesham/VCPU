/*
* @Author Beesham Sarendranauth
* @Date: 2015/04/27
*/

#include "MyLib.h"

/*
	fetch()
	Description: moves the contents of the normal operation registers into the MEMORY ADDRESS REGISTER (maR).
				 moves the contents of maR into MEMORY BUFFER REGISTER (mbR)
				 moves contents of mbR into INSTRUCTION REGISTER (irR)
				 increments the program counter (PC)
*/


void fetch(void *memptr){
	int i;
	maR = PC;
	for(i=0;i<sizeofins;i++){
		mbR = (mbR << 8);
		mbR += ((unsigned char*)memptr)[maR++];
	}
	irR = mbR;
	PC = PC+sizeofins;
}//end of fetch class
