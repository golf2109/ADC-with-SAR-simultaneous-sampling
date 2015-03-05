#include "stm32f10x.h"
#define FLASH_KEY1               ((u32)0x45670123)
#define FLASH_KEY2               ((u32)0xCDEF89AB)
u16 *BufFLASH;
u32 BegAddrFLASH;
u16 NumFLASH;
//u16 ReStarts __attribute__((at(0x20004F00)));
//================================================================================
void WriteFLASH(u16 *Source, u32 BegAddr, u16 SizeFLASH)
{
  BufFLASH=Source;
  BegAddrFLASH=BegAddr;
  NumFLASH=SizeFLASH>>1;
  // Authorize the FPEC Access
  FLASH->KEYR=FLASH_KEY1;		
  FLASH->KEYR=FLASH_KEY2;		
	// FLASH_ErasePage
  while(FLASH->SR & FLASH_SR_BSY);		// Wait for completion of previous operation
  // if the previous operation is completed, proceed to erase the page
	FLASH->CR|=FLASH_CR_PER;
  FLASH->AR=BegAddr;
  FLASH->CR|=FLASH_CR_STRT;	//
  while(FLASH->SR & FLASH_SR_BSY);		// Wait for completion of previous operation    
	// if the erase operation is completed, disable the PER Bit
	FLASH->CR&=(~FLASH_CR_PER);
	// program enable
 	FLASH->CR|=FLASH_CR_PG;
		// фоновая запись во FLASH
		
		while (NumFLASH && ((FLASH->SR & FLASH_SR_BSY)==0))
    {
    	// Proceed to program the new data
    	*(vu16*)BegAddrFLASH=*BufFLASH++;
			BegAddrFLASH+=sizeof(u16);
			if (--NumFLASH==0)
			{
				FLASH->CR&=(~FLASH_CR_PG);
				FLASH->CR|=FLASH_CR_LOCK;
			}
		}	
	}			
/*				
			for (i = 0; i < count; i += 2) 
				{
					*(volatile unsigned short*)(address + i) = (((unsigned short)data[i + 1]) << 8) + data[i];
					while (!(FLASH->SR & FLASH_SR_EOP));
					FLASH->SR = FLASH_SR_EOP;				
				}
*/

//================================================================================
void ReadFLASH(u16 *Destination, u32 BegAddrFLASH, u16 SizeFLASH)
{
	vu16* BegAddr=(vu16*)BegAddrFLASH;
	SizeFLASH>>=1;
  while(FLASH->SR & FLASH_SR_BSY);		// Wait for completion of previous write
  while (SizeFLASH--)
  {
    *Destination++=*BegAddr++;				// Read FLASH
  }
}
