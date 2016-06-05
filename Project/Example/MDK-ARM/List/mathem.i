#line 1 "..\\..\\..\\mathem.c"
#line 1 "..\\..\\..\\mathem.h"
#line 1 "..\\..\\..\\stm32f10x.h"







































 



 



 
    






  


 
  


 

#line 75 "..\\..\\..\\stm32f10x.h"


















 





#line 107 "..\\..\\..\\stm32f10x.h"







            
#line 122 "..\\..\\..\\stm32f10x.h"





 






 
#line 143 "..\\..\\..\\stm32f10x.h"



 



 



 
#line 162 "..\\..\\..\\stm32f10x.h"




 
typedef enum IRQn
{
 
  NonMaskableInt_IRQn         = -14,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      

 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMPER_IRQn                 = 2,       
  RTC_IRQn                    = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Channel1_IRQn          = 11,      
  DMA1_Channel2_IRQn          = 12,      
  DMA1_Channel3_IRQn          = 13,      
  DMA1_Channel4_IRQn          = 14,      
  DMA1_Channel5_IRQn          = 15,      
  DMA1_Channel6_IRQn          = 16,      
  DMA1_Channel7_IRQn          = 17,      

#line 221 "..\\..\\..\\stm32f10x.h"

#line 242 "..\\..\\..\\stm32f10x.h"


  ADC1_2_IRQn                 = 18,      
  USB_HP_CAN1_TX_IRQn         = 19,      
  USB_LP_CAN1_RX0_IRQn        = 20,      
  CAN1_RX1_IRQn               = 21,      
  CAN1_SCE_IRQn               = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_IRQn               = 24,      
  TIM1_UP_IRQn                = 25,      
  TIM1_TRG_COM_IRQn           = 26,      
  TIM1_CC_IRQn                = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTCAlarm_IRQn               = 41,      
  USBWakeUp_IRQn              = 42         


#line 296 "..\\..\\..\\stm32f10x.h"

#line 341 "..\\..\\..\\stm32f10x.h"

#line 381 "..\\..\\..\\stm32f10x.h"

#line 426 "..\\..\\..\\stm32f10x.h"

#line 472 "..\\..\\..\\stm32f10x.h"
} IRQn_Type;



 

#line 1 "..\\..\\..\\Libraries\\CMSIS\\CM3\\CoreSupport\\core_cm3.h"
 




















 





































 

 
 
 
 
 
 
 
 








 











#line 1 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"
 
 





 










#line 26 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"







 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     
typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;

     
typedef   signed       __int64 intmax_t;
typedef unsigned       __int64 uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     


     


     


     

     


     


     


     

     



     



     


     
    
 



#line 197 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"

     







     










     











#line 261 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"



 



#line 91 "..\\..\\..\\Libraries\\CMSIS\\CM3\\CoreSupport\\core_cm3.h"

















 

#line 117 "..\\..\\..\\Libraries\\CMSIS\\CM3\\CoreSupport\\core_cm3.h"





 


 





 
typedef struct
{
  volatile uint32_t ISER[8];                       
       uint32_t RESERVED0[24];                                   
  volatile uint32_t ICER[8];                       
       uint32_t RSERVED1[24];                                    
  volatile uint32_t ISPR[8];                       
       uint32_t RESERVED2[24];                                   
  volatile uint32_t ICPR[8];                       
       uint32_t RESERVED3[24];                                   
  volatile uint32_t IABR[8];                       
       uint32_t RESERVED4[56];                                   
  volatile uint8_t  IP[240];                       
       uint32_t RESERVED5[644];                                  
  volatile  uint32_t STIR;                          
}  NVIC_Type;                                               
   





 
typedef struct
{
  volatile const  uint32_t CPUID;                         
  volatile uint32_t ICSR;                          
  volatile uint32_t VTOR;                          
  volatile uint32_t AIRCR;                         
  volatile uint32_t SCR;                           
  volatile uint32_t CCR;                           
  volatile uint8_t  SHP[12];                       
  volatile uint32_t SHCSR;                         
  volatile uint32_t CFSR;                          
  volatile uint32_t HFSR;                          
  volatile uint32_t DFSR;                          
  volatile uint32_t MMFAR;                         
  volatile uint32_t BFAR;                          
  volatile uint32_t AFSR;                          
  volatile const  uint32_t PFR[2];                        
  volatile const  uint32_t DFR;                           
  volatile const  uint32_t ADR;                           
  volatile const  uint32_t MMFR[4];                       
  volatile const  uint32_t ISAR[5];                       
} SCB_Type;                                                

 












 






























 






 





















 









 


















 
































                                     









 









 









 














   





 
typedef struct
{
  volatile uint32_t CTRL;                          
  volatile uint32_t LOAD;                          
  volatile uint32_t VAL;                           
  volatile const  uint32_t CALIB;                         
} SysTick_Type;

 












 



 



 








   





 
typedef struct
{
  volatile  union  
  {
    volatile  uint8_t    u8;                        
    volatile  uint16_t   u16;                       
    volatile  uint32_t   u32;                       
  }  PORT [32];                                
       uint32_t RESERVED0[864];                                 
  volatile uint32_t TER;                           
       uint32_t RESERVED1[15];                                  
  volatile uint32_t TPR;                           
       uint32_t RESERVED2[15];                                  
  volatile uint32_t TCR;                           
       uint32_t RESERVED3[29];                                  
  volatile uint32_t IWR;                           
  volatile uint32_t IRR;                           
  volatile uint32_t IMCR;                          
       uint32_t RESERVED4[43];                                  
  volatile uint32_t LAR;                           
  volatile uint32_t LSR;                           
       uint32_t RESERVED5[6];                                   
  volatile const  uint32_t PID4;                          
  volatile const  uint32_t PID5;                          
  volatile const  uint32_t PID6;                          
  volatile const  uint32_t PID7;                          
  volatile const  uint32_t PID0;                          
  volatile const  uint32_t PID1;                          
  volatile const  uint32_t PID2;                          
  volatile const  uint32_t PID3;                          
  volatile const  uint32_t CID0;                          
  volatile const  uint32_t CID1;                          
  volatile const  uint32_t CID2;                          
  volatile const  uint32_t CID3;                          
} ITM_Type;                                                

 



 
























 



 



 



 








   





 
typedef struct
{
       uint32_t RESERVED0;
  volatile const  uint32_t ICTR;                          



       uint32_t RESERVED1;

} InterruptType_Type;

 



 








   


#line 614 "..\\..\\..\\Libraries\\CMSIS\\CM3\\CoreSupport\\core_cm3.h"





 
typedef struct
{
  volatile uint32_t DHCSR;                         
  volatile  uint32_t DCRSR;                         
  volatile uint32_t DCRDR;                         
  volatile uint32_t DEMCR;                         
} CoreDebug_Type;

 




































 






 






































   


 
#line 721 "..\\..\\..\\Libraries\\CMSIS\\CM3\\CoreSupport\\core_cm3.h"

#line 728 "..\\..\\..\\Libraries\\CMSIS\\CM3\\CoreSupport\\core_cm3.h"






   




 





#line 758 "..\\..\\..\\Libraries\\CMSIS\\CM3\\CoreSupport\\core_cm3.h"


 


 




#line 783 "..\\..\\..\\Libraries\\CMSIS\\CM3\\CoreSupport\\core_cm3.h"


 
 
 
 








 
extern uint32_t __get_PSP(void);








 
extern void __set_PSP(uint32_t topOfProcStack);








 
extern uint32_t __get_MSP(void);








 
extern void __set_MSP(uint32_t topOfMainStack);








 
extern uint32_t __REV16(uint16_t value);








 
extern int32_t __REVSH(int16_t value);


#line 933 "..\\..\\..\\Libraries\\CMSIS\\CM3\\CoreSupport\\core_cm3.h"





 








 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}







 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xff);
}







 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}







 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}







 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}







 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & 1);
}







 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}







 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}





#line 1445 "..\\..\\..\\Libraries\\CMSIS\\CM3\\CoreSupport\\core_cm3.h"







 
 

 











 
static __inline void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                          
  
  reg_value  =  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR;                                                    
  reg_value &= ~((0xFFFFul << 16) | (7ul << 8));              
  reg_value  =  (reg_value                       |
                (0x5FA << 16) | 
                (PriorityGroupTmp << 8));                                      
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR =  reg_value;
}








 
static __inline uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR & (7ul << 8)) >> 8);    
}








 
static __inline void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}








 
static __inline void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}








 
static __inline void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  ((NVIC_Type *) ((0xE000E000) + 0x0100))->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F));  
}









 
static __inline uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((((NVIC_Type *) ((0xE000E000) + 0x0100))->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0));  
}












 
static __inline void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    ((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - 4)) & 0xff); }  
  else {
    ((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)] = ((priority << (8 - 4)) & 0xff);    }         
}















 
static __inline uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(((SCB_Type *) ((0xE000E000) + 0x0D00))->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - 4)));  }  
  else {
    return((uint32_t)(((NVIC_Type *) ((0xE000E000) + 0x0100))->IP[(uint32_t)(IRQn)]           >> (8 - 4)));  }  
}
















 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;
 
  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}
















 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);           
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > 4) ? 4 : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + 4) < 7) ? 0 : PriorityGroupTmp - 7 + 4;
  
  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}



 












 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > (0xFFFFFFul << 0))  return (1);             
                                                               
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->LOAD  = (ticks & (0xFFFFFFul << 0)) - 1;       
  NVIC_SetPriority (SysTick_IRQn, (1<<4) - 1);   
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->VAL   = 0;                                           
  ((SysTick_Type *) ((0xE000E000) + 0x0010))->CTRL  = (1ul << 2) | 
                   (1ul << 1)   | 
                   (1ul << 0);                     
  return (0);                                                   
}






 





 
static __inline void NVIC_SystemReset(void)
{
  ((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR  = ((0x5FA << 16)      | 
                 (((SCB_Type *) ((0xE000E000) + 0x0D00))->AIRCR & (7ul << 8)) | 
                 (1ul << 2));                    
  __dsb(0);                                                                    
  while(1);                                                     
}

   



 






 
 

extern volatile int ITM_RxBuffer;                     












 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if ((((CoreDebug_Type *) (0xE000EDF0))->DEMCR & (1ul << 24))  &&       
      (((ITM_Type *) (0xE0000000))->TCR & (1ul << 0))                  &&       
      (((ITM_Type *) (0xE0000000))->TER & (1ul << 0)        )                    )      
  {
    while (((ITM_Type *) (0xE0000000))->PORT[0].u32 == 0);
    ((ITM_Type *) (0xE0000000))->PORT[0].u8 = (uint8_t) ch;
  }  
  return (ch);
}










 
static __inline int ITM_ReceiveChar (void) {
  int ch = -1;                                

  if (ITM_RxBuffer != 0x5AA55AA5) {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = 0x5AA55AA5;        
  }
  
  return (ch); 
}









 
static __inline int ITM_CheckChar (void) {

  if (ITM_RxBuffer == 0x5AA55AA5) {
    return (0);                                  
  } else {
    return (1);                                  
  }
}

   






   



 
#line 479 "..\\..\\..\\stm32f10x.h"
#line 1 "..\\..\\..\\system_stm32f10x.h"


















 



 



   
  


 









 



 




 

extern uint32_t SystemCoreClock;           



 



 



 



 



 



 
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


 









 
  


   
 
#line 480 "..\\..\\..\\stm32f10x.h"
#line 481 "..\\..\\..\\stm32f10x.h"



   

 
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;   
typedef const int16_t sc16;   
typedef const int8_t sc8;    

typedef volatile int32_t  vs32;
typedef volatile int16_t  vs16;
typedef volatile int8_t   vs8;

typedef volatile const int32_t vsc32;   
typedef volatile const int16_t vsc16;   
typedef volatile const int8_t vsc8;    

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;   
typedef const uint16_t uc16;   
typedef const uint8_t uc8;    

typedef volatile uint32_t  vu32;
typedef volatile uint16_t vu16;
typedef volatile uint8_t  vu8;

typedef volatile const uint32_t vuc32;   
typedef volatile const uint16_t vuc16;   
typedef volatile const uint8_t vuc8;    

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;


typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

 





 



    



 

typedef struct
{
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
} ADC_TypeDef;



 

typedef struct
{
  uint32_t  RESERVED0;
  volatile uint16_t DR1;
  uint16_t  RESERVED1;
  volatile uint16_t DR2;
  uint16_t  RESERVED2;
  volatile uint16_t DR3;
  uint16_t  RESERVED3;
  volatile uint16_t DR4;
  uint16_t  RESERVED4;
  volatile uint16_t DR5;
  uint16_t  RESERVED5;
  volatile uint16_t DR6;
  uint16_t  RESERVED6;
  volatile uint16_t DR7;
  uint16_t  RESERVED7;
  volatile uint16_t DR8;
  uint16_t  RESERVED8;
  volatile uint16_t DR9;
  uint16_t  RESERVED9;
  volatile uint16_t DR10;
  uint16_t  RESERVED10; 
  volatile uint16_t RTCCR;
  uint16_t  RESERVED11;
  volatile uint16_t CR;
  uint16_t  RESERVED12;
  volatile uint16_t CSR;
  uint16_t  RESERVED13[5];
  volatile uint16_t DR11;
  uint16_t  RESERVED14;
  volatile uint16_t DR12;
  uint16_t  RESERVED15;
  volatile uint16_t DR13;
  uint16_t  RESERVED16;
  volatile uint16_t DR14;
  uint16_t  RESERVED17;
  volatile uint16_t DR15;
  uint16_t  RESERVED18;
  volatile uint16_t DR16;
  uint16_t  RESERVED19;
  volatile uint16_t DR17;
  uint16_t  RESERVED20;
  volatile uint16_t DR18;
  uint16_t  RESERVED21;
  volatile uint16_t DR19;
  uint16_t  RESERVED22;
  volatile uint16_t DR20;
  uint16_t  RESERVED23;
  volatile uint16_t DR21;
  uint16_t  RESERVED24;
  volatile uint16_t DR22;
  uint16_t  RESERVED25;
  volatile uint16_t DR23;
  uint16_t  RESERVED26;
  volatile uint16_t DR24;
  uint16_t  RESERVED27;
  volatile uint16_t DR25;
  uint16_t  RESERVED28;
  volatile uint16_t DR26;
  uint16_t  RESERVED29;
  volatile uint16_t DR27;
  uint16_t  RESERVED30;
  volatile uint16_t DR28;
  uint16_t  RESERVED31;
  volatile uint16_t DR29;
  uint16_t  RESERVED32;
  volatile uint16_t DR30;
  uint16_t  RESERVED33; 
  volatile uint16_t DR31;
  uint16_t  RESERVED34;
  volatile uint16_t DR32;
  uint16_t  RESERVED35;
  volatile uint16_t DR33;
  uint16_t  RESERVED36;
  volatile uint16_t DR34;
  uint16_t  RESERVED37;
  volatile uint16_t DR35;
  uint16_t  RESERVED38;
  volatile uint16_t DR36;
  uint16_t  RESERVED39;
  volatile uint16_t DR37;
  uint16_t  RESERVED40;
  volatile uint16_t DR38;
  uint16_t  RESERVED41;
  volatile uint16_t DR39;
  uint16_t  RESERVED42;
  volatile uint16_t DR40;
  uint16_t  RESERVED43;
  volatile uint16_t DR41;
  uint16_t  RESERVED44;
  volatile uint16_t DR42;
  uint16_t  RESERVED45;    
} BKP_TypeDef;
  


 

typedef struct
{
  volatile uint32_t TIR;
  volatile uint32_t TDTR;
  volatile uint32_t TDLR;
  volatile uint32_t TDHR;
} CAN_TxMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t RIR;
  volatile uint32_t RDTR;
  volatile uint32_t RDLR;
  volatile uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t FR1;
  volatile uint32_t FR2;
} CAN_FilterRegister_TypeDef;



 
  
typedef struct
{
  volatile uint32_t MCR;
  volatile uint32_t MSR;
  volatile uint32_t TSR;
  volatile uint32_t RF0R;
  volatile uint32_t RF1R;
  volatile uint32_t IER;
  volatile uint32_t ESR;
  volatile uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  volatile uint32_t FMR;
  volatile uint32_t FM1R;
  uint32_t  RESERVED2;
  volatile uint32_t FS1R;
  uint32_t  RESERVED3;
  volatile uint32_t FFA1R;
  uint32_t  RESERVED4;
  volatile uint32_t FA1R;
  uint32_t  RESERVED5[8];

  CAN_FilterRegister_TypeDef sFilterRegister[14];



} CAN_TypeDef;



 
typedef struct
{
  volatile uint32_t CFGR;
  volatile uint32_t OAR;
  volatile uint32_t PRES;
  volatile uint32_t ESR;
  volatile uint32_t CSR;
  volatile uint32_t TXD;
  volatile uint32_t RXD;  
} CEC_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;
  volatile uint8_t  IDR;
  uint8_t   RESERVED0;
  uint16_t  RESERVED1;
  volatile uint32_t CR;
} CRC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t SWTRIGR;
  volatile uint32_t DHR12R1;
  volatile uint32_t DHR12L1;
  volatile uint32_t DHR8R1;
  volatile uint32_t DHR12R2;
  volatile uint32_t DHR12L2;
  volatile uint32_t DHR8R2;
  volatile uint32_t DHR12RD;
  volatile uint32_t DHR12LD;
  volatile uint32_t DHR8RD;
  volatile uint32_t DOR1;
  volatile uint32_t DOR2;



} DAC_TypeDef;



 

typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;	
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;



 

typedef struct
{
  volatile uint32_t MACCR;
  volatile uint32_t MACFFR;
  volatile uint32_t MACHTHR;
  volatile uint32_t MACHTLR;
  volatile uint32_t MACMIIAR;
  volatile uint32_t MACMIIDR;
  volatile uint32_t MACFCR;
  volatile uint32_t MACVLANTR;              
       uint32_t RESERVED0[2];
  volatile uint32_t MACRWUFFR;              
  volatile uint32_t MACPMTCSR;
       uint32_t RESERVED1[2];
  volatile uint32_t MACSR;                  
  volatile uint32_t MACIMR;
  volatile uint32_t MACA0HR;
  volatile uint32_t MACA0LR;
  volatile uint32_t MACA1HR;
  volatile uint32_t MACA1LR;
  volatile uint32_t MACA2HR;
  volatile uint32_t MACA2LR;
  volatile uint32_t MACA3HR;
  volatile uint32_t MACA3LR;                
       uint32_t RESERVED2[40];
  volatile uint32_t MMCCR;                  
  volatile uint32_t MMCRIR;
  volatile uint32_t MMCTIR;
  volatile uint32_t MMCRIMR;
  volatile uint32_t MMCTIMR;                
       uint32_t RESERVED3[14];
  volatile uint32_t MMCTGFSCCR;             
  volatile uint32_t MMCTGFMSCCR;
       uint32_t RESERVED4[5];
  volatile uint32_t MMCTGFCR;
       uint32_t RESERVED5[10];
  volatile uint32_t MMCRFCECR;
  volatile uint32_t MMCRFAECR;
       uint32_t RESERVED6[10];
  volatile uint32_t MMCRGUFCR;
       uint32_t RESERVED7[334];
  volatile uint32_t PTPTSCR;
  volatile uint32_t PTPSSIR;
  volatile uint32_t PTPTSHR;
  volatile uint32_t PTPTSLR;
  volatile uint32_t PTPTSHUR;
  volatile uint32_t PTPTSLUR;
  volatile uint32_t PTPTSAR;
  volatile uint32_t PTPTTHR;
  volatile uint32_t PTPTTLR;
       uint32_t RESERVED8[567];
  volatile uint32_t DMABMR;
  volatile uint32_t DMATPDR;
  volatile uint32_t DMARPDR;
  volatile uint32_t DMARDLAR;
  volatile uint32_t DMATDLAR;
  volatile uint32_t DMASR;
  volatile uint32_t DMAOMR;
  volatile uint32_t DMAIER;
  volatile uint32_t DMAMFBOCR;
       uint32_t RESERVED9[9];
  volatile uint32_t DMACHTDR;
  volatile uint32_t DMACHRDR;
  volatile uint32_t DMACHTBAR;
  volatile uint32_t DMACHRBAR;
} ETH_TypeDef;



 

typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t AR;
  volatile uint32_t RESERVED;
  volatile uint32_t OBR;
  volatile uint32_t WRPR;
#line 920 "..\\..\\..\\stm32f10x.h"
} FLASH_TypeDef;



 
  
typedef struct
{
  volatile uint16_t RDP;
  volatile uint16_t USER;
  volatile uint16_t Data0;
  volatile uint16_t Data1;
  volatile uint16_t WRP0;
  volatile uint16_t WRP1;
  volatile uint16_t WRP2;
  volatile uint16_t WRP3;
} OB_TypeDef;



 

