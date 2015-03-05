#include "stm32F10x.h"
#include "rtc.h"

//************************** Часы реального времени **************************

//****************************************************************************
//				             Инициализация часов                            //
//****************************************************************************   
void	RtcCorr	(void)
{	

/*
	//разрешить тактирование модулей управления питанием и управлением
		//резервной областью
		RCC->APB1ENR |= RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN;
		//разрешить доступ к области резарвных данных
		PWR->CR |= PWR_CR_DBP;
	
		//выполнить сброс области резервных данных
		RCC->BDCR |= RCC_BDCR_BDRST;
		RCC->BDCR &= ~RCC_BDCR_BDRST;
		//выбрать источником тактовых импульсов внешний кварц 32768 и подать тактирование
		RCC->BDCR |= RCC_BDCR_RTCEN | RCC_BDCR_RTCSEL_LSE;
		//Bit 4 CNF: Configuration flag
		//This bit must be set by software to enter in configuration mode so as to allow new values to
		//be written in the RTC_CNT, RTC_ALR or RTC_PRL registers. The write operation is only
		//executed when the CNF bit is reset by software after has been set.
		//0: Exit configuration mode (start update of RTC registers).
		//1: Enter configuration mode.
		RTC->CRL |= RTC_CRL_CNF;
		//If the input clock frequency (fRTCCLK) is 32.768 kHz, write 7FFFh in this register to get a
		//signal period of 1 second.
		RTC->PRLL = 0x7FF0;         //тактирование от внешнего кварца
		//0: Exit configuration mode (start update of RTC registers).
		RTC->CRL &= ~RTC_CRL_CNF;
    //установить бит разрешения работы и дождаться установки бита готовности
		RCC->BDCR |= RCC_BDCR_LSEON;
		while ((RCC->BDCR & RCC_BDCR_LSEON) != RCC_BDCR_LSEON){}
			
	//while ((RCC->BDCR & RCC_BDCR_LSERDY) != RCC_BDCR_LSERDY);	//вариант
			
//Bit 3 RSF: Registers synchronized flag
//This bit is set by hardware at each time the RTC_CNT and RTC_DIV registers are updated
//and cleared by software. Before any read operation after an APB1 reset or an APB1 clock
//stop, this bit must be cleared by software, and the user application must wait until it is set to
//be sure that the RTC_CNT, RTC_ALR or RTC_PRL registers are synchronized.
//0: Registers not yet synchronized.
//1: Registers synchronized.
		RTC->CRL &= (uint16_t)~RTC_CRL_RSF;
		while((RTC->CRL & RTC_CRL_RSF) != RTC_CRL_RSF){}
*/


	// enable APB1 clocks
	RCC->APB1ENR |= RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN;

	// disable backup domain write protection
	PWR->CR |= PWR_CR_DBP;
	
	// set RTC prescaler: set RTC period to 1sec
	RTC->CRL |= RTC_CRL_CNF;	// enter config mode
	RTC->PRLH = 0;
	RTC->PRLL = 0x8012;

AFIO->EVCR =0xAD; //PC13-calibration clock output enable
BKP->RTCCR |=	BKP_RTCCR_CCO; //Setting this bit outputs the 
//RTC clock with a frequency divided by 64 on the TAMPER pin		

	RTC->CRL &= ~RTC_CRL_CNF;	// exit config mode
	
	// reset Backup Domain
//	RCC->BDCR |= RCC_BDCR_BDRST;
//	RCC->BDCR &= ~RCC_BDCR_BDRST;

	RCC->BDCR &= ~(RCC_BDCR_LSEON | RCC_BDCR_LSEBYP);
	// enable LSE
	RCC->BDCR |= RCC_BDCR_LSEON;
	// wait till LSE is ready
	while (!(RCC->BDCR & RCC_BDCR_LSERDY)) ;
	// select LSE as RTC clock source
	RCC->BDCR |= RCC_BDCR_RTCSEL_LSE;

	// enable RTC clock
	RCC->BDCR |= RCC_BDCR_RTCEN;

	// wait for RTC registers synchronization
    RTC->CRL &= ~RTC_CRL_RSF;
    while (!(RTC->CRL & RTC_CRL_RSF));

	// set RTC prescaler: set RTC period to 1sec
	RTC->CRL |= RTC_CRL_CNF;	// enter config mode
	RTC->PRLH = 0;
	RTC->PRLL = 0x8013;

AFIO->EVCR =0xAD; //PC13-calibration clock output enable
//BKP->RTCCR |=	BKP_RTCCR_CCO; //Setting this bit outputs the 
//RTC clock with a frequency divided by 64 on the TAMPER pin	

BKP->RTCCR |=	BKP_RTCCR_ASOS | BKP_RTCCR_ASOE;

		RTC->CRL &= ~RTC_CRL_CNF;	// exit config mode
    while (!(RTC->CRL & RTC_CRL_RTOFF));
// enable backup domain write protection
		PWR->CR &= ~PWR_CR_DBP;
    while (!(RTC->CRL & RTC_CRL_RTOFF));
}


