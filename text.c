
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
		RTC->PRLL = 0x8000;         //тактирование от внешнего кварца

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

void	RtcCorr	(void)
{	

	// enable APB1 clocks
	RCC->APB1ENR |= RCC_APB1ENR_PWREN | RCC_APB1ENR_BKPEN;

	// disable backup domain write protection
	PWR->CR |= PWR_CR_DBP;
	
	// set RTC prescaler: set RTC period to 1sec
	RTC->CRL |= RTC_CRL_CNF;	// enter config mode
	RTC->PRLH = 0;
	RTC->PRLL = 0x8000;

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
	RTC->PRLL = 0x8000;

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

//RTC Corr
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


#define FIRSTYEAR   2000		// start year
#define FIRSTDAY    1			// 0 = Sunday

static const uint8_t DaysInMonth[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
