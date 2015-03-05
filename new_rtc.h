/*------------------------------------------------------------------------------
 File Name          : rtc.h
 Author             : 
 Version            : 1.1 
 Date               : 17/12/2013
 Description        : contens functions for work rtc timer stm32f103xx
--------------------------------------------------------------------------------*/
#include "stm32F10x.h"
#include "stm32f10x_rtc.h"
#include "misc.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#include "glb_def.h"
#include "ublox530m_gps.h"

#include "rtc.h"
/*------------------------------------------------------------------------------
|                                     RTC                                      |
------------------------------------------------------------------------------*/

/* Extern variables ----------------------------------------------------------*/
extern FlagEvent_t        flag_event;

/* Private variables ---------------------------------------------------------*/                                                           
static uint32_t           cnt_wait;                                                          
static struct tm          caltime;    /* from time.h*/
__IO   static time_t      counter;
    
/* Private function declaration ----------------------------------------------*/                             
static void   Rtc_counter_to_struct(struct tm *caltime);
static time_t Rtc_struct_to_counter(struct tm *caltime);
                              
/**---------------------------------------------------------------------------
  * @brief    RTC_IRQHandler
  * @param    none 
  * @retval   none
	*---------------------------------------------------------------------------
  */
void RTC_IRQHandler (void) {
  
  uint32_t  current_cnt;

  if (RTC_GetITStatus(RTC_IT_SEC) == SET) {
    
    RTC_ClearITPendingBit(RTC_IT_SEC);
    
    /*Waits until last write operation
      on RTC registers has finished */    
    RTC_WaitForLastTask();
        
    current_cnt = RTC_GetCounter();
          
    if (current_cnt > cnt_wait) {
      /*Waits until last write operation
        on RTC registers has finished */
      RTC_WaitForLastTask();
      /* disable interrupt*/
      RTC_ITConfig(RTC_IT_SEC, DISABLE);
      /* wait elapsed */
      flag_event.WaitElapsed = 1;
    }    
  }
}  
                                                            
/**---------------------------------------------------------------------------
  * @brief    Init rtc timer stm32f103xx for work
  * @param    none  
  * @retval   none
  *---------------------------------------------------------------------------
  */
void Rtc_Init (void)
{
  NVIC_InitTypeDef        NVIC_InitStruct;
  
  //enable clock power supply module and buckup domain
  RCC->APB1ENR |= RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN;
  //enable common access
  PWR->CR |= PWR_CR_DBP;

  RCC->BDCR |= RCC_BDCR_BDRST;
  RCC->BDCR &= ~RCC_BDCR_BDRST;
  RCC->BDCR |= RCC_BDCR_RTCEN | RCC_BDCR_RTCSEL_LSE;
  
  //Enters the RTC configuration mode
  RTC->CRL |= RTC_CRL_CNF;  
  //clock from external quartz
  RTC->PRLL = 0x7FFF;         
  //Exits from the RTC configuration mode
  RTC->CRL &= ~RTC_CRL_CNF;
  
  //setup bit enable work LSE and wait ready LSE
  RCC->BDCR |= RCC_BDCR_LSEON;
  while ((RCC->BDCR & RCC_BDCR_LSEON) != RCC_BDCR_LSEON){}
  
  RTC_WaitForSynchro();
      
  //Setup NVIC for RTC     
  NVIC_InitStruct.NVIC_IRQChannel = RTC_IRQn;
  NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x0F;
  NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStruct);  
}

/**---------------------------------------------------------------------------
  * @brief    Start wait mode
  * @param    
  * @output   
  * @retval   none
  *---------------------------------------------------------------------------
  */
