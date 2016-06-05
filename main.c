#include	"main.h"

//============================================================================

int main()
{	
//int	izz;	
//addr_angl = &uk_addr_angl;	
//for(izz=0;izz<=99	;izz++)
//	{izmer[izz]=0xFF;}
//Обработчик прерывания системного таймера1
SysTick_Config(60000);
//Включаем тактирование порта GPIOA  
//my_RCC_Configuration();
RCC_Configuration();	
//Конфигурируем выводы
GPIO_Configuration();
	
SCB_DEMCR |= 0x01000000;
DWT_CONTROL|= 1; // enable the counter
DWT_CYCCNT  = 0;
	
	
DMA_Configuration();
//mcu_rtc_init();
UART_Configuration();

//printf("123");
	
for(adc_sample_number=0; adc_sample_number<24; adc_sample_number++) //0
{adc_sample_test[0][adc_sample_number]=32768+10000.0*sin(adc_sample_number*2.0*PI/24);}		
adc_sample_number=0;	

for(adc_sample_number=0; adc_sample_number<24; adc_sample_number++) //1
{adc_sample_test[1][adc_sample_number]=32768+11000.0*sin(2*PI/3+adc_sample_number*2.0*PI/24);}	
adc_sample_number=0;

for(adc_sample_number=0; adc_sample_number<24; adc_sample_number++) //2
{adc_sample_test[2][adc_sample_number]=32768+12000.0*sin(-2*PI/3+adc_sample_number*2.0*PI/24);}	
adc_sample_number=0;

for(adc_sample_number=0; adc_sample_number<24; adc_sample_number++) //3
{adc_sample_test[3][adc_sample_number]=32768+13000.0*sin(adc_sample_number*2.0*PI/24);}	
adc_sample_number=0;

for(adc_sample_number=0; adc_sample_number<24; adc_sample_number++) //4
{adc_sample_test[4][adc_sample_number]=32768+14000.0*sin(adc_sample_number*2.0*PI/24);}	
adc_sample_number=0;

for(adc_sample_number=0; adc_sample_number<24; adc_sample_number++) //5	
{adc_sample_test[5][adc_sample_number]=32768+15000.0*sin(2*PI/3+adc_sample_number*2.0*PI/24);}	
adc_sample_number=0;

for(adc_sample_number=0; adc_sample_number<24; adc_sample_number++) //6
{adc_sample_test[6][adc_sample_number]=32768+16000.0*sin(-2*PI/3+adc_sample_number*2.0*PI/24);}	
adc_sample_number=0;

for(adc_sample_number=0; adc_sample_number<24; adc_sample_number++) //7	
{adc_sample_test[7][adc_sample_number]=32768+17000.0*sin(adc_sample_number*2.0*PI/24);}	
adc_sample_number=0;
	
	GPIOA->CRH=0x11111111;	
	
	GPIOA->CRH |= GPIO_CRH_CNF9_1;
	GPIOA->CRH &=~GPIO_CRH_CNF9_0;
	GPIOA->CRH |= GPIO_CRH_MODE9;	
	
RtcInit();
Delay_mks(1000);
//RtcCorr();
write_begin_time();
	
//zzz = DWT_CYCCNT;
//установка начального времени
//RTC clock with a frequency divided by 64 on the TAMPER pin
//rtc_gettime (&timeread);
//if (timeread.year<2014)
//{rtc_settime (&timeset);}

ReadFLASH((u16 *)&Calibr, LASTPAGEFLASH, sizeof(Calibr));
//Calibr=C_Calibr;
WriteFLASH((u16 *)&Calibr, LASTPAGEFLASH, sizeof(Calibr));

ReadFLASH((u16 *)&Calibr, LASTPAGEFLASH, sizeof(Calibr));
	if (CalcCRC16((u8 *)&Calibr, sizeof(Calibr)-sizeof(Calibr.CRC16))!=Calibr.CRC16)
		{	
			Calibr=C_Calibr;
			WriteFLASH((u16 *)&Calibr, LASTPAGEFLASH, sizeof(Calibr));
			StateAI|=ERR_CALIBR;
		}
	// ReStarts
	if (RCC->CSR & RCC_CSR_PORRSTF)
		{
			ReStarts=0;
			//ErrRequestSPI1=0;
	}
	else if (ReStarts<MAXRESTARTS) ++ReStarts;
	RCC->CSR|=RCC_CSR_RMVF;	// Clear the reset flags
	//	IWDG_Configuration();
	//	NVIC_Configuration();
	//					Calibr.CRC16=CalcCRC16((u8 *)&Calibr, sizeof(Calibr)-sizeof(Calibr.CRC16));
	//						  WriteFLASH((u16 *)&Calibr, LASTPAGEFLASH, sizeof(Calibr));				
	//printf("Hello world!");		


							fram_out=0;
				while(fram_out<0x40000)		//обнуление FRAM
					{					
						Write_to_FRAM (fram_out,0x0000);							
						fram_out++;
					}	


	read0=Read_from_FRAM (0x0000);//проверка первичной инициализации FRAM
	if(read0!=0xAA55)
	{
		FRAM_init();
	}
	FRAM_setting();

//====================================================================================
	 // Configure USARTy Rx as input floating 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
    
  // Configure USARTy Tx as alternate function push-pull
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	USART_InitStructure.USART_BaudRate = 921600;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;	
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;  
   //Configure USARTy 
  USART_Init(USART1, &USART_InitStructure);
		
  // Enable USARTy DMA Rx and TX request 
  USART_DMACmd(USART1, USART_DMAReq_Rx | USART_DMAReq_Tx, ENABLE);

  // Enable USARTy TX DMA1 Channel 
	DMA_Cmd(DMA1_Channel4, ENABLE);
  // Enable USARTy RX DMA1 Channel 
	DMA_Cmd(DMA1_Channel5, ENABLE);

  // Enable the USART
  USART_Cmd(USART1, ENABLE);
//=====================================================================================
	
	if(Read_from_FRAM(0x0001) == 0xAA55)//проверка первичной инициализации FRAM
	{
		FRAM_init();
	}
	FRAM_setting();
	
	GPIOA->CRH |= GPIO_CRH_CNF8_0;
	GPIOA->CRH &=~GPIO_CRH_CNF8_1;
	GPIOA->CRH &=~GPIO_CRH_MODE8;		


    initAll();	
__enable_irq ();		
	
  while(1)
		{		
//		avar=(GPIOA->IDR)&0x0100;
//		if(avar==0x0100){oscill=0;}					
		if(adc_read==1)							//проверка готовности АЦП	
			{					
//		adc_input();							//ввод данных АЦП	
		
//adc_read=0;				
if(adc_sample_number==0)
{
for	(adc_ch=0; adc_ch < 8 ; adc_ch++)
{
				adc_sample_now=adc_sample[adc_ch];
//adc_sample_now = adc_sample_test[adc_ch][adc_sample_number];				
				potok();				
}	
}

if(adc_sample_number==6)
{
for	(adc_ch=0; adc_ch < 8 ; adc_ch++)
{
				adc_sample_now=adc_sample[adc_ch];
//adc_sample_now = adc_sample_test[adc_ch][adc_sample_number];				
				potok();				
}	
}

if(adc_sample_number==12)
{	
for	(adc_ch=0; adc_ch < 8 ; adc_ch++)
{
				adc_sample_now=adc_sample[adc_ch];
//adc_sample_now = adc_sample_test[adc_ch][adc_sample_number];					
				potok();				
}	
}

if(adc_sample_number==18)	
{	
for	(adc_ch=0; adc_ch < 8 ; adc_ch++)
{
				adc_sample_now=adc_sample[adc_ch];
//adc_sample_now = adc_sample_test[adc_ch][adc_sample_number];						
				potok();				
}	
}
/*
  		adc_sample_now=adc_sample[0];
//adc_sample_now = adc_sample_test0[adc_sample_number];						
				potok(0);				
				adc_sample_now=adc_sample[1];
//adc_sample_now = adc_sample_test1[adc_sample_number];						
				potok(1);											
				adc_sample_now=adc_sample[2];						
//adc_sample_now = adc_sample_test2[adc_sample_number];						
				potok(2);						
				adc_sample_now=adc_sample[3];
//adc_sample_now = adc_sample_test3[adc_sample_number];		
				potok(3);											
				adc_sample_now=adc_sample[4];
//adc_sample_now = adc_sample_test4[adc_sample_number];						
				potok(4);																	
				adc_sample_now=adc_sample[5];
//adc_sample_now = adc_sample_test5[adc_sample_number];						
				potok(5);												
				adc_sample_now=adc_sample[6];
//adc_sample_now = adc_sample_test6[adc_sample_number];						
				potok(6);												
				adc_sample_now=adc_sample[7];
//adc_sample_now = adc_sample_test7[adc_sample_number];						
				potok(7);
*/				
				
				
/*
switch (adc_sample_number)
{	
case	5 	:	{GPIOA->BSRR=GPIO_BSRR_BR4;out_stm();GPIOA->BSRR=GPIO_BSRR_BS4;}break;
case	11	:	{GPIOA->BSRR=GPIO_BSRR_BR4;out_stm();GPIOA->BSRR=GPIO_BSRR_BS4;}break;
case	17	:	{GPIOA->BSRR=GPIO_BSRR_BR4;out_stm();GPIOA->BSRR=GPIO_BSRR_BS4;}break;
case	23	:	{GPIOA->BSRR=GPIO_BSRR_BR4;out_stm();GPIOA->BSRR=GPIO_BSRR_BS4;}break;
}
*/

//if(adc_sample_number==4)
//{printf("%u,,",aa);printf("%u,,",bb);printf("%u\r",Ia);}	
//{printf("%u,",Ua/0x240);printf("%u,",Ub/0x240);printf("%u,",Uc/0x240);printf("%u,",Ia/0xF8);printf("%u,",Ib/0xF8);printf("%u,",Ic/0xF8);printf("%u,",Uad/0xE88);printf("%u\r",U3o_i/0xE88);}
//if(adc_sample_number==10)
//{printf("%u,",Ua/0x240);printf("%u,",Ub/0x240);printf("%u,",Uc/0x240);printf("%u,",Ia/0xF8);printf("%u,",Ib/0xF8);printf("%u,",Ic/0xF8);printf("%u,",Uad/0xE88);printf("%u\r",U3o_i/0xE88);}
//if(adc_sample_number==16)
//{printf("%u,",Ua/0x240);printf("%u,",Ub/0x240);printf("%u,",Uc/0x240);printf("%u,",Ia/0xF8);printf("%u,",Ib/0xF8);printf("%u,",Ic/0xF8);printf("%u,",Uad/0xE88);printf("%u\r",U3o_i/0xE88);}
//if(adc_sample_number==22)
//{printf("%u,",Ua/0x240);printf("%u,",Ub/0x240);printf("%u,",Uc/0x240);printf("%u,",Ia/0xF8);printf("%u,",Ib/0xF8);printf("%u,",Ic/0xF8);printf("%u,",Uad/0xE88);printf("%u\r",U3o_i/0xE88);}

				adc_read=0;		//сброс флага готовности АЦП



//				adc_sample_number++;
//				if(adc_sample_number>=24)		//проверка последний интервал выборок
//					{	
//						adc_sample_number=0;			//обнуление счетчика выборок АЦП					
//					}					
					
					
					
			}								
  }  
}
//==============================================================================
void SysTick_Handler(void)
{
	
//флаг готовности АЦП
flag_out=1;
mlsec++;
	
if(mlsec==1200)
	{mlsec=0;	
	}	 			
//__disable_irq ();		
	adc_input();							//ввод данных АЦП	
//adc_output_to_OZU();	
//adc_read=1;	
//__enable_irq ();		

				adc_sample_number++;
				if(adc_sample_number>=24)		//проверка последний интервал выборок
					{	
						adc_sample_number=0;			//обнуление счетчика выборок АЦП					
					}	
					
switch (adc_sample_number)
{	
	case	0	:{adc_read=1;}		break;
	case	6	:{adc_read=1;}		break;	
	case	12	:{adc_read=1;}		break;
	case	18	:{adc_read=1;}		break;
default:	break;		
}	
//				adc_DMA();
//sprintf(TxBuffer, "%u\r", adc_sample_test0[adc_sample_number]);			
	
	
	
/////				DMA_Cmd(DMA1_Channel4, DISABLE);
/////	 			DMA1_Channel4->CNDTR = 7;
/////				DMA1->IFCR=0;
/////				DMA_Cmd(DMA1_Channel4, ENABLE);		

	
	
	
	/*
//utoa(value16, buffer, 10);
//		if(oscill==1)
//			{
				timeUART_DMA();		//ежесекундная передача в UART текущего времени		
				DMA_Cmd(DMA1_Channel4, DISABLE);
	 			DMA1_Channel4->CNDTR = 22;
				DMA1->IFCR=0;
				DMA_Cmd(DMA1_Channel4, ENABLE);						
//			}				
*/
//  __asm  {
//		NOP
//  }	
}
//Функция временной задержки
/*===================================================================*/
void Delay_mks(__IO uint32_t nTime)
{ 
  while(nTime != 0)
	{
		nTime--;
	}
}