typedef struct
{
  volatile uint32_t BTCR[8];   
} FSMC_Bank1_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t BWTR[7];
} FSMC_Bank1E_TypeDef;



 
  
typedef struct
{
  volatile uint32_t PCR2;
  volatile uint32_t SR2;
  volatile uint32_t PMEM2;
  volatile uint32_t PATT2;
  uint32_t  RESERVED0;   
  volatile uint32_t ECCR2; 
} FSMC_Bank2_TypeDef;  



 
  
typedef struct
{
  volatile uint32_t PCR3;
  volatile uint32_t SR3;
  volatile uint32_t PMEM3;
  volatile uint32_t PATT3;
  uint32_t  RESERVED0;   
  volatile uint32_t ECCR3; 
} FSMC_Bank3_TypeDef; 



 
  
typedef struct
{
  volatile uint32_t PCR4;
  volatile uint32_t SR4;
  volatile uint32_t PMEM4;
  volatile uint32_t PATT4;
  volatile uint32_t PIO4; 
} FSMC_Bank4_TypeDef; 



 

typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t EVCR;
  volatile uint32_t MAPR;
  volatile uint32_t EXTICR[4];
  uint32_t RESERVED0;
  volatile uint32_t MAPR2;  
} AFIO_TypeDef;


 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t OAR1;
  uint16_t  RESERVED2;
  volatile uint16_t OAR2;
  uint16_t  RESERVED3;
  volatile uint16_t DR;
  uint16_t  RESERVED4;
  volatile uint16_t SR1;
  uint16_t  RESERVED5;
  volatile uint16_t SR2;
  uint16_t  RESERVED6;
  volatile uint16_t CCR;
  uint16_t  RESERVED7;
  volatile uint16_t TRISE;
  uint16_t  RESERVED8;
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
} IWDG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CSR;
} PWR_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;










} RCC_TypeDef;



 

typedef struct
{
  volatile uint16_t CRH;
  uint16_t  RESERVED0;
  volatile uint16_t CRL;
  uint16_t  RESERVED1;
  volatile uint16_t PRLH;
  uint16_t  RESERVED2;
  volatile uint16_t PRLL;
  uint16_t  RESERVED3;
  volatile uint16_t DIVH;
  uint16_t  RESERVED4;
  volatile uint16_t DIVL;
  uint16_t  RESERVED5;
  volatile uint16_t CNTH;
  uint16_t  RESERVED6;
  volatile uint16_t CNTL;
  uint16_t  RESERVED7;
  volatile uint16_t ALRH;
  uint16_t  RESERVED8;
  volatile uint16_t ALRL;
  uint16_t  RESERVED9;
} RTC_TypeDef;



 

typedef struct
{
  volatile uint32_t POWER;
  volatile uint32_t CLKCR;
  volatile uint32_t ARG;
  volatile uint32_t CMD;
  volatile const uint32_t RESPCMD;
  volatile const uint32_t RESP1;
  volatile const uint32_t RESP2;
  volatile const uint32_t RESP3;
  volatile const uint32_t RESP4;
  volatile uint32_t DTIMER;
  volatile uint32_t DLEN;
  volatile uint32_t DCTRL;
  volatile const uint32_t DCOUNT;
  volatile const uint32_t STA;
  volatile uint32_t ICR;
  volatile uint32_t MASK;
  uint32_t  RESERVED0[2];
  volatile const uint32_t FIFOCNT;
  uint32_t  RESERVED1[13];
  volatile uint32_t FIFO;
} SDIO_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SR;
  uint16_t  RESERVED2;
  volatile uint16_t DR;
  uint16_t  RESERVED3;
  volatile uint16_t CRCPR;
  uint16_t  RESERVED4;
  volatile uint16_t RXCRCR;
  uint16_t  RESERVED5;
  volatile uint16_t TXCRCR;
  uint16_t  RESERVED6;
  volatile uint16_t I2SCFGR;
  uint16_t  RESERVED7;
  volatile uint16_t I2SPR;
  uint16_t  RESERVED8;  
} SPI_TypeDef;



 

typedef struct
{
  volatile uint16_t CR1;
  uint16_t  RESERVED0;
  volatile uint16_t CR2;
  uint16_t  RESERVED1;
  volatile uint16_t SMCR;
  uint16_t  RESERVED2;
  volatile uint16_t DIER;
  uint16_t  RESERVED3;
  volatile uint16_t SR;
  uint16_t  RESERVED4;
  volatile uint16_t EGR;
  uint16_t  RESERVED5;
  volatile uint16_t CCMR1;
  uint16_t  RESERVED6;
  volatile uint16_t CCMR2;
  uint16_t  RESERVED7;
  volatile uint16_t CCER;
  uint16_t  RESERVED8;
  volatile uint16_t CNT;
  uint16_t  RESERVED9;
  volatile uint16_t PSC;
  uint16_t  RESERVED10;
  volatile uint16_t ARR;
  uint16_t  RESERVED11;
  volatile uint16_t RCR;
  uint16_t  RESERVED12;
  volatile uint16_t CCR1;
  uint16_t  RESERVED13;
  volatile uint16_t CCR2;
  uint16_t  RESERVED14;
  volatile uint16_t CCR3;
  uint16_t  RESERVED15;
  volatile uint16_t CCR4;
  uint16_t  RESERVED16;
  volatile uint16_t BDTR;
  uint16_t  RESERVED17;
  volatile uint16_t DCR;
  uint16_t  RESERVED18;
  volatile uint16_t DMAR;
  uint16_t  RESERVED19;
} TIM_TypeDef;



 
 
typedef struct
{
  volatile uint16_t SR;
  uint16_t  RESERVED0;
  volatile uint16_t DR;
  uint16_t  RESERVED1;
  volatile uint16_t BRR;
  uint16_t  RESERVED2;
  volatile uint16_t CR1;
  uint16_t  RESERVED3;
  volatile uint16_t CR2;
  uint16_t  RESERVED4;
  volatile uint16_t CR3;
  uint16_t  RESERVED5;
  volatile uint16_t GTPR;
  uint16_t  RESERVED6;
} USART_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_TypeDef;



 
  


 











 




#line 1312 "..\\..\\..\\stm32f10x.h"

#line 1335 "..\\..\\..\\stm32f10x.h"



#line 1354 "..\\..\\..\\stm32f10x.h"




















 
  


   

#line 1454 "..\\..\\..\\stm32f10x.h"



 



 
  
  

 
    
 
 
 

 
 
 
 
 

 



 



 


 
 
 
 
 

 











 
#line 1515 "..\\..\\..\\stm32f10x.h"




 





 
 
 
 
 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 





 



 






 
 
 
 
 

 
#line 1691 "..\\..\\..\\stm32f10x.h"

#line 1698 "..\\..\\..\\stm32f10x.h"

 
 








 








 






#line 1734 "..\\..\\..\\stm32f10x.h"

 











 











 













 






#line 1850 "..\\..\\..\\stm32f10x.h"




#line 1870 "..\\..\\..\\stm32f10x.h"

 





#line 1883 "..\\..\\..\\stm32f10x.h"

 
#line 1902 "..\\..\\..\\stm32f10x.h"

#line 1911 "..\\..\\..\\stm32f10x.h"

 
#line 1919 "..\\..\\..\\stm32f10x.h"



















#line 1944 "..\\..\\..\\stm32f10x.h"












 













#line 1976 "..\\..\\..\\stm32f10x.h"





#line 1990 "..\\..\\..\\stm32f10x.h"

#line 1997 "..\\..\\..\\stm32f10x.h"

#line 2007 "..\\..\\..\\stm32f10x.h"











 


















#line 2043 "..\\..\\..\\stm32f10x.h"

 
#line 2051 "..\\..\\..\\stm32f10x.h"



















#line 2076 "..\\..\\..\\stm32f10x.h"












 













#line 2108 "..\\..\\..\\stm32f10x.h"





#line 2122 "..\\..\\..\\stm32f10x.h"

#line 2129 "..\\..\\..\\stm32f10x.h"

#line 2139 "..\\..\\..\\stm32f10x.h"











 








 








   
#line 2178 "..\\..\\..\\stm32f10x.h"

#line 2273 "..\\..\\..\\stm32f10x.h"

#line 2300 "..\\..\\..\\stm32f10x.h"
 
 
 
 
 
 

 




































































 




































































 
#line 2462 "..\\..\\..\\stm32f10x.h"

 
#line 2480 "..\\..\\..\\stm32f10x.h"

 
#line 2498 "..\\..\\..\\stm32f10x.h"

#line 2515 "..\\..\\..\\stm32f10x.h"

 
#line 2533 "..\\..\\..\\stm32f10x.h"

 
#line 2552 "..\\..\\..\\stm32f10x.h"

 

 






 
#line 2579 "..\\..\\..\\stm32f10x.h"






 








 









 








 








 









 










 




#line 2654 "..\\..\\..\\stm32f10x.h"

 










#line 2685 "..\\..\\..\\stm32f10x.h"

 





 
#line 2700 "..\\..\\..\\stm32f10x.h"

 
#line 2709 "..\\..\\..\\stm32f10x.h"

   
#line 2718 "..\\..\\..\\stm32f10x.h"

 
#line 2727 "..\\..\\..\\stm32f10x.h"

 





 
#line 2742 "..\\..\\..\\stm32f10x.h"

 
#line 2751 "..\\..\\..\\stm32f10x.h"

   
#line 2760 "..\\..\\..\\stm32f10x.h"

 
#line 2769 "..\\..\\..\\stm32f10x.h"

 





 
#line 2784 "..\\..\\..\\stm32f10x.h"

 
#line 2793 "..\\..\\..\\stm32f10x.h"

   
#line 2802 "..\\..\\..\\stm32f10x.h"

 
#line 2811 "..\\..\\..\\stm32f10x.h"

 





 
#line 2826 "..\\..\\..\\stm32f10x.h"

 
#line 2835 "..\\..\\..\\stm32f10x.h"

   
#line 2844 "..\\..\\..\\stm32f10x.h"

 
#line 2853 "..\\..\\..\\stm32f10x.h"

#line 2862 "..\\..\\..\\stm32f10x.h"

#line 2871 "..\\..\\..\\stm32f10x.h"

#line 2881 "..\\..\\..\\stm32f10x.h"

 
 
 
 
 

 





 


 


 




 
 
 
 
 

 
#line 2945 "..\\..\\..\\stm32f10x.h"

 
#line 2980 "..\\..\\..\\stm32f10x.h"

 
#line 3015 "..\\..\\..\\stm32f10x.h"

 
#line 3050 "..\\..\\..\\stm32f10x.h"

 
#line 3085 "..\\..\\..\\stm32f10x.h"

 





 





 





 





 





 





 





 





 






 
#line 3152 "..\\..\\..\\stm32f10x.h"

 



 









 
#line 3176 "..\\..\\..\\stm32f10x.h"




 




 
#line 3192 "..\\..\\..\\stm32f10x.h"

 





 
#line 3214 "..\\..\\..\\stm32f10x.h"

 
 





 
#line 3229 "..\\..\\..\\stm32f10x.h"
 
#line 3236 "..\\..\\..\\stm32f10x.h"

 




 






 


 


 


 
 
 
 
 

 
#line 3285 "..\\..\\..\\stm32f10x.h"

 
#line 3307 "..\\..\\..\\stm32f10x.h"

 
#line 3329 "..\\..\\..\\stm32f10x.h"

 
#line 3351 "..\\..\\..\\stm32f10x.h"

 
#line 3373 "..\\..\\..\\stm32f10x.h"

 
#line 3395 "..\\..\\..\\stm32f10x.h"

 
 
 
 
 

 
#line 3431 "..\\..\\..\\stm32f10x.h"

 
#line 3461 "..\\..\\..\\stm32f10x.h"

 
#line 3471 "..\\..\\..\\stm32f10x.h"















 
#line 3495 "..\\..\\..\\stm32f10x.h"















 
#line 3519 "..\\..\\..\\stm32f10x.h"















 
#line 3543 "..\\..\\..\\stm32f10x.h"















 
#line 3567 "..\\..\\..\\stm32f10x.h"















 
#line 3591 "..\\..\\..\\stm32f10x.h"















 
#line 3615 "..\\..\\..\\stm32f10x.h"















 


 


 


 


 


 


 


 


 


 



 


 


 



 


 


 


 



 


 


 


 


 
 
 
 
 

 






 
#line 3716 "..\\..\\..\\stm32f10x.h"

#line 3725 "..\\..\\..\\stm32f10x.h"















  
 
#line 3748 "..\\..\\..\\stm32f10x.h"


















 








































 


















































 


 


 


 


 


 


 
#line 3883 "..\\..\\..\\stm32f10x.h"

#line 3890 "..\\..\\..\\stm32f10x.h"

#line 3897 "..\\..\\..\\stm32f10x.h"

#line 3904 "..\\..\\..\\stm32f10x.h"







 
#line 3918 "..\\..\\..\\stm32f10x.h"

#line 3925 "..\\..\\..\\stm32f10x.h"

#line 3932 "..\\..\\..\\stm32f10x.h"

#line 3939 "..\\..\\..\\stm32f10x.h"

#line 3946 "..\\..\\..\\stm32f10x.h"

#line 3953 "..\\..\\..\\stm32f10x.h"

 
#line 3961 "..\\..\\..\\stm32f10x.h"

#line 3968 "..\\..\\..\\stm32f10x.h"

#line 3975 "..\\..\\..\\stm32f10x.h"

#line 3982 "..\\..\\..\\stm32f10x.h"

#line 3989 "..\\..\\..\\stm32f10x.h"

#line 3996 "..\\..\\..\\stm32f10x.h"

 
#line 4004 "..\\..\\..\\stm32f10x.h"

#line 4011 "..\\..\\..\\stm32f10x.h"

#line 4018 "..\\..\\..\\stm32f10x.h"

#line 4025 "..\\..\\..\\stm32f10x.h"





 


 


 


 


 



 
 
 
 
 

 









































 



 


 


 


 


 


 


 



 



 



 


 


 



 
 
 
 
 
 





 






 


 
#line 4167 "..\\..\\..\\stm32f10x.h"

 
#line 4177 "..\\..\\..\\stm32f10x.h"

 


 


 
 
 
 
 

 
















 









#line 4225 "..\\..\\..\\stm32f10x.h"

 

























 
#line 4268 "..\\..\\..\\stm32f10x.h"

 
#line 4282 "..\\..\\..\\stm32f10x.h"

 
#line 4292 "..\\..\\..\\stm32f10x.h"

 




























 





















 




























 





















 
#line 4411 "..\\..\\..\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
#line 4446 "..\\..\\..\\stm32f10x.h"





#line 4457 "..\\..\\..\\stm32f10x.h"

 
#line 4465 "..\\..\\..\\stm32f10x.h"

#line 4472 "..\\..\\..\\stm32f10x.h"

 


 
 
 
 
 

 




 
#line 4494 "..\\..\\..\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
 
 
 
 

 


 





 


 



 
 
 
 
 

 
#line 4556 "..\\..\\..\\stm32f10x.h"



 
#line 4568 "..\\..\\..\\stm32f10x.h"







 


 
 
 
 
 

 











#line 4606 "..\\..\\..\\stm32f10x.h"

 











#line 4629 "..\\..\\..\\stm32f10x.h"

 











#line 4652 "..\\..\\..\\stm32f10x.h"

 











#line 4675 "..\\..\\..\\stm32f10x.h"

 








































 








































 








































 








































 


































 


































 


































 


































 



























 



























 



























 
#line 5072 "..\\..\\..\\stm32f10x.h"

 
#line 5081 "..\\..\\..\\stm32f10x.h"

 
#line 5090 "..\\..\\..\\stm32f10x.h"

 
#line 5101 "..\\..\\..\\stm32f10x.h"

#line 5111 "..\\..\\..\\stm32f10x.h"

#line 5121 "..\\..\\..\\stm32f10x.h"

#line 5131 "..\\..\\..\\stm32f10x.h"

 
#line 5142 "..\\..\\..\\stm32f10x.h"

#line 5152 "..\\..\\..\\stm32f10x.h"

#line 5162 "..\\..\\..\\stm32f10x.h"

#line 5172 "..\\..\\..\\stm32f10x.h"

 
#line 5183 "..\\..\\..\\stm32f10x.h"

#line 5193 "..\\..\\..\\stm32f10x.h"

#line 5203 "..\\..\\..\\stm32f10x.h"

#line 5213 "..\\..\\..\\stm32f10x.h"

 
#line 5224 "..\\..\\..\\stm32f10x.h"

#line 5234 "..\\..\\..\\stm32f10x.h"

#line 5244 "..\\..\\..\\stm32f10x.h"

#line 5254 "..\\..\\..\\stm32f10x.h"

 
#line 5265 "..\\..\\..\\stm32f10x.h"

#line 5275 "..\\..\\..\\stm32f10x.h"

#line 5285 "..\\..\\..\\stm32f10x.h"

#line 5295 "..\\..\\..\\stm32f10x.h"

 
#line 5306 "..\\..\\..\\stm32f10x.h"

#line 5316 "..\\..\\..\\stm32f10x.h"

#line 5326 "..\\..\\..\\stm32f10x.h"

#line 5336 "..\\..\\..\\stm32f10x.h"

 
#line 5347 "..\\..\\..\\stm32f10x.h"

#line 5357 "..\\..\\..\\stm32f10x.h"

#line 5367 "..\\..\\..\\stm32f10x.h"

#line 5377 "..\\..\\..\\stm32f10x.h"

 


 


 
 
 
 
 

 




 












 


 






#line 5425 "..\\..\\..\\stm32f10x.h"

 


 


 


 


 


 


 


 


 
















 


 
#line 5495 "..\\..\\..\\stm32f10x.h"

 
#line 5510 "..\\..\\..\\stm32f10x.h"

 
#line 5536 "..\\..\\..\\stm32f10x.h"

 


 


 
 
 
 
 

 
 























 























 























 























 























 























 























 























 
 
#line 5757 "..\\..\\..\\stm32f10x.h"

 
#line 5769 "..\\..\\..\\stm32f10x.h"

 






 
#line 5786 "..\\..\\..\\stm32f10x.h"



     


 
 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 

 


 


 


 


 


 


 


 


 

 


#line 5930 "..\\..\\..\\stm32f10x.h"



 


#line 5942 "..\\..\\..\\stm32f10x.h"



 


#line 5954 "..\\..\\..\\stm32f10x.h"



 


#line 5966 "..\\..\\..\\stm32f10x.h"



 


#line 5978 "..\\..\\..\\stm32f10x.h"



 


#line 5990 "..\\..\\..\\stm32f10x.h"



 


#line 6002 "..\\..\\..\\stm32f10x.h"



 


#line 6014 "..\\..\\..\\stm32f10x.h"



 

 


#line 6028 "..\\..\\..\\stm32f10x.h"



 


#line 6040 "..\\..\\..\\stm32f10x.h"



 


#line 6052 "..\\..\\..\\stm32f10x.h"



 


#line 6064 "..\\..\\..\\stm32f10x.h"



 


#line 6076 "..\\..\\..\\stm32f10x.h"



 


#line 6088 "..\\..\\..\\stm32f10x.h"



 


#line 6100 "..\\..\\..\\stm32f10x.h"



 


#line 6112 "..\\..\\..\\stm32f10x.h"



 


#line 6124 "..\\..\\..\\stm32f10x.h"



 


#line 6136 "..\\..\\..\\stm32f10x.h"



 


#line 6148 "..\\..\\..\\stm32f10x.h"



 


#line 6160 "..\\..\\..\\stm32f10x.h"



 


#line 6172 "..\\..\\..\\stm32f10x.h"



 


#line 6184 "..\\..\\..\\stm32f10x.h"



 


#line 6196 "..\\..\\..\\stm32f10x.h"



 


#line 6208 "..\\..\\..\\stm32f10x.h"



 
 
 
 
 

 
 
