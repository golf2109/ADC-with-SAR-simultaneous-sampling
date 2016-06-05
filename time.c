#include "stm32f10x.h"
#include	"time.h"
#include <stdio.h>
int	Ya;

void	oscill_tyme()
{
	rtc_gettime (&timeread);
	Write_to_FRAM (50,	timeset.year);
	Write_to_FRAM (51,	timeset.month);
	Write_to_FRAM (52,	timeset.mday);
	Write_to_FRAM (53,	timeset.hour);
	Write_to_FRAM (54,	timeset.min);
	Write_to_FRAM (55,	timeset.sec);
	Write_to_FRAM (56,	mlsec);

}

void	write_begin_time (void)
{
	int	time_year;
	rtc_gettime (&timeread);
	time_year=timeread.year;
	if(time_year<0x7DE)
	{		
	timeset.year=0x7DE;
	timeset.month=9;
	timeset.mday=26;
	timeset.hour=0x17;
	timeset.min=0x17;						
	timeset.sec=0;
	writeRTC();	
	}	
}

void	write_sec(uint32_t	sec)
{		
	rtc_gettime (&timeread);
	timeset.year=timeread.year;
	timeset.month=timeread.month;
	timeset.mday=timeread.mday;
	timeset.hour=timeread.hour;
	timeset.min=timeread.min;						
	timeset.sec=sec;
	writeRTC();
}
void	write_min(uint32_t	min)
{
	rtc_gettime (&timeread);
	timeset.year=timeread.year;
	timeset.month=timeread.month;
	timeset.mday=timeread.mday;
	timeset.hour=timeread.hour;
	timeset.min=min;						
	timeset.sec=timeread.sec;
	writeRTC();
}

void	write_hour(uint32_t	hour)
{
	rtc_gettime (&timeread);
	timeset.year=timeread.year;
	timeset.month=timeread.month;
	timeset.mday=timeread.mday;
	timeset.hour=hour;
	timeset.min=timeread.min;						
	timeset.sec=timeread.sec;
	writeRTC();
}

void	write_mday(uint32_t	mday)
{
	rtc_gettime (&timeread);
	timeset.year=timeread.year;
	timeset.month=timeread.month;
	timeset.mday=mday;
	timeset.hour=timeread.hour;
	timeset.min=timeread.min;						
	timeset.sec=timeread.sec;
	writeRTC();
}

void	write_month(uint32_t	month)
{
	rtc_gettime (&timeread);
	timeset.year=timeread.year;
	timeset.month=month;
	timeset.mday=timeread.mday;
	timeset.hour=timeread.hour;
	timeset.min=timeread.min;						
	timeset.sec=timeread.sec;
	writeRTC();
}

void	write_year(uint32_t	year)
{
	rtc_gettime (&timeread);
	timeset.year=year+0x7D0;
	timeset.month=timeread.month;
	timeset.mday=timeread.mday;
	timeset.hour=timeread.hour;
	timeset.min=timeread.min;						
	timeset.sec=timeread.sec;
	writeRTC();
}
	void	writeRTC(void)	
{
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;  
//		RCC->APB1ENR |=  RCC_APB1ENR_BKPEN; 						
    PWR->CR |= PWR_CR_DBP; // enable access to RTC, BDC registers
//    RTC->CRL &= ~RTC_CRL_RSF; // Wait syncronization
    RTC->CRL |= RTC_CRL_CNF; // Enter configuration mode
rtc_settime (&timeset);
    RTC->CRL &= ~RTC_CRL_CNF; // Leave configuration mode
    // TODO dirty hack 		
		while( (RTC->CRL & RTC_CRL_RTOFF) == 0 ){} ; // Poll RTOFF, wait until its value goes to ‘1’ to check the end of the write operation.
    PWR->CR &= ~PWR_CR_DBP; // disable access to RTC registers	
}

void USART1_Send(u8 chr) {
  while(!(USART1->SR & USART_SR_TC));
  USART1->DR = chr;
}
void USART1_Send_String(char* str) {
  int i=0;
  while(str[i])
    USART1_Send(i++);
}

