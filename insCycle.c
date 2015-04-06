#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "registersVar.h"
#include "myDefines.h"

#define LR reg[14]
#define PC	pc

unsigned short irX; //holds the value of which register to use, ir0/ir1

unsigned int rd,rn;
unsigned short immeVal;
unsigned short ldStrBit;
unsigned short wrdBytBit;
unsigned short ALU;

/*
	splitIR
	Description: determines which instruction register to use IR1/IR2
*/
void splitIR(){

	ir0 = (irR >> 16) & irM;
	printf(" ir0: %04X ",ir0);
	ir1 = irR & irM;
	printf(" ir1: %04X ",ir1);

	if(irF==0){
		irX = ir0;
	}
	else{
		irX = ir1;
	}

	printf("\nSplitting irR\n");

}//end of slpitIR

/*
	insType
	Description: returns the number corresponding to the instruction
	0: data processing
	1: load/store
	2&3: immediate instruction
	4: conditional branch
	5: push/pull
	6: unconditional branch
	7: stop
*/

int insType() {
	return irX >> 13;
}

/*
	flags
	Description: sets the flags appropriately
	isSigned: checks if the result is signeds
	isZero: checks if result returns zero
	carryF: checks if the ALU returns a carry
*/

void flags(){
	signF = isSigned(ALU);
	zeroF = isZero(ALU);
	carryF = isCarry(reg[rd],immeVal,carryF);
}//end of flags


void dataProcessingIns(){
	short opCode = (irX&dataProOpM)>>8;
	switch(opCode){
		case 0:
			break;
		case 1:
			break;
		case 2://SUB
			reg[rd]=reg[rd]+(~reg[rn])+1;
			flags();
			break;
		case 3:
			break;
		case 4://ADD
			reg[rd]=reg[rd]+reg[rn];
			flags();
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
	}//end of switch
}//end of dataProcessingIns

/*
	The offset is an 8-bit relative address. The 8-bit signed value is added to the PC.
*/

void conditionalBranch(){
	switch((irX&condBrM)>>8){
		case 0:
			zeroF=1;
			break;
		case 1:
			zeroF=0;
			break;
		case 2:
			carryF=1;
			break;
		case 3:
			carryF=0;
			break;
		case 4:
			signF=1;
			break;
		case 5:
			signF=0;
			break;
		case 6:
			
			break;
		case 7:
			break;
		case 8:
			carryF=1;
			zeroF=0;
			break;
		case 9:
			carryF=0;
			zeroF=1;
			break;
		case 10:
			break;
	}//end of switch

	PC=PC+(irX&condBrRelAddrM);

}//end of conditionalBranch

void unconditionalBranch(){
	short linkbit = (irX&unconBrLiM)>>12;
	switch(linkbit){
	case (0):
		conditionalBranch();
		break;
	case (1):
		LR=PC;
		PC=irX&unconBrOffsetM;
		break;
	}//end of switch
}//end of unconditionalBranch

/*
	moveIns
	Description: move the immediate value from the insrtuction register to a register
*/

void movIns(){

	printf("\nMove INS\n");

	printf(" iregH: %08X ",irX);
	reg[rd] = immeVal;
	printf(" rd: %08X ",rd);
	printf(" reg[%d]: %08X ",rd,reg[rd]);
	flags();
}//end of movIns

/*
	addIns
	Description: add the immediate value to destination register
*/

void addIns(){
	printf("\nAdd INS\n");
	ALU	 = reg[rd] + immeVal;//reg[rn];
	flags();
	reg[rd] = ALU;
	
}//end of addIns

/*
	subIns
	Description: subtract the immediate value to destination register
*/

void subIns(){
	printf("\nSub INS\n");
	
	ALU = reg[rd] + (~immeVal) + 1;
	flags();
	reg[rd] = ALU;
	
}//end of subIns

/*
	subIns
	Description: compares the immediate value to destination register
*/

void cmpIns(){
	printf("\nComp INS\n");
	
	ALU = reg[rd]+(~immeVal)+1;
	//reg[rd]  = ALU;
	flags();
}//end of comIns


