#include	"rtc.h"

void USART1_Send(u8 chr);
void USART1_Send_String(char* str);
RTC_t	timeread;
RTC_t	timeset;
void	timeUART	(void);
void	timeUART_DMA	(void);
void	writeRTC(void);
void	write_begin_time (void);
void	write_sec(uint32_t	sec);
void	write_min(uint32_t	min);
void	write_hour(uint32_t	hour);
void	write_mday(uint32_t	min);
void	write_month(uint32_t	min);
void	write_year(uint32_t	min);

void	write_begin_time (void);
void	oscill_tyme(void);

extern	void		Write_to_FRAM (uint32_t AddrFRAM, uint16_t DataFRAM);
extern	uint16_t	mlsec;
extern	uint8_t TxBuffer[22];
