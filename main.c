#include	"main.h"
USART_InitTypeDef usart;
/*******************************************************************************
* Function Name  : RCC_Configuration
* Description    : Configures the different system clocks.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void RCC_Configuration(void)
{
  // Enable HSE
	RCC->CR|=RCC_CR_HSEON;
	//RTC
	RCC->CR|=RCC_BDCR_RTCSEL;
	RCC->CR|=RCC_BDCR_RTCEN;
  // Flash 1 wait state
	FLASH->ACR=FLASH_ACR_PRFTBE|FLASH_ACR_LATENCY_2;
	// USB clock=PLLCLK, HCLK=SYSCLK, PCLK2=HCLK, PCLK1=HCLK/2, PLLCLK=8MHz*9=72MHz
	RCC->CFGR=RCC_CFGR_USBPRE|RCC_CFGR_PLLMULL9|RCC_CFGR_PLLSRC_HSE|RCC_CFGR_PPRE1_DIV2;
  // Wait till HSE is ready
	while ((RCC->CR&RCC_CR_HSERDY)==0);
  // Enable PLL
	RCC->CR|=RCC_CR_PLLON;
	// Wait till PLL is ready
	while ((RCC->CR&RCC_CR_PLLRDY)==0);
	// Select PLL as system clock source
	RCC->CFGR|=RCC_CFGR_SW_PLL;
	// Wait till PLL is used as system clock source
	while ((RCC->CFGR&RCC_CFGR_SWS)!=RCC_CFGR_SWS_PLL);
	// APB1ENR SPI2 clock enable
	RCC->APB1ENR=RCC_APB1ENR_SPI2EN|RCC_APB1ENR_TIM2EN;
	// APB2ENR SPI1, TIM1, GPIOC, GPIOB, GPIOA, AFIO clock enable
	RCC->APB2ENR=RCC_APB2ENR_SPI1EN|RCC_APB2ENR_TIM1EN|RCC_APB2ENR_IOPCEN|RCC_APB2ENR_IOPBEN|RCC_APB2ENR_IOPAEN|RCC_APB2ENR_AFIOEN;
	// AHBENR DMA1 clock enable
	RCC->AHBENR=RCC_AHBENR_DMA1EN;
	// PWR_CR
	PWR->CR=PWR_CR_PLS_2V5|PWR_CR_PVDE;
}
/*******************************************************************************
* Function Name  : GPIO_Configuration
* Description    : Configures the different GPIO ports.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void GPIO_Configuration(void)
{
	//port A - OUT
	GPIOA->CRL=0x33333333;
	GPIOA->CRH=0x33333333;
	GPIOA->ODR=0xFFFF;
	//port B - IN
	GPIOB->CRL=0x88888888;
	GPIOB->CRH=0x88888888;
	//port C - OUT
//	GPIOC->CRH=0x22222222;		занято часами

//AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_DISABLE;
AFIO->MAPR  = 0x02000000;//отключаем выводы JTAG 

AFIO->EVCR =0xAD; //PC13-calibration clock output enable
BKP->RTCCR |=	BKP_RTCCR_CCO; //Setting this bit outputs the 
//RTC clock with a frequency divided by 64 on the TAMPER pin	
}
//===============================================================================
void UART_Configuration(void)
{
/*
	RCC->APB2ENR	|= RCC_APB2ENR_USART1EN;	//включение тактовой частоты
//	USART1->BRR =0x4E; //1 080 000
  USART1->BRR  = 72000000/115200;                // set baudrate	
//	USART1->BRR    |= 0x11<<4;		//установка скорости 115200
//  USART1->BRR    |= 0xd;
// Устанавливаем PA9  (TX) на альтернавтивную функцию выхода push-pull при 50 MHz
// Установим PA10 (RX) на floating input
    GPIOA->CRH = 0x000004B0;
		USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
*/	

/*
	// Включаем модули USART1 и GPIOA, а также включаем альтернативные функции выходов
  RCC->APB2ENR|= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
  // Контакт PA9 будет выходом с альтернативной функцией, а контакт PA10 - входом
  GPIOA->CRH  |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_0 | GPIO_CRH_CNF10_0;
  // Настраиваем регистр тактирования
  USART1->BRR = ( (0x0027 << 4) | (0x0001) );	//115200  (72Mhz)

  // Выключаем TxD и RxD USART
  USART1->CR1 |= USART_CR1_TE | USART_CR1_RE;
  // Запускаем модуль USART
  USART1->CR1 |= USART_CR1_UE;
  // Разрешаем прерывание по приёму информации с RxD
  USART1->CR1 |= USART_CR1_RXNEIE;
  // Назначаем обработчик для всех прерываний от USART1
  NVIC_EnableIRQ(USART1_IRQn);	
	
*/

}