int  RtcInit  (void)
{
  //разрешить тактирование модулей управления питанием и управлением
  //резервной областью - enable APB1 clocks
  RCC->APB1ENR |= RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN;
  // disable backup domain write protection
	//разрешить доступ к области резарвных данных
  PWR->CR |= PWR_CR_DBP;
  //если часы выключены - инициализировать их
	//Bit 15 RTCEN: RTC clock enable
	//Set and cleared by software.
	//0: RTC clock disabled
	//1: RTC clock enabled
	if ((RCC->BDCR & RCC_BDCR_RTCEN) != RCC_BDCR_RTCEN)
	{
		//выполнить сброс области резервных данных
		// reset Backup Domain
		//Bit 16 BDRST: Backup domain software reset
		//Set and cleared by software.
		//0: Reset not activated
		//1: Resets the entire Backup domain
		RCC->BDCR |= RCC_BDCR_BDRST;
		RCC->BDCR &= ~RCC_BDCR_BDRST;
		//выбрать источником тактовых импульсов внешний кварц 32768 и подать тактирование
		//Bit 15 RTCEN: RTC clock enable
		//Set and cleared by software.
		//0: RTC clock disabled
		//1: RTC clock enabled
		//Bits 9:8 RTCSEL[1:0]: RTC clock source selection
		//Set by software to select the clock source for the RTC. Once the RTC clock source has been selected,
		// it cannot be changed anymore unless the Backup domain is reset. The BDRST bit can be used to reset them.
		//00: No clock
		//01: LSE oscillator clock used as RTC clock10: LSI oscillator clock used as RTC clock
		//11: HSE oscillator clock divided by 128 used as RTC clock
		RCC->BDCR |= RCC_BDCR_RTCEN | RCC_BDCR_RTCSEL_LSE;
		//установка маски разрешения секундных прерываний
		//Bit 0 SECIE: Second interrupt enable
		//0: Second interrupt is masked.
		//1: Second interrupt is enabled.
		RTC->CRH |= RTC_CRH_SECIE;	///!!!!!!!!!!!!SECOND INTERRUPT ENABLE
		//Bit 4 CNF: Configuration flag
		//This bit must be set by software to enter in configuration mode so as to allow new values to
		//be written in the RTC_CNT, RTC_ALR or RTC_PRL registers. The write operation is only
		//executed when the CNF bit is reset by software after has been set.
		//0: Exit configuration mode (start update of RTC registers).
		//1: Enter configuration mode.
		RTC->CRL |= RTC_CRL_CNF;
		//If the input clock frequency (fRTCCLK) is 32.768 kHz, write 7FFFh in this register to get a
		//signal period of 1 second.
		RTC->PRLH = 0;
		RTC->PRLL = 0x8014;         //тактирование от внешнего кварца

		AFIO->EVCR =0xAD; //PC13-calibration clock output enable
		
		BKP->RTCCR |=	BKP_RTCCR_CCO; //Setting this bit outputs the 
		//RTC clock with a frequency divided by 64 on the TAMPER pin	
BKP->RTCCR |=	BKP_RTCCR_ASOS | BKP_RTCCR_ASOE;
		//0: Exit configuration mode (start update of RTC registers).
		RTC->CRL &= ~RTC_CRL_CNF;
    //установить бит разрешения работы и дождаться установки бита готовности
		RCC->BDCR |= RCC_BDCR_LSEON;
		while ((RCC->BDCR & RCC_BDCR_LSEON) != RCC_BDCR_LSEON){}
			
	//while ((RCC->BDCR & RCC_BDCR_LSERDY) != RCC_BDCR_LSERDY);	//вариант
			
//Bit 3 RSF: Registers synchronized flag
//This bit is set by hardware at each time the RTC_CNT and RTC_DIV registers are updated
//and cleared by software. Before any read operation after an APB1 reset or an APB1 clock
//stop, this bit must be cleared by software, and the user application must wait until it is set to
//be sure that the RTC_CNT, RTC_ALR or RTC_PRL registers are synchronized.
//0: Registers not yet synchronized.
//1: Registers synchronized.
		RTC->CRL &= (uint16_t)~RTC_CRL_RSF;
		while((RTC->CRL & RTC_CRL_RSF) != RTC_CRL_RSF){}
		return	0;
	}
   return	1;
}

