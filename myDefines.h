/*
	MyDefines
	Description: contains all/most of the defines needed for masking and other operations
*/

#define memSize			0x4000//16384
#define NUM_OF_REGS		16
#define NUM_BITS_REG	16
#define inputBuf		10
#define sizeofins		4
#define MAX32			0xFFFFFFFF //32
#define REG_SIZE		4			//4 bytes
#define STACK_BEG		0x3A0F


//#define STACK MEMORY[STACK_BEG]
#define PC	reg[15]	//reg[15]
#define LR  reg[14] //reg[14]
#define SP  reg[13] //reg[13]

#define memptrM			0x00003FFF		//memory pointer mask
#define irM				0x0000FFFF		//irMask
#define opCodeM			0x0003			//opcode mask
#define rdM				0x0000000F		//rdMask
#define rnM				0x000000F0		//rnMask
#define immeM			0x0FF0			//immediate value mask
#define LBitM			0x0800			//L bit Mask
#define HBBitM			0x0400			//H/B bit Mask
#define RBitM			0x0100			//R bit Mask
#define byteM			0X000F			//load/store a byte, this is the mask
#define condBrM			0x0F00			// conditional branch mask
#define dataProOpM		0x0F00			// data processing opration mask
#define lowerBitsM		0x00FF			//conditional branch relative address / register list mask
#define unconBrLiM		0x1000			//unconditional branch link bit mask
#define unconBrOffsetM	0x0FFF			//unconditional branch offset mask
