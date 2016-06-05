#include "stm32f10x.h"
//#include	"var.h"

#define BAUDRATE		921600
#define DMA_BUFFER_SIZE		8

//	IWDG
#define IWDG_ACCESS			0x5555
#define IWDG_RL					0xaaaa
#define IWDG_EN					0xcccc

DMA_InitTypeDef dma;
//uint8_t dataBuffer[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};// '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
extern	uint8_t dataBuffer[16];
extern	uint8_t TxBuffer[22];
extern	uint8_t RxBuffer[8];
uint8_t   dt[16];

void RCC_Configuration(void)
{
  __asm {
/*
		loop: LDRB    ch, [src], #1
					STRB    ch, [dst], #1
					CMP     ch, #0
					BNE     loop		
*/		
		NOP
		NOP
		NOP
		NOP
  }
  // Enable HSE
	RCC->CR|=RCC_CR_HSEON;
	//RTC
	RCC->CR|=RCC_BDCR_RTCSEL;
	RCC->CR|=RCC_BDCR_RTCEN;
  // Flash 1 wait state
	FLASH->ACR=FLASH_ACR_PRFTBE|FLASH_ACR_LATENCY_2;
	// USB clock=PLLCLK, HCLK=SYSCLK, PCLK2=HCLK, PCLK1=HCLK/2, PLLCLK=8MHz*9=72MHz
	RCC->CFGR=RCC_CFGR_PLLMULL9|RCC_CFGR_PLLSRC_HSE|RCC_CFGR_PPRE1_DIV2;
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
//	RCC->APB1ENR=RCC_APB1ENR_SPI2EN|RCC_APB1ENR_TIM2EN;
	// APB2ENR SPI1, TIM1, GPIOC, GPIOB, GPIOA, AFIO clock enable
//	RCC->APB2ENR=RCC_APB2ENR_SPI1EN|RCC_APB2ENR_TIM1EN|RCC_APB2ENR_IOPCEN|RCC_APB2ENR_IOPBEN|RCC_APB2ENR_IOPAEN|RCC_APB2ENR_AFIOEN;
RCC->APB2ENR=RCC_APB2ENR_IOPCEN|RCC_APB2ENR_IOPBEN|RCC_APB2ENR_IOPAEN|RCC_APB2ENR_AFIOEN;
	// AHBENR DMA1 clock enable
//	RCC->AHBENR=RCC_AHBENR_DMA1EN;
	// PWR_CR
	PWR->CR=PWR_CR_PLS_2V5|PWR_CR_PVDE;
}
void my_RCC_Configuration(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN; //????????? ???????????? ????? A
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
	GPIOA->CRH=0x33888833;	//PA13 PA12 PA11 PA10!!! - INPUT
	GPIOA->ODR=0x000001FF;	//PA8 - INT_ATM запрос на прерывание к Atmega
	//port B - IN
	GPIOB->CRL=0x88888888;
	GPIOB->CRH=0x88888888;
	//port C - OUT
//	GPIOC->CRH=0x22222222;		занято часами

//AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_DISABLE;
AFIO->MAPR  = 0x02000000;//отключаем выводы JTAG 
//AFIO->MAPR  = 0x04000000;//отключаем выводы JTAG SW
AFIO->EVCR =0xAD; //PC13-calibration clock output enable
BKP->RTCCR |=	BKP_RTCCR_CCO; //Setting this bit outputs the 
//RTC clock with a frequency divided by 64 on the TAMPER pin	

//EXTI->FTSR |= EXTI_FTSR_TR11;
//EXTI->RTSR = 0;	

//EXTI->IMR |=EXTI_IMR_MR11;// Разрешаем прерывания в периферии для вывода 11
//NVIC_EnableIRQ (EXTI15_10_IRQn);	
}
//===============================================================================