#line 6228 "..\\..\\..\\stm32f10x.h"

 
#line 6239 "..\\..\\..\\stm32f10x.h"

 
#line 6257 "..\\..\\..\\stm32f10x.h"











 





 





 
#line 6295 "..\\..\\..\\stm32f10x.h"

 












 
#line 6316 "..\\..\\..\\stm32f10x.h"

 
 






 




 





 





 






 




 





 





 






   




 





 





 





 




 





 





 





 




 





 





 
 


 
#line 6456 "..\\..\\..\\stm32f10x.h"

 
#line 6473 "..\\..\\..\\stm32f10x.h"

 
#line 6490 "..\\..\\..\\stm32f10x.h"

 
#line 6507 "..\\..\\..\\stm32f10x.h"

 
#line 6541 "..\\..\\..\\stm32f10x.h"

 
#line 6575 "..\\..\\..\\stm32f10x.h"

 
#line 6609 "..\\..\\..\\stm32f10x.h"

 
#line 6643 "..\\..\\..\\stm32f10x.h"

 
#line 6677 "..\\..\\..\\stm32f10x.h"

 
#line 6711 "..\\..\\..\\stm32f10x.h"

 
#line 6745 "..\\..\\..\\stm32f10x.h"

 
#line 6779 "..\\..\\..\\stm32f10x.h"

 
#line 6813 "..\\..\\..\\stm32f10x.h"

 
#line 6847 "..\\..\\..\\stm32f10x.h"

 
#line 6881 "..\\..\\..\\stm32f10x.h"

 
#line 6915 "..\\..\\..\\stm32f10x.h"

 
#line 6949 "..\\..\\..\\stm32f10x.h"

 
#line 6983 "..\\..\\..\\stm32f10x.h"

 
#line 7017 "..\\..\\..\\stm32f10x.h"

 
#line 7051 "..\\..\\..\\stm32f10x.h"

 
#line 7085 "..\\..\\..\\stm32f10x.h"

 
#line 7119 "..\\..\\..\\stm32f10x.h"

 
#line 7153 "..\\..\\..\\stm32f10x.h"

 
#line 7187 "..\\..\\..\\stm32f10x.h"

 
#line 7221 "..\\..\\..\\stm32f10x.h"

 
#line 7255 "..\\..\\..\\stm32f10x.h"

 
#line 7289 "..\\..\\..\\stm32f10x.h"

 
#line 7323 "..\\..\\..\\stm32f10x.h"

 
#line 7357 "..\\..\\..\\stm32f10x.h"

 
#line 7391 "..\\..\\..\\stm32f10x.h"

 
#line 7425 "..\\..\\..\\stm32f10x.h"

 
#line 7459 "..\\..\\..\\stm32f10x.h"

 
 
 
 
 

 









#line 7486 "..\\..\\..\\stm32f10x.h"

 
#line 7494 "..\\..\\..\\stm32f10x.h"

 
#line 7504 "..\\..\\..\\stm32f10x.h"

 


 


 


 


 





















 




 
 
 
 
 

 
#line 7565 "..\\..\\..\\stm32f10x.h"

 
#line 7574 "..\\..\\..\\stm32f10x.h"







 



#line 7595 "..\\..\\..\\stm32f10x.h"



 



 


 
#line 7620 "..\\..\\..\\stm32f10x.h"

 
#line 7630 "..\\..\\..\\stm32f10x.h"

 




 


 
 
 
 
 

 
#line 7656 "..\\..\\..\\stm32f10x.h"

 


 



 
#line 7680 "..\\..\\..\\stm32f10x.h"

 
#line 7689 "..\\..\\..\\stm32f10x.h"







 
#line 7709 "..\\..\\..\\stm32f10x.h"

 
#line 7720 "..\\..\\..\\stm32f10x.h"



 
 
 
 
 

 


#line 7749 "..\\..\\..\\stm32f10x.h"

 









#line 7783 "..\\..\\..\\stm32f10x.h"

 
 
 
 
 

 









 


 


 





 
#line 7823 "..\\..\\..\\stm32f10x.h"

 


 









 


 

 



 



 



 



 



 



 



 



#line 8287 "..\\..\\..\\stm32f10x.h"



 

 

  

#line 1 "..\\stm32f10x_conf.h"



















 

 



 
 
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"




















 

 







 
#line 1 "..\\..\\..\\Libraries\\CMSIS\\CM3\\DeviceSupport\\ST\\STM32F10x\\stm32f10x.h"







































 



 



 
    
#line 8327 "..\\..\\..\\Libraries\\CMSIS\\CM3\\DeviceSupport\\ST\\STM32F10x\\stm32f10x.h"



 

  

 

 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"



 



 



 



 

typedef struct
{
  uint32_t ADC_Mode;                      

 

  FunctionalState ADC_ScanConvMode;       

 

  FunctionalState ADC_ContinuousConvMode; 

 

  uint32_t ADC_ExternalTrigConv;          

 

  uint32_t ADC_DataAlign;                 
 

  uint8_t ADC_NbrOfChannel;               

 
}ADC_InitTypeDef;


 



 










 

#line 104 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"

#line 115 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"


 



 

#line 129 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"




#line 139 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"

#line 154 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"


 



 







 



 

#line 192 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"




#line 205 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"


 



 

#line 229 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"


 



 

















#line 266 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"


 



 

#line 282 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"


 



 

#line 297 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"

#line 305 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"


 



 











 



 

#line 338 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_adc.h"


 



 





 



 





 



 





 



 





  




 




 



 





 



 





 



 



 



 



 

void ADC_DeInit(ADC_TypeDef* ADCx);
void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct);
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct);
void ADC_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ITConfig(ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState);
void ADC_ResetCalibration(ADC_TypeDef* ADCx);
FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx);
void ADC_StartCalibration(ADC_TypeDef* ADCx);
FlagStatus ADC_GetCalibrationStatus(ADC_TypeDef* ADCx);
void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx);
void ADC_DiscModeChannelCountConfig(ADC_TypeDef* ADCx, uint8_t Number);
void ADC_DiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_ExternalTrigConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
uint16_t ADC_GetConversionValue(ADC_TypeDef* ADCx);
uint32_t ADC_GetDualModeConversionValue(void);
void ADC_AutoInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_InjectedDiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_ExternalTrigInjectedConvConfig(ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConv);
void ADC_ExternalTrigInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState);
FlagStatus ADC_GetSoftwareStartInjectedConvCmdStatus(ADC_TypeDef* ADCx);
void ADC_InjectedChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime);
void ADC_InjectedSequencerLengthConfig(ADC_TypeDef* ADCx, uint8_t Length);
void ADC_SetInjectedOffset(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel, uint16_t Offset);
uint16_t ADC_GetInjectedConversionValue(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel);
void ADC_AnalogWatchdogCmd(ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog);
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* ADCx, uint16_t HighThreshold, uint16_t LowThreshold);
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel);
void ADC_TempSensorVrefintCmd(FunctionalState NewState);
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
void ADC_ClearFlag(ADC_TypeDef* ADCx, uint8_t ADC_FLAG);
ITStatus ADC_GetITStatus(ADC_TypeDef* ADCx, uint16_t ADC_IT);
void ADC_ClearITPendingBit(ADC_TypeDef* ADCx, uint16_t ADC_IT);









 



 



 

 
#line 29 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_bkp.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_bkp.h"



 



 



 



 



 



 







 



 

#line 78 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_bkp.h"


 



 

#line 128 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_bkp.h"

#line 143 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_bkp.h"




 



 



 



 



 

void BKP_DeInit(void);
void BKP_TamperPinLevelConfig(uint16_t BKP_TamperPinLevel);
void BKP_TamperPinCmd(FunctionalState NewState);
void BKP_ITConfig(FunctionalState NewState);
void BKP_RTCOutputConfig(uint16_t BKP_RTCOutputSource);
void BKP_SetRTCCalibrationValue(uint8_t CalibrationValue);
void BKP_WriteBackupRegister(uint16_t BKP_DR, uint16_t Data);
uint16_t BKP_ReadBackupRegister(uint16_t BKP_DR);
FlagStatus BKP_GetFlagStatus(void);
void BKP_ClearFlag(void);
ITStatus BKP_GetITStatus(void);
void BKP_ClearITPendingBit(void);








 



 



 

 
#line 30 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"



 



 



 






 

typedef struct
{
  uint16_t CAN_Prescaler;   
 
  
  uint8_t CAN_Mode;         

 

  uint8_t CAN_SJW;          



 

  uint8_t CAN_BS1;          

 

  uint8_t CAN_BS2;          


 
  
  FunctionalState CAN_TTCM; 

 
  
  FunctionalState CAN_ABOM;  

 

  FunctionalState CAN_AWUM;  

 

  FunctionalState CAN_NART;  

 

  FunctionalState CAN_RFLM;  

 

  FunctionalState CAN_TXFP;  

 
} CAN_InitTypeDef;



 

typedef struct
{
  uint16_t CAN_FilterIdHigh;         

 

  uint16_t CAN_FilterIdLow;          

 

  uint16_t CAN_FilterMaskIdHigh;     


 

  uint16_t CAN_FilterMaskIdLow;      


 

  uint16_t CAN_FilterFIFOAssignment; 
 
  
  uint8_t CAN_FilterNumber;           

  uint8_t CAN_FilterMode;            
 

  uint8_t CAN_FilterScale;           
 

  FunctionalState CAN_FilterActivation; 
 
} CAN_FilterInitTypeDef;



 

typedef struct
{
  uint32_t StdId;  
 

  uint32_t ExtId;  
 

  uint8_t IDE;     

 

  uint8_t RTR;     

 

  uint8_t DLC;     

 

  uint8_t Data[8]; 
 
} CanTxMsg;



 

typedef struct
{
  uint32_t StdId;  
 

  uint32_t ExtId;  
 

  uint8_t IDE;     

 

  uint8_t RTR;     

 

  uint8_t DLC;     
 

  uint8_t Data[8]; 
 

  uint8_t FMI;     

 
} CanRxMsg;



 



 



 






 



 












 





   










 
  



   







 



 










 



 

#line 301 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"




 



 

#line 319 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"





 



 





 



 







 



 








 



 









 



 







 



 



 



 








 



 







 



 







 



 








 



 








 



 






 



 






 




   
                                                                
#line 493 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"




 



 

 
 

 




 
#line 518 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"

 



 

 





#line 539 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"








 

  


 


  


 
#line 565 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"

 



 






 





#line 590 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"

#line 597 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"



 



 
#line 621 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_can.h"



 



 



 



 



 
  
void CAN_DeInit(CAN_TypeDef* CANx);

  
uint8_t CAN_Init(CAN_TypeDef* CANx, CAN_InitTypeDef* CAN_InitStruct);
void CAN_FilterInit(CAN_FilterInitTypeDef* CAN_FilterInitStruct);
void CAN_StructInit(CAN_InitTypeDef* CAN_InitStruct);
void CAN_SlaveStartBank(uint8_t CAN_BankNumber); 
void CAN_DBGFreeze(CAN_TypeDef* CANx, FunctionalState NewState);
void CAN_TTComModeCmd(CAN_TypeDef* CANx, FunctionalState NewState);

 
uint8_t CAN_Transmit(CAN_TypeDef* CANx, CanTxMsg* TxMessage);
uint8_t CAN_TransmitStatus(CAN_TypeDef* CANx, uint8_t TransmitMailbox);
void CAN_CancelTransmit(CAN_TypeDef* CANx, uint8_t Mailbox);

 
void CAN_Receive(CAN_TypeDef* CANx, uint8_t FIFONumber, CanRxMsg* RxMessage);
void CAN_FIFORelease(CAN_TypeDef* CANx, uint8_t FIFONumber);
uint8_t CAN_MessagePending(CAN_TypeDef* CANx, uint8_t FIFONumber);


 
uint8_t CAN_OperatingModeRequest(CAN_TypeDef* CANx, uint8_t CAN_OperatingMode);
uint8_t CAN_Sleep(CAN_TypeDef* CANx);
uint8_t CAN_WakeUp(CAN_TypeDef* CANx);

 
uint8_t CAN_GetLastErrorCode(CAN_TypeDef* CANx);
uint8_t CAN_GetReceiveErrorCounter(CAN_TypeDef* CANx);
uint8_t CAN_GetLSBTransmitErrorCounter(CAN_TypeDef* CANx);

 
void CAN_ITConfig(CAN_TypeDef* CANx, uint32_t CAN_IT, FunctionalState NewState);
FlagStatus CAN_GetFlagStatus(CAN_TypeDef* CANx, uint32_t CAN_FLAG);
void CAN_ClearFlag(CAN_TypeDef* CANx, uint32_t CAN_FLAG);
ITStatus CAN_GetITStatus(CAN_TypeDef* CANx, uint32_t CAN_IT);
void CAN_ClearITPendingBit(CAN_TypeDef* CANx, uint32_t CAN_IT);








 



 



 

 
#line 31 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_cec.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_cec.h"



 



 
  



 
   


  
typedef struct
{
  uint16_t CEC_BitTimingMode; 
 
  uint16_t CEC_BitPeriodMode; 
 
}CEC_InitTypeDef;



 



  
  


  







 



  







  




  
#line 100 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_cec.h"


  




  



  



  




 



 
   


  
#line 136 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_cec.h"



  
#line 147 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_cec.h"


                               
#line 157 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_cec.h"



  



  



 
 


 



  
void CEC_DeInit(void);
void CEC_Init(CEC_InitTypeDef* CEC_InitStruct);
void CEC_Cmd(FunctionalState NewState);
void CEC_ITConfig(FunctionalState NewState);
void CEC_OwnAddressConfig(uint8_t CEC_OwnAddress);
void CEC_SetPrescaler(uint16_t CEC_Prescaler);
void CEC_SendDataByte(uint8_t Data);
uint8_t CEC_ReceiveDataByte(void);
void CEC_StartOfMessage(void);
void CEC_EndOfMessageCmd(FunctionalState NewState);
FlagStatus CEC_GetFlagStatus(uint32_t CEC_FLAG);
void CEC_ClearFlag(uint32_t CEC_FLAG);
ITStatus CEC_GetITStatus(uint8_t CEC_IT);
void CEC_ClearITPendingBit(uint16_t CEC_IT);









  



  



  

 
#line 32 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_crc.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_crc.h"



 



 



 



 



 



 



 



 



 

void CRC_ResetDR(void);
uint32_t CRC_CalcCRC(uint32_t Data);
uint32_t CRC_CalcBlockCRC(uint32_t pBuffer[], uint32_t BufferLength);
uint32_t CRC_GetCRC(void);
void CRC_SetIDRegister(uint8_t IDValue);
uint8_t CRC_GetIDRegister(void);








 



 



 

 
#line 33 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dac.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dac.h"



 



 



 



 

typedef struct
{
  uint32_t DAC_Trigger;                      
 

  uint32_t DAC_WaveGeneration;               

 

  uint32_t DAC_LFSRUnmask_TriangleAmplitude; 

 

  uint32_t DAC_OutputBuffer;                 
 
}DAC_InitTypeDef;



 



 



 

#line 94 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dac.h"

#line 104 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dac.h"



 



 

#line 119 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dac.h"


 



 

#line 151 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dac.h"

#line 176 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dac.h"


 



 







 



 







 



 

#line 214 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dac.h"


 



 







 



 




 
#line 261 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dac.h"



 



 



 



 

void DAC_DeInit(void);
void DAC_Init(uint32_t DAC_Channel, DAC_InitTypeDef* DAC_InitStruct);
void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct);
void DAC_Cmd(uint32_t DAC_Channel, FunctionalState NewState);



void DAC_DMACmd(uint32_t DAC_Channel, FunctionalState NewState);
void DAC_SoftwareTriggerCmd(uint32_t DAC_Channel, FunctionalState NewState);
void DAC_DualSoftwareTriggerCmd(FunctionalState NewState);
void DAC_WaveGenerationCmd(uint32_t DAC_Channel, uint32_t DAC_Wave, FunctionalState NewState);
void DAC_SetChannel1Data(uint32_t DAC_Align, uint16_t Data);
void DAC_SetChannel2Data(uint32_t DAC_Align, uint16_t Data);
void DAC_SetDualChannelData(uint32_t DAC_Align, uint16_t Data2, uint16_t Data1);
uint16_t DAC_GetDataOutputValue(uint32_t DAC_Channel);
#line 299 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dac.h"








 



 



 

 
#line 34 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dbgmcu.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dbgmcu.h"



 



 



 



 



 

#line 80 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dbgmcu.h"
                                              



  



 



 



 

uint32_t DBGMCU_GetREVID(void);
uint32_t DBGMCU_GetDEVID(void);
void DBGMCU_Config(uint32_t DBGMCU_Periph, FunctionalState NewState);








 



 



 

 
#line 35 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"



 



 



 



 

typedef struct
{
  uint32_t DMA_PeripheralBaseAddr;  

  uint32_t DMA_MemoryBaseAddr;      

  uint32_t DMA_DIR;                
 

  uint32_t DMA_BufferSize;         

 

  uint32_t DMA_PeripheralInc;      
 

  uint32_t DMA_MemoryInc;          
 

  uint32_t DMA_PeripheralDataSize; 
 

  uint32_t DMA_MemoryDataSize;     
 

  uint32_t DMA_Mode;               


 

  uint32_t DMA_Priority;           
 

  uint32_t DMA_M2M;                
 
}DMA_InitTypeDef;



 



 

#line 107 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"



 







 



 







 



 







 



 

#line 154 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"


 



 

#line 168 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"


 



 






 



 

#line 195 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"


 



 







 



 






#line 248 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"

#line 269 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"



#line 296 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"



 



 
#line 332 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"

#line 353 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"



#line 380 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_dma.h"


 



 





 



 



 



 



 

void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx);
void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct);
void DMA_StructInit(DMA_InitTypeDef* DMA_InitStruct);
void DMA_Cmd(DMA_Channel_TypeDef* DMAy_Channelx, FunctionalState NewState);
void DMA_ITConfig(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT, FunctionalState NewState);
void DMA_SetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx, uint16_t DataNumber); 
uint16_t DMA_GetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx);
FlagStatus DMA_GetFlagStatus(uint32_t DMAy_FLAG);
void DMA_ClearFlag(uint32_t DMAy_FLAG);
ITStatus DMA_GetITStatus(uint32_t DMAy_IT);
void DMA_ClearITPendingBit(uint32_t DMAy_IT);








 



 



 

 
#line 36 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_exti.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_exti.h"



 



 



 



 

typedef enum
{
  EXTI_Mode_Interrupt = 0x00,
  EXTI_Mode_Event = 0x04
}EXTIMode_TypeDef;





 

typedef enum
{
  EXTI_Trigger_Rising = 0x08,
  EXTI_Trigger_Falling = 0x0C,  
  EXTI_Trigger_Rising_Falling = 0x10
}EXTITrigger_TypeDef;






 

typedef struct
{
  uint32_t EXTI_Line;               
 
   
  EXTIMode_TypeDef EXTI_Mode;       
 

  EXTITrigger_TypeDef EXTI_Trigger; 
 

  FunctionalState EXTI_LineCmd;     
  
}EXTI_InitTypeDef;



 



 



 

#line 124 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_exti.h"
                                          
#line 136 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_exti.h"

                    


 



 



 



 



 

void EXTI_DeInit(void);
void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);
FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line);
void EXTI_ClearFlag(uint32_t EXTI_Line);
ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);
void EXTI_ClearITPendingBit(uint32_t EXTI_Line);








 



 



 

 
#line 37 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"



 



 



 



 

typedef enum
{ 
  FLASH_BUSY = 1,
  FLASH_ERROR_PG,
  FLASH_ERROR_WRP,
  FLASH_COMPLETE,
  FLASH_TIMEOUT
}FLASH_Status;



 



 



 

#line 77 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"


 



 







 



 







 



 

 
#line 118 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"

 
#line 144 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"

 
#line 211 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"











 



 







 



 







 



 





#line 270 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"


 


 
#line 291 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"






 



 
#line 333 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"





 
#line 346 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"



 



 



 



 



 

 
void FLASH_SetLatency(uint32_t FLASH_Latency);
void FLASH_HalfCycleAccessCmd(uint32_t FLASH_HalfCycleAccess);
void FLASH_PrefetchBufferCmd(uint32_t FLASH_PrefetchBuffer);
void FLASH_Unlock(void);
void FLASH_Lock(void);
FLASH_Status FLASH_ErasePage(uint32_t Page_Address);
FLASH_Status FLASH_EraseAllPages(void);
FLASH_Status FLASH_EraseOptionBytes(void);
FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data);
FLASH_Status FLASH_ProgramHalfWord(uint32_t Address, uint16_t Data);
FLASH_Status FLASH_ProgramOptionByteData(uint32_t Address, uint8_t Data);
FLASH_Status FLASH_EnableWriteProtection(uint32_t FLASH_Pages);
FLASH_Status FLASH_ReadOutProtection(FunctionalState NewState);
FLASH_Status FLASH_UserOptionByteConfig(uint16_t OB_IWDG, uint16_t OB_STOP, uint16_t OB_STDBY);
uint32_t FLASH_GetUserOptionByte(void);
uint32_t FLASH_GetWriteProtectionOptionByte(void);
FlagStatus FLASH_GetReadOutProtectionStatus(void);
FlagStatus FLASH_GetPrefetchBufferStatus(void);
void FLASH_ITConfig(uint32_t FLASH_IT, FunctionalState NewState);
FlagStatus FLASH_GetFlagStatus(uint32_t FLASH_FLAG);
void FLASH_ClearFlag(uint32_t FLASH_FLAG);
FLASH_Status FLASH_GetStatus(void);
FLASH_Status FLASH_WaitForLastOperation(uint32_t Timeout);

 
void FLASH_UnlockBank1(void);
void FLASH_LockBank1(void);
FLASH_Status FLASH_EraseAllBank1Pages(void);
FLASH_Status FLASH_GetBank1Status(void);
FLASH_Status FLASH_WaitForLastBank1Operation(uint32_t Timeout);

