To compile follow steps:

1-Copy all files to a folder
2-gcc *.c
3-done!


Introduction
This Virtual CPU is a simulation of and is loosely based on the ARM Cortex M0+. The simulation will be at a register level(i.e. will simulate register to register transfers). The program has a simple user interface that allows it to be used to test machine level programs written for the CPU (read a binary file into memory, display memory, single step instructions, display registers, etc.). 

Memory
Memory is byte addressable array. Only 16K (0x4000) will be present but can be expanded as needed for other version of the CPU.

Byte Order
This machine has a big-endian architecture, i.e., words are stored in memory MSB first.
 
Registers
	R0-R15	- (16 32-bits) general purpose registers
Special Uses:	R13 – SP – Stack Pointer
	R14 – LR – Link Register
	R15 – PC – Program Counter
	CCR	- Condition Codes - Sign, Zero and Carry flags
	MBR	- (32-bits) Memory Buffer Register - buffer for all data
	MAR	- (32-bits) Memory Address Register - Holds memory address
	IR0, IR1	- (16-bits) 2 Instruction Registers
	Stop flag	- flag set by STOP instruction
	IR active flag	- selects active IR
 
