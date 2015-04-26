/*
* @Author Beesham Sarendranauth
* @Date: 2015/04/27
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MyDefines.h"

/*
	memDumpPrompt()
	Description: prompts the user for offset and length

*/

void memDumpPrompt(void *memptr){

	char offsetC[memSize],lengthC[memSize];
	unsigned offsetI = 0,lengthI = 0;

	printf("**Offset range: 0-4000H\n**Length: 0-4000H\n**Please enter within these ranges!\n**Any other characters will be treated as 0\n");
	printf("Enter offset: ");
	fgets(offsetC,sizeof(offsetC)-1,stdin);
	sscanf(offsetC," %X",&offsetI);
	printf("Enter length: ");
	fgets(lengthC,sizeof(lengthC)-1,stdin);
	sscanf(lengthC," %X",&lengthI);
	if((lengthI+offsetI) > memSize){
		printf("Error: exceeding memory!\n");
	}
	else	memDump(memptr,offsetI,lengthI);

}//end of memDumpPrompt

