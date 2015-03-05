#include "stm32f10x.h"
//#include "time.h"
#define RESTART					0x01
#define ERR_PHASE				0x10
#define ERR_REGIME			0x20
#define ERR_CALIBR			0x40
#define READY_DATA			0x80
#define MAXRESTARTS			9999
#define MAXERRREQSPI1		9999
//	FLASH
#define LASTPAGEFLASH		0x0800FC00	// C8
u16 ReStarts __attribute__((at(0x20004F00)));

//	IWDG
#define IWDG_ACCESS			0x5555
#define IWDG_RL					0xaaaa
#define IWDG_EN					0xcccc
//#define NVIC_VectTab_FLASH           ((u32)0x08000000)

u8			StateAI=(READY_DATA|RESTART), StateClbAI;

u16 CalcCRC16(u8 *Buffer, u16 SizeBuf);

void WriteFLASH(u16 *Source, u32 BegAddr, u16 SizeFLASH);
void ReadFLASH(u16 *Destination, u32 BegAddrFLASH, u16 SizeFLASH);
__packed struct CalibrStruct
{
  float Clb[8];
  float Ang[8];
	u16		CRC16;
};

struct CalibrStruct Calibr;

//																		Ia				Ib			Ic			I0				Uab			Ubc				Uca			U0
const struct CalibrStruct C_Calibr={2.62e-4, 2.62e-4, 2.62e-4, 2.32e-5, 2.70e-4, 2.70e-4, 2.70e-4, 4.18e-4,
// теоретические значения						0.00e-2, 2.45e-2, 4.91e-2, 7.36e-2, 9.82e-2, 1.23e-1, 1.47e-1, 1.72e-1, 0};
																		0.00e-2, 2.45e-2, 4.91e-2, 4.66e-2, 1.50e-1, 1.75e-1, 1.99e-1, 2.24e-1, 0};
int32_t	ReIa,ImIa,ReIb,ImIb,ReIc,ImIc,Re3Io,Im3Io,
        ReUa,ImUa,ReUb,ImUb,ReUc,ImUc,Re3Uo,Im3Uo,  																				
				ReIa_g2,ImIa_g2,ReIb_g2,ImIb_g2,ReIc_g2,ImIc_g2,Re3Io_g2,Im3Io_g2,
				ReUa_g2,ImUa_g2,ReUb_g2,ImUb_g2,ReUc_g2,ImUc_g2,Re3Uo_g2,Im3Uo_g2;


int32_t	Re1,Re2,Re5,Im1,Im2,Im5;
uint32_t	angl1[8]={0,0,0,0,0,0,0,0};
uint32_t	Ia,Ib,Ic,Ia_g2,Ib_g2,Ic_g2;
uint32_t	Ia_2_1g,Ib_2_1g,Ic_2_1g;
uint32_t	I_3o_p,I_3o_u;
uint32_t	Ua,Ub,Uc,Ua_g2,Ub_g2,Uc_g2;
uint32_t	Uab,Ubc,Uca,U_3o_p,U_3o_u;