#define FIRSTYEAR   2000		// start year
#define FIRSTDAY    1			// 0 = Sunday

static const uint8_t DaysInMonth[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/*******************************************************************************
* Function Name  : isDST
* Description    : checks if given time is in Daylight Saving time-span.
* Input          : time-struct, must be fully populated including weekday
* Output         : none
* Return         : false: no DST ("winter"), true: in DST ("summer")
*  DST according to German standard
*  Based on code from Peter Dannegger found in the microcontroller.net forum.
*******************************************************************************/
static uint8_t isDST( const RTC_t *t )
{
	uint8_t wday, month;		// locals for faster access

	month = t->month;

	if( month < 3 || month > 10 ) {		// month 1, 2, 11, 12
		return 0;					// -> Winter
	}

	wday  = t->wday;

	if( t->mday - wday >= 25 && (wday || t->hour >= 2) ) { // after last Sunday 2:00
		if( month == 10 ) {				// October -> Winter
			return 0;
		}
	} else {							// before last Sunday 2:00
		if( month == 3 ) {				// March -> Winter
			return 0;
		}
	}

	return 1;
}

/*******************************************************************************
* Function Name  : adjustDST
* Description    : adjusts time to DST if needed
* Input          : non DST time-struct, must be fully populated including weekday
* Output         : time-stuct gets modified
* Return         : false: no DST ("winter"), true: in DST ("summer")
*  DST according to German standard
*  Based on code from Peter Dannegger found in the microcontroller.net forum.
*******************************************************************************/
static uint32_t adjustDST( RTC_t *t )
{
	uint32_t hour, day, wday, month;			// locals for faster access

	hour  = t->hour;
	day   = t->mday;
	wday  = t->wday;
	month = t->month;

	if ( isDST(t) ) {
		t->dst = 1;
		hour++;								// add one hour
		if( hour == 24 ){					// next day
			hour = 0;
			wday++;							// next weekday
			if( wday == 7 ) {
				wday = 0;
			}
			if( day == DaysInMonth[month-1] ) {		// next month
				day = 0;
				month++;
			}
			day++;
		}
		t->month = month;
		t->hour  = hour;
		t->mday  = day;
		t->wday  = wday;
		return 1;
	} else {
		t->dst = 0;
		return 0;
	}
}
/*******************************************************************************
* Function Name  : counter_to_struct
* Description    : populates time-struct based on counter-value
* Input          : - counter-value (unit seconds, 0 -> 1.1.2000 00:00:00),
*                  - Pointer to time-struct
* Output         : time-struct gets populated, DST not taken into account here
* Return         : none
*  Based on code from Peter Dannegger found in the microcontroller.net forum.
*******************************************************************************/
static void counter_to_struct( uint32_t sec, RTC_t *t )
{
	uint16_t day;
	uint8_t year;
	uint16_t dayofyear;
	uint8_t leap400;
	uint8_t month;

	t->sec = sec % 60;
	sec /= 60;
	t->min = sec % 60;
	sec /= 60;
	t->hour = sec % 24;
	day = (uint16_t)(sec / 24);

	t->wday = (day + FIRSTDAY) % 7;		// weekday

	year = FIRSTYEAR % 100;				// 0..99
	leap400 = 4 - ((FIRSTYEAR - 1) / 100 & 3);	// 4, 3, 2, 1

	for(;;) {
		dayofyear = 365;
		if( (year & 3) == 0 ) {
			dayofyear = 366;					// leap year
			if( year == 0 || year == 100 || year == 200 ) {	// 100 year exception
				if( --leap400 ) {					// 400 year exception
					dayofyear = 365;
				}
			}
		}
		if( day < dayofyear ) {
			break;
		}
		day -= dayofyear;
		year++;					// 00..136 / 99..235
	}
	t->year = year + FIRSTYEAR / 100 * 100;	// + century

	if( dayofyear & 1 && day > 58 ) { 	// no leap year and after 28.2.
		day++;					// skip 29.2.
	}

	for( month = 1; day >= DaysInMonth[month-1]; month++ ) {
		day -= DaysInMonth[month-1];
	}

	t->month = month;				// 1..12
	t->mday = day + 1;				// 1..31
}
/*******************************************************************************
* Function Name  : struct_to_counter
* Description    : calculates second-counter from populated time-struct
* Input          : Pointer to time-struct
* Output         : none
* Return         : counter-value (unit seconds, 0 -> 1.1.2000 00:00:00),
*  Based on code from "LalaDumm" found in the microcontroller.net forum.
*******************************************************************************/
static uint32_t struct_to_counter( const RTC_t *t )
{
	uint8_t i;
	uint32_t result = 0;
	uint16_t idx, year;

	year = t->year;

	/* Calculate days of years before */
	result = (uint32_t)year * 365;
	if (t->year >= 1) {
		result += (year + 3) / 4;
		result -= (year - 1) / 100;
		result += (year - 1) / 400;
	}

	/* Start with 2000 a.d. */
	result -= 730485UL;

	/* Make month an array index */
	idx = t->month - 1;

	/* Loop thru each month, adding the days */
	for (i = 0; i < idx; i++) {
		result += DaysInMonth[i];
	}

	/* Leap year? adjust February */
	if (year%400 == 0 || (year%4 == 0 && year%100 !=0)) {
		;
	} else {
		if (t->month > 1) {
			result--;
		}
	}

	/* Add remaining days */
	result += t->mday;

	/* Convert to seconds, add all the other stuff */
	result = (result-1) * 86400L + (uint32_t)t->hour * 3600 +
		(uint32_t)t->min * 60 + t->sec;

	return result;
}
/*******************************************************************************
* Function Name  : rtc_gettime
* Description    : populates structure from HW-RTC, takes DST into account
* Input          : None
* Output         : time-struct gets modified
* Return         : always true/not used
*******************************************************************************/
void rtc_gettime (RTC_t *rtc)
{
	uint32_t t;
	t = ((uint32_t)RTC->CNTH << 16) | RTC->CNTL;
	counter_to_struct( t, rtc ); // get non DST time
	adjustDST( rtc );
}

/*******************************************************************************
* Function Name  : SetCounterRTC
* Description    : sets the hardware-counter
* Input          : new counter-value
* Output         : None
* Return         : None
*******************************************************************************/
 void SetCounterRTC(uint32_t cnt)
{
	/* Change the current time */
	RTC->CRL |= RTC_CRL_CNF;// заходим в режим конфигурации
  RTC->CNTH = cnt>>16;
	RTC->CNTL = cnt;
	RTC->CRL &= ~RTC_CRL_CNF; // выходим из режима конфигурации
}

/*******************************************************************************
* Function Name  : rtc_settime
* Description    : sets HW-RTC with values from time-struct, takes DST into
*                  account, HW-RTC always running in non-DST time
* Input          : None
* Output         : None
* Return         : not used
*******************************************************************************/
void rtc_settime (const RTC_t *rtc)
{
	uint32_t cnt;
	volatile uint16_t i;
	RTC_t ts;
	cnt = struct_to_counter( rtc ); // non-DST counter-value
	counter_to_struct( cnt, &ts );  // normalize struct (for weekday)
	if ( isDST( &ts ) )	cnt -= 60*60; // Subtract one hour
    SetCounterRTC( cnt );
}


void	RTC_setup_SPL(void)
{

  /* Allow access to Backup Registers */
  PWR_BackupAccessCmd(ENABLE);

//  if(BKP_ReadBackupRegister(BKP_DR1) != CONFIGURATION_DONE)
//  {
    /* Enable Backup and Power Interface Peripheral Clocks */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP | RCC_APB1Periph_PWR, ENABLE);

    /* Backup Domain Reset */
    BKP_DeInit();

#ifdef USE_LSE_FOR_RTC

    /* Enable 32.768 kHz external oscillator */
    RCC_LSEConfig(RCC_LSE_ON);

    /* Wait for LSE to become ready */
    while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET) continue;

/////////////////////////////////////////////////////////////////////
//// When 'USE_LSE_FOR_RTC' defined, code stops in previous call ////
//// whilst waiting for LSERDY flag to assert.                   ////
/////////////////////////////////////////////////////////////////////

    /* Set LSE as RTC clock source */
    RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);

#elif defined USE_LSI_FOR_RTC

    /* Enable 32.000kHz internal oscillator */
    RCC_LSICmd(ENABLE);

    /* Wait until LSI is ready */
    while (RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET) continue;

    /* Select LSI as RTC Clock Source */
    RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);

#endif

    /* RTC Enabled */
    RCC_RTCCLKCmd(ENABLE);

    /* Wait for RTC registers synchronisation */
    RTC_WaitForSynchro();

/////////////////////////////////////////////////////////////////////
//// When 'USE_LSI_FOR_RTC' defined, code stops in previous call ////
//// whilst waiting for RSF flag to assert.                      ////
/////////////////////////////////////////////////////////////////////

    /* Wait for last RTC operation to finish */
    RTC_WaitForLastTask();
//------------------------------------------------------------------------------
//	}
}

