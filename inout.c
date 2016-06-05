#include "stm32f10x.h"
extern	uint32_t	flag_out;
extern	uint16_t	number_send_byte;
extern	uint8_t	izmer[101];
extern	uint32_t	input[110];

//===============================================================================
void out_stm (void)
{	
int	flag, qqq1;		

if(flag_out==1)	
{	
		GPIOA->CRH=0x338883B3;	//PA13 PA12 PA11  - INPUT		
		GPIOA->BSRR=GPIO_BSRR_BR8;				//INT_ATM - установка запроса прерывания INT_ATM 
		GPIOB->CRL=0x33333333;						//младшая часть шины PB - OUT		
        flag=0;
				for(qqq1=0;qqq1<=50;qqq1++)
					{						
//						if(((GPIOA->IDR)&0x1000)==0x1000)	//READ_ATM = 1?	
					if((GPIOA->IDR)&GPIO_IDR_IDR12)	
							{
								flag=1;
								break;
							}	
					}
				if (flag==0)	
				{
					GPIOB->CRL=0x88888888;	//младшая часть шины PB - IN
					GPIOA->BSRR=GPIO_BSRR_BR10;	
          GPIOA->BSRR=GPIO_BSRR_BS8;				//INT_ATM - сброс запроса прерывания INT_ATM 		
					GPIOA->CRH=0x338888B3;	//PA13 PA12 PA11 PA10!!! - INPUT											
					return;
				}						
	for	(number_send_byte=0;number_send_byte<=101;number_send_byte++)
		{					
				GPIOB->ODR=izmer[number_send_byte];	
				GPIOA->BSRR=GPIO_BSRR_BS10;
				if(((GPIOA->IDR)&0x1000)==0x0000)	{break;}			
				GPIOA->BSRR=GPIO_BSRR_BR10;		
		}			
	flag=0;
	GPIOB->CRL=0x88888888;	//младшая часть шины PB - IN
	GPIOA->BSRR=GPIO_BSRR_BR10;			
	GPIOA->BSRR=GPIO_BSRR_BS8;				//INT_ATM - сброс запроса прерывания INT_ATM 			
	GPIOA->CRH=0x338888B3;	//PA13 PA12 PA11 PA10!!! - INPUT		
	}		
flag_out=0;
}
//==============================================================================
void	input_stm (void)
{
register	int	inp=0;
register	int	input_byte=0;
	
	int	flag,qqq2;
	flag=0;
for(qqq2=0;qqq2<=50;qqq2++)	
{
if((GPIOA->IDR)&GPIO_IDR_IDR11)
	{
		flag=1;
		break;
	}
}	

if(flag==0)
{
GPIOA->BSRR=GPIO_BSRR_BR12;//READ_ATM=0				
GPIOA->CRH=0x338888B3;	
return;		
}	
if(((GPIOA->IDR)&GPIO_IDR_IDR11)==0)
{
		  GPIOA->CRH=0x338388B3;	
			GPIOA->BSRR=GPIO_BSRR_BS12; //READ_ATM=1
}	
	    while(((GPIOA->IDR)&GPIO_IDR_IDR11)==0)
			{
			  if(GPIOA->IDR&GPIO_IDR_IDR10) input_byte=GPIOB->IDR; 
        else
					if(GPIOA->IDR&GPIO_IDR_IDR10) input_byte=GPIOB->IDR; // input_byte; //test DATA_STM
          else
					if(GPIOA->IDR&GPIO_IDR_IDR10) input_byte=GPIOB->IDR; // input_byte; //test DATA_STM
					else
					if(GPIOA->IDR&GPIO_IDR_IDR10) input_byte=GPIOB->IDR; // input_byte; //test DATA_STM					
					else
					if(GPIOA->IDR&GPIO_IDR_IDR10) input_byte=GPIOB->IDR; // input_byte; //test DATA_STM
					else
					if(GPIOA->IDR&GPIO_IDR_IDR10) input_byte=GPIOB->IDR; // input_byte; //test DATA_STM
            else break;

				if(GPIOA->IDR&GPIO_IDR_IDR10) 
									if(GPIOA->IDR&GPIO_IDR_IDR10) 
														if(GPIOA->IDR&GPIO_IDR_IDR10) 
																			if(GPIOA->IDR&GPIO_IDR_IDR10) 
					if(GPIOA->IDR&GPIO_IDR_IDR10)
						if(GPIOA->IDR&GPIO_IDR_IDR10) break;	
				input[inp++]=input_byte;
	//				inp++;					
      }					
			GPIOA->BSRR=GPIO_BSRR_BR12;//READ_ATM=0				
GPIOA->CRH=0x338888B3;	
//EXTI->PR  |= EXTI_PR_PR11;
//			EXTI->PR =0x0ff;			
//input_byte=0xff;
}
