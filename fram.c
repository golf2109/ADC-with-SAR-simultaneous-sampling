#include "stm32f10x.h"
#include "fram.h"
extern	void Delay_mks(__IO uint32_t nTime);

void	 Write_to_FRAM (uint32_t AddrFRAM, uint16_t DataFRAM)
{
	GPIOB->CRL=0x33333333;
	GPIOB->CRH=0x33333333;	
	GPIOB->ODR=AddrFRAM;
				Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR5;	//CLK1-ADR  младший адрес FRAM положительный фронт
				Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BS5;
AddrFRAM=AddrFRAM >> 16;			//получение старшей части адреса
	GPIOB->ODR=AddrFRAM;
				Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR15;	//CLK2-ADR  младший адрес FRAM положительный фронт
				Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BS15;

	GPIOB->ODR=DataFRAM;	
				Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR2;	//CS FRAM=0
				Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR6;	//WR=0
				Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BS6;	//WR=1
			Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BS2;	//CS FRAM=1
	//port B - IN
	GPIOB->CRL=0x88888888;
	GPIOB->CRH=0x88888888;	
}
//============================================================================
uint32_t	Read_from_FRAM (uint32_t AddrFRAM)
{
	uint16_t	read;
	GPIOB->CRL=0x33333333;
	GPIOB->CRH=0x33333333;	
	GPIOB->ODR=AddrFRAM;
GPIOA->BSRR=GPIO_BSRR_BS5;	//CLK1-ADR  младший адрес FRAM положительный фронт
				Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR5;
AddrFRAM=AddrFRAM >> 16;			//получение старшей части адреса
	GPIOB->ODR=AddrFRAM;
GPIOA->BSRR=GPIO_BSRR_BS15;	//CLK2-ADR  младший адрес FRAM положительный фронт
				Delay_mks(1);
GPIOA->BSRR=GPIO_BSRR_BR15;

	GPIOB->CRL=0x88888888;
	GPIOB->CRH=0x88888888;
	
GPIOA->BSRR=GPIO_BSRR_BR2;	//CS FRAM=0
GPIOA->BSRR=GPIO_BSRR_BR7;	//RD=0	
				Delay_mks(1);
	read=GPIOB->IDR;
GPIOA->BSRR=GPIO_BSRR_BS7;	//RD=1
GPIOA->BSRR=GPIO_BSRR_BS2;	//CS FRAM=1

	return(read);
}
//===================================================================================

