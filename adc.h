#include "stm32f10x.h"
#include "def_all.h"

//#define	ADC_MASK	0xFFFF
extern	void	oscill_read(void);



uint16_t idxIN=0;// idxOUT=0
uint16_t buffer [BUF_SIZE];
//uint16_t	adc;
//buffer[idxIN++] = value;
//idxIN &= BUF_MASK;
extern	uint32_t	length_oscill;
extern	uint32_t	begin_oscill;
extern void Delay_mks(__IO uint32_t nTime);
int16_t adc_sample[8];
extern	u8	oscill;
extern	void			Write_to_FRAM (uint32_t AddrFRAM, uint16_t DataFRAM);
void	adc_output_to_OZU(void);
void	adc_output_to_FRAM(void);
void	adc_output_to_FRAM_and_buf(void);
uint16_t	length_buf=0;

extern	uint16_t	adc_sample_test[8][24];

extern	uint16_t	adc_sample_test0[24];
extern	uint16_t	adc_sample_test1[24];
extern	uint16_t	adc_sample_test2[24];
extern	uint16_t	adc_sample_test3[24];
extern	uint16_t	adc_sample_test4[24];
extern	uint16_t	adc_sample_test5[24];
extern	uint16_t	adc_sample_test6[24];
extern	uint16_t	adc_sample_test7[24];

extern int	adc_sample_number;
