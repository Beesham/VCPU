#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	memDump class
	Description: The interface code will prompt the user for an offset and length to be dumped from the CPU memory. 
	The data dumped will depend on what has been placed in memory by the load file function.
	Args: memptr(points to the start of a section of memory)
		  offset (specifies the part to be displayed)
		  length (specifies the number of bytes to be displayed)
*/

void memDump(void *memptr, unsigned offset, unsigned length){
	int i,n=0,j=offset,lineSize=16;
	for(n,i=offset;n<length,i<=length;n++,i++){

		if ((((n % lineSize)==0) && n>=lineSize)||i==length){
			printf("\n");
			printf("       ");
			for (j;j<i;j++){
						if (isprint(((unsigned char*)memptr)[j])){
							printf("%c  ",((unsigned char*)memptr)[j] );	//prints the character at location
						}
						else printf(".  ");
				}
		}

		if ((n % lineSize) == 0){
			printf("\n");
			printf("%04X  ",i);	 //prints beginning of location
		}

		if(i!=length)	printf("%02X ",((unsigned char*)memptr)[i]);	//prints hex value

		//getchar();

	}//end of for

	printf("\n");

}//end of memDump
