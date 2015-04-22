/*
Author: Beesham Sarendranauth
Description: The program starts by displaying an introduction memory and
	implement a simple user interface for the Virtual CPU program.
Date: 2015/02/06

note: assuming long is 4 bytes 

*/


//#include "MyDefines.h"
#include "MyLib.h"
//#include "MyFunctions.h"

//void disRegisters();
void prompt();
void quit();


unsigned char MEMORY[memSize] = ""; 
//unsigned char STACK;


unsigned long reg[NUM_OF_REGS] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
int signF = 0;
int zeroF = 0;
int carryF = 0;
int stopF = 0;
int irF = 0;
unsigned long mbR = 0 ,maR = 0;
unsigned long irR = 0;
//unsigned long pc = reg[15];
unsigned short ir0 = 0, ir1 = 0;
//unsigned long SP; 

int main(){
	//reg[13] = MEMORY[STACK_BEG];
	printf("Name: Beesham Sarendranauth\n");
	printf("Memory: 16Kbytes\n");
	printf("The program starts by displaying an introduction memory and\nimplement a simple user interface for the Virtual CPU program.\n\n");
	help();

	zero();
	//fetch(&MEMORY);

	prompt();

}//end of main

/*
	prompt class
	Description: prompts the user for an input
	Does not take an argument nor return a value
*/

void prompt(){

	char input[inputBuf];
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

			case('G'):
			case('g'):{
				while(!stopF){
					insCycle();
					disRegisters();
				}

					  }//end of case g
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
				disRegisters();
					  }//end of case r
				break;

			case('T'):
			case('t'):{
				//fetch(&MEMORY);
				insCycle();
				disRegisters();
					  }//end of case t
				break;

			case('Z'):
			case('z'):{
				zero();
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


void quit(){
	exit(0);
}//end of quit

