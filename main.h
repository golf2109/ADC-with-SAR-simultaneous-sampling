#include "stm32f10x.h"
#include	"var.h"
//#include	"time.h"
//#include	"rtc.h"
#include <math.h>
#include <stdio.h>
#define    DWT_CYCCNT       *(volatile unsigned long *)0xE0001004
#define    DWT_CONTROL   *(volatile unsigned long *)0xE0001000
#define    SCB_DEMCR         *(volatile unsigned long *)0xE000EDFC
#define DMA_BUFFER_SIZE		8
extern	void USART1_Send(u8 chr);
extern	void	write_sec(uint32_t	sec);
extern	void	write_min(uint32_t	min);
extern	void	write_hour(uint32_t hour);
extern	void	write_mday(uint32_t	min);
extern	void	write_month(uint32_t	min);
extern	void	write_year(uint32_t	min);
extern	void	timeUART	(void);
static __IO uint32_t TimingDelay;
//static u32	TimingDelay;
int	adc_read=0;
extern uint32_t	adc_sample[8];
extern uint32_t	adc_sample_1[8];
extern	uint32_t	begin_oscill;
extern	uint32_t	length_oscill;
extern	void potok(int	adc_ch);
extern	void	adc_input(void);
extern	void ReadFLASH(u16 *Destination, u32 BegAddrFLASH, u16 SizeFLASH);
extern	void	FRAM_init	(void);
extern	void	FRAM_setting(void);
void Delay_ms(__IO uint32_t nTime);
void Delay_mks(__IO uint32_t nTime);

extern	void			Write_to_FRAM (uint32_t AddrFRAM, uint16_t DataFRAM);
extern	uint32_t	Read_from_FRAM (uint32_t AddrFRAM);
extern	void	adc_output_OZU(void);
extern	void	RtcCorr(void);
extern	int	RtcInit(void);
extern	uint32_t ModAngl(int32_t Re,int32_t Im,uint32_t *ang);
extern	uint32_t Modul(int32_t Re,int32_t Im);
extern	uint32_t	ang;
u32	zzz=0;
u8	uart_in[2];
u8	buff;
u8	oscill;
u32	mlsec;
extern	int	adc_sample_now;
extern	int	adc_sample_number;
//u32	year,month,mday,wday,hour,min,sec,dst;
uint8_t dataBuffer[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
u32	AddrFRAM  = 0;
u16	DataWriteFRAM;
u16	DataReadFRAM;
u16	read0,read1,read2,read3,read4,read5,read6,read7;
uint32_t	time_count;
u8	inp[8];
u8	cmd, cmd1,n=0,v,command_in=0;
uint32_t	fram_out;
uint32_t	mask;
