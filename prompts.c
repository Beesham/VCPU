#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "memDump.c"

/*Inputs*/
void memDumpPrompt(void *memptr){

	char offsetC[256],lengthC[256];
	unsigned offsetI = 0,lengthI = 0;

	printf("Enter offset: ");
	fgets(offsetC,sizeof(offsetC)-1,stdin);
	sscanf(offsetC," %s",offsetC);
	//sscanf(&offsetI, " %X", offsetC);
	
	offsetI=atoi(offsetC);

	printf("Enter length: ");
	fgets(lengthC,sizeof(lengthC)-1,stdin);
	sscanf(lengthC," %s",lengthC);
	//sscanf(&lengthI, " %X", lengthC);

	lengthI=atoi(lengthC);

	//printf("%i\n", offsetC);
	//printf("%i\n", lengthC);

	memDump(memptr,offsetI,lengthI);

}//end of memDumpPrompt