#include "stm32f10x.h"
extern	int16_t adc_sample[8];
extern	int	adc_sample_test0[];
extern	int	adc_sample_number;
extern	uint8_t TxBuffer[22];
u8	Bufer[32];
u8	res;
unsigned char getch_Uart(USART_TypeDef* USARTx)
{
	/*	while(USART_GetFlagStatus(USARTx,USART_FLAG_RXNE) == RESET){}

	return USART_ReceiveData(USARTx);
*/
	res=USART1->DR;
	return (res);
}


//	читаем текстовую строку с UART, до ввода <enter>. Максимальная длина строки 512Байт
void read_str_uart(USART_TypeDef* USARTx,unsigned char* s)
{
	unsigned char temp;
	unsigned int index=0;
	while(index<32)
	{
		temp=getch_Uart(USARTx);
		if(temp!=13)
		{
			*s++=temp;
		}
		else
		{
			index=32;
		}
		index++;
	}
}
//===============================================================
void	adc_DMA	(void)
{
		u8	aaa;
		u8	b5,b4,b3,b2,b1;

		b5=adc_sample_test0[adc_sample_number]/10000;
		b5=b5 &0xF;
		aaa=b5|0x30;
		TxBuffer[0]=aaa;
		b4=(adc_sample_test0[adc_sample_number]-b5*10000)/1000;
		b4=b4 &0xF;
		aaa=b4|0x30;	
		TxBuffer[1]=aaa;	
    b3=(adc_sample_test0[adc_sample_number]-b5*10000-b4*1000)/100;
		b3=b3 &0xF;	
	  aaa=b3|0x30;
		TxBuffer[2]=aaa;
	  b2=(adc_sample_test0[adc_sample_number]-b5*10000-b4*1000-b3*100)/10;
		b2=b2 &0xF;
		aaa=b2|0x30;
		TxBuffer[3]=aaa;	
		b1=(adc_sample_test0[adc_sample_number]-b5*10000-b4*1000-b3*100-b2*10);
		b1=b1 &0xF;	
	  aaa=b1|0x30;
		TxBuffer[4]=aaa;			
	TxBuffer[20]=0x0D;
	TxBuffer[21]=0x0A;		
}
