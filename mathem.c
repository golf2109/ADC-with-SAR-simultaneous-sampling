#include "mathem.h"
#include <math.h>
//#include "arm_math.h"
//================================================================
int	aa,bb,zn2,aa1,bb1,aa2,bb2,mmm,bbz0,bbz1,bbz2;
int	anglIab,anglIbc,anglIca;
void	perem(void)
{
	switch (adc_ch)
	{	
		case	0	:	{ReIa=Re1;ImIa=Im1;ReIa_2g=Re2;ImIa_2g=Im2;}	break;	
		case	1	:	{ReIb=Re1;ImIb=Im1;ReIb_2g=Re2;ImIb_2g=Im2;}	break;		
		case	2	:	{ReIc=Re1;ImIc=Im1;ReIc_2g=Re2;ImIc_2g=Im2;}	break;	
		case	3	:	{ReUad=Re1;ImUad=Im1;ReUad_2g=Re2;ImUad_2g=Im2;}	break;
		case	4	:	{ReUa=Re1;ImUa=Im1;ReUa_2g=Re2;ImUa_2g=Im2;}	break;	
		case	5	:	{ReUb=Re1;ImUb=Im1;ReUb_2g=Re2;ImUb_2g=Im2;}	break;		
		case	6	:	{ReUc=Re1;ImUc=Im1;ReUc_2g=Re2;ImUc_2g=Im2;}	break;	
		case	7	:	{ReU3o_i=Re1;ImU3o_i=Im1;}	break;					
	}
}	
uint32_t my_sqrt (int32_t Re,int32_t Im)
{
int	x,y,b,m;	
	
m = 0x40000000;
y = 0;			
x=Re*Re+Im*Im;	
   while (m != 0)
		{		 
      b = y | m;
      y = y >> 1;
      if (x >= b) 
				{
						x = x - b;
						y = y | m;
				}
      m = m >> 2;
		}	
		
   return y;
}

//=================================================================
//=================================================================
//=================================================================

void	mat_potok_1 (void)
{	
zzz1 = DWT_CYCCNT;
//arcF_Ia=arctg1(ReIa,ImIa);		
//bbz0=arctangens(ReIa,ImIa);	
	
arcF_Ia=arctg(ReIa,ImIa);	
zzz2 = DWT_CYCCNT-zzz1;		
Ia=985*my_sqrt(ReIa,ImIa)/1000;	
izmer[9]= Ia>>8;
izmer[10]= Ia;	

arcF_Ib=arctg(ReIb,ImIb);		
Ib=985*my_sqrt(ReIb,ImIb)/1000;	
izmer[11]= Ib>>8;
izmer[12]= Ib;		

arcF_Ic=arctg(ReIc,ImIc);	
Ic=985*my_sqrt(ReIc,ImIc)/1000;
izmer[13]= Ic>>8;
izmer[14]= Ic;	
	
//==================================
Ua=9975*my_sqrt(ReUa,ImUa)/4500;			
arcF_Ua=arctg(ReUa,ImUa);
izmer[0]= Ua>>8;
izmer[1]= Ua;
//==================================
Ub=9975*my_sqrt(ReUb,ImUb)/4500;
arcF_Ub=arctg(ReUb,ImUb);
izmer[2]= Ub>>8;
izmer[3]= Ub;
	
Uc=9975*my_sqrt(ReUc,ImUc)/4500;
arcF_Uc=arctg(ReUc,ImUc);
izmer[4]= Uc>>8;
izmer[5]= Uc;			
	
Uad=2*my_sqrt(ReUad,ImUad);
arcF_Uad=arctg(ReUad,ImUad);
izmer[96]= Uad>>16;
izmer[97]= Uad>>8;
izmer[98]= Uad;	
	




}

//===============================================================
//===============================================================
//===============================================================
void	mat_potok_2 (void)
{
Ia_2g=Mod(ReIa_2g,ImIa_2g);			
Ib_2g=Mod(ReIb_2g,ImIb_2g);		
Ic_2g=Mod(ReIc_2g,ImIc_2g);			

U3o_i=my_sqrt(ReU3o_i,ImU3o_i);
arcF_U3o_i=arctg(ReU3o_i,ImU3o_i);
izmer[6]= U3o_i>>24;
izmer[7]= U3o_i>>16;
izmer[8]= U3o_i>>8;	

if	(Ia>ING)  
{Ia_2_1g = Ia_2g*100/Ia;}
else	{Ia_2_1g=0;}
izmer[50]= Ia_2_1g;

if	(Ib>ING)  
{Ib_2_1g = Ib_2g*100/Ib;}
else	{Ib_2_1g=0;}
izmer[51]= Ib_2_1g;

if	(Ic>ING)  
{Ic_2_1g = Ic_2g*100/Ic;}
else	{Ic_2_1g=0;}
izmer[52]= Ic_2_1g;


Re_I3o_p	=	ReIa + ReIb + ReIc;
Im_I3o_p	=	ImIa + ImIb + ImIc;
I3o_p = (1000*my_sqrt(Re_I3o_p,Im_I3o_p)/1414);
arcI3o_p=arctg(Re_I3o_p,Im_I3o_p);
//arcI3o_p=arcF_Ia+arcF_Ib+arcF_Ic;
if (I3o_p >= 0x960000){I3o_p=0x960000;}
izmer[44]= I3o_p>>8;
izmer[45]= I3o_p;

Re_Uab=ReUa-ReUb;		Im_Uab=ImUa-ImUb; 
Uab=9975*my_sqrt(Re_Uab,Im_Uab)/4500;
if (Uab>>24!=0){Uab=0xFEFFFF;}
arcF_Uab=arctg(Re_Uab,Im_Uab);
izmer[32]= Uab>>8;
izmer[33]= Uab;	

Re_Ubc=ReUb-ReUc;		Im_Ubc=ImUb-ImUc; 
Ubc=9975*my_sqrt(Re_Ubc,Im_Ubc)/4500;
if (Ubc>>24!=0){Ubc=0xFEFFFF;}
arcF_Ubc=arctg(Re_Ubc,Im_Ubc);
izmer[34]= Ubc>>8;
izmer[35]= Ubc;

Re_Uca=ReUc-ReUa;		Im_Uca=ImUc-ImUa; 
Uca=9975*my_sqrt(Re_Uca,Im_Uca)/4500;
if (Uca>>24!=0){Uca=0xFEFFFF;}
arcF_Uca=arctg(Re_Uca,Im_Uca);
izmer[36]= Uca>>8;
izmer[37]= Uca;

Re_Ubnn = Ktn*(2*ReUa+ReUb+ReUc)-Ktn0*(ReUad+ReU3o_i);
Im_Ubnn = Ktn*(2*ImUa+ImUb+ImUc)-Ktn0*(ImUad+ImU3o_i);
Ubnn = Mod(Re_Ubnn,Im_Ubnn);
Ubnn = my_sqrt(Re_Ubnn,Im_Ubnn);
if (Ubnn>>24!=0){Ubnn=0xFEFFFF;}
izmer[38]= Ubnn>>8;
izmer[39]= Ubnn;

}

