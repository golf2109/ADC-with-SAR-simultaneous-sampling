#include "stm32f10x.h"
#define	ING	30000
#define	Kkft	3

extern	char	adc_ch;
extern int32_t*	addr_angl;
extern	int32_t	Re1,Re2,Re5,Im1,Im2,Im5;
extern	uint32_t	Ia,Ib,Ic,Ia_2g,Ib_2g,Ic_2g;
extern	uint32_t	Ia_2_1g,Ib_2_1g,Ic_2_1g;
extern	int32_t	ReI2,ImI2,I2,Re_I3o_p,Im_I3o_p;
extern	uint32_t	ReI1,ImI1,I1;
float	f_ReI1,f_ImI1,f_I1;
float	f_ReI2,f_ImI2,f_I2;
extern	int32_t	I3o_p,I3o_i;
extern	uint32_t	Ua,Ub,Uc,Uad,Ua_2g,Ub_2g,Uc_2g;
extern	uint32_t	Uab,Ubc,Uca,U3o_p,U3o_i;
extern	int32_t	ReU2,ImU2,U2;
extern	int32_t	ReU1,ImU1,U1;
	
extern	int32_t	ReIa,ImIa,ReIb,ImIb,ReIc,ImIc,Re3Io_i,Im3Io_i,ReUad,ImUad,
        ReUa,ImUa,ReUb,ImUb,ReUc,ImUc,ReU3o_i,ImU3o_i,  																				
				ReIa_2g,ImIa_2g,ReIb_2g,ImIb_2g,ReIc_2g,ImIc_2g,Re3Io_2g,Im3Io_2g,ReUad_2g,ImUad_2g,
				ReUa_2g,ImUa_2g,ReUb_2g,ImUb_2g,ReUc_2g,ImUc_2g,ReU3o_2g,ImU3o_2g;

extern	uint32_t ModAngl(int32_t Re,int32_t Im);
extern	uint32_t Mod(int32_t Re,int32_t Im);

extern int32_t	F_Ia,F_Ib,F_Ic,F_I3o_p,F_3Io_i,F_Uad_p,F_Uad;
extern int32_t	F_Ua,F_Ub,F_Uc,F_Uab,F_Ubc,F_Uca;
extern int32_t	F_Ia_bc,F_Ib_Uca,F_IcUab;
extern int32_t	F_U3oi,F_3oi_U3oi,F_3Iop_U3oi;
extern int32_t	F_Ia_Ubc,F_Ib_Uca,F_Ic_Uab;
extern int32_t	F_U3oi,F_3Ioi_U3oi,F_3IopU3oi;
extern	uint32_t 	ang;

extern	int32_t		Zp,ReZp,ImZp,Fp,maxI,k,Ing,Ung,Io_p,Zp_0p,Zp_0i;	
extern	uint32_t	Zab,Zbc,Zca,Za0,Zb0,Zc0,ZZp_0p,ZZp_0i;

extern	int32_t	FB_Ia,FB_Ib,FB_Ic,FB_I3o_p,FB_3Io_i;
extern	int32_t	FB_Ua,FB_Ub,FB_Uc,FB_Uab,FB_Ubc,FB_Uca,FB_U3o_i,FB_Uad,FB_I3o_p;
extern	int32_t	Delta_I1,Delta_I2;
extern	int32_t	Re_Uab,Im_Uab,Re_Ubc,Im_Ubc,Re_Uca,Im_Uca;

extern	int32_t	Ktn,Ktn0;
extern	int32_t	Ubnn,Re_Ubnn,Im_Ubnn;
extern	int32_t	F_Zab,F_Zbc,F_Zca,F_Za0,F_Zb0,F_Zc0;

uint32_t	MemDel_I1,MemDel_I2;
int32_t baz;
uint32_t	Iab,Ibc,Ica;
int32_t	Re_Iab,Im_Iab,Re_Ibc,Im_Ibc,Re_Ica,Im_Ica;
int32_t	ReIZa,ImIZa,ReIZb,ImIZb,ReIZc,ImIZc;

int32_t	Re_Zab,Im_Zab,Re_Zbc,Im_Zbc,Re_Zca,Im_Zca;
int32_t	arcZab,arcZbc,arcZca;
int32_t	Re_Za0,Im_Za0,Re_Zb0,Im_Zb0,Re_Zc0,Im_Zc0;
int32_t	arcZa0,arcZb0,arcZc0,arcI3o_p;
int32_t	F_U3o_i,F_I3op_U3oi;

int32_t	arcF_Ia,arcF_Ib,arcF_Ic;
int32_t	arcF_Ua,arcF_Ub,arcF_Uc,arcF_Uad,arcF_U3o_i,arcF_Uab,arcF_Ubc,arcF_Uca;

extern	uint8_t	izmer[101];
extern	u32	zzz,zzz1,zzz2;
#define    DWT_CYCCNT       *(volatile unsigned long *)0xE0001004
uint32_t sqrtf_int;
extern	u32	zzz1_m1,zzz1_m2,zzz1_m3,zzz1_m4,zzz1_m5;
uint32_t my_sq;

extern	int sqrt_32	(int	a, int	b);
extern	int32_t	arctg(int32_t	Re, int32_t Im);
extern	int32_t	arctg1(int32_t	Re, int32_t Im);
extern	int32_t	arctg_dec(int32_t	Re, int32_t Im);
extern	int arctangens(int x,int y);
extern	int32_t arctg_cordic(int32_t Re,int32_t Im);

int ang_Za0,ang_Zb0,ang_Zc0;
int	IZa,IZb,IZc;