void Rtc_StartWait (DataTimeCmd_t *SETime)
{
  struct tm  t1, t2;
  uint32_t  dt;
  
  t1.tm_hour  = SETime->StartWaitTime.hour;
  t1.tm_isdst = 0; 
  t1.tm_mday  = SETime->StartWaitTime.mday;
  t1.tm_min   = SETime->StartWaitTime.min;
  t1.tm_mon   = SETime->StartWaitTime.month-1;
  t1.tm_sec   = SETime->StartWaitTime.sec;
  t1.tm_year  = SETime->StartWaitTime.year - 1900;
  
  counter = Rtc_struct_to_counter(&t1); 

  /*Waits until last write operation
    on RTC registers has finished */  
  RTC_WaitForLastTask();
  
  Rtc_SetCounter(counter);
 
  /**/
  t2.tm_hour  = SETime->EndWaitTime.hour;
  t2.tm_isdst = 0; 
  t2.tm_mday  = SETime->EndWaitTime.mday;
  t2.tm_min   = SETime->EndWaitTime.min;
  t2.tm_mon   = SETime->EndWaitTime.month-1;
  t2.tm_sec   = SETime->EndWaitTime.sec;
  t2.tm_year  = SETime->EndWaitTime.year - 1900;   
  /**/
  dt = mktime(&t2) - mktime(&t1);
  
  /*Waits until last write operation
    on RTC registers has finished */  
  RTC_WaitForLastTask();     
  
  cnt_wait = RTC_GetCounter() + dt;//wmin*60;
  
  //Enable second interrupt
  RTC_ITConfig(RTC_IT_SEC, ENABLE);
}

/**---------------------------------------------------------------------------
  * @brief    populates time-struct based on counter-value
  * @param    caltime   - pointer to time-struct tm (from time.h)
  * @output   time-struct tm fills 
  * @retval   none
  *---------------------------------------------------------------------------
  */
static void Rtc_counter_to_struct (struct tm *caltime)
{
  struct tm *ct;
  counter   = RTC_GetCounter();
  ct = localtime((const time_t*)&counter);
  memcpy((void*)caltime, (void*)ct, sizeof(struct tm)); 
}

/**---------------------------------------------------------------------------
  * @brief    calculates second-counter from populated time-struct tm
  * @param    caltime   - pointer to time-struct tm (from time.h)
  * @output   none
  * @retval   counter-value (unit seconds) time_t type
  *---------------------------------------------------------------------------
  */
static time_t Rtc_struct_to_counter (struct tm *caltime)
{  
  counter = mktime(caltime);
	return counter;
}

/**---------------------------------------------------------------------------
  * @brief    populates time-struct RTC_t type from struct tm type
  * @param    rtc   - pointer to RTC_t struct
  * @output   time-struct gets modified
  * @retval   none
  *---------------------------------------------------------------------------
  */
void Rtc_Gettime (DataTime_t *rtc)
{
	Rtc_counter_to_struct(&caltime);
  
  rtc->hour   = caltime.tm_hour;
  rtc->mday   = caltime.tm_mday;
  rtc->min    = caltime.tm_min;
  rtc->month  = caltime.tm_mon+1;
  rtc->sec    = caltime.tm_sec;
  rtc->wday   = caltime.tm_wday;
  rtc->year   = caltime.tm_year + 1900;
}

/**---------------------------------------------------------------------------
  * @brief    sets the hardware-counter          
  * @param    new counter-value
  * @output   none
  * @retval   none
  *---------------------------------------------------------------------------
  */
void Rtc_SetCounter (uint32_t cnt)
{
	/* Change the current time */
	RTC->CRL |= RTC_CRL_CNF;
  RTC->CNTH = cnt>>16;
	RTC->CNTL = cnt;
	RTC->CRL &= ~RTC_CRL_CNF;
}

/**---------------------------------------------------------------------------
  * @brief    populates time-struct tm type from time-struct RTC_t type
  * @param    none
  * @output   caltime - global time-struct tm type
  *           counter - global sec counter
  *           sets the hardware-counter
  * @retval   none
  *---------------------------------------------------------------------------
  */
