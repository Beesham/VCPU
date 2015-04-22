//#include <stdio.h>
//#include <stdio.h>
//#include <stdlib.h>/
//#include <string.h>
//#include <ctype.h>
#include "MyLib.h"
//#include "MemDump.c"
//#include "MyDefines.h"

/*Inputs*/
void memDumpPrompt(void *memptr){

	char offsetC[memSize],lengthC[memSize];
	//unsigned length=NULL,offset=NULL;
	unsigned offsetI = 0,lengthI = 0;

	printf("Enter offset: ");
	fgets(offsetC,sizeof(offsetC)-1,stdin);
	sscanf(offsetC," %X",&offsetI);
	//sscanf(&offsetI, " %X", offsetC);
	
	//offsetI=atoi(offsetC);

	printf("Enter length: ");
	fgets(lengthC,sizeof(lengthC)-1,stdin);
	sscanf(lengthC," %X",&lengthI);
	//sscanf(&lengthI, " %X", lengthC);

	//lengthI=atoi(lengthC);

	//printf("%i\n", offsetC);
	//printf("%i\n", lengthC);

	memDump(memptr,offsetI,lengthI);

}//end of memDumpPrompt
