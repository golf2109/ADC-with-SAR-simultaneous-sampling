#include "adc.h"
/*
процедура получения данных от 8 каналов измерения АЦП 
и записи их в массив adc_sample[8] для дальнейшей обработки
*/

void	adc_input(void)
{
	if(oscill==0)				//проверка на поступление сигнала начала записи
		{	
			if(length_buf>4095)	//проверка на окончание записи буфера ОЗУ в FRAM
				{
					adc_output_to_FRAM();	//запись осциллограммы в FRAM
					
						if(length_oscill>8191)
							{
//выдача осциллограммы в USART
//								oscill_read();
//								while(1){}
//сброс флага аварии								
								oscill=1;
								length_buf=0;
								length_oscill=0;
								begin_oscill=0;
							}
						else{}
				}				
			else
				{adc_output_to_FRAM_and_buf();} //запись в FRAM осциллограммы и буфера ОЗУ
		}
	else		
		{adc_output_to_OZU();}	
}
//===============================================================
//запись в кольцевой буфер ОЗУ
//===============================================================

void	adc_output_to_OZU(void)
{
//массив данных получаемых от АЦП для обработки
	
//GPIOA->BSRR=GPIO_BSRR_BS9; //WR!!!!!!!!!!

//подтяжка входов данных получаемых от АЦП
	GPIOB->ODR=0xffff;
	GPIOA->BSRR=GPIO_BSRR_BS3;	//PA2-CONVST запуск преобразования
	Delay_mks(15);		//задержка перед окончанием преобразования EOC (3 мкс)
	GPIOA->BSRR=GPIO_BSRR_BR3;//PA2-CONVST  сброс строба запуска преобразования
	Delay_mks(1);//!!!!!!!!!!!!
	GPIOA->BSRR=GPIO_BSRR_BR0;	//PA0-CS ADC    выборка АЦП
	
	Delay_mks(1);
	
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
	Delay_mks(1);	
adc_sample[0]=GPIOB->IDR;					//0  чтение данных канала преобразования
//adc_sample[0]=adc_sample_test[0][adc_sample_number];		
adc_sample[0]&=ADC_MASK;
GPIOA->BSRR=GPIO_BSRR_BS7;//RD	
buffer[idxIN++] = adc_sample[0];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
	Delay_mks(0);		
adc_sample[1]=GPIOB->IDR;					//1
//adc_sample[1]=adc_sample_test[1][adc_sample_number];	
adc_sample[1]&=ADC_MASK;
GPIOA->BSRR=GPIO_BSRR_BS7;//RD	
buffer[idxIN++] = adc_sample[1];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
	Delay_mks(0);	
adc_sample[2]=GPIOB->IDR;					//2
//adc_sample[2]=adc_sample_test[2][adc_sample_number];	
adc_sample[2]&=ADC_MASK;
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
buffer[idxIN++] = adc_sample[2];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
	Delay_mks(0);	
adc_sample[3]=GPIOB->IDR;					//3
//adc_sample[3]=adc_sample_test[3][adc_sample_number];	
adc_sample[3]&=ADC_MASK;
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
buffer[idxIN++] = adc_sample[3];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
	Delay_mks(0);	
adc_sample[4]=GPIOB->IDR;					//4
//adc_sample[4]=adc_sample_test[4][adc_sample_number];	
adc_sample[4]&=ADC_MASK;
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
buffer[idxIN++] = adc_sample[4];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
	Delay_mks(0);	
adc_sample[5]=GPIOB->IDR;					//5
//adc_sample[5]=adc_sample_test[5][adc_sample_number];	
adc_sample[5]&=ADC_MASK;
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
buffer[idxIN++] = adc_sample[5];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
	Delay_mks(0);	
adc_sample[6]=GPIOB->IDR;					//6
//adc_sample[6]=adc_sample_test[6][adc_sample_number];	
adc_sample[6]&=ADC_MASK;
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
buffer[idxIN++] = adc_sample[6];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
	Delay_mks(0);	
adc_sample[7]=GPIOB->IDR;					//7
//adc_sample[7]=adc_sample_test[7][adc_sample_number];	
adc_sample[7]&=ADC_MASK;
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
buffer[idxIN++] = adc_sample[7];
idxIN &= BUF_MASK;
GPIOA->BSRR=GPIO_BSRR_BS0;//PA0-CS ADC     выборка АЦП

//	for(i=0; i<8; i++) adc_sample[i] = 1000;//обнуление АЦП для теста!!!!!!!!

}

//=================================================================
//запись осциллограммы в FRAM
//=================================================================

