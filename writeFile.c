#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	writeFile class
	Description: Writes (creates if not exists) to a file a specified amount of bytes determined by the user
	Takes a pointer to memory that is the max amount of bytes to write to the file
	Does not return a value
*/

void writeFile(void *memory){

	char fileName[100];
	char numBytesC[10];
	int numBytes;
	//char stuff[]="suffffffffff to write to fileeeee";
	FILE *fileptr;

	printf("Enter the name of your file: ");
	fgets(fileName,sizeof(fileName),stdin);
	sscanf(fileName," %s",fileName);

	printf("Enter the number of bytes to write to file: ");
	fgets(numBytesC,sizeof(numBytesC),stdin);
	sscanf(numBytesC," %s",numBytesC);

	numBytes = atoi(numBytesC);

	fileptr = fopen(fileName, "wb");

	if(fileptr == NULL){
		printf("Error opening file: %s\n",fileName);
		perror("WriteFile");
	}
	else{
		fseek(fileptr, 0, SEEK_SET);
		fwrite(memory,sizeof(char),numBytes,fileptr);
		fclose(fileptr);
	}
}//end of writeFile
