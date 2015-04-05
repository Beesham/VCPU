/*
	registerVar
	Description: contains all registers and flags, makes them global to be used by other functions
*/

extern unsigned long reg[15];
extern int signF;
extern int zeroF;
extern int carryF;
extern int stopF;
extern int irF;
extern unsigned long mbR,maR;
extern unsigned long irR;
extern unsigned short ir0;
extern unsigned short ir1;
extern unsigned long pc;

extern unsigned char MEMORY[];