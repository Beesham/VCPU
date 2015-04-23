
#include "MyLib.h"


/*
	memDumpPrompt()
	Description: prompts the user for offset and length

*/

void memDumpPrompt(void *memptr){

	char offsetC[memSize],lengthC[memSize];
	unsigned offsetI = 0,lengthI = 0;

	printf("Enter offset: ");
	fgets(offsetC,sizeof(offsetC)-1,stdin);
	sscanf(offsetC," %X",&offsetI);
	printf("Enter length: ");
	fgets(lengthC,sizeof(lengthC)-1,stdin);
	sscanf(lengthC," %X",&lengthI);
	memDump(memptr,offsetI,lengthI);

}//end of memDumpPrompt
