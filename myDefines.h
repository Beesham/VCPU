/*
* @Author Beesham Sarendranauth
* @Date: 2015/04/27
*/

/*
	MyDefines.h
	Description: contains all/most of the defines needed for masking and other operations
*/

#define memSize			0x4000			//16384 bytes of memory
#define NUM_OF_REGS		16				//Number of registers in CPU
#define NUM_BITS_REG	32				//Number of bit per register: 32
#define NUM_BITS_INS	16				//Number of bit per instruction: 16
#define NUM_BITS_BYTE	8				//NUmber of bits per byte
#define inputBuf		32				//Size of input
#define sizeofins		4				//Size of instruction: 4 byte 
#define MAX32			0xFFFFFFFF		//Max value can be stores in a register

#define PC	reg[15]						//Stack Pointer (SP)
#define LR  reg[14]						//Link Register (LR)
#define SP  reg[13]						//Program Counter (PC)

#define lsbM			0x00000001		//mask for least significat bit
#define lowerByteM		0x000000FF		//masks the least significant byte/zeros all other bits except lsbyte
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
