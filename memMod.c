/*
* @Author Beesham Sarendranauth
* @Date: 2015/04/27
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MyDefines.h"

/*
	memMod()
	Description: prompts the user to enter a starting location in memory, then prompts the user
				 to enter a new value
*/

void memMod(void *memptr){
	char startingaddrC[256],lengthC[256], newValueC[256];
	unsigned long startingaddrI,lengthI;

	unsigned newVal = 0x00;
	unsigned exitval = '.';

	printf("**Range: 0-4000H\n**Please enter within this range!\n**Any other characters will be treated as 0\n");
	printf("Enter starting address: ");
	fgets(startingaddrC,sizeof(startingaddrC)-1,stdin);
	sscanf(startingaddrC," %X",&startingaddrI);
	if(startingaddrI > memSize){
		printf("Error: exceeding memory\n");
	}
	else{
		while(newVal!=exitval){
			printf("Enter new value for location %04X (00-FFH): ",startingaddrI);
			fgets(newValueC,sizeof(newValueC)-1,stdin);	
			if(newValueC[0]==exitval)	break;
			sscanf(newValueC," %X",&newVal);
			(((char*)memptr)[startingaddrI]) = newVal;
			startingaddrI++;
		}
	}
}//end of memMod
