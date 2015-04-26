/*
* @Author Beesham Sarendranauth
* @Date: 2015/04/27
* @Description: contains functions that checks for invalid input or prints
*				an error message
*/

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Error Checking Functions*/

void errorMsg(void *error){
	printf("%s is not a command\n",error);
}


