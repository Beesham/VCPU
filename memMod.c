#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	memMod()
	Description: prompts the user to enter a starting location in memory, then prompts the user
				 to enter a new value
	Does not return a value
*/

void memMod(void *memptr){
	char startingaddrC[256],lengthC[256],newValueC[256];
	unsigned long startingaddrI,lengthI;

	unsigned newVal = 0x00;
	unsigned exitval = '.';

	printf("Enter starting address: ");
	fgets(startingaddrC,sizeof(startingaddrC)-1,stdin);
	sscanf(startingaddrC," %x",&startingaddrI);
	while(newVal!=exitval){
		printf("Enter new value for location %04X: ",startingaddrI);
		fgets(newValueC,sizeof(newValueC)-1,stdin);
		if(newValueC[0]==exitval)	break;
		sscanf(newValueC," %X",&newVal);
		(((char*)memptr)[startingaddrI]) = newVal;
		startingaddrI++;
	}
}//end of memMod