void NVIC_Configuration(void)
{
/*
// NVIC							
	SCB->VTOR=NVIC_VectTab_FLASH;
  SCB->AIRCR=((u32)0x5FA<<SCB_AIRCR_VECTKEY_Pos)|((u32)0x05<<8);
// Enable the SPI1 interrupt IRQ channel
	NVIC->IP[SPI1_IRQn]=0x00;
	NVIC->ISER[SPI1_IRQn>>0x05]|=(u32)0x01<<(SPI1_IRQn&(u8)0x1f);
// EXTI Controller (nSS)
	EXTI->IMR=EXTI_IMR_MR4;
	EXTI->EMR=EXTI_EMR_MR4;
	EXTI->RTSR=EXTI_RTSR_TR4;
	EXTI->FTSR=0;
	EXTI->SWIER=0;
	AFIO->EXTICR[1]=AFIO_EXTICR2_EXTI4_PA;
// Enable EXTI4 interrupt IRQ channel
	NVIC->IP[EXTI4_IRQn]=0x40;
	NVIC->ISER[EXTI4_IRQn>>0x05]|=(u32)0x01<<(EXTI4_IRQn&(u8)0x1f);
// Enable the DMA1 Channel4 interrupt IRQ channel
	NVIC->IP[DMA1_Channel4_IRQn]=0x50;
	NVIC->ISER[DMA1_Channel4_IRQn>>0x05]|=(u32)0x01<<(DMA1_Channel4_IRQn&(u8)0x1f);
*/
}

/*******************************************************************************
* Function Name  : IWDG_Configuration
* Description    : Configures the IWDG.
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void IWDG_Configuration(void)
{
	IWDG->KR=IWDG_ACCESS;	//IWDG_ACCESS = 0x5555	Writing the key value 5555h 
												//to enable access to the IWDG_PR
	IWDG->PR=0;						//Prescaler register
	IWDG->KR=IWDG_ACCESS;
	IWDG->RLR=1000;				//Reload register
	IWDG->KR=IWDG_EN;			//IWDG_EN	=	0xcccc	starts the watchdog
}
//******************************************************************************
void	DMA_Configuration(void)
{
	DMA_InitTypeDef dma;
	
DMA_StructInit(&dma);
dma.DMA_PeripheralBaseAddr = (uint32_t)&(USART1->DR);
dma.DMA_MemoryBaseAddr = (uint32_t)&adc_sample[0];
dma.DMA_DIR = DMA_DIR_PeripheralDST;
dma.DMA_BufferSize = DMA_BUFFER_SIZE;
dma.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
dma.DMA_MemoryInc = DMA_MemoryInc_Enable;
dma.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
dma.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
DMA_Init(DMA1_Channel4, &dma);
}
//============================================================================
int main()
{
/*uint32_t	ADC_1[20]={52937,54901,51195,57214,
										58608,42324,27086,30793,
										38016,31680,25344,32567,
										36274,21036,5198,6146,
										12165,8459,10423,31680};
*/									
//Обработчик прерывания системного таймера
SysTick_Config(60000);
//Включаем тактирование порта GPIOA  
RCC_Configuration();
//Конфигурируем выводы
GPIO_Configuration();
//DMA_Configuration();
//mcu_rtc_init();
//UART_Configuration();

SCB_DEMCR |= 0x01000000;
DWT_CONTROL|= 1; // enable the counter
DWT_CYCCNT  = 0;

__enable_irq ();
//GPIOA->ODR = 0x00C7;	//начальное состояние 
RtcCorr();
RtcInit();
zzz = DWT_CYCCNT;
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
	
	read0=Read_from_FRAM (0x0000);//проверка первичной инициализации FRAM
							fram_out=0;
				while(fram_out<0x40000)	//обнуление FRAM
					{					
						Write_to_FRAM (fram_out,0x0000);							
						fram_out++;
					}	
