/*
* @Author Beesham Sarendranauth
* @Date: 2015/04/27
*/

#include <stdio.h>

/*
	help()
	Description: Displays a menu of options with description for the user to choose from
	Does not take an argument nor return a value
*/

void help(){
	printf("d\tdump memory\n");   
	printf("g\tgo - run the entire program\n");
	printf("l\tload a file into memory	(Allows you to specify the file name.)\n");
	printf("m\tmemory modify\n"); 
	printf("q\tquit\n");
	printf("r\tdisplay registers\n");
	printf("t\ttrace - execute one instruction\n");
	printf("w\twrite file\n");
	printf("z\treset all registers to zero\n");
	printf("?, h\tdisplay list of commands\n"); 	
}//end of help
