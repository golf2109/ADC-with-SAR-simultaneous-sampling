#include <math.h>
#include	"dft24.h"
extern void Delay_mks(__IO uint32_t nTime);
extern	uint32_t ModAngl(int32_t Re,int32_t Im,uint32_t *ang);
uint32_t	ang;
extern	uint32_t	ADC_1[20];

//=====================================================================
void	potok(int	adc_ch)
{
//extern int	adc_sample_number;
//extern int	adc_sample_now;
uint32_t	b;
//результат преобразования АЦП для текущего канала

//вычисление промежуточных сумм гармоник 1-го потока
b=adc_sample_number;
sum1_sin_g1[adc_ch]=sum1_sin_g1[adc_ch]+adc_sample_now*(SIN_F1[b]);
sum1_cos_g1[adc_ch]=sum1_cos_g1[adc_ch]+adc_sample_now*(COS_F1[b]);	
sum1_sin_g2[adc_ch]=sum1_sin_g2[adc_ch]+adc_sample_now*(SIN_F2[b]);
sum1_cos_g2[adc_ch]=sum1_cos_g2[adc_ch]+adc_sample_now*(COS_F2[b]);
sum1_sin_g5[adc_ch]=sum1_sin_g5[adc_ch]+adc_sample_now*(SIN_F5[b]);
sum1_cos_g5[adc_ch]=sum1_cos_g5[adc_ch]+adc_sample_now*(COS_F5[b]);
//вычисление промежуточных сумм гармоник 2-го потока
b=adc_sample_number+6;
sum2_sin_g1[adc_ch]=sum2_sin_g1[adc_ch]+adc_sample_now*(SIN_F1[b]);
sum2_cos_g1[adc_ch]=sum2_cos_g1[adc_ch]+adc_sample_now*(COS_F1[b]);	
sum2_sin_g2[adc_ch]=sum2_sin_g2[adc_ch]+adc_sample_now*(SIN_F2[b]);
sum2_cos_g2[adc_ch]=sum2_cos_g2[adc_ch]+adc_sample_now*(COS_F2[b]);
sum2_sin_g5[adc_ch]=sum2_sin_g5[adc_ch]+adc_sample_now*(SIN_F5[b]);
sum2_cos_g5[adc_ch]=sum2_cos_g5[adc_ch]+adc_sample_now*(COS_F5[b]);
//вычисление промежуточных сумм гармоник 3-го потока
b=adc_sample_number+12;
sum3_sin_g1[adc_ch]=sum3_sin_g1[adc_ch]+adc_sample_now*(SIN_F1[b]);
sum3_cos_g1[adc_ch]=sum3_cos_g1[adc_ch]+adc_sample_now*(COS_F1[b]);	
sum3_sin_g2[adc_ch]=sum3_sin_g2[adc_ch]+adc_sample_now*(SIN_F2[b]);
sum3_cos_g2[adc_ch]=sum3_cos_g2[adc_ch]+adc_sample_now*(COS_F2[b]);
sum3_sin_g5[adc_ch]=sum3_sin_g5[adc_ch]+adc_sample_now*(SIN_F5[b]);
sum3_cos_g5[adc_ch]=sum3_cos_g5[adc_ch]+adc_sample_now*(COS_F5[b]);
//вычисление промежуточных сумм гармоник 4-го потока
b=adc_sample_number+18;
sum4_sin_g1[adc_ch]=sum4_sin_g1[adc_ch]+adc_sample_now*(SIN_F1[b]);
sum4_cos_g1[adc_ch]=sum4_cos_g1[adc_ch]+adc_sample_now*(COS_F1[b]);	
sum4_sin_g2[adc_ch]=sum4_sin_g2[adc_ch]+adc_sample_now*(SIN_F2[b]);
sum4_cos_g2[adc_ch]=sum4_cos_g2[adc_ch]+adc_sample_now*(COS_F2[b]);
sum4_sin_g5[adc_ch]=sum4_sin_g5[adc_ch]+adc_sample_now*(SIN_F5[b]);
sum4_cos_g5[adc_ch]=sum4_cos_g5[adc_ch]+adc_sample_now*(COS_F5[b]);

//проверка на окончание цикла вычисления гармоник

//проверка окончания 1-го потока 
/*--------------------------------------------------------------------------------*/
	if(adc_sample_number==0)		
		{		
			//определение амплитуды 1-й гармоники 1-го потока
			Ag1[adc_ch]=ModAngl(sum1_cos_g1[adc_ch]/12000,sum1_sin_g1[adc_ch]/12000,&ang);
			angl1[adc_ch]=ang;
			//сброс промежуточных сумм 1-й гармоники 1-го потока
			Re1=sum1_cos_g1[adc_ch];
			Im1=sum1_sin_g1[adc_ch];
			sum1_cos_g1[adc_ch]=0;sum1_sin_g1[adc_ch]=0;
		
			//определение амплитуды 2-й гармоники 1-го потока
			Ag2[adc_ch]=ModAngl(sum1_cos_g2[adc_ch]/12000,sum1_sin_g2[adc_ch]/12000,&ang);
			//сброс промежуточных сумм 2-й гармоники 1-го потока
			Re2=sum1_cos_g2[adc_ch];
			Im2=sum1_sin_g2[adc_ch];			
			sum1_cos_g2[adc_ch]=0;sum1_sin_g2[adc_ch]=0;

			//определение амплитуды 5-й гармоники 1-го потока
			Ag5[adc_ch]=ModAngl(sum1_cos_g5[adc_ch]/12000,sum1_sin_g5[adc_ch]/12000,&ang);
			//сброс промежуточных сумм 5-й гармоники 1-го потока
			Re5=sum1_cos_g5[adc_ch];
			Im5=sum1_sin_g5[adc_ch];
			sum1_cos_g5[adc_ch]=0;sum1_sin_g5[adc_ch]=0;
			
		}
//проверка окончания 2-го потока
/*--------------------------------------------------------------------------------*/
if(adc_sample_number==6)
	{
			//определение амплитуды 1-й гармоники 2-го потока
			Ag1[adc_ch]=ModAngl(sum2_cos_g1[adc_ch]/12000,sum2_sin_g1[adc_ch]/12000,&ang);
			angl1[adc_ch]=ang;
			//сброс промежуточных сумм 1-й гармоники 2-го потока
			Re1=sum2_cos_g1[adc_ch];
			Im1=sum2_sin_g1[adc_ch];			
			sum2_sin_g1[adc_ch]=0;sum2_cos_g1[adc_ch]=0;
		
			//определение амплитуды 2-й гармоники 2-го потока
			Ag2[adc_ch]=ModAngl(sum2_cos_g2[adc_ch]/12000,sum2_sin_g2[adc_ch]/12000,&ang);
			//сброс промежуточных сумм 2-й гармоники 2-го потока
			Re2=sum2_cos_g2[adc_ch];
			Im2=sum2_sin_g2[adc_ch];
			sum2_sin_g2[adc_ch]=0;sum2_cos_g2[adc_ch]=0;

			//определение амплитуды 5-й гармоники 2-го потока
			Ag5[adc_ch]=ModAngl(sum2_cos_g5[adc_ch]/12000,sum2_sin_g5[adc_ch]/12000,&ang);
			//сброс промежуточных сумм 5-й гармоники 2-го потока
			Re5=sum2_cos_g5[adc_ch];
			Im5=sum2_sin_g5[adc_ch];	
			sum2_sin_g5[adc_ch]=0;sum2_cos_g5[adc_ch]=0;
	}
//проверка окончания 3-го потока
/*--------------------------------------------------------------------------------*/
if(adc_sample_number==12)
	{
			//определение амплитуды 1-й гармоники 3-го потока
			Ag1[adc_ch]=ModAngl(sum3_cos_g1[adc_ch]/12000,sum3_sin_g1[adc_ch]/12000,&ang);
			angl1[adc_ch]=ang;
			//сброс промежуточных сумм 1-й гармоники 3-го потока
			Re1=sum3_cos_g1[adc_ch];
			Im1=sum3_sin_g1[adc_ch];		
			sum3_sin_g1[adc_ch]=0;sum3_cos_g1[adc_ch]=0;
		
			//определение амплитуды 2-й гармоники 3-го потока
			Ag2[adc_ch]=ModAngl(sum3_cos_g2[adc_ch]/12000,sum3_sin_g2[adc_ch]/12000,&ang);
			//сброс промежуточных сумм 2-й гармоники 1-го потока
			Re2=sum3_cos_g2[adc_ch];
			Im2=sum3_sin_g2[adc_ch];		
			sum3_sin_g2[adc_ch]=0;sum3_cos_g2[adc_ch]=0;

			//определение амплитуды 5-й гармоники 3-го потока
			Ag5[adc_ch]=ModAngl(sum3_cos_g5[adc_ch]/12000,sum3_sin_g5[adc_ch]/12000,&ang);
			//сброс промежуточных сумм 5-й гармоники 3-го потока
			Re5=sum3_cos_g5[adc_ch];
			Im5=sum3_sin_g5[adc_ch];		
			sum3_sin_g5[adc_ch]=0;sum3_cos_g5[adc_ch]=0;
	}
//проверка окончания 4-го потока
/*--------------------------------------------------------------------------------*/
if(adc_sample_number==18)
	{
			//определение амплитуды 1-й гармоники 4-го потока
			Ag1[adc_ch]=ModAngl(sum4_cos_g1[adc_ch]/12000,sum4_sin_g1[adc_ch]/12000,&ang);
			angl1[adc_ch]=ang;
			//сброс промежуточных сумм 1-й гармоники 4-го потока
			Re1=sum4_cos_g1[adc_ch];
			Im1=sum4_sin_g1[adc_ch];		
			sum4_sin_g1[adc_ch]=0;sum4_cos_g1[adc_ch]=0;
		
			//определение амплитуды 2-й гармоники 4-го потока
			Ag2[adc_ch]=ModAngl(sum4_cos_g2[adc_ch]/12000,sum4_sin_g2[adc_ch]/12000,&ang);
			Re2=sum4_cos_g2[adc_ch];
			Im2=sum4_sin_g2[adc_ch];		
			//сброс промежуточных сумм 2-й гармоники 4-го потока
			sum4_sin_g2[adc_ch]=0;sum4_cos_g2[adc_ch]=0;

			//определение амплитуды 5-й гармоники 4-го потока
			Ag5[adc_ch]=ModAngl(sum4_cos_g5[adc_ch]/12000,sum4_sin_g5[adc_ch]/12000,&ang);
			Re5=sum4_cos_g5[adc_ch];
			Im5=sum4_sin_g5[adc_ch];		
			//сброс промежуточных сумм 5-й гармоники 4-го потока
			sum4_sin_g5[adc_ch]=0;sum4_cos_g5[adc_ch]=0;
	}	
}
