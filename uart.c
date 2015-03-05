#include "stm32f10x.h"

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
