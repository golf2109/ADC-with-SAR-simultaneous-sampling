#include <stm32f10x.h>
#include <stdio.h>

int sendchar(int ch);
struct __FILE {int handle;};
FILE __stdout;


int fputc(int ch, FILE *f) {
return (sendchar(ch));
}

int sendchar(int ch)
{
while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
USART_SendData(USART1, ch);
return 0;
}



