/* ************************************************************************
; Project:	PC83-AB2-AI
;	Release:	13.05.10.
;	File:			crc16.h
;*********************************************************************** */
#include "stm32f10x.h"

u16 CalcCRC16(u8 *Buffer, u16 SizeBuf);

u16 UpdateCRC16(u16 PrevCRC16, u8 CurrData);
