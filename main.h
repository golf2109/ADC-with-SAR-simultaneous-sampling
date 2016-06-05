#include "stm32f10x.h"
#include	"var.h"
#include "def_all.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define    DWT_CYCCNT       *(volatile unsigned long *)0xE0001004
#define    DWT_CONTROL   *(volatile unsigned long *)0xE0001000
#define    SCB_DEMCR         *(volatile unsigned long *)0xE000EDFC
#define    DBGMCU_CR         *(volatile unsigned long *)0xE0042004
#define DMA_BUFFER_SIZE		8

extern	void	initAll(void);
extern	void RCC_Configuration(void);
extern	void GPIO_Configuration(void);
extern	void UART_Configuration(void);
extern	void NVIC_Configuration(void);
extern	void IWDG_Configuration(void);
extern	void	DMA_Configuration(void);

extern	void out_stm (void);
extern	void	input_stm (void);
extern	void	adc_DMA(void);
extern	void USART1_Send(u8 chr);
extern	void	write_sec(uint32_t	sec);
extern	void	write_min(uint32_t	min);
extern	void	write_hour(uint32_t hour);
extern	void	write_mday(uint32_t	min);
extern	void	write_month(uint32_t	min);
extern	void	write_year(uint32_t	min);
extern	void	oscill_read(uint8_t number_oscill);
extern	void	timeUART_DMA	(void);
extern	void	write_begin_time (void);
static __IO uint32_t TimingDelay;
//static u32	TimingDelay;
int	adc_read=0;
extern int16_t	adc_sample[8];
extern	uint32_t	begin_oscill;
extern	uint32_t	length_oscill;
extern	void potok(void);
extern	void	adc_input(void);
extern	void dft(char adc_ch);

extern	void ReadFLASH(u16 *Destination, u32 BegAddrFLASH, u16 SizeFLASH);
extern	void	FRAM_init	(void);
extern	void	FRAM_setting(void);

void Delay_mks(__IO uint32_t nTime);
extern	void	oscill_tyme(void);
extern	void	Write_to_FRAM (uint32_t AddrFRAM, uint16_t DataFRAM);
extern	uint32_t	Read_from_FRAM (uint32_t AddrFRAM);
extern	void	adc_output_to_OZU(void);
extern	void	RtcCorr(void);
extern	int	RtcInit(void);
extern	uint32_t ModAngl(int32_t Re,int32_t Im);
extern	uint32_t Mod(int32_t Re,int32_t Im);
extern	uint32_t	ang;

extern	uint16_t idxIN;
extern	uint16_t buffer [BUF_SIZE];

u32	zzz,zzz1,zzz2;
u8	uart_in[2];
u8	buff;
u8	oscill=1;
uint8_t number_oscill=1;
uint16_t	mlsec;
extern	int	adc_sample_now;
extern	int	adc_sample_number;
//u32	year,month,mday,wday,hour,min,sec,dst;
uint8_t dataBuffer[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

uint16_t	adc_sample_test[8][24];

uint16_t	adc_sample_test0[24];
uint16_t	adc_sample_test1[24];
uint16_t	adc_sample_test2[24];
uint16_t	adc_sample_test3[24];
uint16_t	adc_sample_test4[24];
uint16_t	adc_sample_test5[24];
uint16_t	adc_sample_test6[24];
uint16_t	adc_sample_test7[24];

u32	AddrFRAM  = 0;
u16	DataWriteFRAM;
u16	DataReadFRAM;
u16	read0,read1,read2,read3,read4,read5,read6,read7;
uint32_t	time_count;
u8	inp[8];
u8	cmd, cmd1,n=0,v,command_in=0;
uint32_t	fram_out;
uint32_t	mask;
u16	avar;
uint16_t	mem;

uint8_t TxBuffer[22];
uint8_t RxBuffer[8];
USART_InitTypeDef USART_InitStructure;
GPIO_InitTypeDef GPIO_InitStructure;

uint8_t	adc_number;
int32_t*	addr_angl;
int32_t	uk_addr_angl;

const	float PI=3.141593;

uint16_t in_porta;
uint16_t in_porta1;
uint16_t	number_send_byte=0;
uint8_t	izmer[101];
uint32_t	input[110];
uint32_t	flag_out;
extern uint16_t	length_buf;
extern	u32	zzz1_m1,zzz1_m2,zzz1_m3,zzz1_m4,zzz1_m5;
extern	uint32_t my_sq;
extern	int	aa,bb,zn2;
char	adc_ch;