void UART_Configuration(void)
{

	RCC->APB2ENR	|= RCC_APB2ENR_USART1EN;	//включение тактовой частоты
// Устанавливаем PA9  (TX) на альтернавтивную функцию выхода push-pull при 50 MHz
// Установим PA10 (RX) на floating input
    GPIOA->CRH = 0x000004B0;
//		USART1->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
	
	// Включаем модули USART1 и GPIOA, а также включаем альтернативные функции выходов
  RCC->APB2ENR|= RCC_APB2ENR_USART1EN | RCC_APB2ENR_IOPAEN | RCC_APB2ENR_AFIOEN;
  // Контакт PA9 будет выходом с альтернативной функцией, а контакт PA10 - входом
  GPIOA->CRH  |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9_0 | GPIO_CRH_CNF10_0;
  // Настраиваем регистр тактирования
  USART1->BRR  = 72000000/921600;                // set baudrate	
	//USART1->BRR  = 3;//1-4500000 2-2250000 3-1500000
  // Включаем TxD и RxD USART
  USART1->CR1 |= USART_CR1_TE | USART_CR1_RE;
  // Запускаем модуль USART
  USART1->CR1 |= USART_CR1_UE;
  // Разрешаем прерывание по приёму информации с RxD
//  USART1->CR1 |= USART_CR1_RXNEIE;
  // Назначаем обработчик для всех прерываний от USART1
//  NVIC_EnableIRQ(USART1_IRQn);	
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
/*
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
*/
	
  DMA_InitTypeDef DMA_InitStructure;

  /* USARTy TX DMA1 Channel (triggered by USARTy Tx event) Config */
  DMA_DeInit(DMA1_Channel4);  
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&USART1->DR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)TxBuffer;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST;
  DMA_InitStructure.DMA_BufferSize = 22;
  DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
  DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
  DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
  DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;
  DMA_Init(DMA1_Channel4, &DMA_InitStructure);

  /* USARTy RX DMA1 Channel (triggered by USARTy Rx event) Config */
  DMA_DeInit(DMA1_Channel5);  
  DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&USART1->DR;
  DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)RxBuffer;
  DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
  DMA_InitStructure.DMA_BufferSize = 16;
  DMA_Init(DMA1_Channel5, &DMA_InitStructure);	
	
	
}
//============================================================================


void	initAll(void)
{	
GPIO_InitTypeDef port;
USART_InitTypeDef usart;
 
/*******************************************************************/
RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);	
 
DMA_StructInit(&dma);
dma.DMA_PeripheralBaseAddr = (uint32_t)&(USART1->DR);
dma.DMA_MemoryBaseAddr = (uint32_t)&dataBuffer[0];
dma.DMA_DIR = DMA_DIR_PeripheralDST;
dma.DMA_BufferSize = DMA_BUFFER_SIZE;
dma.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
dma.DMA_MemoryInc = DMA_MemoryInc_Enable;
dma.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
dma.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
DMA_Init(DMA1_Channel4, &dma);	
 
GPIO_StructInit(&port);
port.GPIO_Mode = GPIO_Mode_AF_PP;
port.GPIO_Pin = GPIO_Pin_9;
port.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(GPIOA, &port);
 
port.GPIO_Mode = GPIO_Mode_AF_PP;
port.GPIO_Pin = GPIO_Pin_10;
port.GPIO_Speed = GPIO_Speed_50MHz;
GPIO_Init(GPIOA, &port);
 
USART_StructInit(&usart);
usart.USART_BaudRate = BAUDRATE;
USART_Init(USART1, &usart);

//while(USART1->SR & USART_SR_RXNE) USART1->DR; //???????? ???????

DMA1_Channel5->CCR = 0; //????????? ?????? ??????
DMA1_Channel5->CPAR = (uint32_t)dt;
DMA1_Channel5->CMAR = (uint32_t)&USART1->DR; //????? ?????? ? ??????
DMA1_Channel5->CNDTR = 16; //????????? ?????????? ?????? ??? ??????

DMA1->IFCR |= DMA1_FLAG_TC5;
USART_ClearFlag(USART1, USART_FLAG_RXNE|USART_FLAG_IDLE);
DMA1_Channel5->CCR = DMA_CCR5_MINC|DMA_CCR5_EN; //????????? ?????? ??????

//GPIOA->CRL=0x33333333;
}
