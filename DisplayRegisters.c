
#include "MyLib.h"

/*
	disRegisters class
	Description: Displays the contents of all registers

*/

void disRegisters(){
	int i;
	int regSize=16;

	printf("\nR[0%d]: %08X R[0%d]: %08X R[0%d]: %08X R[0%d]: %08X R[0%d]: %08X\n",0,reg[0],1,reg[1],2,reg[2],3,reg[3],4,reg[4]);
	printf("R[0%d]: %08X R[0%d]: %08X R[0%d]: %08X R[0%d]: %08X R[0%d]: %08X\n",5,reg[5],6,reg[6],7,reg[7],8,reg[8],9,reg[9]);
	printf("R[%d]: %08X R[%d]: %08X R[%d]: %08X R[%d]: %08X R[%d]: %08X\n",10,reg[10],11,reg[11],12,reg[12],13,reg[13],14,reg[14]);
	printf("R[%d]: %08X ",15,reg[15]);

	printf("N: %d  ",signF);
	printf("C: %d  ",carryF);
	printf("Z: %d  ",zeroF);
	printf("Stp: %d  ",stopF);
	printf("IR_ACTIVE: %d\n",irF);
	printf("MAR: %08X  ",maR);
	printf("MBR: %08X  ",mbR);
	printf("IR : %08X\n",irR);

}//end ofdisRegisters
