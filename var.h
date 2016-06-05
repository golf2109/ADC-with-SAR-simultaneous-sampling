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
//                        					0.00e-2, 2.45e-2, 4.91e-2, 7.36e-2, 9.82e-2, 1.23e-1, 1.47e-1, 1.72e-1, 0};
																		0.00e-2, 2.45e-2, 4.91e-2, 4.66e-2, 1.50e-1, 1.75e-1, 1.99e-1, 2.24e-1, 0};
int32_t	ReIa,ImIa,ReIb,ImIb,ReIc,ImIc,Re3Io_i,Im3Io_i,ReUad,ImUad,
        ReUa,ImUa,ReUb,ImUb,ReUc,ImUc,ReU3o_i,ImU3o_i,  																				
				ReIa_2g,ImIa_2g,ReIb_2g,ImIb_2g,ReIc_2g,ImIc_2g,Re3Io_2g,Im3Io_2g,ReUad_2g,ImUad_2g,
				ReUa_2g,ImUa_2g,ReUb_2g,ImUb_2g,ReUc_2g,ImUc_2g,ReU3o_2g,ImU3o_2g;


int32_t	Re1,Re2,Re5,Im1,Im2,Im5;

int32_t	Ia,Ib,Ic,Ia_2g,Ib_2g,Ic_2g;
int32_t	Ia_2_1g,Ib_2_1g,Ic_2_1g;
int32_t	Ia_2_1g,Ib_2_1g,Ic_2_1g;
int32_t	ReI2,ImI2,I2,Re_I3o_p,Im_I3o_p,ReUad_p,ImUad_p;
int32_t	ReI1,ImI1,I1;
int32_t	Delta_I1,Delta_I2;
int32_t	I3o_p,I3o_i;
int32_t	Ua,Ub,Uc,Uad,Ua_2g,Ub_2g,Uc_2g;
int32_t	Uab,Ubc,Uca,U3o_p,U3o_i;
int32_t	ReU2,ImU2,U2;
int32_t	ReU1,ImU1,U1;

int32_t	F_Ia,F_Ib,F_Ic,F_I3o_p,F_3Io_i,F_Uad,F_Uad_i;
int32_t	F_Ua,F_Ub,F_Uc,F_Uab,F_Ubc,F_Uca;
int32_t	F_Ia_bc,F_Ib_Uca,F_IcUab;
int32_t	F_U3oi,F_3oi_U3oi,F_3Iop_U3oi;
int32_t	F_Ia_Ubc,F_Ib_Uca,F_Ic_Uab;
int32_t	F_U3oi,F_3Ioi_U3oi,F_3IopU3oi;

int32_t	F_Zab,F_Zbc,F_Zca,F_Za0,F_Zb0,F_Zc0;

int32_t	FB_Ia,FB_Ib,FB_Ic,FB_I3o_p,FB_3Io_i;
int32_t	FB_Ua,FB_Ub,FB_Uc,FB_Uab,FB_Ubc,FB_Uca,FB_U3o_i,FB_Uad,FB_I3o_p;
int32_t	Re_Uab,Im_Uab,Re_Ubc,Im_Ubc,Re_Uca,Im_Uca;
int32_t	Zp,ReZp,ImZp,Fp,maxI,k,Ing=10,Ung,Io_p,Zp_0p,ZZp_0i;	
int32_t	Ktn=1,Ktn0=1;

int32_t	Ubnn,Re_Ubnn,Im_Ubnn;
int32_t	Zab,Zbc,Zca,Za0,Zb0,Zc0,ZZp_0p,ZZp_0i;