#line 408 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_flash.h"








 



 



 

 
#line 38 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_fsmc.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_fsmc.h"



 



 



 



 

typedef struct
{
  uint32_t FSMC_AddressSetupTime;       


 

  uint32_t FSMC_AddressHoldTime;        


 

  uint32_t FSMC_DataSetupTime;          


 

  uint32_t FSMC_BusTurnAroundDuration;  


 

  uint32_t FSMC_CLKDivision;            

 

  uint32_t FSMC_DataLatency;            





 

  uint32_t FSMC_AccessMode;             
 
}FSMC_NORSRAMTimingInitTypeDef;



 

typedef struct
{
  uint32_t FSMC_Bank;                
 

  uint32_t FSMC_DataAddressMux;      

 

  uint32_t FSMC_MemoryType;          

 

  uint32_t FSMC_MemoryDataWidth;     
 

  uint32_t FSMC_BurstAccessMode;     

 
                                       
  uint32_t FSMC_AsynchronousWait;     

 

  uint32_t FSMC_WaitSignalPolarity;  

 

  uint32_t FSMC_WrapMode;            

 

  uint32_t FSMC_WaitSignalActive;    


 

  uint32_t FSMC_WriteOperation;      
 

  uint32_t FSMC_WaitSignal;          

 

  uint32_t FSMC_ExtendedMode;        
 

  uint32_t FSMC_WriteBurst;          
  

  FSMC_NORSRAMTimingInitTypeDef* FSMC_ReadWriteTimingStruct;    

  FSMC_NORSRAMTimingInitTypeDef* FSMC_WriteTimingStruct;            
}FSMC_NORSRAMInitTypeDef;



 

typedef struct
{
  uint32_t FSMC_SetupTime;      



 

  uint32_t FSMC_WaitSetupTime;  



 

  uint32_t FSMC_HoldSetupTime;  




 

  uint32_t FSMC_HiZSetupTime;   



 
}FSMC_NAND_PCCARDTimingInitTypeDef;



 

typedef struct
{
  uint32_t FSMC_Bank;              
 

  uint32_t FSMC_Waitfeature;      
 

  uint32_t FSMC_MemoryDataWidth;  
 

  uint32_t FSMC_ECC;              
 

  uint32_t FSMC_ECCPageSize;      
 

  uint32_t FSMC_TCLRSetupTime;    

 

  uint32_t FSMC_TARSetupTime;     

  

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct;     

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct;  
}FSMC_NANDInitTypeDef;



 

typedef struct
{
  uint32_t FSMC_Waitfeature;    
 

  uint32_t FSMC_TCLRSetupTime;  

 

  uint32_t FSMC_TARSetupTime;   

  

  
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct;  

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct;    
  
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_IOSpaceTimingStruct;    
}FSMC_PCCARDInitTypeDef;



 



 



 






 



   




 



     



 



















 



 








 



 

#line 317 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_fsmc.h"



 



 








 



 







 
  


 







 
  


 








 



 








 



 








 



 





                              


 



 







 



 









 



 







 



 





 



 





 



 





 



 





 



 





 



 





 



 

#line 521 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_fsmc.h"



 



 
  


 



 








 




 








 



 

#line 577 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_fsmc.h"



 



 





 



 





 



 





 



 





 



 





 



 





 



 

#line 653 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_fsmc.h"


 



 

#line 669 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_fsmc.h"





 



 



 



 



 



 

void FSMC_NORSRAMDeInit(uint32_t FSMC_Bank);
void FSMC_NANDDeInit(uint32_t FSMC_Bank);
void FSMC_PCCARDDeInit(void);
void FSMC_NORSRAMInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct);
void FSMC_NANDInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct);
void FSMC_PCCARDInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct);
void FSMC_NORSRAMStructInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct);
void FSMC_NANDStructInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct);
void FSMC_PCCARDStructInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct);
void FSMC_NORSRAMCmd(uint32_t FSMC_Bank, FunctionalState NewState);
void FSMC_NANDCmd(uint32_t FSMC_Bank, FunctionalState NewState);
void FSMC_PCCARDCmd(FunctionalState NewState);
void FSMC_NANDECCCmd(uint32_t FSMC_Bank, FunctionalState NewState);
uint32_t FSMC_GetECC(uint32_t FSMC_Bank);
void FSMC_ITConfig(uint32_t FSMC_Bank, uint32_t FSMC_IT, FunctionalState NewState);
FlagStatus FSMC_GetFlagStatus(uint32_t FSMC_Bank, uint32_t FSMC_FLAG);
void FSMC_ClearFlag(uint32_t FSMC_Bank, uint32_t FSMC_FLAG);
ITStatus FSMC_GetITStatus(uint32_t FSMC_Bank, uint32_t FSMC_IT);
void FSMC_ClearITPendingBit(uint32_t FSMC_Bank, uint32_t FSMC_IT);








 



 



  

 
#line 39 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"



 



 



 

#line 53 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"
                                     


 

typedef enum
{ 
  GPIO_Speed_10MHz = 1,
  GPIO_Speed_2MHz, 
  GPIO_Speed_50MHz
}GPIOSpeed_TypeDef;





 

typedef enum
{ GPIO_Mode_AIN = 0x0,
  GPIO_Mode_IN_FLOATING = 0x04,
  GPIO_Mode_IPD = 0x28,
  GPIO_Mode_IPU = 0x48,
  GPIO_Mode_Out_OD = 0x14,
  GPIO_Mode_Out_PP = 0x10,
  GPIO_Mode_AF_OD = 0x1C,
  GPIO_Mode_AF_PP = 0x18
}GPIOMode_TypeDef;








 

typedef struct
{
  uint16_t GPIO_Pin;             
 

  GPIOSpeed_TypeDef GPIO_Speed;  
 

  GPIOMode_TypeDef GPIO_Mode;    
 
}GPIO_InitTypeDef;




 

typedef enum
{ Bit_RESET = 0,
  Bit_SET
}BitAction;





 



 



 

#line 144 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"



#line 163 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"



 



 

#line 204 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"







#line 217 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"






#line 245 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"
                              


  



 

#line 266 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"

#line 274 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"



 



 

#line 299 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"

#line 316 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_gpio.h"



 



  








                                                 


 



 



 



 

void GPIO_DeInit(GPIO_TypeDef* GPIOx);
void GPIO_AFIODeInit(void);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct);
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx);
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx);
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal);
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal);
void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void GPIO_EventOutputConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
void GPIO_EventOutputCmd(FunctionalState NewState);
void GPIO_PinRemapConfig(uint32_t GPIO_Remap, FunctionalState NewState);
void GPIO_EXTILineConfig(uint8_t GPIO_PortSource, uint8_t GPIO_PinSource);
void GPIO_ETH_MediaInterfaceConfig(uint32_t GPIO_ETH_MediaInterface);








 



 



 

 
#line 40 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_i2c.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_i2c.h"



 



 



 



 

typedef struct
{
  uint32_t I2C_ClockSpeed;          
 

  uint16_t I2C_Mode;                
 

  uint16_t I2C_DutyCycle;           
 

  uint16_t I2C_OwnAddress1;         
 

  uint16_t I2C_Ack;                 
 

  uint16_t I2C_AcknowledgedAddress; 
 
}I2C_InitTypeDef;



  




 





 

#line 92 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_i2c.h"


 



 







  



 







 



 







 



 







  



 

#line 166 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_i2c.h"


 



 







 



 







  



 







  



 







  



 

#line 236 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_i2c.h"



#line 246 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_i2c.h"


 



 



 

#line 265 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_i2c.h"



 

#line 284 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_i2c.h"



#line 298 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_i2c.h"


 



 




 







 
 

























 

 


 





























 

  
 


 
 

 






 
























 

    
 



 



 



























 

  
 

 


 
 


 


 

#line 496 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_i2c.h"


 



 




 



 




 



 



 



 



 

void I2C_DeInit(I2C_TypeDef* I2Cx);
void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct);
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct);
void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_DMACmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_DMALastTransferCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_OwnAddress2Config(I2C_TypeDef* I2Cx, uint8_t Address);
void I2C_DualAddressCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_GeneralCallCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_ITConfig(I2C_TypeDef* I2Cx, uint16_t I2C_IT, FunctionalState NewState);
void I2C_SendData(I2C_TypeDef* I2Cx, uint8_t Data);
uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx);
void I2C_Send7bitAddress(I2C_TypeDef* I2Cx, uint8_t Address, uint8_t I2C_Direction);
uint16_t I2C_ReadRegister(I2C_TypeDef* I2Cx, uint8_t I2C_Register);
void I2C_SoftwareResetCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_NACKPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_NACKPosition);
void I2C_SMBusAlertConfig(I2C_TypeDef* I2Cx, uint16_t I2C_SMBusAlert);
void I2C_TransmitPEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_PECPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_PECPosition);
void I2C_CalculatePEC(I2C_TypeDef* I2Cx, FunctionalState NewState);
uint8_t I2C_GetPEC(I2C_TypeDef* I2Cx);
void I2C_ARPCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_StretchClockCmd(I2C_TypeDef* I2Cx, FunctionalState NewState);
void I2C_FastModeDutyCycleConfig(I2C_TypeDef* I2Cx, uint16_t I2C_DutyCycle);













































































 





 
ErrorStatus I2C_CheckEvent(I2C_TypeDef* I2Cx, uint32_t I2C_EVENT);




 
uint32_t I2C_GetLastEvent(I2C_TypeDef* I2Cx);




 
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG);



 

void I2C_ClearFlag(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG);
ITStatus I2C_GetITStatus(I2C_TypeDef* I2Cx, uint32_t I2C_IT);
void I2C_ClearITPendingBit(I2C_TypeDef* I2Cx, uint32_t I2C_IT);








  



  



  

 
#line 41 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_iwdg.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_iwdg.h"



 



 



 



 



 



 







 



 

#line 84 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_iwdg.h"


 



 







 



 



 



 



 

void IWDG_WriteAccessCmd(uint16_t IWDG_WriteAccess);
void IWDG_SetPrescaler(uint8_t IWDG_Prescaler);
void IWDG_SetReload(uint16_t Reload);
void IWDG_ReloadCounter(void);
void IWDG_Enable(void);
FlagStatus IWDG_GetFlagStatus(uint16_t IWDG_FLAG);








 



 



 

 
#line 42 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_pwr.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_pwr.h"



 



  



  



  



  



  

#line 70 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_pwr.h"


 



 







 



 




 


 



 










 



 



 



 



 

void PWR_DeInit(void);
void PWR_BackupAccessCmd(FunctionalState NewState);
void PWR_PVDCmd(FunctionalState NewState);
void PWR_PVDLevelConfig(uint32_t PWR_PVDLevel);
void PWR_WakeUpPinCmd(FunctionalState NewState);
void PWR_EnterSTOPMode(uint32_t PWR_Regulator, uint8_t PWR_STOPEntry);
void PWR_EnterSTANDBYMode(void);
FlagStatus PWR_GetFlagStatus(uint32_t PWR_FLAG);
void PWR_ClearFlag(uint32_t PWR_FLAG);








 



 



 

 
#line 43 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"



 



 



 

typedef struct
{
  uint32_t SYSCLK_Frequency;   
  uint32_t HCLK_Frequency;     
  uint32_t PCLK1_Frequency;    
  uint32_t PCLK2_Frequency;    
  uint32_t ADCCLK_Frequency;   
}RCC_ClocksTypeDef;



 



 



 









  



 



#line 94 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"



  



 
#line 126 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"

#line 141 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"


 



 
#line 175 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"


 




 
#line 196 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"


 

#line 283 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"




 

#line 295 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"


 



 

#line 317 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"


  



 

#line 333 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"


 



 

#line 347 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"

#line 364 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"




 




 








 
#line 396 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"


#line 423 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"
  



 

#line 435 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"


 



 








 



 

#line 462 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"


 



 







#line 489 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"


 



 

#line 518 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"




  



 

#line 553 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"
 




 



 







#line 586 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"



 



 

#line 606 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"

#line 625 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"




 



 



 



 



 

void RCC_DeInit(void);
void RCC_HSEConfig(uint32_t RCC_HSE);
ErrorStatus RCC_WaitForHSEStartUp(void);
void RCC_AdjustHSICalibrationValue(uint8_t HSICalibrationValue);
void RCC_HSICmd(FunctionalState NewState);
void RCC_PLLConfig(uint32_t RCC_PLLSource, uint32_t RCC_PLLMul);
void RCC_PLLCmd(FunctionalState NewState);





#line 666 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rcc.h"

void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
uint8_t RCC_GetSYSCLKSource(void);
void RCC_HCLKConfig(uint32_t RCC_SYSCLK);
void RCC_PCLK1Config(uint32_t RCC_HCLK);
void RCC_PCLK2Config(uint32_t RCC_HCLK);
void RCC_ITConfig(uint8_t RCC_IT, FunctionalState NewState);


 void RCC_USBCLKConfig(uint32_t RCC_USBCLKSource);




void RCC_ADCCLKConfig(uint32_t RCC_PCLK2);






void RCC_LSEConfig(uint8_t RCC_LSE);
void RCC_LSICmd(FunctionalState NewState);
void RCC_RTCCLKConfig(uint32_t RCC_RTCCLKSource);
void RCC_RTCCLKCmd(FunctionalState NewState);
void RCC_GetClocksFreq(RCC_ClocksTypeDef* RCC_Clocks);
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);





void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_BackupResetCmd(FunctionalState NewState);
void RCC_ClockSecuritySystemCmd(FunctionalState NewState);
void RCC_MCOConfig(uint8_t RCC_MCO);
FlagStatus RCC_GetFlagStatus(uint8_t RCC_FLAG);
void RCC_ClearFlag(void);
ITStatus RCC_GetITStatus(uint8_t RCC_IT);
void RCC_ClearITPendingBit(uint8_t RCC_IT);








 



 



  

 
#line 44 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rtc.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rtc.h"



 



  



  



  



 



 

#line 64 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rtc.h"


  



 

#line 82 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_rtc.h"



 



 



 



 



 

void RTC_ITConfig(uint16_t RTC_IT, FunctionalState NewState);
void RTC_EnterConfigMode(void);
void RTC_ExitConfigMode(void);
uint32_t  RTC_GetCounter(void);
void RTC_SetCounter(uint32_t CounterValue);
void RTC_SetPrescaler(uint32_t PrescalerValue);
void RTC_SetAlarm(uint32_t AlarmValue);
uint32_t  RTC_GetDivider(void);
void RTC_WaitForLastTask(void);
void RTC_WaitForSynchro(void);
FlagStatus RTC_GetFlagStatus(uint16_t RTC_FLAG);
void RTC_ClearFlag(uint16_t RTC_FLAG);
ITStatus RTC_GetITStatus(uint16_t RTC_IT);
void RTC_ClearITPendingBit(uint16_t RTC_IT);








 



 



 

 
#line 45 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_sdio.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_sdio.h"



 



 



 

typedef struct
{
  uint32_t SDIO_ClockEdge;            
 

  uint32_t SDIO_ClockBypass;          

 

  uint32_t SDIO_ClockPowerSave;       

 

  uint32_t SDIO_BusWide;              
 

  uint32_t SDIO_HardwareFlowControl;  
 

  uint8_t SDIO_ClockDiv;              
 
                                           
} SDIO_InitTypeDef;

typedef struct
{
  uint32_t SDIO_Argument;  


 

  uint32_t SDIO_CmdIndex;   

  uint32_t SDIO_Response;  
 

  uint32_t SDIO_Wait;      
 

  uint32_t SDIO_CPSM;      

 
} SDIO_CmdInitTypeDef;

typedef struct
{
  uint32_t SDIO_DataTimeOut;     

  uint32_t SDIO_DataLength;      
 
  uint32_t SDIO_DataBlockSize;  
 
 
  uint32_t SDIO_TransferDir;    

 
 
  uint32_t SDIO_TransferMode;   
 
 
  uint32_t SDIO_DPSM;           

 
} SDIO_DataInitTypeDef;



  



 



 







 



 







  



 







 



 









 



 







 



 






  




 

#line 222 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_sdio.h"


  



 




 



 

#line 245 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_sdio.h"


 



 








 



 






  



 

#line 283 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_sdio.h"


 



 




 



 

#line 330 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_sdio.h"


 



 







 



 







 



 






 



 

#line 421 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_sdio.h"



#line 448 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_sdio.h"





 



 







 



 



 



 



 

void SDIO_DeInit(void);
void SDIO_Init(SDIO_InitTypeDef* SDIO_InitStruct);
void SDIO_StructInit(SDIO_InitTypeDef* SDIO_InitStruct);
void SDIO_ClockCmd(FunctionalState NewState);
void SDIO_SetPowerState(uint32_t SDIO_PowerState);
uint32_t SDIO_GetPowerState(void);
void SDIO_ITConfig(uint32_t SDIO_IT, FunctionalState NewState);
void SDIO_DMACmd(FunctionalState NewState);
void SDIO_SendCommand(SDIO_CmdInitTypeDef *SDIO_CmdInitStruct);
void SDIO_CmdStructInit(SDIO_CmdInitTypeDef* SDIO_CmdInitStruct);
uint8_t SDIO_GetCommandResponse(void);
uint32_t SDIO_GetResponse(uint32_t SDIO_RESP);
void SDIO_DataConfig(SDIO_DataInitTypeDef* SDIO_DataInitStruct);
void SDIO_DataStructInit(SDIO_DataInitTypeDef* SDIO_DataInitStruct);
uint32_t SDIO_GetDataCounter(void);
uint32_t SDIO_ReadData(void);
void SDIO_WriteData(uint32_t Data);
uint32_t SDIO_GetFIFOCount(void);
void SDIO_StartSDIOReadWait(FunctionalState NewState);
void SDIO_StopSDIOReadWait(FunctionalState NewState);
void SDIO_SetSDIOReadWaitMode(uint32_t SDIO_ReadWaitMode);
void SDIO_SetSDIOOperation(FunctionalState NewState);
void SDIO_SendSDIOSuspendCmd(FunctionalState NewState);
void SDIO_CommandCompletionCmd(FunctionalState NewState);
void SDIO_CEATAITCmd(FunctionalState NewState);
void SDIO_SendCEATACmd(FunctionalState NewState);
FlagStatus SDIO_GetFlagStatus(uint32_t SDIO_FLAG);
void SDIO_ClearFlag(uint32_t SDIO_FLAG);
ITStatus SDIO_GetITStatus(uint32_t SDIO_IT);
void SDIO_ClearITPendingBit(uint32_t SDIO_IT);








 



 



 

 
#line 46 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_spi.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_spi.h"



 



  



 



 

typedef struct
{
  uint16_t SPI_Direction;           
 

  uint16_t SPI_Mode;                
 

  uint16_t SPI_DataSize;            
 

  uint16_t SPI_CPOL;                
 

  uint16_t SPI_CPHA;                
 

  uint16_t SPI_NSS;                 

 
 
  uint16_t SPI_BaudRatePrescaler;   



 

  uint16_t SPI_FirstBit;            
 

  uint16_t SPI_CRCPolynomial;        
}SPI_InitTypeDef;



 

typedef struct
{

  uint16_t I2S_Mode;         
 

  uint16_t I2S_Standard;     
 

  uint16_t I2S_DataFormat;   
 

  uint16_t I2S_MCLKOutput;   
 

  uint32_t I2S_AudioFreq;    
 

  uint16_t I2S_CPOL;         
 
}I2S_InitTypeDef;



 



 










 
  
#line 136 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_spi.h"


 



 







 



 







  



 







 



 







 



 







  



 

#line 220 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_spi.h"


  



 







 



 

#line 248 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_spi.h"


 



 

#line 266 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_spi.h"


 



 

#line 282 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_spi.h"


  



 







 



 

#line 312 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_spi.h"






  



 







 



 






 



 







 



 






 



 







 



 

#line 396 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_spi.h"


 



 

#line 417 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_spi.h"


 



 




 



 



 



 



 

