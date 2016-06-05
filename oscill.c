#include "stm32f10x.h"
#include <stdio.h>
extern	void	Write_to_FRAM (uint32_t AddrFRAM, uint16_t DataFRAM);
extern	uint32_t	Read_from_FRAM (uint32_t AddrFRAM);
extern	void Delay_mks(__IO uint32_t nTime);

extern	uint32_t	fram_out;

uint8_t		N_ocill;		//номер текущей осциллограммы
uint8_t		day_oscill=0x31;
uint8_t		month_oscill=0x12;
uint8_t		year_oscill=0x14;
uint8_t		hour_oscill=0x23;
uint8_t		min_oscill=0x59;
uint8_t		sec_oscill=0x59;
uint8_t		big_millisec=0x39;
uint8_t		little_millise=0x39;

uint32_t	begin_oscill=0x00000000;		//начало текущей осциллограммы
uint32_t	length_oscill=0x00001000;		//длина текущей осциллограммы

void	FRAM_init	(void)
{
	Write_to_FRAM(0x0000,0xAA55);//инициализация новой FRAM
	Write_to_FRAM(0x0001,0x11);//флаг необходимости перехода на новую осциллограмму
	Write_to_FRAM(0x0002,0x31);//N_ocill   номер текущей осциллограммы

	Write_to_FRAM(0x0010,0x01);//N_ocill         номер осциллограммы
	Write_to_FRAM(0x0011,0x31);//day_oscill      число		
	Write_to_FRAM(0x0012,0x12);//month_oscill    месяц
	Write_to_FRAM(0x0013,0x14);//year_oscill     год		
	Write_to_FRAM(0x0014,0x23);//hour_oscill     часы
	Write_to_FRAM(0x0015,0x59);//min_oscill      минуты
	Write_to_FRAM(0x0016,0x59);//sec_oscill      секунды		
	Write_to_FRAM(0x0017,0x39);//big_millisec    сотни миллисекунд
	Write_to_FRAM(0x0018,0x39);//little_millisec десятки и единицы миллисекунд
	Write_to_FRAM(0x0019,0xAA);//begin_oscill    старший байт адреса начала
	Write_to_FRAM(0x001A,0xBB);//begin_oscill    младший байт адреса начала	
	Write_to_FRAM(0x001B,0xCC);//length_oscill   длина осциллограммы
	
}

void	FRAM_setting	(void)
{
	N_ocill=1;   //Read_from_FRAM (0x0001);
	begin_oscill=0x00000100;      //Read_from_FRAM
	length_oscill=0x00001000;   //Read_from_FRAM
}


void	oscill_read(void)
{
	uint16_t	read0;
	fram_out=0;


				while(fram_out<0x3009)	
					{					
			read0=Read_from_FRAM (fram_out);												  																								
			printf("%u;",read0);
			fram_out++;	
			read0=Read_from_FRAM (fram_out);						
			printf("%u;",read0);
			fram_out++;	
			read0=Read_from_FRAM (fram_out);						
			printf("%u;",read0);
			fram_out++;	
			read0=Read_from_FRAM (fram_out);						
			printf("%u;",read0);
			fram_out++;	
			read0=Read_from_FRAM (fram_out);						
			printf("%u;",read0);
			fram_out++;	
			read0=Read_from_FRAM (fram_out);						
			printf("%u;",read0);
			fram_out++;	
			read0=Read_from_FRAM (fram_out);						
			printf("%u;",read0);
			fram_out++;	
			read0=Read_from_FRAM (fram_out);			
			printf("%u;\r\n",read0);
			fram_out++;							
					}	
//		while(1){}		
}			

