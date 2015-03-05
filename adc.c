#include "stm32f10x.h"

#define BUF_SIZE 128 //размер буфера обязательно равен степени двойки!
#define BUF_MASK (BUF_SIZE-1)
uint8_t idxIN=0, idxOUT=0;
uint16_t buffer [BUF_SIZE];
uint16_t	adc;
//buffer[idxIN++] = value;
//idxIN &= BUF_MASK;
extern	uint32_t	length_oscill;
extern	uint32_t	begin_oscill;
extern void Delay_mks(__IO uint32_t nTime);
uint16_t adc_sample[8];
extern	u8	oscill;
extern	void			Write_to_FRAM (uint32_t AddrFRAM, uint16_t DataFRAM);
void	adc_output_OZU(void);
void	adc_output_FRAM(void);

/*
процедура получения данных от 8 каналов измерения АЦП 
и записи их в массив adc_sample[8] для дальнейшей обработки
*/





/*
void	adc_input(void)
{
	if(oscill==1)
		{	
			if(length_oscill==0){oscill=0;}
				adc_output_FRAM();
		}
	adc_output_OZU();
	
			DMA_Cmd(DMA1_Channel4, DISABLE);
//			DMA1_Channel4->CNDTR = 8;     
			DMA_SetCurrDataCounter(DMA1_Channel4,8);
						DMA1->IFCR=0;
			DMA_Cmd(DMA1_Channel4, ENABLE);
}
*/



void	adc_input(void)
{

adc_output_FRAM();

}



void	adc_output_OZU(void)
{
//__disable_irq ();
//массив данных получаемых от АЦП для обработки

	
//GPIOA->BSRR=GPIO_BSRR_BS9; //WR!!!!!!!!!!

//подтяжка входов данных получаемых от АЦП
	GPIOB->ODR=0x0000;
	GPIOA->BSRR=GPIO_BSRR_BS3;	//PA2-CONVST запуск преобразования
	Delay_mks(20);		//задержка перед окончанием преобразования EOC (3 мкс)
	GPIOA->BSRR=GPIO_BSRR_BR0;	//PA0-CS ADC    выборка АЦП

GPIOA->BSRR=GPIO_BSRR_BR7;//RD	
adc_sample[0]=GPIOB->IDR;					//0  чтение данных канала преобразования
buffer[idxIN++] = adc_sample[0];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[1]=GPIOB->IDR;					//1
buffer[idxIN++] = adc_sample[1];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[2]=GPIOB->IDR;					//2
buffer[idxIN++] = adc_sample[2];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[3]=GPIOB->IDR;					//3
buffer[idxIN++] = adc_sample[3];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[4]=GPIOB->IDR;					//4
buffer[idxIN++] = adc_sample[4];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[5]=GPIOB->IDR;					//5
buffer[idxIN++] = adc_sample[5];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[6]=GPIOB->IDR;					//6
buffer[idxIN++] = adc_sample[6];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[7]=GPIOB->IDR;					//7
buffer[idxIN++] = adc_sample[7];
idxIN &= BUF_MASK;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
	GPIOA->BSRR=GPIO_BSRR_BS0;//PA0-CS ADC     выборка АЦП
	GPIOA->BSRR=GPIO_BSRR_BR3;//PA2-CONVST  сброс строба запуска преобразования

//__enable_irq ();
}
//=================================================================


/*
void	adc_output_FRAM(void)
{
uint32_t	adc;
uint32_t	*adr_osc;
	adr_osc=begin_oscill;
	GPIOB->ODR=0x0000;
	GPIOA->BSRR=GPIO_BSRR_BS3;	//PA2-CONVST запуск преобразования
	Delay_mks(20);		//задержка перед окончанием преобразования EOC (3 мкс)
	GPIOA->BSRR=GPIO_BSRR_BR0;	//PA0-CS ADC    выборка АЦП

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD	
adc_sample[0]=GPIOB->IDR;					//0  чтение данных канала преобразования
adc = 0x00FF | (adc_sample[0]>>8);

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[1]=GPIOB->IDR;	
adc = adc | (0xFF00 |adc_sample[1]);					//1
*adr_osc=adc;begin_oscill++;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[2]=GPIOB->IDR;					//2
adc = 0x00FF | (adc_sample[2]>>8);

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[3]=GPIOB->IDR;					//3
adc = adc | (0xFF00 |adc_sample[3]);					//1
*adr_osc=adc;begin_oscill++;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[4]=GPIOB->IDR;					//4
adc = 0x00FF | (adc_sample[4]>>8);

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[5]=GPIOB->IDR;					//5
adc = adc | (0xFF00 |adc_sample[5]);					//1
*adr_osc=adc;begin_oscill++;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[6]=GPIOB->IDR;					//6
adc = 0x00FF | (adc_sample[6]>>8);

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[7]=GPIOB->IDR;					//7
adc = adc | (0xFF00 |adc_sample[7]);					//1
*adr_osc=adc;begin_oscill++;

GPIOA->BSRR=GPIO_BSRR_BS7;//RD
	GPIOA->BSRR=GPIO_BSRR_BS0;//PA0-CS ADC     выборка АЦП
	GPIOA->BSRR=GPIO_BSRR_BR3;//PA2-CONVST  сброс строба запуска преобразования
}
*/



void	adc_output_FRAM(void)
{
	//GPIOB->ODR=0x0000;
	GPIOA->BSRR=GPIO_BSRR_BS4;	//PA2-CONVST запуск преобразования
	Delay_mks(20);		//задержка перед окончанием преобразования EOC (3 мкс)
	GPIOA->BSRR=GPIO_BSRR_BR1;	//PA0-CS ADC    выборка АЦП
		Delay_mks(1);
	
GPIOA->BSRR=GPIO_BSRR_BR7;//RD	
adc_sample[0]=GPIOB->IDR;					//0  чтение данных канала преобразования
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
		Delay_mks(1);		
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
Delay_mks(1);	
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
Delay_mks(1);	
	
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[1]=GPIOB->IDR;	
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
		Delay_mks(1);		
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
Delay_mks(1);	
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
Delay_mks(1);	
	
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[2]=GPIOB->IDR;					//2
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
		Delay_mks(1);		
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
Delay_mks(1);	
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
Delay_mks(1);			

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[3]=GPIOB->IDR;					//3
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
		Delay_mks(1);		
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
Delay_mks(1);	
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
Delay_mks(1);			

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[4]=GPIOB->IDR;					//4
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
		Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
Delay_mks(1);	
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
Delay_mks(1);			

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[5]=GPIOB->IDR;					//5
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
		Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
Delay_mks(1);	
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
Delay_mks(1);	

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[6]=GPIOB->IDR;					//6
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
		Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
Delay_mks(1);	
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
Delay_mks(1);			

GPIOA->BSRR=GPIO_BSRR_BR7;//RD
adc_sample[7]=GPIOB->IDR;					//7
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
		Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR7;//RD
Delay_mks(1);	
GPIOA->BSRR=GPIO_BSRR_BS7;//RD
Delay_mks(1);			
		
	GPIOA->BSRR=GPIO_BSRR_BS1;//PA0-CS ADC     выборка АЦП
	GPIOA->BSRR=GPIO_BSRR_BR4;//PA2-CONVST  сброс строба запуска преобразования
}

