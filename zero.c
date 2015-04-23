
#include "MyLib.h"

/*
	zero()
	Description: resets all registers to default value of 0
*/
void zero(){
	int i;

	for(i=0;i<NUM_OF_REGS;i++) reg[i] = 0;	//Zeroes all registers, reg[0] to re[15]

	signF  =	0;
	zeroF  =	0;
	carryF =	0;
	stopF  =	0;
	irF    =	0;
	mbR    =	0;
	maR    =	0;
	irR    =	0;

}//end ofdisRegisters
