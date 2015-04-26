/*
* @Author Beesham Sarendranauth
* @Date: 2015/04/27
*/

/*
	registerVar
	Description: contains all registers and flags, makes them global to be used by other functions
*/

unsigned long reg[];
int signF;
int zeroF;
int carryF;
int stopF;
int irF;
unsigned long mbR,maR;
unsigned long irR;
unsigned short ir0;
unsigned short ir1;

unsigned char MEMORY[];
