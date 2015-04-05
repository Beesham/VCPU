#include <stdio.h>

/*
	help class
	Description: Displays a menu of options with description for the user to choose from
	Does not take an argument nor return a value
*/

void help(){
	printf("d		dump memory\n");   
	printf("g		go – run the entire program\n");
	printf("l		load a file into memory	(Allows you to specify the file name.)\n");
	printf("m		memory modify\n"); 
	printf("q		quit\n");
	printf("r		display registers\n");
	printf("t		trace – execute one instruction\n");
	printf("w		write file\n");
	printf("z		reset all registers to zero\n");
	printf("?, h	display list of commands\n"); 	
}//end of help
