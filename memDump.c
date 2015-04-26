/*
* @Author Beesham Sarendranauth
* @Date: 2015/04/27
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
	memDump()
	Description: The interface code will prompt the user for an offset and length to be dumped from the CPU memory. 
	The data dumped will depend on what has been placed in memory by the load file function.
	Args: memptr(points to the start of a section of memory)
		  offset (specifies the part to be displayed)
		  length (specifies the number of bytes to be displayed)
*/

void memDump(void *memptr, unsigned offset, unsigned length){
	int i,n=0,lineSize=16;
	
	for(i=offset;i<(offset+length);i +=lineSize){
		printf("\n");
		n=i;
		printf("%04X  ",i);		//prints beginning of location
		while(n <(i+lineSize)){
			if(n == (offset+length)){
				break;
			}
			printf("%02X ",((unsigned char*)memptr)[n]);	//prints hex value
			n++;
		}//end of while

		printf("\n       ");
		n=i;
		while(n <(i+lineSize)){
			if(n == (offset+length)){
				break;
			}
			if (isprint(((unsigned char*)memptr)[n])){
				printf("%c  ",((unsigned char*)memptr)[n] );	//prints the character at location
			}
			else printf(".  ");

			n++;
		}
		printf("\n");
	}//end of for	
	printf("\n");
}//end of memDump
