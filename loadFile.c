#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	loadFile()
	Description: Loads a file into memory with the max size being the size of memeory specified
	Takes a pointer to memory and the max amount of bytes to read in
	Returns an int; the number of bytes read in
*/

int loadFile(void *memory, unsigned int max){

	char fileName[256];
	int bytesRead=0;
	FILE *fileptr;

	printf("Enter the name of your file: ");
	fgets(fileName,sizeof(fileName)-1,stdin);
	sscanf(fileName," %s",fileName);

	fileptr = fopen(fileName, "rb");
	if(fileptr == NULL){
		printf("Error opening file: %s\n",fileName);
	}else{
		fseek(fileptr, 0, SEEK_SET);
		fread(memory,max,1,fileptr);
		bytesRead = ftell(fileptr);
		fclose(fileptr);
	}
	
	return bytesRead;
}//end of loadFile