//===============================================
//выдча в UART текущего времени
void	timeUART	(void)
{
		u8	aaa;
		u8	bbb;

	rtc_gettime (&timeread);	//получение текущего значения часов
		aaa=timeread.mday/0xA;
		aaa=aaa|0x30;
		USART1_Send(aaa);
		bbb=timeread.mday%0xA;
		aaa=bbb|0x30;
		USART1_Send(aaa);
		USART1_Send(0x2D);	

//		rtc_gettime (&timeread);
		aaa=timeread.month/0xA;
		aaa=aaa|0x30;
		USART1_Send(aaa);
		bbb=timeread.month%0xA;
		aaa=bbb|0x30;
		USART1_Send(aaa);
		USART1_Send(0x2D);

//		rtc_gettime (&timeread);
    aaa=timeread.year-0x7D0;
		Ya=aaa;
		aaa=aaa/0xA;		
		aaa=aaa|0x30;
		USART1_Send(aaa);
		bbb=(timeread.year-0x7D0)%0xA;
		aaa=bbb|0x30;
		USART1_Send(aaa);
		USART1_Send(0x20);	
		USART1_Send(0x20);	
		USART1_Send(0x20);	
		USART1_Send(0x20);	
		
//		rtc_gettime (&timeread);
		aaa=timeread.hour/0xA;
		aaa=aaa|0x30;
		USART1_Send(aaa);
		bbb=timeread.hour%0xA;
		aaa=bbb|0x30;
		USART1_Send(aaa);
		USART1_Send(0x3A);

//		rtc_gettime (&timeread);
		aaa=timeread.min/0xA;
		aaa=aaa|0x30;
		USART1_Send(aaa);
		bbb=timeread.min%0xA;
		aaa=bbb|0x30;
		USART1_Send(aaa);
		USART1_Send(0x3A);
	
//		rtc_gettime (&timeread);
		aaa=timeread.sec/0xA;
		aaa=aaa|0x30;
		USART1_Send(aaa);
		bbb=timeread.sec%0xA;
		aaa=bbb|0x30;
		USART1_Send(aaa);
		USART1_Send(0xD);
		USART1_Send(0xA);
}

//===============================================
//выдча в UART текущего времени
void	timeUART_DMA	(void)
{
		u8	aaa;
		u8	bbb;

	rtc_gettime (&timeread);	//получение текущего значения часов
		aaa=timeread.mday/0xA;
		aaa=aaa|0x30;
	TxBuffer[0]=aaa;
//		USART1_Send(aaa);
		bbb=timeread.mday%0xA;
		aaa=bbb|0x30;
	TxBuffer[1]=aaa;
//		USART1_Send(aaa);
	TxBuffer[2]=0x2D;
//		USART1_Send(0x2D);	

//		rtc_gettime (&timeread);
		aaa=timeread.month/0xA;
		aaa=aaa|0x30;
	TxBuffer[3]=aaa;	
//		USART1_Send(aaa);
		bbb=timeread.month%0xA;
		aaa=bbb|0x30;
	TxBuffer[4]=aaa;		
//		USART1_Send(aaa);
	TxBuffer[5]=0x2D;
//		USART1_Send(0x2D);

//		rtc_gettime (&timeread);
    aaa=timeread.year-0x7D0;
		Ya=aaa;
		aaa=aaa/0xA;		
		aaa=aaa|0x30;
	TxBuffer[6]=aaa;		
//		USART1_Send(aaa);
		bbb=(timeread.year-0x7D0)%0xA;
		aaa=bbb|0x30;
	TxBuffer[7]=aaa;		
//		USART1_Send(aaa);
	TxBuffer[8]=0x20;
	TxBuffer[9]=0x20;
	TxBuffer[10]=0x20;
	TxBuffer[11]=0x20;	
//		USART1_Send(0x20);	
//		USART1_Send(0x20);	
//		USART1_Send(0x20);	
//		USART1_Send(0x20);	
		
//		rtc_gettime (&timeread);
		aaa=timeread.hour/0xA;
		aaa=aaa|0x30;
	TxBuffer[12]=aaa;		
//		USART1_Send(aaa);
		bbb=timeread.hour%0xA;
		aaa=bbb|0x30;
	TxBuffer[13]=aaa;		
//		USART1_Send(aaa);
	TxBuffer[14]=0x3A;		
//		USART1_Send(0x3A);

//		rtc_gettime (&timeread);
		aaa=timeread.min/0xA;
		aaa=aaa|0x30;
	TxBuffer[15]=aaa;			
//		USART1_Send(aaa);
		bbb=timeread.min%0xA;
		aaa=bbb|0x30;
	TxBuffer[16]=aaa;			
//		USART1_Send(aaa);
	TxBuffer[17]=0x3A;		
//		USART1_Send(0x3A);
	
//		rtc_gettime (&timeread);
		aaa=timeread.sec/0xA;
		aaa=aaa|0x30;
	TxBuffer[18]=aaa;			
//		USART1_Send(aaa);
		bbb=timeread.sec%0xA;
		aaa=bbb|0x30;
	TxBuffer[19]=aaa;			
//		USART1_Send(aaa);
	TxBuffer[20]=0x0D;
//		USART1_Send(0xD);
	TxBuffer[21]=0x0A;		
//		USART1_Send(0xA);
}