//	if(read0!=0x78)
//	{
//		FRAM_init();
//	}
//	FRAM_setting();
					
  while(1)
		{		
		if(adc_read==1)							//проверка готовности АЦП	
			{

__disable_irq ();


				
				adc_input();							//ввод данных АЦП	
				

//				mask = 0xFF & adc_sample[0]>>8;
//adc = adc_sample[0]>>8;
//adc |= (adc_sample[0] & 0xFF00);
Write_to_FRAM (begin_oscill, adc_sample[0]);
begin_oscill++;
/*				
	if(begin_oscill > 0x100)
	{
			while(1)
			{}
	}
*/		
				//	adc_sample_now=ADC_1[adc_sample_number];
				adc_sample_now=adc_sample[0];
				potok(0);
				ReIa=Re1;ImIa=Im1;
				Ia=1000*Modul(ReIa,ImIa)/1414;
				ReIa_g2=Re2;ImIa_g2=Re2;
				Ia_g2=1000*Modul(ReIa_g2,ImIa_g2)/1414;				
				Ia_2_1g=100*Ia_g2/Ia;
				
				adc_sample_now=adc_sample[1];
				potok(1);
				ReIb=Re1;ImIb=Im1;
				Ib=1000*Modul(ReIb,ImIb)/1414;				
				ReIb_g2=Re2;ImIb_g2=Re2;
				Ib_g2=1000*Modul(ReIb_g2,ImIb_g2)/1414;	
				Ib_2_1g=100*Ib_g2/Ib;				
				
				adc_sample_now=adc_sample[2];
				potok(2);
				ReIc=Re1;ImIc=Im1;
				Ic=1000*Modul(ReIc,ImIc)/1414;				
				ReIc_g2=Re2;ImIc_g2=Re2;
				Ic_g2=1000*Modul(ReIc_g2,ImIc_g2)/1414;				
				Ic_2_1g=100*Ic_g2/Ic;				
				I_3o_p=1000*Modul((ReIa+ReIb+ReIc),(ImIa+ImIb+ImIc));

				adc_sample_now=adc_sample[3];
				potok(3);
				Re3Io=Re1;Im3Io=Im1;				
				I_3o_u=1000*Modul(3*Re3Io,3*Im3Io);
				
				adc_sample_now=adc_sample[4];
				potok(4);
				ReUa=Re1;ImUa=Im1;
				Ua=1000*Modul(ReUa,ImUa)/1414;				
				
				adc_sample_now=adc_sample[5];
				potok(5);
				ReUb=Re1;ImUb=Im1;
				Ub=1000*Modul(ReUb,ImUb)/1414;				
				
				adc_sample_now=adc_sample[6];
				potok(6);
				ReUc=Re1;ImUc=Im1;
				Uc=1000*Modul(ReUc,ImUc)/1414;
				Uab=1000*Modul((ReUa-ReUb),(ImUa-ImUb))/1414;
				Ubc=1000*Modul((ReUb-ReUc),(ImUb-ImUc))/1414;			
				Uca=1000*Modul((ReUc-ReUa),(ImUc-ImUa))/1414;				
				U_3o_p=1000*Modul((ReUa+ReUb+ReUc),(ImUa+ImUb+ImUc));
				
				adc_sample_now=adc_sample[7];
				potok(7);
				Re3Uo=Re1;Im3Uo=Im1;	
				U_3o_u=1000*Modul(3*Re3Uo,3*Im3Uo);				
				



//				rtc_gettime (&timeread);
//				rtc_gettime(RTC_t *rtc);
//				time_count = ((uint32_t)RTC->CNTH << 16) | RTC->CNTL;
/*
				year=timeread.year;
				month=timeread.month;
				mday=timeread.mday;
				wday=timeread.wday;
				hour=timeread.hour;		
				min=timeread.min;
				sec=timeread.sec;	
				dst=timeread.dst;
*/
				//printf("123");
/*			
				//			data=hour;
				USART1->DR = timeread.hour;
				while ((USART1->SR & USART_SR_TXE) == 0);
*/
				//ART1->DR = 0x35;
__enable_irq ();
				adc_read=0;		//сброс флага готовности АЦП
				adc_sample_number++;

				if(adc_sample_number==24)		//проверка последний интервал выборок
					{	
						adc_sample_number=0;			//обнуление счетчика выборок АЦП	
					}
			}			

		
/*		
			if(command_in !=0)
				{
					command_in=0;
//				USART1_Send(inp[0]);
//				USART1_Send(inp[1]);
					switch(inp[0])
					{
						case	0x20	:	
							write_sec(0);											
						break;
						case	0x1F	:
							write_sec(inp[1]);
						break;		
						case	0x1E	:
							write_min(inp[1]);
						break;							
						case	0x1D	:
							write_hour(inp[1]);
						break;	
						case	0x1C	:
							write_mday(inp[1]);
						break;							
						case	0x1B	:
							write_month(inp[1]);
						break;	
						case	0x1A	:
							write_year(inp[1]);
						break;																
					}									
				inp[0]=0;
				inp[1]=0;				
				
			}
*/			
  }  
}

/*
// Обработчик всех прерываний от USART1
void USART1_IRQHandler(void) 
	{
  // Выясняем, какое именно событие вызвало прерывание. Если это приём байта в RxD - обрабатываем.
  if (USART1->SR & USART_SR_RXNE) 
		{
    // Сбрасываем флаг прерывания
    USART1->SR&=~USART_SR_RXNE; 			
		inp[n]=USART1->DR;
		n++;			
		if(n==2) 
			{
				n=0;
				command_in=1;
			}
		}
	}
//============================================
*/
void SysTick_Handler(void)
{

//флаг готовности АЦП
adc_read=1;
mlsec++;
if(mlsec==1000)
	{mlsec=0;
//	timeUART();
	}

}
/*===================================================================*/
void Delay_mks(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;
  while(TimingDelay != 0)
	{
		TimingDelay--;
	}
		;
}
//Функция временной задержки
void Delay_ms(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;
  while(TimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}

