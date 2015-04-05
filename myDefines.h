/*
	myDefines
	Description: contains all/most of the defines needed for masking and other operations
*/

#define memSize 16384
#define inputBuf 10
#define sizeofins 4
#define MAX32 32

#define pc	reg[15]

#define irM				0x0000FFFF	//irMask
#define opCodeM			0x0003  //opcode mask
#define rdM				0x0000000F  //rdMask
#define rnM				0x000000F0  //rnMask
#define immeM			0x0FF0 //immediate value mask
#define ldrStrM			0x0800 //load/store Mask
#define wrdBytM			0x0400 //load byte/word Mask
#define byteM			0X000F //load/store a byte, this is the mask
#define condBrM			0x0F00 // conditional branch mask
#define dataProOpM		0x0F00 // data processing opration mask
#define condBrRelAddrM	0x00FF //conditional branch relative address
#define unconBrLiM		0x1000 //unconditional branch link bit mask
#define unconBrOffsetM	0x0FFF //unconditional branch offset mask