void SPI_I2S_DeInit(SPI_TypeDef* SPIx);
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct);
void I2S_Init(SPI_TypeDef* SPIx, I2S_InitTypeDef* I2S_InitStruct);
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct);
void I2S_StructInit(I2S_InitTypeDef* I2S_InitStruct);
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void I2S_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_I2S_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT, FunctionalState NewState);
void SPI_I2S_DMACmd(SPI_TypeDef* SPIx, uint16_t SPI_I2S_DMAReq, FunctionalState NewState);
void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data);
uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx);
void SPI_NSSInternalSoftwareConfig(SPI_TypeDef* SPIx, uint16_t SPI_NSSInternalSoft);
void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState);
void SPI_DataSizeConfig(SPI_TypeDef* SPIx, uint16_t SPI_DataSize);
void SPI_TransmitCRC(SPI_TypeDef* SPIx);
void SPI_CalculateCRC(SPI_TypeDef* SPIx, FunctionalState NewState);
uint16_t SPI_GetCRC(SPI_TypeDef* SPIx, uint8_t SPI_CRC);
uint16_t SPI_GetCRCPolynomial(SPI_TypeDef* SPIx);
void SPI_BiDirectionalLineConfig(SPI_TypeDef* SPIx, uint16_t SPI_Direction);
FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);
void SPI_I2S_ClearFlag(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG);
ITStatus SPI_I2S_GetITStatus(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT);
void SPI_I2S_ClearITPendingBit(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT);








 



 



 

 
#line 47 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"



 



  



  




 

typedef struct
{
  uint16_t TIM_Prescaler;         
 

  uint16_t TIM_CounterMode;       
 

  uint16_t TIM_Period;            

  

  uint16_t TIM_ClockDivision;     
 

  uint8_t TIM_RepetitionCounter;  






 
} TIM_TimeBaseInitTypeDef;       



 

typedef struct
{
  uint16_t TIM_OCMode;        
 

  uint16_t TIM_OutputState;   
 

  uint16_t TIM_OutputNState;  

 

  uint16_t TIM_Pulse;         
 

  uint16_t TIM_OCPolarity;    
 

  uint16_t TIM_OCNPolarity;   

 

  uint16_t TIM_OCIdleState;   

 

  uint16_t TIM_OCNIdleState;  

 
} TIM_OCInitTypeDef;



 

typedef struct
{

  uint16_t TIM_Channel;      
 

  uint16_t TIM_ICPolarity;   
 

  uint16_t TIM_ICSelection;  
 

  uint16_t TIM_ICPrescaler;  
 

  uint16_t TIM_ICFilter;     
 
} TIM_ICInitTypeDef;




 

typedef struct
{

  uint16_t TIM_OSSRState;        
 

  uint16_t TIM_OSSIState;        
 

  uint16_t TIM_LOCKLevel;        
  

  uint16_t TIM_DeadTime;         

 

  uint16_t TIM_Break;            
 

  uint16_t TIM_BreakPolarity;    
 

  uint16_t TIM_AutomaticOutput;  
 
} TIM_BDTRInitTypeDef;



 

#line 186 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"

 



 






 
#line 205 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"
									                                 
 
#line 216 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"

                                             
#line 225 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"

 
#line 236 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"

 
#line 249 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"

                                         
#line 266 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"

 
#line 279 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"
                                                                                                                                                                                                                          


  



 

#line 308 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


 



 







  



 

#line 341 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 

#line 355 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


 



 

#line 373 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 







 



 
  






 



 







  



 







  



 







  



 







  



 







  



 







  



 







  



 

#line 497 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 







 



 







  



 







  



 







  



 

#line 561 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 

#line 577 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 

#line 593 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 

#line 610 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"

#line 619 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 

#line 665 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 

#line 709 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 

#line 725 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"



  



 

#line 742 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 

#line 770 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 

#line 784 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



  






 



 







  



 







  



 

#line 833 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  




 

#line 851 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"



  



 

#line 866 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 







  



 





                                     


  



 







  



 

#line 927 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 

#line 943 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


  



 







  



 

#line 987 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"
                               
                               



  



 




  



 




  



 

#line 1034 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_tim.h"


 



 



 



  



 

void TIM_DeInit(TIM_TypeDef* TIMx);
void TIM_TimeBaseInit(TIM_TypeDef* TIMx, TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_OC1Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC2Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC3Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_OC4Init(TIM_TypeDef* TIMx, TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICInit(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_PWMIConfig(TIM_TypeDef* TIMx, TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRConfig(TIM_TypeDef* TIMx, TIM_BDTRInitTypeDef *TIM_BDTRInitStruct);
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef* TIM_TimeBaseInitStruct);
void TIM_OCStructInit(TIM_OCInitTypeDef* TIM_OCInitStruct);
void TIM_ICStructInit(TIM_ICInitTypeDef* TIM_ICInitStruct);
void TIM_BDTRStructInit(TIM_BDTRInitTypeDef* TIM_BDTRInitStruct);
void TIM_Cmd(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CtrlPWMOutputs(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_ITConfig(TIM_TypeDef* TIMx, uint16_t TIM_IT, FunctionalState NewState);
void TIM_GenerateEvent(TIM_TypeDef* TIMx, uint16_t TIM_EventSource);
void TIM_DMAConfig(TIM_TypeDef* TIMx, uint16_t TIM_DMABase, uint16_t TIM_DMABurstLength);
void TIM_DMACmd(TIM_TypeDef* TIMx, uint16_t TIM_DMASource, FunctionalState NewState);
void TIM_InternalClockConfig(TIM_TypeDef* TIMx);
void TIM_ITRxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_TIxExternalClockConfig(TIM_TypeDef* TIMx, uint16_t TIM_TIxExternalCLKSource,
                                uint16_t TIM_ICPolarity, uint16_t ICFilter);
void TIM_ETRClockMode1Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                             uint16_t ExtTRGFilter);
void TIM_ETRClockMode2Config(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, 
                             uint16_t TIM_ExtTRGPolarity, uint16_t ExtTRGFilter);
void TIM_ETRConfig(TIM_TypeDef* TIMx, uint16_t TIM_ExtTRGPrescaler, uint16_t TIM_ExtTRGPolarity,
                   uint16_t ExtTRGFilter);
void TIM_PrescalerConfig(TIM_TypeDef* TIMx, uint16_t Prescaler, uint16_t TIM_PSCReloadMode);
void TIM_CounterModeConfig(TIM_TypeDef* TIMx, uint16_t TIM_CounterMode);
void TIM_SelectInputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_InputTriggerSource);
void TIM_EncoderInterfaceConfig(TIM_TypeDef* TIMx, uint16_t TIM_EncoderMode,
                                uint16_t TIM_IC1Polarity, uint16_t TIM_IC2Polarity);
void TIM_ForcedOC1Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC2Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC3Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ForcedOC4Config(TIM_TypeDef* TIMx, uint16_t TIM_ForcedAction);
void TIM_ARRPreloadConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCOM(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectCCDMA(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_CCPreloadControl(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_OC1PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC2PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC3PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC4PreloadConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPreload);
void TIM_OC1FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC2FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC3FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_OC4FastConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCFast);
void TIM_ClearOC1Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC2Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC3Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_ClearOC4Ref(TIM_TypeDef* TIMx, uint16_t TIM_OCClear);
void TIM_OC1PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC1NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC2PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC2NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC3PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_OC3NPolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCNPolarity);
void TIM_OC4PolarityConfig(TIM_TypeDef* TIMx, uint16_t TIM_OCPolarity);
void TIM_CCxCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCx);
void TIM_CCxNCmd(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_CCxN);
void TIM_SelectOCxM(TIM_TypeDef* TIMx, uint16_t TIM_Channel, uint16_t TIM_OCMode);
void TIM_UpdateDisableConfig(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_UpdateRequestConfig(TIM_TypeDef* TIMx, uint16_t TIM_UpdateSource);
void TIM_SelectHallSensor(TIM_TypeDef* TIMx, FunctionalState NewState);
void TIM_SelectOnePulseMode(TIM_TypeDef* TIMx, uint16_t TIM_OPMode);
void TIM_SelectOutputTrigger(TIM_TypeDef* TIMx, uint16_t TIM_TRGOSource);
void TIM_SelectSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_SlaveMode);
void TIM_SelectMasterSlaveMode(TIM_TypeDef* TIMx, uint16_t TIM_MasterSlaveMode);
void TIM_SetCounter(TIM_TypeDef* TIMx, uint16_t Counter);
void TIM_SetAutoreload(TIM_TypeDef* TIMx, uint16_t Autoreload);
void TIM_SetCompare1(TIM_TypeDef* TIMx, uint16_t Compare1);
void TIM_SetCompare2(TIM_TypeDef* TIMx, uint16_t Compare2);
void TIM_SetCompare3(TIM_TypeDef* TIMx, uint16_t Compare3);
void TIM_SetCompare4(TIM_TypeDef* TIMx, uint16_t Compare4);
void TIM_SetIC1Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC2Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC3Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetIC4Prescaler(TIM_TypeDef* TIMx, uint16_t TIM_ICPSC);
void TIM_SetClockDivision(TIM_TypeDef* TIMx, uint16_t TIM_CKD);
uint16_t TIM_GetCapture1(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture2(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture3(TIM_TypeDef* TIMx);
uint16_t TIM_GetCapture4(TIM_TypeDef* TIMx);
uint16_t TIM_GetCounter(TIM_TypeDef* TIMx);
uint16_t TIM_GetPrescaler(TIM_TypeDef* TIMx);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef* TIMx, uint16_t TIM_FLAG);
ITStatus TIM_GetITStatus(TIM_TypeDef* TIMx, uint16_t TIM_IT);
void TIM_ClearITPendingBit(TIM_TypeDef* TIMx, uint16_t TIM_IT);








  



  



 

 
#line 48 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_usart.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_usart.h"



 



  



  



  
  
typedef struct
{
  uint32_t USART_BaudRate;            


 

  uint16_t USART_WordLength;          
 

  uint16_t USART_StopBits;            
 

  uint16_t USART_Parity;              




 
 
  uint16_t USART_Mode;                
 

  uint16_t USART_HardwareFlowControl; 

 
} USART_InitTypeDef;



  
  
typedef struct
{

  uint16_t USART_Clock;   
 

  uint16_t USART_CPOL;    
 

  uint16_t USART_CPHA;    
 

  uint16_t USART_LastBit; 

 
} USART_ClockInitTypeDef;



  



  
  
















  
  


                                    




  



  
  
#line 146 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_usart.h"


  



  
  
#line 160 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_usart.h"


  



  
  





  



  
#line 187 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_usart.h"


  



  






  



 
  






  



 







 



 







  



 
  
#line 264 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_usart.h"


 



 







  



 







 



 
  







 



 







  



 

#line 336 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_usart.h"
                              
#line 344 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_usart.h"



  



  



  



  



 

void USART_DeInit(USART_TypeDef* USARTx);
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct);
void USART_StructInit(USART_InitTypeDef* USART_InitStruct);
void USART_ClockInit(USART_TypeDef* USARTx, USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct);
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState);
void USART_DMACmd(USART_TypeDef* USARTx, uint16_t USART_DMAReq, FunctionalState NewState);
void USART_SetAddress(USART_TypeDef* USARTx, uint8_t USART_Address);
void USART_WakeUpConfig(USART_TypeDef* USARTx, uint16_t USART_WakeUp);
void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, uint16_t USART_LINBreakDetectLength);
void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data);
uint16_t USART_ReceiveData(USART_TypeDef* USARTx);
void USART_SendBreak(USART_TypeDef* USARTx);
void USART_SetGuardTime(USART_TypeDef* USARTx, uint8_t USART_GuardTime);
void USART_SetPrescaler(USART_TypeDef* USARTx, uint8_t USART_Prescaler);
void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_OverSampling8Cmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_OneBitMethodCmd(USART_TypeDef* USARTx, FunctionalState NewState);
void USART_IrDAConfig(USART_TypeDef* USARTx, uint16_t USART_IrDAMode);
void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState);
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG);
void USART_ClearFlag(USART_TypeDef* USARTx, uint16_t USART_FLAG);
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16_t USART_IT);
void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT);








  



  



  

 
#line 49 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_wwdg.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_wwdg.h"



 



  



  
  


  



  
  


  
  
#line 68 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\stm32f10x_wwdg.h"



  



  



  


  



  
  
void WWDG_DeInit(void);
void WWDG_SetPrescaler(uint32_t WWDG_Prescaler);
void WWDG_SetWindowValue(uint8_t WindowValue);
void WWDG_EnableIT(void);
void WWDG_SetCounter(uint8_t Counter);
void WWDG_Enable(uint8_t Counter);
FlagStatus WWDG_GetFlagStatus(void);
void WWDG_ClearFlag(void);









  



  



  

 
#line 50 "..\\stm32f10x_conf.h"
#line 1 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\misc.h"




















 

 







 
#line 33 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\misc.h"



 



 



 



 

typedef struct
{
  uint8_t NVIC_IRQChannel;                    


 

  uint8_t NVIC_IRQChannelPreemptionPriority;  

 

  uint8_t NVIC_IRQChannelSubPriority;         

 

  FunctionalState NVIC_IRQChannelCmd;         

    
} NVIC_InitTypeDef;
 


 



 
























 



 



 



 







 



 

#line 133 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\misc.h"


 



 

#line 151 "..\\..\\..\\Libraries\\STM32F10x_StdPeriph_Driver\\inc\\misc.h"















 



 







 



 



 



 



 

void NVIC_PriorityGroupConfig(uint32_t NVIC_PriorityGroup);
void NVIC_Init(NVIC_InitTypeDef* NVIC_InitStruct);
void NVIC_SetVectorTable(uint32_t NVIC_VectTab, uint32_t Offset);
void NVIC_SystemLPConfig(uint8_t LowPowerMode, FunctionalState NewState);
void SysTick_CLKSourceConfig(uint32_t SysTick_CLKSource);









 



 



 

 
#line 51 "..\\stm32f10x_conf.h"

 
 

 
 

 
#line 74 "..\\stm32f10x_conf.h"



 
#line 8298 "..\\..\\..\\stm32f10x.h"




 

















 









 

  

 

 
#line 2 "..\\..\\..\\mathem.h"



extern	char	adc_ch;
extern int32_t*	addr_angl;
extern	int32_t	Re1,Re2,Re5,Im1,Im2,Im5;
extern	uint32_t	Ia,Ib,Ic,Ia_2g,Ib_2g,Ic_2g;
extern	uint32_t	Ia_2_1g,Ib_2_1g,Ic_2_1g;
extern	int32_t	ReI2,ImI2,I2,Re_I3o_p,Im_I3o_p;
extern	uint32_t	ReI1,ImI1,I1;
float	f_ReI1,f_ImI1,f_I1;
float	f_ReI2,f_ImI2,f_I2;
extern	int32_t	I3o_p,I3o_i;
extern	uint32_t	Ua,Ub,Uc,Uad,Ua_2g,Ub_2g,Uc_2g;
extern	uint32_t	Uab,Ubc,Uca,U3o_p,U3o_i;
extern	int32_t	ReU2,ImU2,U2;
extern	int32_t	ReU1,ImU1,U1;
	
extern	int32_t	ReIa,ImIa,ReIb,ImIb,ReIc,ImIc,Re3Io_i,Im3Io_i,ReUad,ImUad,
        ReUa,ImUa,ReUb,ImUb,ReUc,ImUc,ReU3o_i,ImU3o_i,  																				
				ReIa_2g,ImIa_2g,ReIb_2g,ImIb_2g,ReIc_2g,ImIc_2g,Re3Io_2g,Im3Io_2g,ReUad_2g,ImUad_2g,
				ReUa_2g,ImUa_2g,ReUb_2g,ImUb_2g,ReUc_2g,ImUc_2g,ReU3o_2g,ImU3o_2g;

extern	uint32_t ModAngl(int32_t Re,int32_t Im);
extern	uint32_t Mod(int32_t Re,int32_t Im);

extern int32_t	F_Ia,F_Ib,F_Ic,F_I3o_p,F_3Io_i,F_Uad_p,F_Uad;
extern int32_t	F_Ua,F_Ub,F_Uc,F_Uab,F_Ubc,F_Uca;
extern int32_t	F_Ia_bc,F_Ib_Uca,F_IcUab;
extern int32_t	F_U3oi,F_3oi_U3oi,F_3Iop_U3oi;
extern int32_t	F_Ia_Ubc,F_Ib_Uca,F_Ic_Uab;
extern int32_t	F_U3oi,F_3Ioi_U3oi,F_3IopU3oi;
extern	uint32_t 	ang;

extern	int32_t		Zp,ReZp,ImZp,Fp,maxI,k,Ing,Ung,Io_p,Zp_0p,Zp_0i;	
extern	uint32_t	Zab,Zbc,Zca,Za0,Zb0,Zc0,ZZp_0p,ZZp_0i;

extern	int32_t	FB_Ia,FB_Ib,FB_Ic,FB_I3o_p,FB_3Io_i;
extern	int32_t	FB_Ua,FB_Ub,FB_Uc,FB_Uab,FB_Ubc,FB_Uca,FB_U3o_i,FB_Uad,FB_I3o_p;
extern	int32_t	Delta_I1,Delta_I2;
extern	int32_t	Re_Uab,Im_Uab,Re_Ubc,Im_Ubc,Re_Uca,Im_Uca;

extern	int32_t	Ktn,Ktn0;
extern	int32_t	Ubnn,Re_Ubnn,Im_Ubnn;
extern	int32_t	F_Zab,F_Zbc,F_Zca,F_Za0,F_Zb0,F_Zc0;

uint32_t	MemDel_I1,MemDel_I2;
int32_t baz;
uint32_t	Iab,Ibc,Ica;
int32_t	Re_Iab,Im_Iab,Re_Ibc,Im_Ibc,Re_Ica,Im_Ica;
int32_t	ReIZa,ImIZa,ReIZb,ImIZb,ReIZc,ImIZc;

int32_t	Re_Zab,Im_Zab,Re_Zbc,Im_Zbc,Re_Zca,Im_Zca;
int32_t	arcZab,arcZbc,arcZca;
int32_t	Re_Za0,Im_Za0,Re_Zb0,Im_Zb0,Re_Zc0,Im_Zc0;
int32_t	arcZa0,arcZb0,arcZc0,arcI3o_p;
int32_t	F_U3o_i,F_I3op_U3oi;

int32_t	arcF_Ia,arcF_Ib,arcF_Ic;
int32_t	arcF_Ua,arcF_Ub,arcF_Uc,arcF_Uad,arcF_U3o_i,arcF_Uab,arcF_Ubc,arcF_Uca;

extern	uint8_t	izmer[101];
extern	u32	zzz,zzz1,zzz2;

uint32_t sqrtf_int;
extern	u32	zzz1_m1,zzz1_m2,zzz1_m3,zzz1_m4,zzz1_m5;
uint32_t my_sq;

extern	int sqrt_32	(int	a, int	b);
extern	int32_t	arctg(int32_t	Re, int32_t Im);
extern	int32_t	arctg1(int32_t	Re, int32_t Im);
extern	int32_t	arctg_dec(int32_t	Re, int32_t Im);
extern	int arctangens(int x,int y);
extern	int32_t arctg_cordic(int32_t Re,int32_t Im);

int ang_Za0,ang_Zb0,ang_Zc0;
int	IZa,IZb,IZc;
#line 2 "..\\..\\..\\mathem.c"
#line 1 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\math.h"




 





 












 








 






#line 48 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\math.h"

#line 62 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\math.h"

   




 















 
#line 93 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\math.h"











 





extern __softfp unsigned __ARM_dcmp4(double  , double  );
extern __softfp unsigned __ARM_fcmp4(float  , float  );
    




 

