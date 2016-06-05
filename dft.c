#include <math.h>
#include	"dft24.h"
extern void Delay_mks(__IO uint32_t nTime);
extern	uint32_t ModAngl(int32_t Re,int32_t Im);
uint32_t	ang;
extern	uint32_t	ADC_1[20];

void dft(char adc_ch)
{		
		
my_arr[0]=buffer[(BUF_SIZE-1)&(idxIN-23*8+adc_ch-8)];
my_arr[1]=buffer[(BUF_SIZE-1)&(idxIN-22*8+adc_ch-8)];
my_arr[2]=buffer[(BUF_SIZE-1)&(idxIN-21*8+adc_ch-8)];
my_arr[3]=buffer[(BUF_SIZE-1)&(idxIN-20*8+adc_ch-8)];
my_arr[4]=buffer[(BUF_SIZE-1)&(idxIN-19*8+adc_ch-8)];
my_arr[5]=buffer[(BUF_SIZE-1)&(idxIN-18*8+adc_ch-8)];
my_arr[6]=buffer[(BUF_SIZE-1)&(idxIN-17*8+adc_ch-8)];
my_arr[7]=buffer[(BUF_SIZE-1)&(idxIN-16*8+adc_ch-8)];
my_arr[8]=buffer[(BUF_SIZE-1)&(idxIN-15*8+adc_ch-8)];
my_arr[9]=buffer[(BUF_SIZE-1)&(idxIN-14*8+adc_ch-8)];
my_arr[10]=buffer[(BUF_SIZE-1)&(idxIN-13*8+adc_ch-8)];
my_arr[11]=buffer[(BUF_SIZE-1)&(idxIN-12*8+adc_ch-8)];
my_arr[12]=buffer[(BUF_SIZE-1)&(idxIN-11*8+adc_ch-8)];
my_arr[13]=buffer[(BUF_SIZE-1)&(idxIN-10*8+adc_ch-8)];
my_arr[14]=buffer[(BUF_SIZE-1)&(idxIN-9*8+adc_ch-8)];
my_arr[15]=buffer[(BUF_SIZE-1)&(idxIN-8*8+adc_ch-8)];
my_arr[16]=buffer[(BUF_SIZE-1)&(idxIN-7*8+adc_ch-8)];
my_arr[17]=buffer[(BUF_SIZE-1)&(idxIN-6*8+adc_ch-8)];
my_arr[18]=buffer[(BUF_SIZE-1)&(idxIN-5*8+adc_ch-8)];
my_arr[19]=buffer[(BUF_SIZE-1)&(idxIN-4*8+adc_ch-8)];
my_arr[20]=buffer[(BUF_SIZE-1)&(idxIN-3*8+adc_ch-8)];
my_arr[21]=buffer[(BUF_SIZE-1)&(idxIN-2*8+adc_ch-8)];
my_arr[22]=buffer[(BUF_SIZE-1)&(idxIN-1*8+adc_ch-8)];
my_arr[23]=buffer[(BUF_SIZE-1)&(idxIN-0*8+adc_ch-8)];

//определение амплитуды 1-й гармоники
my_cos1=(259*(my_arr[0]+my_arr[10]-my_arr[12]-my_arr[22])+
			  500*(my_arr[1]+my_arr[9]-my_arr[13]-my_arr[21])+
			  707*(my_arr[2]+my_arr[8]-my_arr[14]-my_arr[20])+
			  866*(my_arr[3]+my_arr[7]-my_arr[15]-my_arr[19])+	
			  966*(my_arr[4]+my_arr[6]-my_arr[16]-my_arr[18])+				
			 1000*my_arr[5]-1000*my_arr[17]);
			
my_sin1=(259*(my_arr[4]-my_arr[6]-my_arr[16]+my_arr[18])+
				500*(my_arr[3]-my_arr[7]-my_arr[15]+my_arr[19])+
				707*(my_arr[2]-my_arr[8]-my_arr[14]+my_arr[20])+
				866*(my_arr[1]-my_arr[9]-my_arr[13]+my_arr[21])+
				966*(my_arr[0]-my_arr[10]-my_arr[12]+my_arr[22])+
				1000*my_arr[23]-1000*my_arr[11]);			
			
			Re1=my_cos1/12000;
			Im1=my_sin1/12000;
		
			//определение амплитуды 2-й гармоники
			
my_cos2=(500*(my_arr[0]+my_arr[4]-my_arr[6]-my_arr[10]+
							my_arr[12]+my_arr[16]-my_arr[18]-my_arr[22])+
				 866*(my_arr[1]+my_arr[3]-my_arr[7]-my_arr[9]+		
							my_arr[13]+my_arr[15]-my_arr[19]-my_arr[21])+
			  1000*(my_arr[2]-my_arr[8]+my_arr[14]-my_arr[20]));
			
my_sin2=(500*(my_arr[1]-my_arr[3]-my_arr[7]+my_arr[9]+
							my_arr[13]-my_arr[15]-my_arr[19]+my_arr[21])+
				 866*(my_arr[0]-my_arr[4]-my_arr[6]+my_arr[10]+		
							my_arr[12]-my_arr[16]-my_arr[18]+my_arr[22])+
			  1000*(-my_arr[5]+my_arr[11]-my_arr[17]+my_arr[23]));
		
			Re2=my_cos2/12000;
			Im2=my_sin2/12000;					


			//определение амплитуды 5-й гармоники 

my_cos5=(259*(my_arr[4]+my_arr[6]-my_arr[16]-my_arr[18])+
			  500*(my_arr[1]+my_arr[9]-my_arr[13]-my_arr[21])+
			  707*(-my_arr[2]-my_arr[8]+my_arr[14]+my_arr[20])+
			  866*(-my_arr[3]-my_arr[7]+my_arr[15]+my_arr[19])+	
			  966*(my_arr[0]+my_arr[10]-my_arr[12]-my_arr[22])+				
			 1000*my_arr[5]-1000*my_arr[17]);
			
my_sin5=(259*(my_arr[0]-my_arr[10]-my_arr[12]+my_arr[22])+
				500*(my_arr[3]-my_arr[7]-my_arr[15]+my_arr[19])+
				707*(-my_arr[2]+my_arr[8]+my_arr[14]-my_arr[20])+
				866*(-my_arr[1]+my_arr[9]+my_arr[13]-my_arr[21])+
				966*(my_arr[4]-my_arr[6]-my_arr[16]+my_arr[18])+
				1000*my_arr[23]-1000*my_arr[11]);		
			
			Re5=my_cos5/12000;
			Im5=my_sin5/12000;			
			
			perem();	
			
}	
//=====================================================================
void	potok(void)
{
//static int	my_adc_ch;
//my_adc_ch=adc_ch;	
GPIOA->BSRR=GPIO_BSRR_BS1;
//	GPIOA->ODR ^=(1<< 1); 	
	zzz = DWT_CYCCNT;
	dft(adc_ch);
	mat_potok_all();
	out_stm();
	input_stm();
	zzz1_m1 = (DWT_CYCCNT-zzz);
GPIOA->BSRR=GPIO_BSRR_BR1;	
//	GPIOA->ODR ^=(1<< 1);
	
	
/*
	switch (adc_sample_number)
{	
	case	0	:	{zzz = DWT_CYCCNT;dft(adc_ch);zzz1_m5 = (DWT_CYCCNT-zzz);	}	break;
//	case	1	:	{GPIOA->ODR ^=(1<< 4); zzz = DWT_CYCCNT;mat_potok_1();zzz1_m1 = (DWT_CYCCNT-zzz);GPIOA->ODR ^=(1<< 4);}	break;		
	case	1	:	{mat_potok_1();}	break;		//333 mks	
	case	2	:	{zzz = DWT_CYCCNT;mat_potok_2();zzz1_m2 = (DWT_CYCCNT-zzz);}	break;	
//	case	2	:	{mat_potok_2();}	break;		//378 mks
	case	3	:	{zzz = DWT_CYCCNT;mat_potok_3();zzz1_m3 = (DWT_CYCCNT-zzz);}	break;	
//	case	3	:	{mat_potok_3();}	break;	//689 mks
	case	4	:	{zzz = DWT_CYCCNT;mat_potok_4();zzz1_m4 = (DWT_CYCCNT-zzz);}	break;		
//	case	4	:	{mat_potok_4();}	break;							 	
case	5 	:	{GPIOA->BSRR=GPIO_BSRR_BR4;out_stm();GPIOA->BSRR=GPIO_BSRR_BS4;}break;			

	case	6	:{ dft(adc_ch);} break;
	case	7	:	{mat_potok_1();}	break;	
	case	8	:	{mat_potok_2();}	break;	
	case	9	:	{mat_potok_3();}	break;					
	case	10	:	{mat_potok_4();}	break;	
case	11	:	{GPIOA->BSRR=GPIO_BSRR_BR4;out_stm();GPIOA->BSRR=GPIO_BSRR_BS4;}break;	

	case	12  : {dft(adc_ch);}	break;
	case	13	:	{mat_potok_1();}	break;	
	case	14	:	{mat_potok_2();}	break;
	case	15	:	{mat_potok_3();}	break;				
	case	16	:	{mat_potok_4();}	break;		
case	17	:	{GPIOA->BSRR=GPIO_BSRR_BR4;out_stm();GPIOA->BSRR=GPIO_BSRR_BS4;}break;	

	case	18	:	{dft(adc_ch);}	break;
	case	19	:	{mat_potok_1();}	break;			
	case	20	:	{mat_potok_2();}	break;
	case	21	:	{mat_potok_3();}	break;						
	case	22	:	{mat_potok_4();}	break;		
case	23	:	{GPIOA->BSRR=GPIO_BSRR_BR4;out_stm();GPIOA->BSRR=GPIO_BSRR_BS4;}break;	
//	default:	break;		

}
*/

}
