#include "stm32f10x.h"

//размер буфера обязательно равен степени двойки!
#define BUF_SIZE  512
#define	ADC_MASK	0xFFFF
#define BUF_MASK  (BUF_SIZE-1)
