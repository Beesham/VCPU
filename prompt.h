#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	prompt class
	Description: prompts the user for an input
	Does not take an argument nor return a value
*/

void prompt(){

	char input[256];
	int bytesRead;

	while(1){
		
		printf("prompt>");	
		fgets(input,sizeof(input)-1,stdin);
		sscanf(input," %s",input);

		if(strlen(input) > 1){	
			errorMsg(input);
		}
		else{
			switch(*input){
			case('?'):
			case('H'):
			case('h'):{
				help();
					  }//end of case h
				break;

			case('L'):
			case('l'):{
				bytesRead = loadFile(&MEMORY,sizeof(MEMORY));
				printf("Bytes read in Decimal: %d, Hex: %X\n",bytesRead,bytesRead);

				if(bytesRead == sizeof(MEMORY)) printf("File is truncated\n");
				else printf("File is not truncated\n");
					  }//end of case l
				break;

			case('W'):
			case('w'):{
				writeFile(&MEMORY);
					  }//end of case w
				break;

			case('D'):
			case('d'):{
				memDumpPrompt(&MEMORY);
					  }//end of case d
				break;

			case('M'):
			case('m'):{
				memMod(&MEMORY);
					  }//end of case m
				break;

			case('R'):
			case('r'):{
				//memMod(&MEMORY);
					  }//end of case r
				break;

			case('Z'):
			case('z'):{
				//memMod(&MEMORY);
					  }//end of case z
				break;

			case('Q'):
			case('q'):{
				quit();
					  }//end of case q

			default:{
				errorMsg(input);
					}

			}//end of switch
		}//end of if(strlen(input) > 1)	
	}//end of while(1)
}//end of prompt