extern __declspec(__nothrow) __softfp int __ARM_fpclassifyf(float  );
extern __declspec(__nothrow) __softfp int __ARM_fpclassify(double  );
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isfinitef(float __x)
{
    return (((*(unsigned *)&(__x)) >> 23) & 0xff) != 0xff;
}
__inline __declspec(__nothrow) __softfp int __ARM_isfinite(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff) != 0x7ff;
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isinff(float __x)
{
    return ((*(unsigned *)&(__x)) << 1) == 0xff000000;
}
__inline __declspec(__nothrow) __softfp int __ARM_isinf(double __x)
{
    return (((*(1 + (unsigned *)&(__x))) << 1) == 0xffe00000) && ((*(unsigned *)&(__x)) == 0);
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_islessgreaterf(float __x, float __y)
{
    unsigned __f = __ARM_fcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
__inline __declspec(__nothrow) __softfp int __ARM_islessgreater(double __x, double __y)
{
    unsigned __f = __ARM_dcmp4(__x, __y) >> 28;
    return (__f == 8) || (__f == 2);  
}
    


 

__inline __declspec(__nothrow) __softfp int __ARM_isnanf(float __x)
{
    return (0x7f800000 - ((*(unsigned *)&(__x)) & 0x7fffffff)) >> 31;
}
__inline __declspec(__nothrow) __softfp int __ARM_isnan(double __x)
{
    unsigned __xf = (*(1 + (unsigned *)&(__x))) | (((*(unsigned *)&(__x)) == 0) ? 0 : 1);
    return (0x7ff00000 - (__xf & 0x7fffffff)) >> 31;
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_isnormalf(float __x)
{
    unsigned __xe = ((*(unsigned *)&(__x)) >> 23) & 0xff;
    return (__xe != 0xff) && (__xe != 0);
}
__inline __declspec(__nothrow) __softfp int __ARM_isnormal(double __x)
{
    unsigned __xe = ((*(1 + (unsigned *)&(__x))) >> 20) & 0x7ff;
    return (__xe != 0x7ff) && (__xe != 0);
}
     
     

__inline __declspec(__nothrow) __softfp int __ARM_signbitf(float __x)
{
    return (*(unsigned *)&(__x)) >> 31;
}
__inline __declspec(__nothrow) __softfp int __ARM_signbit(double __x)
{
    return (*(1 + (unsigned *)&(__x))) >> 31;
}
     
     








#line 211 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\math.h"



   
  typedef float float_t;
  typedef double double_t;







extern const int math_errhandling;



extern __declspec(__nothrow) double acos(double  );
    
    
    
extern __declspec(__nothrow) double asin(double  );
    
    
    
    

extern __declspec(__nothrow) __pure double atan(double  );
    
    

extern __declspec(__nothrow) double atan2(double  , double  );
    
    
    
    

extern __declspec(__nothrow) double cos(double  );
    
    
    
    
extern __declspec(__nothrow) double sin(double  );
    
    
    
    

extern void __use_accurate_range_reduction(void);
    
    

extern __declspec(__nothrow) double tan(double  );
    
    
    
    

extern __declspec(__nothrow) double cosh(double  );
    
    
    
    
extern __declspec(__nothrow) double sinh(double  );
    
    
    
    
    

extern __declspec(__nothrow) __pure double tanh(double  );
    
    

extern __declspec(__nothrow) double exp(double  );
    
    
    
    
    

extern __declspec(__nothrow) double frexp(double  , int *  ) __attribute__((__nonnull__(2)));
    
    
    
    
    
    

extern __declspec(__nothrow) double ldexp(double  , int  );
    
    
    
    
extern __declspec(__nothrow) double log(double  );
    
    
    
    
    
extern __declspec(__nothrow) double log10(double  );
    
    
    
extern __declspec(__nothrow) double modf(double  , double *  ) __attribute__((__nonnull__(2)));
    
    
    
    

extern __declspec(__nothrow) double pow(double  , double  );
    
    
    
    
    
    
extern __declspec(__nothrow) double sqrt(double  );
    
    
    




    __inline double _sqrt(double __x) { return sqrt(__x); }




    __inline float _sqrtf(float __x) { return (float)sqrt(__x); }

    



 

extern __declspec(__nothrow) __pure double ceil(double  );
    
    
extern __declspec(__nothrow) __pure double fabs(double  );
    
    

extern __declspec(__nothrow) __pure double floor(double  );
    
    

extern __declspec(__nothrow) double fmod(double  , double  );
    
    
    
    
    

    









 



extern __declspec(__nothrow) double acosh(double  );
    

 
extern __declspec(__nothrow) double asinh(double  );
    

 
extern __declspec(__nothrow) double atanh(double  );
    

 
extern __declspec(__nothrow) double cbrt(double  );
    

 
__inline __declspec(__nothrow) __pure double copysign(double __x, double __y)
    

 
{
    (*(1 + (unsigned *)&(__x))) = ((*(1 + (unsigned *)&(__x))) & 0x7fffffff) | ((*(1 + (unsigned *)&(__y))) & 0x80000000);
    return __x;
}
__inline __declspec(__nothrow) __pure float copysignf(float __x, float __y)
    

 
{
    (*(unsigned *)&(__x)) = ((*(unsigned *)&(__x)) & 0x7fffffff) | ((*(unsigned *)&(__y)) & 0x80000000);
    return __x;
}
extern __declspec(__nothrow) double erf(double  );
    

 
extern __declspec(__nothrow) double erfc(double  );
    

 
extern __declspec(__nothrow) double expm1(double  );
    

 



    

 






#line 445 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\math.h"


extern __declspec(__nothrow) double hypot(double  , double  );
    




 
extern __declspec(__nothrow) int ilogb(double  );
    

 
extern __declspec(__nothrow) int ilogbf(float  );
    

 
extern __declspec(__nothrow) int ilogbl(long double  );
    

 







    

 





    



 





    



 





    

 





    



 





    



 





    



 





    

 





    

 





    


 

extern __declspec(__nothrow) double lgamma (double  );
    


 
extern __declspec(__nothrow) double log1p(double  );
    

 
extern __declspec(__nothrow) double logb(double  );
    

 
extern __declspec(__nothrow) float logbf(float  );
    

 
extern __declspec(__nothrow) long double logbl(long double  );
    

 
extern __declspec(__nothrow) double nextafter(double  , double  );
    


 
extern __declspec(__nothrow) float nextafterf(float  , float  );
    


 
extern __declspec(__nothrow) long double nextafterl(long double  , long double  );
    


 
extern __declspec(__nothrow) double nexttoward(double  , long double  );
    


 
extern __declspec(__nothrow) float nexttowardf(float  , long double  );
    


 
extern __declspec(__nothrow) long double nexttowardl(long double  , long double  );
    


 
extern __declspec(__nothrow) double remainder(double  , double  );
    

 
extern __declspec(__nothrow) __pure double rint(double  );
    

 
extern __declspec(__nothrow) double scalbln(double  , long int  );
    

 
extern __declspec(__nothrow) float scalblnf(float  , long int  );
    

 
extern __declspec(__nothrow) long double scalblnl(long double  , long int  );
    

 
extern __declspec(__nothrow) double scalbn(double  , int  );
    

 
extern __declspec(__nothrow) float scalbnf(float  , int  );
    

 
extern __declspec(__nothrow) long double scalbnl(long double  , int  );
    

 




    

 



 
extern __declspec(__nothrow) __pure float _fabsf(float);  
__inline __declspec(__nothrow) __pure float fabsf(float __f) { return _fabsf(__f); }
extern __declspec(__nothrow) float sinf(float  );
extern __declspec(__nothrow) float cosf(float  );
extern __declspec(__nothrow) float tanf(float  );
extern __declspec(__nothrow) float acosf(float  );
extern __declspec(__nothrow) float asinf(float  );
extern __declspec(__nothrow) float atanf(float  );
extern __declspec(__nothrow) float atan2f(float  , float  );
extern __declspec(__nothrow) float sinhf(float  );
extern __declspec(__nothrow) float coshf(float  );
extern __declspec(__nothrow) float tanhf(float  );
extern __declspec(__nothrow) float expf(float  );
extern __declspec(__nothrow) float logf(float  );
extern __declspec(__nothrow) float log10f(float  );
extern __declspec(__nothrow) float powf(float  , float  );
extern __declspec(__nothrow) float sqrtf(float  );
extern __declspec(__nothrow) float ldexpf(float  , int  );
extern __declspec(__nothrow) float frexpf(float  , int *  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) __pure float ceilf(float  );
extern __declspec(__nothrow) __pure float floorf(float  );
extern __declspec(__nothrow) float fmodf(float  , float  );
extern __declspec(__nothrow) float modff(float  , float *  ) __attribute__((__nonnull__(2)));

 
 













 
__declspec(__nothrow) long double acosl(long double );
__declspec(__nothrow) long double asinl(long double );
__declspec(__nothrow) long double atanl(long double );
__declspec(__nothrow) long double atan2l(long double , long double );
__declspec(__nothrow) long double ceill(long double );
__declspec(__nothrow) long double cosl(long double );
__declspec(__nothrow) long double coshl(long double );
__declspec(__nothrow) long double expl(long double );
__declspec(__nothrow) long double fabsl(long double );
__declspec(__nothrow) long double floorl(long double );
__declspec(__nothrow) long double fmodl(long double , long double );
__declspec(__nothrow) long double frexpl(long double , int* ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double ldexpl(long double , int );
__declspec(__nothrow) long double logl(long double );
__declspec(__nothrow) long double log10l(long double );
__declspec(__nothrow) long double modfl(long double  , long double *  ) __attribute__((__nonnull__(2)));
__declspec(__nothrow) long double powl(long double , long double );
__declspec(__nothrow) long double sinl(long double );
__declspec(__nothrow) long double sinhl(long double );
__declspec(__nothrow) long double sqrtl(long double );
__declspec(__nothrow) long double tanl(long double );
__declspec(__nothrow) long double tanhl(long double );





 
extern __declspec(__nothrow) float acoshf(float  );
__declspec(__nothrow) long double acoshl(long double );
extern __declspec(__nothrow) float asinhf(float  );
__declspec(__nothrow) long double asinhl(long double );
extern __declspec(__nothrow) float atanhf(float  );
__declspec(__nothrow) long double atanhl(long double );
__declspec(__nothrow) long double copysignl(long double , long double );
extern __declspec(__nothrow) float cbrtf(float  );
__declspec(__nothrow) long double cbrtl(long double );
extern __declspec(__nothrow) float erff(float  );
__declspec(__nothrow) long double erfl(long double );
extern __declspec(__nothrow) float erfcf(float  );
__declspec(__nothrow) long double erfcl(long double );
extern __declspec(__nothrow) float expm1f(float  );
__declspec(__nothrow) long double expm1l(long double );
extern __declspec(__nothrow) float log1pf(float  );
__declspec(__nothrow) long double log1pl(long double );
extern __declspec(__nothrow) float hypotf(float  , float  );
__declspec(__nothrow) long double hypotl(long double , long double );
extern __declspec(__nothrow) float lgammaf(float  );
__declspec(__nothrow) long double lgammal(long double );
extern __declspec(__nothrow) float remainderf(float  , float  );
__declspec(__nothrow) long double remainderl(long double , long double );
extern __declspec(__nothrow) float rintf(float  );
__declspec(__nothrow) long double rintl(long double );






 
extern __declspec(__nothrow) double exp2(double  );  
extern __declspec(__nothrow) float exp2f(float  );
__declspec(__nothrow) long double exp2l(long double );
extern __declspec(__nothrow) double fdim(double  , double  );
extern __declspec(__nothrow) float fdimf(float  , float  );
__declspec(__nothrow) long double fdiml(long double , long double );
#line 769 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\math.h"
extern __declspec(__nothrow) double fma(double  , double  , double  );
extern __declspec(__nothrow) float fmaf(float  , float  , float  );
__inline __declspec(__nothrow) long double fmal(long double __x, long double __y, long double __z)     { return (long double)fma((double)__x, (double)__y, (double)__z); }

extern __declspec(__nothrow) __pure double fmax(double  , double  );
extern __declspec(__nothrow) __pure float fmaxf(float  , float  );
__declspec(__nothrow) long double fmaxl(long double , long double );
extern __declspec(__nothrow) __pure double fmin(double  , double  );
extern __declspec(__nothrow) __pure float fminf(float  , float  );
__declspec(__nothrow) long double fminl(long double , long double );
extern __declspec(__nothrow) double log2(double  );  
extern __declspec(__nothrow) float log2f(float  );
__declspec(__nothrow) long double log2l(long double );
extern __declspec(__nothrow) long lrint(double  );
extern __declspec(__nothrow) long lrintf(float  );
__inline __declspec(__nothrow) long lrintl(long double __x)     { return lrint((double)__x); }

extern __declspec(__nothrow) __int64 llrint(double  );
extern __declspec(__nothrow) __int64 llrintf(float  );
__inline __declspec(__nothrow) __int64 llrintl(long double __x)     { return llrint((double)__x); }

extern __declspec(__nothrow) long lround(double  );
extern __declspec(__nothrow) long lroundf(float  );
__inline __declspec(__nothrow) long lroundl(long double __x)     { return lround((double)__x); }

extern __declspec(__nothrow) __int64 llround(double  );
extern __declspec(__nothrow) __int64 llroundf(float  );
__inline __declspec(__nothrow) __int64 llroundl(long double __x)     { return llround((double)__x); }

extern __declspec(__nothrow) __pure double nan(const char * );
extern __declspec(__nothrow) __pure float nanf(const char * );
__inline __declspec(__nothrow) __pure long double nanl(const char *__t)     { return (long double)nan(__t); }
#line 808 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\math.h"
extern __declspec(__nothrow) __pure double nearbyint(double  );
extern __declspec(__nothrow) __pure float nearbyintf(float  );
__declspec(__nothrow) long double nearbyintl(long double );
extern  double remquo(double  , double  , int * );
extern  float remquof(float  , float  , int * );
__inline long double remquol(long double __x, long double __y, int *__q)     { return (long double)remquo((double)__x, (double)__y, __q); }

extern __declspec(__nothrow) __pure double round(double  );
extern __declspec(__nothrow) __pure float roundf(float  );
__declspec(__nothrow) long double roundl(long double );
extern __declspec(__nothrow) double tgamma(double  );  
extern __declspec(__nothrow) float tgammaf(float  );
__declspec(__nothrow) long double tgammal(long double );
extern __declspec(__nothrow) __pure double trunc(double  );
extern __declspec(__nothrow) __pure float truncf(float  );
__declspec(__nothrow) long double truncl(long double );






#line 980 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\math.h"











#line 1182 "C:\\Keil_474\\ARM\\ARMCC\\bin\\..\\include\\math.h"



 

#line 3 "..\\..\\..\\mathem.c"


int	aa,bb,zn2,aa1,bb1,aa2,bb2,mmm,bbz0,bbz1,bbz2;
int	anglIab,anglIbc,anglIca;
void	perem(void)
{
	switch (adc_ch)
	{	
		case	0	:	{ReIa=Re1;ImIa=Im1;ReIa_2g=Re2;ImIa_2g=Im2;}	break;	
		case	1	:	{ReIb=Re1;ImIb=Im1;ReIb_2g=Re2;ImIb_2g=Im2;}	break;		
		case	2	:	{ReIc=Re1;ImIc=Im1;ReIc_2g=Re2;ImIc_2g=Im2;}	break;	
		case	3	:	{ReUad=Re1;ImUad=Im1;ReUad_2g=Re2;ImUad_2g=Im2;}	break;
		case	4	:	{ReUa=Re1;ImUa=Im1;ReUa_2g=Re2;ImUa_2g=Im2;}	break;	
		case	5	:	{ReUb=Re1;ImUb=Im1;ReUb_2g=Re2;ImUb_2g=Im2;}	break;		
		case	6	:	{ReUc=Re1;ImUc=Im1;ReUc_2g=Re2;ImUc_2g=Im2;}	break;	
		case	7	:	{ReU3o_i=Re1;ImU3o_i=Im1;}	break;					
	}
}	
uint32_t my_sqrt (int32_t Re,int32_t Im)
{
int	x,y,b,m;	
	
m = 0x40000000;
y = 0;			
x=Re*Re+Im*Im;	
   while (m != 0)
		{		 
      b = y | m;
      y = y >> 1;
      if (x >= b) 
				{
						x = x - b;
						y = y | m;
				}
      m = m >> 2;
		}	
		
   return y;
}





void	mat_potok_1 (void)
{	
zzz1 = *(volatile unsigned long *)0xE0001004;


	
arcF_Ia=arctg(ReIa,ImIa);	
zzz2 = *(volatile unsigned long *)0xE0001004-zzz1;		
Ia=985*my_sqrt(ReIa,ImIa)/1000;	
izmer[9]= Ia>>8;
izmer[10]= Ia;	

arcF_Ib=arctg(ReIb,ImIb);		
Ib=985*my_sqrt(ReIb,ImIb)/1000;	
izmer[11]= Ib>>8;
izmer[12]= Ib;		

arcF_Ic=arctg(ReIc,ImIc);	
Ic=985*my_sqrt(ReIc,ImIc)/1000;
izmer[13]= Ic>>8;
izmer[14]= Ic;	
	

Ua=9975*my_sqrt(ReUa,ImUa)/4500;			
arcF_Ua=arctg(ReUa,ImUa);
izmer[0]= Ua>>8;
izmer[1]= Ua;

Ub=9975*my_sqrt(ReUb,ImUb)/4500;
arcF_Ub=arctg(ReUb,ImUb);
izmer[2]= Ub>>8;
izmer[3]= Ub;
	
Uc=9975*my_sqrt(ReUc,ImUc)/4500;
arcF_Uc=arctg(ReUc,ImUc);
izmer[4]= Uc>>8;
izmer[5]= Uc;			
	
Uad=2*my_sqrt(ReUad,ImUad);
arcF_Uad=arctg(ReUad,ImUad);
izmer[96]= Uad>>16;
izmer[97]= Uad>>8;
izmer[98]= Uad;	
	




}




void	mat_potok_2 (void)
{
Ia_2g=Mod(ReIa_2g,ImIa_2g);			
Ib_2g=Mod(ReIb_2g,ImIb_2g);		
Ic_2g=Mod(ReIc_2g,ImIc_2g);			

U3o_i=my_sqrt(ReU3o_i,ImU3o_i);
arcF_U3o_i=arctg(ReU3o_i,ImU3o_i);
izmer[6]= U3o_i>>24;
izmer[7]= U3o_i>>16;
izmer[8]= U3o_i>>8;	

if	(Ia>30000)  
{Ia_2_1g = Ia_2g*100/Ia;}
else	{Ia_2_1g=0;}
izmer[50]= Ia_2_1g;

if	(Ib>30000)  
{Ib_2_1g = Ib_2g*100/Ib;}
else	{Ib_2_1g=0;}
izmer[51]= Ib_2_1g;

if	(Ic>30000)  
{Ic_2_1g = Ic_2g*100/Ic;}
else	{Ic_2_1g=0;}
izmer[52]= Ic_2_1g;


Re_I3o_p	=	ReIa + ReIb + ReIc;
Im_I3o_p	=	ImIa + ImIb + ImIc;
I3o_p = (1000*my_sqrt(Re_I3o_p,Im_I3o_p)/1414);
arcI3o_p=arctg(Re_I3o_p,Im_I3o_p);

if (I3o_p >= 0x960000){I3o_p=0x960000;}
izmer[44]= I3o_p>>8;
izmer[45]= I3o_p;

Re_Uab=ReUa-ReUb;		Im_Uab=ImUa-ImUb; 
Uab=9975*my_sqrt(Re_Uab,Im_Uab)/4500;
if (Uab>>24!=0){Uab=0xFEFFFF;}
arcF_Uab=arctg(Re_Uab,Im_Uab);
izmer[32]= Uab>>8;
izmer[33]= Uab;	

Re_Ubc=ReUb-ReUc;		Im_Ubc=ImUb-ImUc; 
Ubc=9975*my_sqrt(Re_Ubc,Im_Ubc)/4500;
if (Ubc>>24!=0){Ubc=0xFEFFFF;}
arcF_Ubc=arctg(Re_Ubc,Im_Ubc);
izmer[34]= Ubc>>8;
izmer[35]= Ubc;

Re_Uca=ReUc-ReUa;		Im_Uca=ImUc-ImUa; 
Uca=9975*my_sqrt(Re_Uca,Im_Uca)/4500;
if (Uca>>24!=0){Uca=0xFEFFFF;}
arcF_Uca=arctg(Re_Uca,Im_Uca);
izmer[36]= Uca>>8;
izmer[37]= Uca;

Re_Ubnn = Ktn*(2*ReUa+ReUb+ReUc)-Ktn0*(ReUad+ReU3o_i);
Im_Ubnn = Ktn*(2*ImUa+ImUb+ImUc)-Ktn0*(ImUad+ImU3o_i);
Ubnn = Mod(Re_Ubnn,Im_Ubnn);
Ubnn = my_sqrt(Re_Ubnn,Im_Ubnn);
if (Ubnn>>24!=0){Ubnn=0xFEFFFF;}
izmer[38]= Ubnn>>8;
izmer[39]= Ubnn;

}




void	mat_potok_3 (void)
{
	
ReI1 = ReIa/3 - ReIb/6 - (ImIb*866)/3000 - ReIc/6 + (ImIc*866)/3000;
ImI1 = ImIa/3 - ImIb/6 + (ReIb*866)/3000 - ImIc/6 - (ReIc*866)/3000;
I1 = 50*Mod(ReI1,ImI1)/45;
izmer[46]= I1>>8;
izmer[47]= I1;

Delta_I1  = I1 - MemDel_I1;
MemDel_I1 = I1;

ReI2 = ReIa/3 - ReIb/6 + (ImIb*866)/3000 - ReIc/6 - (ImIc*866)/3000;
ImI2 = ImIa/3 - ImIb/6 - (ReIb*866)/3000 - ImIc/6 + (ReIc*866)/3000;
I2 = 50*Mod(ReI2,ImI2)/45;
izmer[48]= I2>>8;
izmer[49]= I2;

Delta_I2 = I2 - MemDel_I2;
MemDel_I2 = I2;

ReU1 = ReUa/3 - ReUb/6 - (ImUb*866)/3000 - ReUc/6 + (ImUc*866)/3000;
ImU1 = ImUa/3 - ImUb/6 + (ReUb*866)/3000 - ImUc/6 - (ReUc*866)/3000;
U1 = 101*Mod(ReU1,ImU1)/45;
izmer[40]= U1>>8;
izmer[41]= U1;

ReU2 = ReUa/3 - ReUb/6 + (ImUb*866)/3000 - ReUc/6 - (ImUc*866)/3000;
ImU2 = ImUa/3 - ImUb/6 - (ReUb*866)/3000 - ImUc/6 + (ReUc*866)/3000;
U2 = 101*Mod(ReU2,ImU2)/45;
izmer[42]= U2>>8;
izmer[43]= U2;	
	

Re_Uab=ReUa-ReUb;		  Im_Uab=ImUa-ImUb;
Re_Ubc=ReUb-ReUc;			Im_Ubc=ImUb-ImUc;
Re_Uca=ReUc-ReUa;			Im_Uca=ImUc-ImUa;
	
Re_Iab=ReIa-ReIb;			Im_Iab=ImIa-ImIb;
Re_Ibc=ReIb-ReIc;			Im_Ibc=ImIb-ImIc;
Re_Ica=ReIc-ReIa;			Im_Ica=ImIc-ImIa;


zn2=Re_Iab*Re_Iab+Im_Iab*Im_Iab;
Re_Zab=(Re_Uab*Re_Iab + Im_Uab*Im_Iab)/zn2;
Im_Zab=(Im_Uab*Re_Iab - Re_Uab*Im_Iab)/zn2;
anglIab=arctg(Re_Iab,Im_Iab);
arcZab=arcF_Uab-anglIab;
Iab = my_sqrt(Re_Iab,Im_Iab);
if(Iab>Ing){Zab=2595*Uab/Iab/10;}
else{Zab=0xFFFFFFFF;}
izmer[53]= Zab>>16;
izmer[54]= Zab>>8;
izmer[55]= Zab;

zn2=Re_Ibc*Re_Ibc+Im_Ibc*Im_Ibc;	
Re_Zbc=(Re_Ubc*Re_Ibc + Im_Ubc*Im_Ibc)/zn2;
Im_Zbc=(Im_Ubc*Re_Ibc - Re_Ubc*Im_Ibc)/zn2;
anglIbc=arctg(Re_Ibc,Im_Ibc);
arcZbc=arcF_Ubc-anglIbc;
Ibc = my_sqrt(Re_Ibc,Im_Ibc);
if(Ibc>Ing){Zbc=2595*Ubc/Ibc/10;}
else{Zbc=0xFFFFFFFF;}
izmer[56]= Zbc>>16;
izmer[57]= Zbc>>8;
izmer[58]= Zbc;

zn2=Re_Ica*Re_Ica+Im_Ica*Im_Ica;	
Re_Zca=(Re_Uca*Re_Ica + Im_Uca*Im_Ica)/zn2;
Im_Zca=(Im_Uca*Re_Ica - Re_Uca*Im_Ica)/zn2;
anglIca=arctg(Re_Ica,Im_Ica);
arcZca=arcF_Uca-anglIca;
Ica = my_sqrt(Re_Ica,Im_Ica);
if(Ica>Ing){Zca=2595*Uca/Ica/10;}
else{Zca=0xFFFFFFFF;}
izmer[59]= Zca>>16;
izmer[60]= Zca>>8;
izmer[61]= Zca;



ZZp_0p=2672*U3o_i/I3o_p;

izmer[71]= ZZp_0p>>16;
izmer[72]= ZZp_0p>>8;
izmer[73]= ZZp_0p;



ReIZa=ReIa+3*Re_I3o_p/3;
ImIZa=ImIa+3*Im_I3o_p/3;
IZa = my_sqrt(ReIZa,ImIZa);
ang_Za0 = arctg(ReIZa,ImIZa);
arcZa0=arcF_Ua-ang_Za0;
if((IZa>Ing)&&(Ia>Ing)){Za0=2595*Ua/IZa/10;}
else{Za0=0xFFFFFFFF;}
izmer[62]= Za0>>16;
izmer[63]= Za0>>8;
izmer[64]= Za0;
}



void	mat_potok_4 (void)
{


ReIZb=ReIb+3*Re_I3o_p/3;
ImIZb=ImIb+3*Im_I3o_p/3;
IZb = my_sqrt(ReIZb,ImIZb);
ang_Zb0 = arctg(ReIZb,ImIZb);
arcZb0=arcF_Ub-ang_Zb0;
if((IZb>Ing)&&(Ib>Ing)){Zb0=2595*Ub/IZb/10;}
else{Zb0=0xFFFFFFFF;}
izmer[65]= Zb0>>16;
izmer[66]= Zb0>>8;
izmer[67]= Zb0;

ReIZc=ReIc+3*Re_I3o_p/3;
ImIZc=ImIc+3*Im_I3o_p/3;
IZc = my_sqrt(ReIZc,ImIZc);
ang_Zc0 = arctg(ReIZc,ImIZc);
arcZc0=arcF_Uc-ang_Zc0;
if((IZc>Ing)&&(Ic>Ing)){Zc0=2595*Uc/IZc/10;}
else{Zc0=0xFFFFFFFF;}
izmer[68]= Zc0>>16;
izmer[69]= Zc0>>8;
izmer[70]= Zc0;	
	


F_Zab = arcZab;	
if (Zab == 0xFFFFFFFF) {F_Zab=0xFFFFFFFF;}
if (Zab == 0) {F_Zab=0xFFFFFFFF;}
if(F_Zab<0){F_Zab = F_Zab+1800;}
if((Uab>=Ung)&&(Iab>=Ing)){F_Zab=F_Zab/10;}
else{F_Zab=0xFFFFFFFF;}
izmer[82]= F_Zab>>8;
izmer[83]= F_Zab;


F_Zbc = arcZbc;
if (Zbc == 0xFFFFFFFF) {F_Zbc=0xFFFFFFFF;}
if (Zbc == 0) {F_Zbc=0xFFFFFFFF;}	
if(F_Zbc<0){F_Zbc = F_Zbc+1800;}
if((Ubc>=Ung)&&(Ibc>=Ing)){F_Zbc=F_Zbc/10;}
else{F_Zbc=0xFFFFFFFF;}	
izmer[84]= F_Zbc>>8;
izmer[85]= F_Zbc;


F_Zca = arcZca;
if (Zca == 0xFFFFFFFF) {F_Zca=0xFFFFFFFF;}
if (Zca == 0) {F_Zca=0xFFFFFFFF;}	
if(F_Zca<0){F_Zca = F_Zca+1800;}
if((Uca>=Ung)&&(Ica>=Ing)){F_Zca=F_Zca/10;}
else{F_Zca=0xFFFFFFFF;}	
izmer[86]= F_Zca>>8;
izmer[87]= F_Zca;



F_Za0 = arcZa0;	
if (Za0 == 0xFFFFFFFF) {F_Za0=0xFFFFFFFF;}
if (Za0 == 0) {F_Za0=0xFFFFFFFF;}	
if(F_Za0<0){F_Za0=F_Za0+1800;}
if((Ua>Ung)&&(IZa>Ing)){F_Za0=F_Za0/10;}
else{F_Za0=0xFFFFFFFF;}	
if(Ia<Ing){F_Za0=0xFFFFFFFF;}
izmer[88]= F_Za0>>8;
izmer[89]= F_Za0;


F_Zb0 = arcZb0;
if (Zb0 == 0xFFFFFFFF) {F_Zb0=0xFFFFFFFF;}
if (Zb0== 0) {F_Zb0=0xFFFFFFFF;}
if(F_Zb0<0){F_Zb0=F_Zb0+1800;}
if((Ub>Ung)&&(IZb>Ing)){F_Zb0=F_Zb0/10;}
else{F_Zb0=0xFFFFFFFF;}	
if(Ib<Ing){F_Za0=0xFFFFFFFF;}
izmer[90]= F_Zb0>>8;
izmer[91]= F_Zb0;


F_Zc0 = arcZc0;
if (Zc0 == 0xFFFFFFFF) {F_Zc0=0xFFFFFFFF;}
if (Zc0== 0) {F_Zc0=0xFFFFFFFF;}	
if(F_Zc0<0){F_Zc0=F_Zc0+1800;}
if((Uc>Ung)&&(IZc>Ing)){F_Zc0=F_Zc0/10;}
else{F_Zc0=0xFFFFFFFF;}	
if(Ic<Ing){F_Za0=0xFFFFFFFF;}
izmer[92]= F_Zc0>>8;
izmer[93]= F_Zc0;


if	(I3o_p >= Ing)
{	
F_I3o_p = arcI3o_p;	
if (I3o_p == 0xFFFFFFFF) {F_I3o_p=0xFFFFFFFF;}
if (I3o_p== 0) {F_I3o_p=0xFFFFFFFF;}	





if((Re_I3o_p<0)&&(Im_I3o_p>0))	{F_I3o_p = arcI3o_p + 1800;}
if((Re_I3o_p<0)&&(Im_I3o_p<0)) 	{F_I3o_p = arcI3o_p - 1800;}
}	
else	F_I3o_p=0xFFFFFFFF;	


F_Ia = arcF_Ia;
if (Ia == 0xFFFFFFFF) {F_Ia=0xFFFFFFFF;}
if (Ia == 0) {F_Ia=0xFFFFFFFF;}





if((ReIa<0)&&(ImIa>0))	{F_Ia = arcF_Ia + 1800;}
if((ReIa<0)&&(ImIa<0)) 	{F_Ia = arcF_Ia - 1800;}


F_Ib = arcF_Ib;
if (Ib == 0xFFFFFFFF) {F_Ib=0xFFFFFFFF;}
if (Ib == 0) {F_Ib=0xFFFFFFFF;}





if((ReIb<0)&&(ImIb>0))	{F_Ib = arcF_Ib + 1800;}
if((ReIb<0)&&(ImIb<0)) 	{F_Ib = arcF_Ib - 1800;}


F_Ic = arcF_Ic;
if (Ic == 0xFFFFFFFF) {F_Ic=0xFFFFFFFF;}
if (Ic == 0) {F_Ic=0xFFFFFFFF;}





if((ReIc<0)&&(ImIc>0))	{F_Ic = arcF_Ic + 1800;}
if((ReIc<0)&&(ImIc<0)) 	{F_Ic = arcF_Ic - 1800;}


F_Ua = arcF_Ua;
if (Ua == 0xFFFFFFFF) {F_Ua=0xFFFFFFFF;}
if (Ua == 0) {F_Ua=0xFFFFFFFF;}





if((ReUa<0)&&(ImUa>0))	{F_Ua = arcF_Ua + 1800;}
if((ReUa<0)&&(ImUa<0)) 	{F_Ua = arcF_Ua - 1800;}


F_Ub = arcF_Ub;
if (Ub == 0xFFFFFFFF) {F_Ub=0xFFFFFFFF;}
if (Ub == 0) {F_Ub=0xFFFFFFFF;}





if((ReUb<0)&&(ImUb>0))	{F_Ub = arcF_Ub + 1800;}
if((ReUb<0)&&(ImUb<0)) 	{F_Ub = arcF_Ub - 1800;}


F_Uc = arcF_Uc;	
if (Uc == 0xFFFFFFFF) {F_Uc=0xFFFFFFFF;}
if (Uc == 0) {F_Uc=0xFFFFFFFF;}





if((ReUc<0)&&(ImUc>0))	{F_Uc = arcF_Uc + 1800;}
if((ReUc<0)&&(ImUc<0)) 	{F_Uc = arcF_Uc - 1800;}	

F_Uad = arcF_Uad;	
if (Uad == 0xFFFFFFFF) {F_Uad=0xFFFFFFFF;}
if (Uad == 0) {F_Uad=0xFFFFFFFF;}





if((ReUad<0)&&(ImUad>0))	{F_Uad = arcF_Uad + 1800;}
if((ReUad<0)&&(ImUad<0)) 	{F_Uad = arcF_Uad - 1800;}


F_Uab = arcF_Uab;
if (Uab == 0xFFFFFFFF) {F_Uab=0xFFFFFFFF;}
if (Uab == 0) {F_Uab=0xFFFFFFFF;}





if((Re_Uab<0)&&(Im_Uab>0))	{F_Uab = F_Uab + 1800;}
if((Re_Uab<0)&&(Im_Uab<0)) 	{F_Uab = F_Uab - 1800;}


F_Ubc = arcF_Ubc;
if (Ubc == 0xFFFFFFFF) {F_Ubc=0xFFFFFFFF;}
if (Ubc == 0) {F_Ubc=0xFFFFFFFF;}





if((Re_Ubc<0)&&(Im_Ubc>0))	{F_Ubc = F_Ubc + 1800;}
if((Re_Ubc<0)&&(Im_Ubc<0)) 	{F_Ubc = F_Ubc - 1800;}


F_Uca = arcF_Uca;
if (Uca == 0xFFFFFFFF) {F_Uca=0xFFFFFFFF;}
if (Uca == 0) {F_Uca=0xFFFFFFFF;}





if((Re_Uca<0)&&(Im_Uca>0))	{F_Uca = F_Uca + 1800;}
if((Re_Uca<0)&&(Im_Uca<0)) 	{F_Uca = F_Uca - 1800;}


if ((Ubc>=Ung)&&(Ia>=Ing))
{F_Ia_Ubc=F_Ubc-F_Ia+900;}
else	{F_Ia_Ubc=0xFFFFFFFF;}

if ((Uca>=Ung)&&(Ib>=Ing))
{F_Ib_Uca=F_Uca-F_Ib+900;}
else	{F_Ia_Ubc=0xFFFFFFFF;}

if ((Uab>=Ung)&&(Ic>=Ing))
{F_Ic_Uab=F_Uab-F_Ic+900;}
else	{F_Ic_Uab=0xFFFFFFFF;}


if	(U3o_i>=Ung)
{
F_U3o_i = arcF_U3o_i;
if (U3o_i == 0xFFFFFFFF) {F_U3o_i=0xFFFFFFFF;}
if (U3o_i == 0) {F_U3o_i=0xFFFFFFFF;}





if((ReU3o_i<0)&&(ImU3o_i>0))	{F_U3o_i = F_U3o_i + 1800;}
if((ReU3o_i<0)&&(ImU3o_i<0)) 	{F_U3o_i = F_U3o_i - 1800;}
}
else	{F_U3o_i=0xFFFFFFFF;}
izmer[21]= F_U3o_i/10>>8;
izmer[22]= F_U3o_i/10;


F_I3op_U3oi=F_U3o_i-F_I3o_p;
if(F_I3op_U3oi<0){
F_I3op_U3oi=1800+F_I3op_U3oi;}
F_I3op_U3oi=F_U3o_i-F_I3o_p;




baz=F_Ua;


FB_Ia=F_Ia-baz;
if(FB_Ia<0){FB_Ia=FB_Ia+3600;}
izmer[23]= FB_Ia/10>>8;
izmer[24]= FB_Ia/10;

FB_Ib=F_Ib-baz;
if(FB_Ib<0){FB_Ib=FB_Ib+3600;}
izmer[25]= FB_Ib/10>>8;
izmer[26]= FB_Ib/10;

FB_Ic=F_Ic-baz;
if(FB_Ic<0){FB_Ic=FB_Ic+3600;}
izmer[27]= FB_Ic/10>>8;
izmer[28]= FB_Ic/10;

FB_Ua=F_Ua-baz;
if(FB_Ua<0){FB_Ua=FB_Ua+3600;}
izmer[15]= FB_Ua/10>>8;
izmer[16]= FB_Ua/10;

FB_Ub=F_Ub-baz;
if(FB_Ub<0){FB_Ub=FB_Ub+3600;}
izmer[17]= FB_Ub/10>>8;
izmer[18]= FB_Ub/10;

FB_Uc=F_Uc-baz;
if(FB_Uc<0){FB_Uc=FB_Uc+3600;}
izmer[19]= FB_Uc/10>>8;
izmer[20]= FB_Uc/10;

FB_U3o_i=F_U3o_i-baz;
if(FB_U3o_i<0){FB_U3o_i=FB_U3o_i+3600;}
izmer[21]= FB_U3o_i/10>>8;
izmer[22]= FB_U3o_i/10;

FB_Uad=F_Uad-baz;
if(FB_Uad<0){FB_Uad=FB_Uad+3600;}
izmer[99]= FB_Uad/10>>8;
izmer[100]= FB_Uad/10;


FB_Uab=F_Uab-baz;
if(FB_Uab<0){FB_Uab=FB_Uab+3600;}
izmer[74]= FB_Uab/10>>8;
izmer[75]= FB_Uab/10;

FB_Ubc=F_Ubc-baz;
if(FB_Ubc<0){FB_Ubc=FB_Ubc+3600;}
izmer[76]= FB_Ubc/10>>8;
izmer[77]= FB_Ubc/10;

FB_Uca=F_Uca-baz;
if(FB_Uca<0){FB_Uca=FB_Uca+3600;}
izmer[78]= FB_Uca/10>>8;
izmer[79]= FB_Uca/10;

FB_I3o_p=F_I3o_p-baz;
if(FB_I3o_p<0){FB_I3o_p=FB_I3o_p+3600;}
izmer[80]= FB_I3o_p/10>>8;
izmer[81]= FB_I3o_p/10;	

FB_I3o_p=F_I3o_p-baz;
if(F_I3op_U3oi<0){F_I3op_U3oi=F_I3op_U3oi+3600;}
izmer[94]= F_I3op_U3oi/10>>8;
izmer[95]= F_I3op_U3oi/10;
}



void	mat_potok_all (void)
{
zzz1 = *(volatile unsigned long *)0xE0001004;


	
arcF_Ia=arctg(ReIa,ImIa);	
zzz2 = *(volatile unsigned long *)0xE0001004-zzz1;		
Ia=985*my_sqrt(ReIa,ImIa)/1000;	
izmer[9]= Ia>>8;
izmer[10]= Ia;	

arcF_Ib=arctg(ReIb,ImIb);		
Ib=985*my_sqrt(ReIb,ImIb)/1000;	
izmer[11]= Ib>>8;
izmer[12]= Ib;		

arcF_Ic=arctg(ReIc,ImIc);	
Ic=985*my_sqrt(ReIc,ImIc)/1000;
izmer[13]= Ic>>8;
izmer[14]= Ic;	
	

Ua=9975*my_sqrt(ReUa,ImUa)/4500;			
arcF_Ua=arctg(ReUa,ImUa);
izmer[0]= Ua>>8;
izmer[1]= Ua;

Ub=9975*my_sqrt(ReUb,ImUb)/4500;
arcF_Ub=arctg(ReUb,ImUb);
izmer[2]= Ub>>8;
izmer[3]= Ub;
	
Uc=9975*my_sqrt(ReUc,ImUc)/4500;
arcF_Uc=arctg(ReUc,ImUc);
izmer[4]= Uc>>8;
izmer[5]= Uc;			
	
Uad=2*my_sqrt(ReUad,ImUad);
arcF_Uad=arctg(ReUad,ImUad);
izmer[96]= Uad>>16;
izmer[97]= Uad>>8;
izmer[98]= Uad;	
	
Ia_2g=Mod(ReIa_2g,ImIa_2g);			
Ib_2g=Mod(ReIb_2g,ImIb_2g);		
Ic_2g=Mod(ReIc_2g,ImIc_2g);			

U3o_i=my_sqrt(ReU3o_i,ImU3o_i);
arcF_U3o_i=arctg(ReU3o_i,ImU3o_i);
izmer[6]= U3o_i>>24;
izmer[7]= U3o_i>>16;
izmer[8]= U3o_i>>8;	

if	(Ia>30000)  
{Ia_2_1g = Ia_2g*100/Ia;}
else	{Ia_2_1g=0;}
izmer[50]= Ia_2_1g;

if	(Ib>30000)  
{Ib_2_1g = Ib_2g*100/Ib;}
else	{Ib_2_1g=0;}
izmer[51]= Ib_2_1g;

if	(Ic>30000)  
{Ic_2_1g = Ic_2g*100/Ic;}
else	{Ic_2_1g=0;}
izmer[52]= Ic_2_1g;


Re_I3o_p	=	ReIa + ReIb + ReIc;
Im_I3o_p	=	ImIa + ImIb + ImIc;
I3o_p = (1000*my_sqrt(Re_I3o_p,Im_I3o_p)/1414);
arcI3o_p=arctg(Re_I3o_p,Im_I3o_p);

if (I3o_p >= 0x960000){I3o_p=0x960000;}
izmer[44]= I3o_p>>8;
izmer[45]= I3o_p;

Re_Uab=ReUa-ReUb;		Im_Uab=ImUa-ImUb; 
Uab=9975*my_sqrt(Re_Uab,Im_Uab)/4500;
if (Uab>>24!=0){Uab=0xFEFFFF;}
arcF_Uab=arctg(Re_Uab,Im_Uab);
izmer[32]= Uab>>8;
izmer[33]= Uab;	

Re_Ubc=ReUb-ReUc;		Im_Ubc=ImUb-ImUc; 
Ubc=9975*my_sqrt(Re_Ubc,Im_Ubc)/4500;
if (Ubc>>24!=0){Ubc=0xFEFFFF;}
arcF_Ubc=arctg(Re_Ubc,Im_Ubc);
izmer[34]= Ubc>>8;
izmer[35]= Ubc;

Re_Uca=ReUc-ReUa;		Im_Uca=ImUc-ImUa; 
Uca=9975*my_sqrt(Re_Uca,Im_Uca)/4500;
if (Uca>>24!=0){Uca=0xFEFFFF;}
arcF_Uca=arctg(Re_Uca,Im_Uca);
izmer[36]= Uca>>8;
izmer[37]= Uca;

Re_Ubnn = Ktn*(2*ReUa+ReUb+ReUc)-Ktn0*(ReUad+ReU3o_i);
Im_Ubnn = Ktn*(2*ImUa+ImUb+ImUc)-Ktn0*(ImUad+ImU3o_i);
Ubnn = Mod(Re_Ubnn,Im_Ubnn);
Ubnn = my_sqrt(Re_Ubnn,Im_Ubnn);
if (Ubnn>>24!=0){Ubnn=0xFEFFFF;}
izmer[38]= Ubnn>>8;
izmer[39]= Ubnn;

ReI1 = ReIa/3 - ReIb/6 - (ImIb*866)/3000 - ReIc/6 + (ImIc*866)/3000;
ImI1 = ImIa/3 - ImIb/6 + (ReIb*866)/3000 - ImIc/6 - (ReIc*866)/3000;
I1 = 50*Mod(ReI1,ImI1)/45;
izmer[46]= I1>>8;
izmer[47]= I1;

Delta_I1  = I1 - MemDel_I1;
MemDel_I1 = I1;

ReI2 = ReIa/3 - ReIb/6 + (ImIb*866)/3000 - ReIc/6 - (ImIc*866)/3000;
ImI2 = ImIa/3 - ImIb/6 - (ReIb*866)/3000 - ImIc/6 + (ReIc*866)/3000;
I2 = 50*Mod(ReI2,ImI2)/45;
izmer[48]= I2>>8;
izmer[49]= I2;

Delta_I2 = I2 - MemDel_I2;
MemDel_I2 = I2;

ReU1 = ReUa/3 - ReUb/6 - (ImUb*866)/3000 - ReUc/6 + (ImUc*866)/3000;
ImU1 = ImUa/3 - ImUb/6 + (ReUb*866)/3000 - ImUc/6 - (ReUc*866)/3000;
U1 = 101*Mod(ReU1,ImU1)/45;
izmer[40]= U1>>8;
izmer[41]= U1;

ReU2 = ReUa/3 - ReUb/6 + (ImUb*866)/3000 - ReUc/6 - (ImUc*866)/3000;
ImU2 = ImUa/3 - ImUb/6 - (ReUb*866)/3000 - ImUc/6 + (ReUc*866)/3000;
U2 = 101*Mod(ReU2,ImU2)/45;
izmer[42]= U2>>8;
izmer[43]= U2;	
	

Re_Uab=ReUa-ReUb;		  Im_Uab=ImUa-ImUb;
Re_Ubc=ReUb-ReUc;			Im_Ubc=ImUb-ImUc;
Re_Uca=ReUc-ReUa;			Im_Uca=ImUc-ImUa;
	
Re_Iab=ReIa-ReIb;			Im_Iab=ImIa-ImIb;
Re_Ibc=ReIb-ReIc;			Im_Ibc=ImIb-ImIc;
Re_Ica=ReIc-ReIa;			Im_Ica=ImIc-ImIa;


zn2=Re_Iab*Re_Iab+Im_Iab*Im_Iab;
Re_Zab=(Re_Uab*Re_Iab + Im_Uab*Im_Iab)/zn2;
Im_Zab=(Im_Uab*Re_Iab - Re_Uab*Im_Iab)/zn2;
anglIab=arctg(Re_Iab,Im_Iab);
arcZab=arcF_Uab-anglIab;
Iab = my_sqrt(Re_Iab,Im_Iab);
if(Iab>Ing){Zab=2595*Uab/Iab/10;}
else{Zab=0xFFFFFFFF;}
izmer[53]= Zab>>16;
izmer[54]= Zab>>8;
izmer[55]= Zab;

zn2=Re_Ibc*Re_Ibc+Im_Ibc*Im_Ibc;	
Re_Zbc=(Re_Ubc*Re_Ibc + Im_Ubc*Im_Ibc)/zn2;
Im_Zbc=(Im_Ubc*Re_Ibc - Re_Ubc*Im_Ibc)/zn2;
anglIbc=arctg(Re_Ibc,Im_Ibc);
arcZbc=arcF_Ubc-anglIbc;
Ibc = my_sqrt(Re_Ibc,Im_Ibc);
if(Ibc>Ing){Zbc=2595*Ubc/Ibc/10;}
else{Zbc=0xFFFFFFFF;}
izmer[56]= Zbc>>16;
izmer[57]= Zbc>>8;
izmer[58]= Zbc;

zn2=Re_Ica*Re_Ica+Im_Ica*Im_Ica;	
Re_Zca=(Re_Uca*Re_Ica + Im_Uca*Im_Ica)/zn2;
Im_Zca=(Im_Uca*Re_Ica - Re_Uca*Im_Ica)/zn2;
anglIca=arctg(Re_Ica,Im_Ica);
arcZca=arcF_Uca-anglIca;
Ica = my_sqrt(Re_Ica,Im_Ica);
if(Ica>Ing){Zca=2595*Uca/Ica/10;}
else{Zca=0xFFFFFFFF;}
izmer[59]= Zca>>16;
izmer[60]= Zca>>8;
izmer[61]= Zca;



ZZp_0p=2672*U3o_i/I3o_p;

izmer[71]= ZZp_0p>>16;
izmer[72]= ZZp_0p>>8;
izmer[73]= ZZp_0p;



ReIZa=ReIa+3*Re_I3o_p/3;
ImIZa=ImIa+3*Im_I3o_p/3;
IZa = my_sqrt(ReIZa,ImIZa);
ang_Za0 = arctg(ReIZa,ImIZa);
arcZa0=arcF_Ua-ang_Za0;
if((IZa>Ing)&&(Ia>Ing)){Za0=2595*Ua/IZa/10;}
else{Za0=0xFFFFFFFF;}
izmer[62]= Za0>>16;
izmer[63]= Za0>>8;
izmer[64]= Za0;


ReIZb=ReIb+3*Re_I3o_p/3;
ImIZb=ImIb+3*Im_I3o_p/3;
IZb = my_sqrt(ReIZb,ImIZb);
ang_Zb0 = arctg(ReIZb,ImIZb);
arcZb0=arcF_Ub-ang_Zb0;
if((IZb>Ing)&&(Ib>Ing)){Zb0=2595*Ub/IZb/10;}
else{Zb0=0xFFFFFFFF;}
izmer[65]= Zb0>>16;
izmer[66]= Zb0>>8;
izmer[67]= Zb0;

ReIZc=ReIc+3*Re_I3o_p/3;
ImIZc=ImIc+3*Im_I3o_p/3;
IZc = my_sqrt(ReIZc,ImIZc);
ang_Zc0 = arctg(ReIZc,ImIZc);
arcZc0=arcF_Uc-ang_Zc0;
if((IZc>Ing)&&(Ic>Ing)){Zc0=2595*Uc/IZc/10;}
else{Zc0=0xFFFFFFFF;}
izmer[68]= Zc0>>16;
izmer[69]= Zc0>>8;
izmer[70]= Zc0;	
	


F_Zab = arcZab;	
if (Zab == 0xFFFFFFFF) {F_Zab=0xFFFFFFFF;}
if (Zab == 0) {F_Zab=0xFFFFFFFF;}
if(F_Zab<0){F_Zab = F_Zab+1800;}
if((Uab>=Ung)&&(Iab>=Ing)){F_Zab=F_Zab/10;}
else{F_Zab=0xFFFFFFFF;}
izmer[82]= F_Zab>>8;
izmer[83]= F_Zab;


F_Zbc = arcZbc;
if (Zbc == 0xFFFFFFFF) {F_Zbc=0xFFFFFFFF;}
if (Zbc == 0) {F_Zbc=0xFFFFFFFF;}	
if(F_Zbc<0){F_Zbc = F_Zbc+1800;}
if((Ubc>=Ung)&&(Ibc>=Ing)){F_Zbc=F_Zbc/10;}
else{F_Zbc=0xFFFFFFFF;}	
izmer[84]= F_Zbc>>8;
izmer[85]= F_Zbc;


F_Zca = arcZca;
if (Zca == 0xFFFFFFFF) {F_Zca=0xFFFFFFFF;}
if (Zca == 0) {F_Zca=0xFFFFFFFF;}	
if(F_Zca<0){F_Zca = F_Zca+1800;}
if((Uca>=Ung)&&(Ica>=Ing)){F_Zca=F_Zca/10;}
else{F_Zca=0xFFFFFFFF;}	
izmer[86]= F_Zca>>8;
izmer[87]= F_Zca;



F_Za0 = arcZa0;	
if (Za0 == 0xFFFFFFFF) {F_Za0=0xFFFFFFFF;}
if (Za0 == 0) {F_Za0=0xFFFFFFFF;}	
if(F_Za0<0){F_Za0=F_Za0+1800;}
if((Ua>Ung)&&(IZa>Ing)){F_Za0=F_Za0/10;}
else{F_Za0=0xFFFFFFFF;}	
if(Ia<Ing){F_Za0=0xFFFFFFFF;}
izmer[88]= F_Za0>>8;
izmer[89]= F_Za0;


F_Zb0 = arcZb0;
if (Zb0 == 0xFFFFFFFF) {F_Zb0=0xFFFFFFFF;}
if (Zb0== 0) {F_Zb0=0xFFFFFFFF;}
if(F_Zb0<0){F_Zb0=F_Zb0+1800;}
if((Ub>Ung)&&(IZb>Ing)){F_Zb0=F_Zb0/10;}
else{F_Zb0=0xFFFFFFFF;}	
if(Ib<Ing){F_Za0=0xFFFFFFFF;}
izmer[90]= F_Zb0>>8;
izmer[91]= F_Zb0;


F_Zc0 = arcZc0;
if (Zc0 == 0xFFFFFFFF) {F_Zc0=0xFFFFFFFF;}
if (Zc0== 0) {F_Zc0=0xFFFFFFFF;}	
if(F_Zc0<0){F_Zc0=F_Zc0+1800;}
if((Uc>Ung)&&(IZc>Ing)){F_Zc0=F_Zc0/10;}
else{F_Zc0=0xFFFFFFFF;}	
if(Ic<Ing){F_Za0=0xFFFFFFFF;}
izmer[92]= F_Zc0>>8;
izmer[93]= F_Zc0;


if	(I3o_p >= Ing)
{	
F_I3o_p = arcI3o_p;	
if (I3o_p == 0xFFFFFFFF) {F_I3o_p=0xFFFFFFFF;}
if (I3o_p== 0) {F_I3o_p=0xFFFFFFFF;}	





if((Re_I3o_p<0)&&(Im_I3o_p>0))	{F_I3o_p = arcI3o_p + 1800;}
if((Re_I3o_p<0)&&(Im_I3o_p<0)) 	{F_I3o_p = arcI3o_p - 1800;}
}	
else	F_I3o_p=0xFFFFFFFF;	


F_Ia = arcF_Ia;
if (Ia == 0xFFFFFFFF) {F_Ia=0xFFFFFFFF;}
if (Ia == 0) {F_Ia=0xFFFFFFFF;}





if((ReIa<0)&&(ImIa>0))	{F_Ia = arcF_Ia + 1800;}
if((ReIa<0)&&(ImIa<0)) 	{F_Ia = arcF_Ia - 1800;}


F_Ib = arcF_Ib;
if (Ib == 0xFFFFFFFF) {F_Ib=0xFFFFFFFF;}
if (Ib == 0) {F_Ib=0xFFFFFFFF;}





if((ReIb<0)&&(ImIb>0))	{F_Ib = arcF_Ib + 1800;}
if((ReIb<0)&&(ImIb<0)) 	{F_Ib = arcF_Ib - 1800;}


F_Ic = arcF_Ic;
if (Ic == 0xFFFFFFFF) {F_Ic=0xFFFFFFFF;}
if (Ic == 0) {F_Ic=0xFFFFFFFF;}





if((ReIc<0)&&(ImIc>0))	{F_Ic = arcF_Ic + 1800;}
if((ReIc<0)&&(ImIc<0)) 	{F_Ic = arcF_Ic - 1800;}


F_Ua = arcF_Ua;
if (Ua == 0xFFFFFFFF) {F_Ua=0xFFFFFFFF;}
if (Ua == 0) {F_Ua=0xFFFFFFFF;}





if((ReUa<0)&&(ImUa>0))	{F_Ua = arcF_Ua + 1800;}
if((ReUa<0)&&(ImUa<0)) 	{F_Ua = arcF_Ua - 1800;}


F_Ub = arcF_Ub;
if (Ub == 0xFFFFFFFF) {F_Ub=0xFFFFFFFF;}
if (Ub == 0) {F_Ub=0xFFFFFFFF;}





if((ReUb<0)&&(ImUb>0))	{F_Ub = arcF_Ub + 1800;}
if((ReUb<0)&&(ImUb<0)) 	{F_Ub = arcF_Ub - 1800;}


F_Uc = arcF_Uc;	
if (Uc == 0xFFFFFFFF) {F_Uc=0xFFFFFFFF;}
if (Uc == 0) {F_Uc=0xFFFFFFFF;}





if((ReUc<0)&&(ImUc>0))	{F_Uc = arcF_Uc + 1800;}
if((ReUc<0)&&(ImUc<0)) 	{F_Uc = arcF_Uc - 1800;}	

F_Uad = arcF_Uad;	
if (Uad == 0xFFFFFFFF) {F_Uad=0xFFFFFFFF;}
if (Uad == 0) {F_Uad=0xFFFFFFFF;}





if((ReUad<0)&&(ImUad>0))	{F_Uad = arcF_Uad + 1800;}
if((ReUad<0)&&(ImUad<0)) 	{F_Uad = arcF_Uad - 1800;}


F_Uab = arcF_Uab;
if (Uab == 0xFFFFFFFF) {F_Uab=0xFFFFFFFF;}
if (Uab == 0) {F_Uab=0xFFFFFFFF;}





if((Re_Uab<0)&&(Im_Uab>0))	{F_Uab = F_Uab + 1800;}
if((Re_Uab<0)&&(Im_Uab<0)) 	{F_Uab = F_Uab - 1800;}


F_Ubc = arcF_Ubc;
if (Ubc == 0xFFFFFFFF) {F_Ubc=0xFFFFFFFF;}
if (Ubc == 0) {F_Ubc=0xFFFFFFFF;}





if((Re_Ubc<0)&&(Im_Ubc>0))	{F_Ubc = F_Ubc + 1800;}
if((Re_Ubc<0)&&(Im_Ubc<0)) 	{F_Ubc = F_Ubc - 1800;}


F_Uca = arcF_Uca;
if (Uca == 0xFFFFFFFF) {F_Uca=0xFFFFFFFF;}
if (Uca == 0) {F_Uca=0xFFFFFFFF;}





if((Re_Uca<0)&&(Im_Uca>0))	{F_Uca = F_Uca + 1800;}
if((Re_Uca<0)&&(Im_Uca<0)) 	{F_Uca = F_Uca - 1800;}


if ((Ubc>=Ung)&&(Ia>=Ing))
{F_Ia_Ubc=F_Ubc-F_Ia+900;}
else	{F_Ia_Ubc=0xFFFFFFFF;}

if ((Uca>=Ung)&&(Ib>=Ing))
{F_Ib_Uca=F_Uca-F_Ib+900;}
else	{F_Ia_Ubc=0xFFFFFFFF;}

if ((Uab>=Ung)&&(Ic>=Ing))
{F_Ic_Uab=F_Uab-F_Ic+900;}
else	{F_Ic_Uab=0xFFFFFFFF;}


if	(U3o_i>=Ung)
{
F_U3o_i = arcF_U3o_i;
if (U3o_i == 0xFFFFFFFF) {F_U3o_i=0xFFFFFFFF;}
if (U3o_i == 0) {F_U3o_i=0xFFFFFFFF;}





if((ReU3o_i<0)&&(ImU3o_i>0))	{F_U3o_i = F_U3o_i + 1800;}
if((ReU3o_i<0)&&(ImU3o_i<0)) 	{F_U3o_i = F_U3o_i - 1800;}
}
else	{F_U3o_i=0xFFFFFFFF;}
izmer[21]= F_U3o_i/10>>8;
izmer[22]= F_U3o_i/10;


F_I3op_U3oi=F_U3o_i-F_I3o_p;
if(F_I3op_U3oi<0){
F_I3op_U3oi=1800+F_I3op_U3oi;}
F_I3op_U3oi=F_U3o_i-F_I3o_p;




baz=F_Ua;


FB_Ia=F_Ia-baz;
if(FB_Ia<0){FB_Ia=FB_Ia+3600;}
izmer[23]= FB_Ia/10>>8;
izmer[24]= FB_Ia/10;

FB_Ib=F_Ib-baz;
if(FB_Ib<0){FB_Ib=FB_Ib+3600;}
izmer[25]= FB_Ib/10>>8;
izmer[26]= FB_Ib/10;

FB_Ic=F_Ic-baz;
if(FB_Ic<0){FB_Ic=FB_Ic+3600;}
izmer[27]= FB_Ic/10>>8;
izmer[28]= FB_Ic/10;

FB_Ua=F_Ua-baz;
if(FB_Ua<0){FB_Ua=FB_Ua+3600;}
izmer[15]= FB_Ua/10>>8;
izmer[16]= FB_Ua/10;

FB_Ub=F_Ub-baz;
if(FB_Ub<0){FB_Ub=FB_Ub+3600;}
izmer[17]= FB_Ub/10>>8;
izmer[18]= FB_Ub/10;

FB_Uc=F_Uc-baz;
if(FB_Uc<0){FB_Uc=FB_Uc+3600;}
izmer[19]= FB_Uc/10>>8;
izmer[20]= FB_Uc/10;

FB_U3o_i=F_U3o_i-baz;
if(FB_U3o_i<0){FB_U3o_i=FB_U3o_i+3600;}
izmer[21]= FB_U3o_i/10>>8;
izmer[22]= FB_U3o_i/10;

FB_Uad=F_Uad-baz;
if(FB_Uad<0){FB_Uad=FB_Uad+3600;}
izmer[99]= FB_Uad/10>>8;
izmer[100]= FB_Uad/10;


FB_Uab=F_Uab-baz;
if(FB_Uab<0){FB_Uab=FB_Uab+3600;}
izmer[74]= FB_Uab/10>>8;
izmer[75]= FB_Uab/10;

FB_Ubc=F_Ubc-baz;
if(FB_Ubc<0){FB_Ubc=FB_Ubc+3600;}
izmer[76]= FB_Ubc/10>>8;
izmer[77]= FB_Ubc/10;

FB_Uca=F_Uca-baz;
if(FB_Uca<0){FB_Uca=FB_Uca+3600;}
izmer[78]= FB_Uca/10>>8;
izmer[79]= FB_Uca/10;

FB_I3o_p=F_I3o_p-baz;
if(FB_I3o_p<0){FB_I3o_p=FB_I3o_p+3600;}
izmer[80]= FB_I3o_p/10>>8;
izmer[81]= FB_I3o_p/10;	

FB_I3o_p=F_I3o_p-baz;
if(F_I3op_U3oi<0){F_I3op_U3oi=F_I3op_U3oi+3600;}
izmer[94]= F_I3op_U3oi/10>>8;
izmer[95]= F_I3op_U3oi/10;
}