void loadStoreIns(){
	
	printf("Load/str Instruction\n");
	//printf("wrdByt: %X",wrdBytBit);
	switch(wrdBytBit){//switch load a byte or a word
	case 0://store to memory
		printf("transfering word\n");
		switch (ldStrBit){//switch to do a load or a store
			case 1:
				printf("load from mem");
				maR = reg[rn];
				mbR = MEMORY[maR];
				printf("mbr: %X\n",mbR);
				mbR = mbR<<8;
				printf("mbr: %X\n",mbR);
				mbR += MEMORY[++maR];
				printf("mbr: %X\n",mbR);
				reg[rd] = mbR;//MEMORY[maR];//mbR;
			break;

			case 0:
				printf("store to mem");
				maR = reg[rn];
				mbR = reg[rd];
				MEMORY[maR]=mbR;//reg[rd];
				mbR = mbR<<8;
				MEMORY[++maR]=mbR;

			break;
		}//end of switch
		break;

	case 1://load from memory
		printf("transfering byte\n");
		switch (ldStrBit){
			case 1:
				printf("load from mem");
				maR = reg[rn];
				mbR = MEMORY[maR];
				reg[rd] = mbR;//MEMORY[maR]&byteM;
			break;

			case 0:
				printf("store to  mem");
				maR = reg[rn];
				mbR = reg[rd];
				MEMORY[maR]=mbR;//reg[rd]&byteM;
			break;
		}//end of switch
		break;
	}//end of switch

}//end of loadStoreIns

/*
	immediateIns
	Description: selects which immediate instuction to process based on the opCode returned
	0: immediate move instruction
	1: immediate compared instruction
	2: immediate add instruction
	3: immediate subtract instruction
*/

void immediateIns(){
	printf("\nSelecting Ins: %X \n",((irX >> 12) & opCodeM));
	switch((irX >> 12) & opCodeM){
	case 0:
		movIns();
		break;
	case 1:
		cmpIns();
		break;
	case 2:
		addIns();
		break;
	case 3:
		subIns();
		break;
	}//end of switch
}//end of immediateIns

/*
	stop
	Description: sets the stop flag
*/

void stop(){
	stopF = 1;
}

/*
	isSigned
	Description: checks if op1 is a signed number
	sets the signed flag
*/

int isSigned(unsigned long op1){
	//printf("/n %X /n",op1>>7);
	//printf("/n op1 %04X: /n",op1);
	if(op1>>7) return 1;
	return 0;
}//end of isSigned

/*
	isZero
	Description: checks if op1 is zero
	sets the zero flag
*/

int isZero(unsigned long op1){
	if(op1 == 0) return 1;
	return 0;
}//end of isZero

/*
	isCarry() - determine if carry is generated by addition: op1+op2+C
	C can only have value of 1 or 0
*/

int isCarry(unsigned long op1, unsigned long op2, unsigned C){//rn,rd,c
	if((op2 == MAX32) && (C == 1)) return 1; //special case where op2 is at MAX32

	return ((op1 > (MAX32 - op2 - C))?1:0);
}//end of isCarry

/*
	execute
	Description: processes the instruction type
	0: data processing instruction
	1: load/store instuction
	2&3: immediate instruction
	4: conditional branch
	5: push/pull *unimplemented
	6: unconditional branch
	7: stop
*/
void execute(){
	printf("\nExecuting\n");
	splitIR();					//splits the instruction registers
	printf(" irR: %08X ",irR);
	printf(" irX: %04X ",irX);
	immeVal = (irX& immeM)>>4;	//determines the immediate value
	printf(" immeVal: %04X ",immeVal);
	rd = (irX & rdM);			//determines the register destination value 
	rn = (irX & rnM)>>4;		//determines the register source value
	printf("rd: %08d",rd);

	ldStrBit = (irX & ldrStrM)>>11;
	wrdBytBit = (irX & wrdBytM)>>10;

	switch(insType()){
		case 0: dataProcessingIns();
			break;
		case 1: loadStoreIns();
			break;
		case 2: immediateIns();
			break;
		case 3: immediateIns();
			break;
		case 4: conditionalBranch();
			break;
		case 6: unconditionalBranch();
			break;
		case 7: stop();
			break;
	}//end of switch


}//end of execute

void insCycle(){
	printf("\nINS Cycle\n");
	
	
	if(irF==0){
		fetch(&MEMORY);	
		execute();
		irF = 1;
	}
	else{
		//fetch(&MEMORY);
		execute();
		irF = 0;
	}
	//printf(" instype: %X ",insType());

}