//=========================================================
//=========================================================
//=========================================================
void	mat_potok_3 (void)
{
	
ReI1 = ReIa/3 - ReIb/6 - (ImIb*866)/3000 - ReIc/6 + (ImIc*866)/3000;
ImI1 = ImIa/3 - ImIb/6 + (ReIb*866)/3000 - ImIc/6 - (ReIc*866)/3000;
I1 = 50*Mod(ReI1,ImI1)/45;
izmer[46]= I1>>8;
izmer[47]= I1;

Delta_I1  = I1 - MemDel_I1;
MemDel_I1 = I1;

ReI2 = ReIa/3 - ReIb/6 + (ImIb*866)/3000 - ReIc/6 - (ImIc*866)/3000;
ImI2 = ImIa/3 - ImIb/6 - (ReIb*866)/3000 - ImIc/6 + (ReIc*866)/3000;
I2 = 50*Mod(ReI2,ImI2)/45;
izmer[48]= I2>>8;
izmer[49]= I2;

Delta_I2 = I2 - MemDel_I2;
MemDel_I2 = I2;

ReU1 = ReUa/3 - ReUb/6 - (ImUb*866)/3000 - ReUc/6 + (ImUc*866)/3000;
ImU1 = ImUa/3 - ImUb/6 + (ReUb*866)/3000 - ImUc/6 - (ReUc*866)/3000;
U1 = 101*Mod(ReU1,ImU1)/45;
izmer[40]= U1>>8;
izmer[41]= U1;

ReU2 = ReUa/3 - ReUb/6 + (ImUb*866)/3000 - ReUc/6 - (ImUc*866)/3000;
ImU2 = ImUa/3 - ImUb/6 - (ReUb*866)/3000 - ImUc/6 + (ReUc*866)/3000;
U2 = 101*Mod(ReU2,ImU2)/45;
izmer[42]= U2>>8;
izmer[43]= U2;	
	
//-------------------
Re_Uab=ReUa-ReUb;		  Im_Uab=ImUa-ImUb;//
Re_Ubc=ReUb-ReUc;			Im_Ubc=ImUb-ImUc;//
Re_Uca=ReUc-ReUa;			Im_Uca=ImUc-ImUa;//
	
Re_Iab=ReIa-ReIb;			Im_Iab=ImIa-ImIb;//
Re_Ibc=ReIb-ReIc;			Im_Ibc=ImIb-ImIc;//
Re_Ica=ReIc-ReIa;			Im_Ica=ImIc-ImIa;//

//Zab===============
zn2=Re_Iab*Re_Iab+Im_Iab*Im_Iab;
Re_Zab=(Re_Uab*Re_Iab + Im_Uab*Im_Iab)/zn2;
Im_Zab=(Im_Uab*Re_Iab - Re_Uab*Im_Iab)/zn2;
anglIab=arctg(Re_Iab,Im_Iab);
arcZab=arcF_Uab-anglIab;
Iab = my_sqrt(Re_Iab,Im_Iab);
if(Iab>Ing){Zab=2595*Uab/Iab/10;}
else{Zab=0xFFFFFFFF;}
izmer[53]= Zab>>16;
izmer[54]= Zab>>8;
izmer[55]= Zab;
//Zbc===============
zn2=Re_Ibc*Re_Ibc+Im_Ibc*Im_Ibc;	
Re_Zbc=(Re_Ubc*Re_Ibc + Im_Ubc*Im_Ibc)/zn2;
Im_Zbc=(Im_Ubc*Re_Ibc - Re_Ubc*Im_Ibc)/zn2;
anglIbc=arctg(Re_Ibc,Im_Ibc);
arcZbc=arcF_Ubc-anglIbc;
Ibc = my_sqrt(Re_Ibc,Im_Ibc);
if(Ibc>Ing){Zbc=2595*Ubc/Ibc/10;}
else{Zbc=0xFFFFFFFF;}
izmer[56]= Zbc>>16;
izmer[57]= Zbc>>8;
izmer[58]= Zbc;
//Zca===============
zn2=Re_Ica*Re_Ica+Im_Ica*Im_Ica;	
Re_Zca=(Re_Uca*Re_Ica + Im_Uca*Im_Ica)/zn2;
Im_Zca=(Im_Uca*Re_Ica - Re_Uca*Im_Ica)/zn2;
anglIca=arctg(Re_Ica,Im_Ica);
arcZca=arcF_Uca-anglIca;
Ica = my_sqrt(Re_Ica,Im_Ica);
if(Ica>Ing){Zca=2595*Uca/Ica/10;}
else{Zca=0xFFFFFFFF;}
izmer[59]= Zca>>16;
izmer[60]= Zca>>8;
izmer[61]= Zca;

//ZZp_0p------
//if (1000*I3o_p >= Ing)
ZZp_0p=2672*U3o_i/I3o_p;
//else{ZZp_0p=0xFFFFFFFF;}
izmer[71]= ZZp_0p>>16;
izmer[72]= ZZp_0p>>8;
izmer[73]= ZZp_0p;

//==================
//Za0-------
ReIZa=ReIa+Kkft*Re_I3o_p/3;
ImIZa=ImIa+Kkft*Im_I3o_p/3;
IZa = my_sqrt(ReIZa,ImIZa);
ang_Za0 = arctg(ReIZa,ImIZa);
arcZa0=arcF_Ua-ang_Za0;
if((IZa>Ing)&&(Ia>Ing)){Za0=2595*Ua/IZa/10;}
else{Za0=0xFFFFFFFF;}
izmer[62]= Za0>>16;
izmer[63]= Za0>>8;
izmer[64]= Za0;
}
//=========================================================
//=========================================================
//=========================================================
void	mat_potok_4 (void)
{

//Zb0------
ReIZb=ReIb+Kkft*Re_I3o_p/3;
ImIZb=ImIb+Kkft*Im_I3o_p/3;
IZb = my_sqrt(ReIZb,ImIZb);
ang_Zb0 = arctg(ReIZb,ImIZb);
arcZb0=arcF_Ub-ang_Zb0;
if((IZb>Ing)&&(Ib>Ing)){Zb0=2595*Ub/IZb/10;}
else{Zb0=0xFFFFFFFF;}
izmer[65]= Zb0>>16;
izmer[66]= Zb0>>8;
izmer[67]= Zb0;
//Zc0------
ReIZc=ReIc+Kkft*Re_I3o_p/3;
ImIZc=ImIc+Kkft*Im_I3o_p/3;
IZc = my_sqrt(ReIZc,ImIZc);
ang_Zc0 = arctg(ReIZc,ImIZc);
arcZc0=arcF_Uc-ang_Zc0;
if((IZc>Ing)&&(Ic>Ing)){Zc0=2595*Uc/IZc/10;}
else{Zc0=0xFFFFFFFF;}
izmer[68]= Zc0>>16;
izmer[69]= Zc0>>8;
izmer[70]= Zc0;	
	
//------------------------------------
//F_Zab------
F_Zab = arcZab;	
if (Zab == 0xFFFFFFFF) {F_Zab=0xFFFFFFFF;}
if (Zab == 0) {F_Zab=0xFFFFFFFF;}
if(F_Zab<0){F_Zab = F_Zab+1800;}
if((Uab>=Ung)&&(Iab>=Ing)){F_Zab=F_Zab/10;}
else{F_Zab=0xFFFFFFFF;}
izmer[82]= F_Zab>>8;
izmer[83]= F_Zab;
//------------------------------------
//F_Zbc-----
F_Zbc = arcZbc;
if (Zbc == 0xFFFFFFFF) {F_Zbc=0xFFFFFFFF;}
if (Zbc == 0) {F_Zbc=0xFFFFFFFF;}	
if(F_Zbc<0){F_Zbc = F_Zbc+1800;}
if((Ubc>=Ung)&&(Ibc>=Ing)){F_Zbc=F_Zbc/10;}
else{F_Zbc=0xFFFFFFFF;}	
izmer[84]= F_Zbc>>8;
izmer[85]= F_Zbc;
//------------------------------------
//F_Zca-----
F_Zca = arcZca;
if (Zca == 0xFFFFFFFF) {F_Zca=0xFFFFFFFF;}
if (Zca == 0) {F_Zca=0xFFFFFFFF;}	
if(F_Zca<0){F_Zca = F_Zca+1800;}
if((Uca>=Ung)&&(Ica>=Ing)){F_Zca=F_Zca/10;}
else{F_Zca=0xFFFFFFFF;}	
izmer[86]= F_Zca>>8;
izmer[87]= F_Zca;

//=========================================
//F_Za0-----
F_Za0 = arcZa0;	
if (Za0 == 0xFFFFFFFF) {F_Za0=0xFFFFFFFF;}
if (Za0 == 0) {F_Za0=0xFFFFFFFF;}	
if(F_Za0<0){F_Za0=F_Za0+1800;}
if((Ua>Ung)&&(IZa>Ing)){F_Za0=F_Za0/10;}
else{F_Za0=0xFFFFFFFF;}	
if(Ia<Ing){F_Za0=0xFFFFFFFF;}
izmer[88]= F_Za0>>8;
izmer[89]= F_Za0;
//-------------------------------------
//F_Zb0-----
F_Zb0 = arcZb0;
if (Zb0 == 0xFFFFFFFF) {F_Zb0=0xFFFFFFFF;}
if (Zb0== 0) {F_Zb0=0xFFFFFFFF;}
if(F_Zb0<0){F_Zb0=F_Zb0+1800;}
if((Ub>Ung)&&(IZb>Ing)){F_Zb0=F_Zb0/10;}
else{F_Zb0=0xFFFFFFFF;}	
if(Ib<Ing){F_Za0=0xFFFFFFFF;}
izmer[90]= F_Zb0>>8;
izmer[91]= F_Zb0;
//-------------------------------------
//F_Zc0-----
F_Zc0 = arcZc0;
if (Zc0 == 0xFFFFFFFF) {F_Zc0=0xFFFFFFFF;}
if (Zc0== 0) {F_Zc0=0xFFFFFFFF;}	
if(F_Zc0<0){F_Zc0=F_Zc0+1800;}
if((Uc>Ung)&&(IZc>Ing)){F_Zc0=F_Zc0/10;}
else{F_Zc0=0xFFFFFFFF;}	
if(Ic<Ing){F_Za0=0xFFFFFFFF;}
izmer[92]= F_Zc0>>8;
izmer[93]= F_Zc0;

//F_I3o_p-----
if	(I3o_p >= Ing)
{	
F_I3o_p = arcI3o_p;	
if (I3o_p == 0xFFFFFFFF) {F_I3o_p=0xFFFFFFFF;}
if (I3o_p== 0) {F_I3o_p=0xFFFFFFFF;}	
//if((Re_I3o_p==0)&&(Im_I3o_p>0)) {F_I3o_p=900;}
//if((Re_I3o_p==0)&&(Im_I3o_p<0)) {F_I3o_p=-900;}
//if((Re_I3o_p>0)&&(Im_I3o_p==0)) {F_I3o_p=0;}
//if((Re_I3o_p<0)&&(Im_I3o_p==0)) {F_I3o_p=1800;}
//if((Re_I3o_p==0)&&(Im_I3o_p==0)) {F_I3o_p=0xFFFFFFFF;}
if((Re_I3o_p<0)&&(Im_I3o_p>0))	{F_I3o_p = arcI3o_p + 1800;}
if((Re_I3o_p<0)&&(Im_I3o_p<0)) 	{F_I3o_p = arcI3o_p - 1800;}
}	
else	F_I3o_p=0xFFFFFFFF;	
//============================================
//F_Ia------
F_Ia = arcF_Ia;
if (Ia == 0xFFFFFFFF) {F_Ia=0xFFFFFFFF;}
if (Ia == 0) {F_Ia=0xFFFFFFFF;}
//if((ReIa==0)&&(ImIa>0)) {F_Ia=900;}
//if((ReIa==0)&&(ImIa<0)) {F_Ia=-900;}
//if((ReIa>0)&&(ImIa==0)) {F_Ia=0;}
//if((ReIa<0)&&(ImIa==0)) {F_Ia=1800;}
//if((ReIa==0)&&(ImIa==0)) {F_Ia=0xFFFFFFFF;}
if((ReIa<0)&&(ImIa>0))	{F_Ia = arcF_Ia + 1800;}
if((ReIa<0)&&(ImIa<0)) 	{F_Ia = arcF_Ia - 1800;}
//--------------------------------------------
//F_Ib------
F_Ib = arcF_Ib;
if (Ib == 0xFFFFFFFF) {F_Ib=0xFFFFFFFF;}
if (Ib == 0) {F_Ib=0xFFFFFFFF;}
//if((ReIb==0)&&(ImIb>0)) {F_Ib=900;}
//if((ReIb==0)&&(ImIb<0)) {F_Ib=-900;}
//if((ReIb>0)&&(ImIb==0)) {F_Ib=0;}
//if((ReIb<0)&&(ImIb==0)) {F_Ib=1800;}
//if((ReIb==0)&&(ImIb==0)) {F_Ib=0xFFFFFFFF;}
if((ReIb<0)&&(ImIb>0))	{F_Ib = arcF_Ib + 1800;}
if((ReIb<0)&&(ImIb<0)) 	{F_Ib = arcF_Ib - 1800;}
//--------------------------------------------
//F_Ic------
F_Ic = arcF_Ic;
if (Ic == 0xFFFFFFFF) {F_Ic=0xFFFFFFFF;}
if (Ic == 0) {F_Ic=0xFFFFFFFF;}
//if((ReIc==0)&&(ImIc>0)) {F_Ic=900;}
//if((ReIc==0)&&(ImIc<0)) {F_Ic=-900;}
//if((ReIc>0)&&(ImIc==0)) {F_Ic=0;}
//if((ReIc<0)&&(ImIc==0)) {F_Ic=1800;}
//if((ReIc==0)&&(ImIc==0)) {F_Ic=0xFFFFFFFF;}
if((ReIc<0)&&(ImIc>0))	{F_Ic = arcF_Ic + 1800;}
if((ReIc<0)&&(ImIc<0)) 	{F_Ic = arcF_Ic - 1800;}
//====================================================
//F_Ua------
F_Ua = arcF_Ua;
if (Ua == 0xFFFFFFFF) {F_Ua=0xFFFFFFFF;}
if (Ua == 0) {F_Ua=0xFFFFFFFF;}
//if((ReUa==0)&&(ImUa>0)) {F_Ua=900;}
//if((ReUa==0)&&(ImUa<0)) {F_Ua=-900;}
//if((ReUa>0)&&(ImUa==0)) {F_Ua=0;}
//if((ReUa<0)&&(ImUa==0)) {F_Ua=1800;}
//if((ReUa==0)&&(ImUa==0)) {F_Ua=0xFFFFFFFF;}
if((ReUa<0)&&(ImUa>0))	{F_Ua = arcF_Ua + 1800;}
if((ReUa<0)&&(ImUa<0)) 	{F_Ua = arcF_Ua - 1800;}
//--------------------------------------------
//F_Ub------
F_Ub = arcF_Ub;
if (Ub == 0xFFFFFFFF) {F_Ub=0xFFFFFFFF;}
if (Ub == 0) {F_Ub=0xFFFFFFFF;}
//if((ReUb==0)&&(ImUb>0)) {F_Ub=900;}
//if((ReUb==0)&&(ImUb<0)) {F_Ub=-900;}
//if((ReUb>0)&&(ImUb==0)) {F_Ub=0;}
//if((ReUb<0)&&(ImUb==0)) {F_Ub=1800;}
//if((ReUb==0)&&(ImUb==0)) {F_Ub=0xFFFFFFFF;}
if((ReUb<0)&&(ImUb>0))	{F_Ub = arcF_Ub + 1800;}
if((ReUb<0)&&(ImUb<0)) 	{F_Ub = arcF_Ub - 1800;}
//--------------------------------------------
//F_Uc------
F_Uc = arcF_Uc;	
if (Uc == 0xFFFFFFFF) {F_Uc=0xFFFFFFFF;}
if (Uc == 0) {F_Uc=0xFFFFFFFF;}
//if((ReUc==0)&&(ImUc>0)) {F_Uc=900;}
//if((ReUc==0)&&(ImUc<0)) {F_Uc=-900;}
//if((ReUc>0)&&(ImUc==0)) {F_Uc=0;}
//if((ReUc<0)&&(ImUc==0)) {F_Uc=1800;}
//if((ReUc==0)&&(ImUc==0)) {F_Uc=0xFFFFFFFF;}
if((ReUc<0)&&(ImUc>0))	{F_Uc = arcF_Uc + 1800;}
if((ReUc<0)&&(ImUc<0)) 	{F_Uc = arcF_Uc - 1800;}	
//F_Uc------
F_Uad = arcF_Uad;	
if (Uad == 0xFFFFFFFF) {F_Uad=0xFFFFFFFF;}
if (Uad == 0) {F_Uad=0xFFFFFFFF;}
//if((ReUad==0)&&(ImUad>0)) {F_Uad=900;}
//if((ReUad==0)&&(ImUad<0)) {F_Uad=-900;}
//if((ReUad>0)&&(ImUad==0)) {F_Uad=0;}
//if((ReUad<0)&&(ImUad==0)) {F_Uad=1800;}
//if((ReUad==0)&&(ImUad==0)) {F_Uad=0xFFFFFFFF;}
if((ReUad<0)&&(ImUad>0))	{F_Uad = arcF_Uad + 1800;}
if((ReUad<0)&&(ImUad<0)) 	{F_Uad = arcF_Uad - 1800;}
//===================================================
//F_Uab------
F_Uab = arcF_Uab;
if (Uab == 0xFFFFFFFF) {F_Uab=0xFFFFFFFF;}
if (Uab == 0) {F_Uab=0xFFFFFFFF;}
//if((Re_Uab==0)&&(Im_Uab>0)) {F_Uab=900;}
//if((Re_Uab==0)&&(Im_Uab<0)) {F_Uab=-900;}
//if((Re_Uab>0)&&(Im_Uab==0)) {F_Uab=0;}
//if((Re_Uab<0)&&(Im_Uab==0)) {F_Uab=1800;}
//if((Re_Uab==0)&&(Im_Uab==0)) {F_Uab=0xFFFFFFFF;}
if((Re_Uab<0)&&(Im_Uab>0))	{F_Uab = F_Uab + 1800;}
if((Re_Uab<0)&&(Im_Uab<0)) 	{F_Uab = F_Uab - 1800;}
//--------------------------------------------
//F_Ubc------
F_Ubc = arcF_Ubc;
if (Ubc == 0xFFFFFFFF) {F_Ubc=0xFFFFFFFF;}
if (Ubc == 0) {F_Ubc=0xFFFFFFFF;}
//if((Re_Ubc==0)&&(Im_Ubc>0)) {F_Ubc=900;}
//if((Re_Ubc==0)&&(Im_Ubc<0)) {F_Ubc=-900;}
//if((Re_Ubc>0)&&(Im_Ubc==0)) {F_Ubc=0;}
//if((Re_Ubc<0)&&(Im_Ubc==0)) {F_Ubc=1800;}
//if((Re_Ubc==0)&&(Im_Ubc==0)) {F_Ubc=0xFFFFFFFF;}
if((Re_Ubc<0)&&(Im_Ubc>0))	{F_Ubc = F_Ubc + 1800;}
if((Re_Ubc<0)&&(Im_Ubc<0)) 	{F_Ubc = F_Ubc - 1800;}
//--------------------------------------------
//F_Uca------
F_Uca = arcF_Uca;
if (Uca == 0xFFFFFFFF) {F_Uca=0xFFFFFFFF;}
if (Uca == 0) {F_Uca=0xFFFFFFFF;}
//if((Re_Uca==0)&&(Im_Uca>0)) {F_Uca=900;}
//if((Re_Uca==0)&&(Im_Uca<0)) {F_Uca=-900;}
//if((Re_Uca>0)&&(Im_Uca==0)) {F_Uca=0;}
//if((Re_Uca<0)&&(Im_Uca==0)) {F_Uca=1800;}
//if((Re_Uca==0)&&(Im_Uca==0)) {F_Uca=0xFFFFFFFF;}
if((Re_Uca<0)&&(Im_Uca>0))	{F_Uca = F_Uca + 1800;}
if((Re_Uca<0)&&(Im_Uca<0)) 	{F_Uca = F_Uca - 1800;}
//=====================================================
//F_Ia_Ubc-----
if ((Ubc>=Ung)&&(Ia>=Ing))
{F_Ia_Ubc=F_Ubc-F_Ia+900;}
else	{F_Ia_Ubc=0xFFFFFFFF;}
//F_Ib_Uca-----
if ((Uca>=Ung)&&(Ib>=Ing))
{F_Ib_Uca=F_Uca-F_Ib+900;}
else	{F_Ia_Ubc=0xFFFFFFFF;}
//F_Ic_Uab-----
if ((Uab>=Ung)&&(Ic>=Ing))
{F_Ic_Uab=F_Uab-F_Ic+900;}
else	{F_Ic_Uab=0xFFFFFFFF;}
//-------------------------------
//F_U3o_i-------
if	(U3o_i>=Ung)
{
F_U3o_i = arcF_U3o_i;
if (U3o_i == 0xFFFFFFFF) {F_U3o_i=0xFFFFFFFF;}
if (U3o_i == 0) {F_U3o_i=0xFFFFFFFF;}
//if((ReU3o_i==0)&&(ImU3o_i>0)) {F_U3o_i=900;}
//if((ReU3o_i==0)&&(ImU3o_i<0)) {F_U3o_i=-900;}
//if((ReU3o_i>0)&&(ImU3o_i==0)) {F_U3o_i=0;}
//if((ReU3o_i<0)&&(ImU3o_i==0)) {F_U3o_i=1800;}
//if((ReU3o_i==0)&&(ImU3o_i==0)) {F_U3o_i=0xFFFFFFFF;}
if((ReU3o_i<0)&&(ImU3o_i>0))	{F_U3o_i = F_U3o_i + 1800;}
if((ReU3o_i<0)&&(ImU3o_i<0)) 	{F_U3o_i = F_U3o_i - 1800;}
}
else	{F_U3o_i=0xFFFFFFFF;}
izmer[21]= F_U3o_i/10>>8;
izmer[22]= F_U3o_i/10;
//--------------------------------------
//F_I3op_U3oi------
F_I3op_U3oi=F_U3o_i-F_I3o_p;
if(F_I3op_U3oi<0){
F_I3op_U3oi=1800+F_I3op_U3oi;}
F_I3op_U3oi=F_U3o_i-F_I3o_p;
//if  ((U3o_i>=Ung)&&(I3o_i>=Ing))
//{F_I3op_U3oi=0xFFFFFFFF;}

//--------------------------------------
baz=F_Ua;
//F_Ua=0;
//--------------------------------------
FB_Ia=F_Ia-baz;
if(FB_Ia<0){FB_Ia=FB_Ia+3600;}
izmer[23]= FB_Ia/10>>8;
izmer[24]= FB_Ia/10;

FB_Ib=F_Ib-baz;
if(FB_Ib<0){FB_Ib=FB_Ib+3600;}
izmer[25]= FB_Ib/10>>8;
izmer[26]= FB_Ib/10;

FB_Ic=F_Ic-baz;
if(FB_Ic<0){FB_Ic=FB_Ic+3600;}
izmer[27]= FB_Ic/10>>8;
izmer[28]= FB_Ic/10;

FB_Ua=F_Ua-baz;
if(FB_Ua<0){FB_Ua=FB_Ua+3600;}
izmer[15]= FB_Ua/10>>8;
izmer[16]= FB_Ua/10;

FB_Ub=F_Ub-baz;
if(FB_Ub<0){FB_Ub=FB_Ub+3600;}
izmer[17]= FB_Ub/10>>8;
izmer[18]= FB_Ub/10;

FB_Uc=F_Uc-baz;
if(FB_Uc<0){FB_Uc=FB_Uc+3600;}
izmer[19]= FB_Uc/10>>8;
izmer[20]= FB_Uc/10;

FB_U3o_i=F_U3o_i-baz;
if(FB_U3o_i<0){FB_U3o_i=FB_U3o_i+3600;}
izmer[21]= FB_U3o_i/10>>8;
izmer[22]= FB_U3o_i/10;

FB_Uad=F_Uad-baz;
if(FB_Uad<0){FB_Uad=FB_Uad+3600;}
izmer[99]= FB_Uad/10>>8;
izmer[100]= FB_Uad/10;


FB_Uab=F_Uab-baz;
if(FB_Uab<0){FB_Uab=FB_Uab+3600;}
izmer[74]= FB_Uab/10>>8;
izmer[75]= FB_Uab/10;

FB_Ubc=F_Ubc-baz;
if(FB_Ubc<0){FB_Ubc=FB_Ubc+3600;}
izmer[76]= FB_Ubc/10>>8;
izmer[77]= FB_Ubc/10;

FB_Uca=F_Uca-baz;
if(FB_Uca<0){FB_Uca=FB_Uca+3600;}
izmer[78]= FB_Uca/10>>8;
izmer[79]= FB_Uca/10;

FB_I3o_p=F_I3o_p-baz;
if(FB_I3o_p<0){FB_I3o_p=FB_I3o_p+3600;}
izmer[80]= FB_I3o_p/10>>8;
izmer[81]= FB_I3o_p/10;	

FB_I3o_p=F_I3o_p-baz;
if(F_I3op_U3oi<0){F_I3op_U3oi=F_I3op_U3oi+3600;}
izmer[94]= F_I3op_U3oi/10>>8;
izmer[95]= F_I3op_U3oi/10;
}
//==========================================
//==========================================
//==========================================
void	mat_potok_all (void)
{
zzz1 = DWT_CYCCNT;
//arcF_Ia=arctg1(ReIa,ImIa);		
//bbz0=arctangens(ReIa,ImIa);	
	
arcF_Ia=arctg(ReIa,ImIa);	
zzz2 = DWT_CYCCNT-zzz1;		
Ia=985*my_sqrt(ReIa,ImIa)/1000;	
izmer[9]= Ia>>8;
izmer[10]= Ia;	

arcF_Ib=arctg(ReIb,ImIb);		
Ib=985*my_sqrt(ReIb,ImIb)/1000;	
izmer[11]= Ib>>8;
izmer[12]= Ib;		

arcF_Ic=arctg(ReIc,ImIc);	
Ic=985*my_sqrt(ReIc,ImIc)/1000;
izmer[13]= Ic>>8;
izmer[14]= Ic;	
	
//==================================
Ua=9975*my_sqrt(ReUa,ImUa)/4500;			
arcF_Ua=arctg(ReUa,ImUa);
izmer[0]= Ua>>8;
izmer[1]= Ua;
//==================================
Ub=9975*my_sqrt(ReUb,ImUb)/4500;
arcF_Ub=arctg(ReUb,ImUb);
izmer[2]= Ub>>8;
izmer[3]= Ub;
	
Uc=9975*my_sqrt(ReUc,ImUc)/4500;
arcF_Uc=arctg(ReUc,ImUc);
izmer[4]= Uc>>8;
izmer[5]= Uc;			
	
Uad=2*my_sqrt(ReUad,ImUad);
arcF_Uad=arctg(ReUad,ImUad);
izmer[96]= Uad>>16;
izmer[97]= Uad>>8;
izmer[98]= Uad;	
	
Ia_2g=Mod(ReIa_2g,ImIa_2g);			
Ib_2g=Mod(ReIb_2g,ImIb_2g);		
Ic_2g=Mod(ReIc_2g,ImIc_2g);			

U3o_i=my_sqrt(ReU3o_i,ImU3o_i);
arcF_U3o_i=arctg(ReU3o_i,ImU3o_i);
izmer[6]= U3o_i>>24;
izmer[7]= U3o_i>>16;
izmer[8]= U3o_i>>8;	

if	(Ia>ING)  
{Ia_2_1g = Ia_2g*100/Ia;}
else	{Ia_2_1g=0;}
izmer[50]= Ia_2_1g;

if	(Ib>ING)  
{Ib_2_1g = Ib_2g*100/Ib;}
else	{Ib_2_1g=0;}
izmer[51]= Ib_2_1g;

if	(Ic>ING)  
{Ic_2_1g = Ic_2g*100/Ic;}
else	{Ic_2_1g=0;}
izmer[52]= Ic_2_1g;


Re_I3o_p	=	ReIa + ReIb + ReIc;
Im_I3o_p	=	ImIa + ImIb + ImIc;
I3o_p = (1000*my_sqrt(Re_I3o_p,Im_I3o_p)/1414);
arcI3o_p=arctg(Re_I3o_p,Im_I3o_p);
//arcI3o_p=arcF_Ia+arcF_Ib+arcF_Ic;
if (I3o_p >= 0x960000){I3o_p=0x960000;}
izmer[44]= I3o_p>>8;
izmer[45]= I3o_p;

Re_Uab=ReUa-ReUb;		Im_Uab=ImUa-ImUb; 
Uab=9975*my_sqrt(Re_Uab,Im_Uab)/4500;
if (Uab>>24!=0){Uab=0xFEFFFF;}
arcF_Uab=arctg(Re_Uab,Im_Uab);
izmer[32]= Uab>>8;
izmer[33]= Uab;	

Re_Ubc=ReUb-ReUc;		Im_Ubc=ImUb-ImUc; 
Ubc=9975*my_sqrt(Re_Ubc,Im_Ubc)/4500;
if (Ubc>>24!=0){Ubc=0xFEFFFF;}
arcF_Ubc=arctg(Re_Ubc,Im_Ubc);
izmer[34]= Ubc>>8;
izmer[35]= Ubc;

Re_Uca=ReUc-ReUa;		Im_Uca=ImUc-ImUa; 
Uca=9975*my_sqrt(Re_Uca,Im_Uca)/4500;
if (Uca>>24!=0){Uca=0xFEFFFF;}
arcF_Uca=arctg(Re_Uca,Im_Uca);
izmer[36]= Uca>>8;
izmer[37]= Uca;

Re_Ubnn = Ktn*(2*ReUa+ReUb+ReUc)-Ktn0*(ReUad+ReU3o_i);
Im_Ubnn = Ktn*(2*ImUa+ImUb+ImUc)-Ktn0*(ImUad+ImU3o_i);
Ubnn = Mod(Re_Ubnn,Im_Ubnn);
Ubnn = my_sqrt(Re_Ubnn,Im_Ubnn);
if (Ubnn>>24!=0){Ubnn=0xFEFFFF;}
izmer[38]= Ubnn>>8;
izmer[39]= Ubnn;

ReI1 = ReIa/3 - ReIb/6 - (ImIb*866)/3000 - ReIc/6 + (ImIc*866)/3000;
ImI1 = ImIa/3 - ImIb/6 + (ReIb*866)/3000 - ImIc/6 - (ReIc*866)/3000;
I1 = 50*Mod(ReI1,ImI1)/45;
izmer[46]= I1>>8;
izmer[47]= I1;

Delta_I1  = I1 - MemDel_I1;
MemDel_I1 = I1;

ReI2 = ReIa/3 - ReIb/6 + (ImIb*866)/3000 - ReIc/6 - (ImIc*866)/3000;
ImI2 = ImIa/3 - ImIb/6 - (ReIb*866)/3000 - ImIc/6 + (ReIc*866)/3000;
I2 = 50*Mod(ReI2,ImI2)/45;
izmer[48]= I2>>8;
izmer[49]= I2;

Delta_I2 = I2 - MemDel_I2;
MemDel_I2 = I2;

ReU1 = ReUa/3 - ReUb/6 - (ImUb*866)/3000 - ReUc/6 + (ImUc*866)/3000;
ImU1 = ImUa/3 - ImUb/6 + (ReUb*866)/3000 - ImUc/6 - (ReUc*866)/3000;
U1 = 101*Mod(ReU1,ImU1)/45;
izmer[40]= U1>>8;
izmer[41]= U1;

ReU2 = ReUa/3 - ReUb/6 + (ImUb*866)/3000 - ReUc/6 - (ImUc*866)/3000;
ImU2 = ImUa/3 - ImUb/6 - (ReUb*866)/3000 - ImUc/6 + (ReUc*866)/3000;
U2 = 101*Mod(ReU2,ImU2)/45;
izmer[42]= U2>>8;
izmer[43]= U2;	
	
//-------------------
Re_Uab=ReUa-ReUb;		  Im_Uab=ImUa-ImUb;//
Re_Ubc=ReUb-ReUc;			Im_Ubc=ImUb-ImUc;//
Re_Uca=ReUc-ReUa;			Im_Uca=ImUc-ImUa;//
	
Re_Iab=ReIa-ReIb;			Im_Iab=ImIa-ImIb;//
Re_Ibc=ReIb-ReIc;			Im_Ibc=ImIb-ImIc;//
Re_Ica=ReIc-ReIa;			Im_Ica=ImIc-ImIa;//

//Zab===============
zn2=Re_Iab*Re_Iab+Im_Iab*Im_Iab;
Re_Zab=(Re_Uab*Re_Iab + Im_Uab*Im_Iab)/zn2;
Im_Zab=(Im_Uab*Re_Iab - Re_Uab*Im_Iab)/zn2;
anglIab=arctg(Re_Iab,Im_Iab);
arcZab=arcF_Uab-anglIab;
Iab = my_sqrt(Re_Iab,Im_Iab);
if(Iab>Ing){Zab=2595*Uab/Iab/10;}
else{Zab=0xFFFFFFFF;}
izmer[53]= Zab>>16;
izmer[54]= Zab>>8;
izmer[55]= Zab;
//Zbc===============
zn2=Re_Ibc*Re_Ibc+Im_Ibc*Im_Ibc;	
Re_Zbc=(Re_Ubc*Re_Ibc + Im_Ubc*Im_Ibc)/zn2;
Im_Zbc=(Im_Ubc*Re_Ibc - Re_Ubc*Im_Ibc)/zn2;
anglIbc=arctg(Re_Ibc,Im_Ibc);
arcZbc=arcF_Ubc-anglIbc;
Ibc = my_sqrt(Re_Ibc,Im_Ibc);
if(Ibc>Ing){Zbc=2595*Ubc/Ibc/10;}
else{Zbc=0xFFFFFFFF;}
izmer[56]= Zbc>>16;
izmer[57]= Zbc>>8;
izmer[58]= Zbc;
//Zca===============
zn2=Re_Ica*Re_Ica+Im_Ica*Im_Ica;	
Re_Zca=(Re_Uca*Re_Ica + Im_Uca*Im_Ica)/zn2;
Im_Zca=(Im_Uca*Re_Ica - Re_Uca*Im_Ica)/zn2;
anglIca=arctg(Re_Ica,Im_Ica);
arcZca=arcF_Uca-anglIca;
Ica = my_sqrt(Re_Ica,Im_Ica);
if(Ica>Ing){Zca=2595*Uca/Ica/10;}
else{Zca=0xFFFFFFFF;}
izmer[59]= Zca>>16;
izmer[60]= Zca>>8;
izmer[61]= Zca;

//ZZp_0p------
//if (1000*I3o_p >= Ing)
ZZp_0p=2672*U3o_i/I3o_p;
//else{ZZp_0p=0xFFFFFFFF;}
izmer[71]= ZZp_0p>>16;
izmer[72]= ZZp_0p>>8;
izmer[73]= ZZp_0p;

//==================
//Za0-------
ReIZa=ReIa+Kkft*Re_I3o_p/3;
ImIZa=ImIa+Kkft*Im_I3o_p/3;
IZa = my_sqrt(ReIZa,ImIZa);
ang_Za0 = arctg(ReIZa,ImIZa);
arcZa0=arcF_Ua-ang_Za0;
if((IZa>Ing)&&(Ia>Ing)){Za0=2595*Ua/IZa/10;}
else{Za0=0xFFFFFFFF;}
izmer[62]= Za0>>16;
izmer[63]= Za0>>8;
izmer[64]= Za0;

//Zb0------
ReIZb=ReIb+Kkft*Re_I3o_p/3;
ImIZb=ImIb+Kkft*Im_I3o_p/3;
IZb = my_sqrt(ReIZb,ImIZb);
ang_Zb0 = arctg(ReIZb,ImIZb);
arcZb0=arcF_Ub-ang_Zb0;
if((IZb>Ing)&&(Ib>Ing)){Zb0=2595*Ub/IZb/10;}
else{Zb0=0xFFFFFFFF;}
izmer[65]= Zb0>>16;
izmer[66]= Zb0>>8;
izmer[67]= Zb0;
//Zc0------
ReIZc=ReIc+Kkft*Re_I3o_p/3;
ImIZc=ImIc+Kkft*Im_I3o_p/3;
IZc = my_sqrt(ReIZc,ImIZc);
ang_Zc0 = arctg(ReIZc,ImIZc);
arcZc0=arcF_Uc-ang_Zc0;
if((IZc>Ing)&&(Ic>Ing)){Zc0=2595*Uc/IZc/10;}
else{Zc0=0xFFFFFFFF;}
izmer[68]= Zc0>>16;
izmer[69]= Zc0>>8;
izmer[70]= Zc0;	
	
//------------------------------------
//F_Zab------
F_Zab = arcZab;	
if (Zab == 0xFFFFFFFF) {F_Zab=0xFFFFFFFF;}
if (Zab == 0) {F_Zab=0xFFFFFFFF;}
if(F_Zab<0){F_Zab = F_Zab+1800;}
if((Uab>=Ung)&&(Iab>=Ing)){F_Zab=F_Zab/10;}
else{F_Zab=0xFFFFFFFF;}
izmer[82]= F_Zab>>8;
izmer[83]= F_Zab;
//------------------------------------
//F_Zbc-----
F_Zbc = arcZbc;
if (Zbc == 0xFFFFFFFF) {F_Zbc=0xFFFFFFFF;}
if (Zbc == 0) {F_Zbc=0xFFFFFFFF;}	
if(F_Zbc<0){F_Zbc = F_Zbc+1800;}
if((Ubc>=Ung)&&(Ibc>=Ing)){F_Zbc=F_Zbc/10;}
else{F_Zbc=0xFFFFFFFF;}	
izmer[84]= F_Zbc>>8;
izmer[85]= F_Zbc;
//------------------------------------
//F_Zca-----
F_Zca = arcZca;
if (Zca == 0xFFFFFFFF) {F_Zca=0xFFFFFFFF;}
if (Zca == 0) {F_Zca=0xFFFFFFFF;}	
if(F_Zca<0){F_Zca = F_Zca+1800;}
if((Uca>=Ung)&&(Ica>=Ing)){F_Zca=F_Zca/10;}
else{F_Zca=0xFFFFFFFF;}	
izmer[86]= F_Zca>>8;
izmer[87]= F_Zca;

//=========================================
//F_Za0-----
F_Za0 = arcZa0;	
if (Za0 == 0xFFFFFFFF) {F_Za0=0xFFFFFFFF;}
if (Za0 == 0) {F_Za0=0xFFFFFFFF;}	
if(F_Za0<0){F_Za0=F_Za0+1800;}
if((Ua>Ung)&&(IZa>Ing)){F_Za0=F_Za0/10;}
else{F_Za0=0xFFFFFFFF;}	
if(Ia<Ing){F_Za0=0xFFFFFFFF;}
izmer[88]= F_Za0>>8;
izmer[89]= F_Za0;
//-------------------------------------
//F_Zb0-----
F_Zb0 = arcZb0;
if (Zb0 == 0xFFFFFFFF) {F_Zb0=0xFFFFFFFF;}
if (Zb0== 0) {F_Zb0=0xFFFFFFFF;}
if(F_Zb0<0){F_Zb0=F_Zb0+1800;}
if((Ub>Ung)&&(IZb>Ing)){F_Zb0=F_Zb0/10;}
else{F_Zb0=0xFFFFFFFF;}	
if(Ib<Ing){F_Za0=0xFFFFFFFF;}
izmer[90]= F_Zb0>>8;
izmer[91]= F_Zb0;
//-------------------------------------
//F_Zc0-----
F_Zc0 = arcZc0;
if (Zc0 == 0xFFFFFFFF) {F_Zc0=0xFFFFFFFF;}
if (Zc0== 0) {F_Zc0=0xFFFFFFFF;}	
if(F_Zc0<0){F_Zc0=F_Zc0+1800;}
if((Uc>Ung)&&(IZc>Ing)){F_Zc0=F_Zc0/10;}
else{F_Zc0=0xFFFFFFFF;}	
if(Ic<Ing){F_Za0=0xFFFFFFFF;}
izmer[92]= F_Zc0>>8;
izmer[93]= F_Zc0;

//F_I3o_p-----
if	(I3o_p >= Ing)
{	
F_I3o_p = arcI3o_p;	
if (I3o_p == 0xFFFFFFFF) {F_I3o_p=0xFFFFFFFF;}
if (I3o_p== 0) {F_I3o_p=0xFFFFFFFF;}	
//if((Re_I3o_p==0)&&(Im_I3o_p>0)) {F_I3o_p=900;}
//if((Re_I3o_p==0)&&(Im_I3o_p<0)) {F_I3o_p=-900;}
//if((Re_I3o_p>0)&&(Im_I3o_p==0)) {F_I3o_p=0;}
//if((Re_I3o_p<0)&&(Im_I3o_p==0)) {F_I3o_p=1800;}
//if((Re_I3o_p==0)&&(Im_I3o_p==0)) {F_I3o_p=0xFFFFFFFF;}
if((Re_I3o_p<0)&&(Im_I3o_p>0))	{F_I3o_p = arcI3o_p + 1800;}
if((Re_I3o_p<0)&&(Im_I3o_p<0)) 	{F_I3o_p = arcI3o_p - 1800;}
}	
else	F_I3o_p=0xFFFFFFFF;	
//============================================
//F_Ia------
F_Ia = arcF_Ia;
if (Ia == 0xFFFFFFFF) {F_Ia=0xFFFFFFFF;}
if (Ia == 0) {F_Ia=0xFFFFFFFF;}
//if((ReIa==0)&&(ImIa>0)) {F_Ia=900;}
//if((ReIa==0)&&(ImIa<0)) {F_Ia=-900;}
//if((ReIa>0)&&(ImIa==0)) {F_Ia=0;}
//if((ReIa<0)&&(ImIa==0)) {F_Ia=1800;}
//if((ReIa==0)&&(ImIa==0)) {F_Ia=0xFFFFFFFF;}
if((ReIa<0)&&(ImIa>0))	{F_Ia = arcF_Ia + 1800;}
if((ReIa<0)&&(ImIa<0)) 	{F_Ia = arcF_Ia - 1800;}
//--------------------------------------------
//F_Ib------
F_Ib = arcF_Ib;
if (Ib == 0xFFFFFFFF) {F_Ib=0xFFFFFFFF;}
if (Ib == 0) {F_Ib=0xFFFFFFFF;}
//if((ReIb==0)&&(ImIb>0)) {F_Ib=900;}
//if((ReIb==0)&&(ImIb<0)) {F_Ib=-900;}
//if((ReIb>0)&&(ImIb==0)) {F_Ib=0;}
//if((ReIb<0)&&(ImIb==0)) {F_Ib=1800;}
//if((ReIb==0)&&(ImIb==0)) {F_Ib=0xFFFFFFFF;}
if((ReIb<0)&&(ImIb>0))	{F_Ib = arcF_Ib + 1800;}
if((ReIb<0)&&(ImIb<0)) 	{F_Ib = arcF_Ib - 1800;}
//--------------------------------------------
//F_Ic------
F_Ic = arcF_Ic;
if (Ic == 0xFFFFFFFF) {F_Ic=0xFFFFFFFF;}
if (Ic == 0) {F_Ic=0xFFFFFFFF;}
//if((ReIc==0)&&(ImIc>0)) {F_Ic=900;}
//if((ReIc==0)&&(ImIc<0)) {F_Ic=-900;}
//if((ReIc>0)&&(ImIc==0)) {F_Ic=0;}
//if((ReIc<0)&&(ImIc==0)) {F_Ic=1800;}
//if((ReIc==0)&&(ImIc==0)) {F_Ic=0xFFFFFFFF;}
if((ReIc<0)&&(ImIc>0))	{F_Ic = arcF_Ic + 1800;}
if((ReIc<0)&&(ImIc<0)) 	{F_Ic = arcF_Ic - 1800;}
//====================================================
//F_Ua------
F_Ua = arcF_Ua;
if (Ua == 0xFFFFFFFF) {F_Ua=0xFFFFFFFF;}
if (Ua == 0) {F_Ua=0xFFFFFFFF;}
//if((ReUa==0)&&(ImUa>0)) {F_Ua=900;}
//if((ReUa==0)&&(ImUa<0)) {F_Ua=-900;}
//if((ReUa>0)&&(ImUa==0)) {F_Ua=0;}
//if((ReUa<0)&&(ImUa==0)) {F_Ua=1800;}
//if((ReUa==0)&&(ImUa==0)) {F_Ua=0xFFFFFFFF;}
if((ReUa<0)&&(ImUa>0))	{F_Ua = arcF_Ua + 1800;}
if((ReUa<0)&&(ImUa<0)) 	{F_Ua = arcF_Ua - 1800;}
//--------------------------------------------
//F_Ub------
F_Ub = arcF_Ub;
if (Ub == 0xFFFFFFFF) {F_Ub=0xFFFFFFFF;}
if (Ub == 0) {F_Ub=0xFFFFFFFF;}
//if((ReUb==0)&&(ImUb>0)) {F_Ub=900;}
//if((ReUb==0)&&(ImUb<0)) {F_Ub=-900;}
//if((ReUb>0)&&(ImUb==0)) {F_Ub=0;}
//if((ReUb<0)&&(ImUb==0)) {F_Ub=1800;}
//if((ReUb==0)&&(ImUb==0)) {F_Ub=0xFFFFFFFF;}
if((ReUb<0)&&(ImUb>0))	{F_Ub = arcF_Ub + 1800;}
if((ReUb<0)&&(ImUb<0)) 	{F_Ub = arcF_Ub - 1800;}
//--------------------------------------------
//F_Uc------
F_Uc = arcF_Uc;	
if (Uc == 0xFFFFFFFF) {F_Uc=0xFFFFFFFF;}
if (Uc == 0) {F_Uc=0xFFFFFFFF;}
//if((ReUc==0)&&(ImUc>0)) {F_Uc=900;}
//if((ReUc==0)&&(ImUc<0)) {F_Uc=-900;}
//if((ReUc>0)&&(ImUc==0)) {F_Uc=0;}
//if((ReUc<0)&&(ImUc==0)) {F_Uc=1800;}
//if((ReUc==0)&&(ImUc==0)) {F_Uc=0xFFFFFFFF;}
if((ReUc<0)&&(ImUc>0))	{F_Uc = arcF_Uc + 1800;}
if((ReUc<0)&&(ImUc<0)) 	{F_Uc = arcF_Uc - 1800;}	
//F_Uc------
F_Uad = arcF_Uad;	
if (Uad == 0xFFFFFFFF) {F_Uad=0xFFFFFFFF;}
if (Uad == 0) {F_Uad=0xFFFFFFFF;}
//if((ReUad==0)&&(ImUad>0)) {F_Uad=900;}
//if((ReUad==0)&&(ImUad<0)) {F_Uad=-900;}
//if((ReUad>0)&&(ImUad==0)) {F_Uad=0;}
//if((ReUad<0)&&(ImUad==0)) {F_Uad=1800;}
//if((ReUad==0)&&(ImUad==0)) {F_Uad=0xFFFFFFFF;}
if((ReUad<0)&&(ImUad>0))	{F_Uad = arcF_Uad + 1800;}
if((ReUad<0)&&(ImUad<0)) 	{F_Uad = arcF_Uad - 1800;}
//===================================================
//F_Uab------
F_Uab = arcF_Uab;
if (Uab == 0xFFFFFFFF) {F_Uab=0xFFFFFFFF;}
if (Uab == 0) {F_Uab=0xFFFFFFFF;}
//if((Re_Uab==0)&&(Im_Uab>0)) {F_Uab=900;}
//if((Re_Uab==0)&&(Im_Uab<0)) {F_Uab=-900;}
//if((Re_Uab>0)&&(Im_Uab==0)) {F_Uab=0;}
//if((Re_Uab<0)&&(Im_Uab==0)) {F_Uab=1800;}
//if((Re_Uab==0)&&(Im_Uab==0)) {F_Uab=0xFFFFFFFF;}
if((Re_Uab<0)&&(Im_Uab>0))	{F_Uab = F_Uab + 1800;}
if((Re_Uab<0)&&(Im_Uab<0)) 	{F_Uab = F_Uab - 1800;}
//--------------------------------------------
//F_Ubc------
F_Ubc = arcF_Ubc;
if (Ubc == 0xFFFFFFFF) {F_Ubc=0xFFFFFFFF;}
if (Ubc == 0) {F_Ubc=0xFFFFFFFF;}
//if((Re_Ubc==0)&&(Im_Ubc>0)) {F_Ubc=900;}
//if((Re_Ubc==0)&&(Im_Ubc<0)) {F_Ubc=-900;}
//if((Re_Ubc>0)&&(Im_Ubc==0)) {F_Ubc=0;}
//if((Re_Ubc<0)&&(Im_Ubc==0)) {F_Ubc=1800;}
//if((Re_Ubc==0)&&(Im_Ubc==0)) {F_Ubc=0xFFFFFFFF;}
if((Re_Ubc<0)&&(Im_Ubc>0))	{F_Ubc = F_Ubc + 1800;}
if((Re_Ubc<0)&&(Im_Ubc<0)) 	{F_Ubc = F_Ubc - 1800;}
//--------------------------------------------
//F_Uca------
F_Uca = arcF_Uca;
if (Uca == 0xFFFFFFFF) {F_Uca=0xFFFFFFFF;}
if (Uca == 0) {F_Uca=0xFFFFFFFF;}
//if((Re_Uca==0)&&(Im_Uca>0)) {F_Uca=900;}
//if((Re_Uca==0)&&(Im_Uca<0)) {F_Uca=-900;}
//if((Re_Uca>0)&&(Im_Uca==0)) {F_Uca=0;}
//if((Re_Uca<0)&&(Im_Uca==0)) {F_Uca=1800;}
//if((Re_Uca==0)&&(Im_Uca==0)) {F_Uca=0xFFFFFFFF;}
if((Re_Uca<0)&&(Im_Uca>0))	{F_Uca = F_Uca + 1800;}
if((Re_Uca<0)&&(Im_Uca<0)) 	{F_Uca = F_Uca - 1800;}
//=====================================================
//F_Ia_Ubc-----
if ((Ubc>=Ung)&&(Ia>=Ing))
{F_Ia_Ubc=F_Ubc-F_Ia+900;}
else	{F_Ia_Ubc=0xFFFFFFFF;}
//F_Ib_Uca-----
if ((Uca>=Ung)&&(Ib>=Ing))
{F_Ib_Uca=F_Uca-F_Ib+900;}
else	{F_Ia_Ubc=0xFFFFFFFF;}
//F_Ic_Uab-----
if ((Uab>=Ung)&&(Ic>=Ing))
{F_Ic_Uab=F_Uab-F_Ic+900;}
else	{F_Ic_Uab=0xFFFFFFFF;}
//-------------------------------
//F_U3o_i-------
if	(U3o_i>=Ung)
{
F_U3o_i = arcF_U3o_i;
if (U3o_i == 0xFFFFFFFF) {F_U3o_i=0xFFFFFFFF;}
if (U3o_i == 0) {F_U3o_i=0xFFFFFFFF;}
//if((ReU3o_i==0)&&(ImU3o_i>0)) {F_U3o_i=900;}
//if((ReU3o_i==0)&&(ImU3o_i<0)) {F_U3o_i=-900;}
//if((ReU3o_i>0)&&(ImU3o_i==0)) {F_U3o_i=0;}
//if((ReU3o_i<0)&&(ImU3o_i==0)) {F_U3o_i=1800;}
//if((ReU3o_i==0)&&(ImU3o_i==0)) {F_U3o_i=0xFFFFFFFF;}
if((ReU3o_i<0)&&(ImU3o_i>0))	{F_U3o_i = F_U3o_i + 1800;}
if((ReU3o_i<0)&&(ImU3o_i<0)) 	{F_U3o_i = F_U3o_i - 1800;}
}
else	{F_U3o_i=0xFFFFFFFF;}
izmer[21]= F_U3o_i/10>>8;
izmer[22]= F_U3o_i/10;
//--------------------------------------
//F_I3op_U3oi------
F_I3op_U3oi=F_U3o_i-F_I3o_p;
if(F_I3op_U3oi<0){
F_I3op_U3oi=1800+F_I3op_U3oi;}
F_I3op_U3oi=F_U3o_i-F_I3o_p;
//if  ((U3o_i>=Ung)&&(I3o_i>=Ing))
//{F_I3op_U3oi=0xFFFFFFFF;}

//--------------------------------------
baz=F_Ua;
//F_Ua=0;
//--------------------------------------
FB_Ia=F_Ia-baz;
if(FB_Ia<0){FB_Ia=FB_Ia+3600;}
izmer[23]= FB_Ia/10>>8;
izmer[24]= FB_Ia/10;

FB_Ib=F_Ib-baz;
if(FB_Ib<0){FB_Ib=FB_Ib+3600;}
izmer[25]= FB_Ib/10>>8;
izmer[26]= FB_Ib/10;

FB_Ic=F_Ic-baz;
if(FB_Ic<0){FB_Ic=FB_Ic+3600;}
izmer[27]= FB_Ic/10>>8;
izmer[28]= FB_Ic/10;

FB_Ua=F_Ua-baz;
if(FB_Ua<0){FB_Ua=FB_Ua+3600;}
izmer[15]= FB_Ua/10>>8;
izmer[16]= FB_Ua/10;

FB_Ub=F_Ub-baz;
if(FB_Ub<0){FB_Ub=FB_Ub+3600;}
izmer[17]= FB_Ub/10>>8;
izmer[18]= FB_Ub/10;

FB_Uc=F_Uc-baz;
if(FB_Uc<0){FB_Uc=FB_Uc+3600;}
izmer[19]= FB_Uc/10>>8;
izmer[20]= FB_Uc/10;

FB_U3o_i=F_U3o_i-baz;
if(FB_U3o_i<0){FB_U3o_i=FB_U3o_i+3600;}
izmer[21]= FB_U3o_i/10>>8;
izmer[22]= FB_U3o_i/10;

FB_Uad=F_Uad-baz;
if(FB_Uad<0){FB_Uad=FB_Uad+3600;}
izmer[99]= FB_Uad/10>>8;
izmer[100]= FB_Uad/10;


FB_Uab=F_Uab-baz;
if(FB_Uab<0){FB_Uab=FB_Uab+3600;}
izmer[74]= FB_Uab/10>>8;
izmer[75]= FB_Uab/10;

FB_Ubc=F_Ubc-baz;
if(FB_Ubc<0){FB_Ubc=FB_Ubc+3600;}
izmer[76]= FB_Ubc/10>>8;
izmer[77]= FB_Ubc/10;

FB_Uca=F_Uca-baz;
if(FB_Uca<0){FB_Uca=FB_Uca+3600;}
izmer[78]= FB_Uca/10>>8;
izmer[79]= FB_Uca/10;

FB_I3o_p=F_I3o_p-baz;
if(FB_I3o_p<0){FB_I3o_p=FB_I3o_p+3600;}
izmer[80]= FB_I3o_p/10>>8;
izmer[81]= FB_I3o_p/10;	

FB_I3o_p=F_I3o_p-baz;
if(F_I3op_U3oi<0){F_I3op_U3oi=F_I3op_U3oi+3600;}
izmer[94]= F_I3op_U3oi/10>>8;
izmer[95]= F_I3op_U3oi/10;
}
