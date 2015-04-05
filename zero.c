#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "registersVar.h"

/*
	zero class
	Description: resets all registers to default value of 0
*/
void zero(){
	int i;
	//reg[15] = 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;

	for(i=0;i<sizeof(reg);i++) reg[i] = 0;

	signF = 0;
	zeroF = 0;
	carryF = 0;
	stopF = 0;
	irF = 0;
	mbR = 0;
	maR = 0;
	irR = 0;
	pc = 0;


}//end ofdisRegisters