void Rtc_Settime (DataTime_t *rtc)
{
  caltime.tm_hour  = rtc->hour;
  caltime.tm_isdst = 0; 
  caltime.tm_mday  = rtc->mday;
  caltime.tm_min   = rtc->min;
  caltime.tm_mon   = rtc->month-1;
  caltime.tm_sec   = rtc->sec;
  caltime.tm_year  = rtc->year - 1900;

  /*Waits until last write operation
    on RTC registers has finished */  
  RTC_WaitForLastTask();
  
  counter = Rtc_struct_to_counter(&caltime);
  
  Rtc_SetCounter(counter);
}

/**---------------------------------------------------------------------------
  * @brief    Get UTC data and time  
  * @param    data - pointer on struct GPSDATA_t: 'dd,mm,yyyy'  
  *           time - pointer on struct GPSTIME_t: 'hhmmss.ddd'
  * @output   populates time-struct GPSDATA_t and GPSTIME_t
  * @retval   none
  *---------------------------------------------------------------------------
  */
void Rtc_GetUtcDateTime (GPSDATA_t *data, GPSTIME_t *time) {
  
  DataTime_t  rtc;
  
	Rtc_Gettime(&rtc); 
  
  data->date_str[0] = rtc.mday/10 + 0x30;
  data->date_str[1] = rtc.mday%10 + 0x30;
  data->date_str[2] = ',';
  data->date_str[3] = rtc.month/10 + 0x30;
  data->date_str[4] = rtc.month%10 + 0x30;
  data->date_str[5] = ',';
  data->date_str[6] =  rtc.year/1000 + 0x30;
  data->date_str[7] = (rtc.year%1000)/100 + 0x30;
  data->date_str[8] = (rtc.year%100)/10 + 0x30;
  data->date_str[9] =  rtc.year%10 + 0x30;  
  //
  time->time_str[0] = rtc.hour/10 + 0x30;
  time->time_str[1] = rtc.hour%10 + 0x30;
  time->time_str[2] = rtc.min/10 + 0x30;
  time->time_str[3] = rtc.min%10 + 0x30;
  time->time_str[4] = rtc.sec/10 + 0x30;
  time->time_str[5] = rtc.sec%10 + 0x30;  
  time->time_str[6] = '.';
  time->time_str[7] = '0';
  time->time_str[8] = '0';
  time->time_str[9] = '0';
} 

/**---------------------------------------------------------------------------
  * @brief    Get UTC data and time  
  * @param    rtc       - pointer on struct RTC_t  
  *           ttime_str - pointer on struct RtcDataTime_t: 'dd,mm,yyyyhhmmss.ddd'
  * @output   populates time-struct RtcDataTime_t
  * @retval   none
  *---------------------------------------------------------------------------
  */
void Rtc_ConvertToStr(DataTime_t *rtc, StrDataTime_t *time_str)
{
  time_str->Data.date_str[0] = rtc->mday/10 + 0x30;
  time_str->Data.date_str[1] = rtc->mday%10 + 0x30;
  time_str->Data.date_str[2] = ',';
  time_str->Data.date_str[3] = rtc->month/10 + 0x30;
  time_str->Data.date_str[4] = rtc->month%10 + 0x30;
  time_str->Data.date_str[5] = ',';
  time_str->Data.date_str[6] =  rtc->year/1000 + 0x30;
  time_str->Data.date_str[7] = (rtc->year%1000)/100 + 0x30;
  time_str->Data.date_str[8] = (rtc->year%100)/10 + 0x30;
  time_str->Data.date_str[9] =  rtc->year%10 + 0x30;  
  //
  time_str->Time.time_str[0] = rtc->hour/10 + 0x30;
  time_str->Time.time_str[1] = rtc->hour%10 + 0x30;
  time_str->Time.time_str[2] = rtc->min/10 + 0x30;
  time_str->Time.time_str[3] = rtc->min%10 + 0x30;
  time_str->Time.time_str[4] = rtc->sec/10 + 0x30;
  time_str->Time.time_str[5] = rtc->sec%10 + 0x30;  
  time_str->Time.time_str[6] = '.';
  time_str->Time.time_str[7] = '0';
  time_str->Time.time_str[8] = '0';
  time_str->Time.time_str[9] = '0';  
}  

/*----------------------------END OF FILE-------------------------------------*/