void	adc_output_to_FRAM(void)
{
	GPIOB->ODR=0x0000;
	GPIOA->BSRR=GPIO_BSRR_BS3;	//PA2-CONVST запуск преобразования
	Delay_mks(15);		//задержка перед окончанием преобразования EOC (3 мкс)
	GPIOA->BSRR=GPIO_BSRR_BR3;//PA2-CONVST  сброс строба запуска преобразования
	GPIOA->BSRR=GPIO_BSRR_BR0;	//PA0-CS ADC    выборка АЦП

//		Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR7;//RD	
adc_sample[0]=GPIOB->IDR;					//0  чтение данных канала преобразования
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
Write_to_FRAM (begin_oscill+4096, adc_sample[0]);
begin_oscill++;
length_oscill++;
		
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[1]=GPIOB->IDR;					//1
GPIOA->BSRR=GPIO_BSRR_BS7;//RD	
Write_to_FRAM (begin_oscill+4096, adc_sample[1]);
begin_oscill++;
length_oscill++;

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[2]=GPIOB->IDR;					//2
GPIOA->BSRR=GPIO_BSRR_BS7;//RD  
Write_to_FRAM (begin_oscill+4096, adc_sample[2]);
begin_oscill++;
length_oscill++;

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[3]=GPIOB->IDR;					//3
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
Write_to_FRAM (begin_oscill+4096, adc_sample[3]);
begin_oscill++;
length_oscill++;

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[4]=GPIOB->IDR;					//4
Write_to_FRAM (begin_oscill+4096, adc_sample[4]);
begin_oscill++;
length_oscill++;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
//		Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[5]=GPIOB->IDR;					//5
Write_to_FRAM (begin_oscill+4096, adc_sample[5]);
begin_oscill++;
length_oscill++;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
//		Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[6]=GPIOB->IDR;					//6
Write_to_FRAM (begin_oscill+4096, adc_sample[6]);
begin_oscill++;
length_oscill++;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
//		Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[7]=GPIOB->IDR;					//7
Write_to_FRAM (begin_oscill+4096, adc_sample[7]);
begin_oscill++;
length_oscill++;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
//		Delay_mks(1);
	GPIOA->BSRR=GPIO_BSRR_BS0;//PA0-CS ADC     выборка АЦП
}
//=========================================================================
//запись в FRAM осциллограммы и буфера ОЗУ
//=========================================================================
void	adc_output_to_FRAM_and_buf(void)
{
	GPIOB->ODR=0x0000;
	GPIOA->BSRR=GPIO_BSRR_BS3;	//PA2-CONVST запуск преобразования
	Delay_mks(15);		//задержка перед окончанием преобразования EOC (3 мкс)
	GPIOA->BSRR=GPIO_BSRR_BR3;//PA2-CONVST  сброс строба запуска преобразования
	GPIOA->BSRR=GPIO_BSRR_BR0;	//PA0-CS ADC    выборка АЦП

GPIOA->BSRR=GPIO_BSRR_BR7;//RD	
adc_sample[0]=GPIOB->IDR;					//0  чтение данных канала преобразования
Write_to_FRAM (begin_oscill+4096, adc_sample[0]);
Write_to_FRAM (begin_oscill, buffer[idxIN++]);
begin_oscill++;
length_buf++;	
idxIN &= BUF_MASK;
	
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[1]=GPIOB->IDR;					//1
Write_to_FRAM (begin_oscill+4096, adc_sample[1]);
Write_to_FRAM (begin_oscill, buffer[idxIN++]);
begin_oscill++;
length_buf++;
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[2]=GPIOB->IDR;					//2
Write_to_FRAM (begin_oscill+4096, adc_sample[2]);
Write_to_FRAM (begin_oscill, buffer[idxIN++]);
begin_oscill++;
length_buf++;
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[3]=GPIOB->IDR;					//3
Write_to_FRAM (begin_oscill+4096, adc_sample[3]);
Write_to_FRAM (begin_oscill, buffer[idxIN++]);
begin_oscill++;
length_buf++;
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[4]=GPIOB->IDR;					//4
Write_to_FRAM (begin_oscill+4096, adc_sample[4]);
Write_to_FRAM (begin_oscill, buffer[idxIN++]);
begin_oscill++;
length_buf++;
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[5]=GPIOB->IDR;					//5
Write_to_FRAM (begin_oscill+4096, adc_sample[5]);
Write_to_FRAM (begin_oscill, buffer[idxIN++]);
begin_oscill++;
length_buf++;
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[6]=GPIOB->IDR;					//6
Write_to_FRAM (begin_oscill+4096, adc_sample[6]);
Write_to_FRAM (begin_oscill, buffer[idxIN++]);
begin_oscill++;
length_buf++;
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[7]=GPIOB->IDR;					//7
Write_to_FRAM (begin_oscill+4096, adc_sample[7]);
Write_to_FRAM (begin_oscill, buffer[idxIN++]);
begin_oscill++;
length_buf++;
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
//		Delay_mks(1);
	GPIOA->BSRR=GPIO_BSRR_BS0;//PA0-CS ADC     выборка АЦП
}

