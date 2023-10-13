// Priorytety przerwan (zewnetrzengo i timera)
//
// Mikrokontroler wykonuje trzy "zadania":
//
// 1. Main - inkrementacja zmiennej var (co 0.5 s)
//
// 2. ISR przerwania zewn (EXTI) - wywolywana nacisnieciem USER Button (niebieski przycisk).
//    Na czas nacisniecia zablokowany jest powrot do main - sygnalizacja czerwona DEL (G14).
//
// 3. ISR timera 7 - wywolywana jego przepelnieniem - zmiana stanu linii G13 (zielonej DEL) na przeciwny
//
// Zadanie glowne - ustawic priorytety przerwan tak, aby ISR timera 7 nie zostala zablokowana.
//
// Zadanie dodatkowe - uruchomic watchdoga - dobrac jego parametry i miejsce jego przeladowywania tak,
// aby przyblokowanie wykonywania jakiejkolwiek czesci programu na ok. dwie sekundy wywolywalo reset CPU.

#include <stdio.h>
#include "stm32f4xx.h"
#include "GLCD.h"

#define __FI       1
#if (__FI == 1)
  #define __FONT_WIDTH  16
  #define __FONT_HEIGHT 24
#else
  #define __FONT_WIDTH   6
  #define __FONT_HEIGHT  8
#endif

volatile uint32_t var;
char tekst[20];

int main ()  {

// --- inicjalizacja i konfiguracja wyswietlacza LCD ---

  GLCD_Initialize();
  GLCD_Clear(White);
  GLCD_SetBackColor(White);
  GLCD_SetTextColor(Black);

// --- konfiguracja peryferiow ---

  RCC->AHB1ENR |= ((1<<6) | (1<<0));					// wlacz "zegar" dla GPIO A i G
  GPIOG->MODER |= (1<<(2*13)) | (1<<(2*14));	// linie G13 i G14 jako wyjscia

  GPIOG->PUPDR |= (1<<(2*2));									// pull up linii G2

  RCC->APB1ENR |= (1<<5) |(1<<4);							// wlacz "zegar" timerow TIM6 i TIM7


// --- 1 ---
// skonfiguruj i wlacz timer TIM7
// wlacz generowanie przerwan z czestotliwoscia nr_grupy<<1
// ---------


	TIM7->PSC = 49999;					// preskaler
	TIM7->ARR =	39;	        // "n" stanow od zera; "auto reload register"; zliczacz od 0 -> do wartosci

  TIM7 ->DIER =	1;  		// dma/irq enable register - enable irq on update
  TIM7->CR1	=	1;				// wlacz timer



	TIM6->PSC = 15999;				// preskaler
	TIM6->ARR = 999;
  TIM6->CR1	|=1;						// wlacz timer CR - control register

// --- 2b ---
// skonfiguruj przyjowanie przerwan zewnetrznych
// z linii A0 (EXTI0, zbocze rosnace 0->1, niebieski przycisk)
// --------- 


	EXTI->IMR	= 1;				// "odmaskuj"/wlacz linie EXTI0
	EXTI->RTSR = 1;					// ustaw reakcje na zbocze rosnace 0->1
	//EXTI->FTSR =					// ustaw reakcje na zbocze opadajace 1->0


// --- 3 ---
// ustaw priorytety przerwan:
// timera TIM7 i zewnetrzengo EXTI0
// tak, aby przerwanie timera nie bylo blokowane
// ---------


	NVIC->IP[6] = 1 << 4;// priorytet przerwania ETI0
	NVIC->IP[55] = 0 << 4;//Priorytet przerwania timera


// --- 2a ---
// wlacz linie przerwan: zewnetrzne EXTI0 i timera TIM7
// w kontrolerze przerwan (NVIC)


	NVIC->ISER[0] = 1 << 6; //przerwanie od EXTI0 nr 6
	NVIC->ISER[1] = 1 << 23; //przerwanie od TIM7 nr 55 55-32=23

//==============================================
// --- petla glowna ---

	for(;;){

		sprintf(tekst,"var = %u",var);
		GLCD_DisplayString(0, 0, __FI,tekst);
		var++;

// --- 4 ---
// dopisz:
// zablokuj dalsze wykonywanie petli dopoki linia G2 jest w stanie niskim


//	delay - jakie wady ma takie rozwiazanie?
		TIM6->CNT=0; while(TIM6->CNT < 500);

	}
}

//==============================================
// Procedura obslugi przerwania (ISR) timera TIM7

void TIM7_IRQHandler(void) { 	 

	TIM7->SR &= ~1;						//skasuj Update Interrupt Flag

	GPIOG->ODR ^= (1<<13);		//zmien stan zielonej DEL
	
}

//==============================================	
// Procedura obslugi przerwania (ISR) zewnetrzengo EXTI0

void EXTI0_IRQHandler(void) {
	
	EXTI->PR |= 1;						//skasuj Interrupt Pending Request

	while(GPIOA->IDR & 1) GPIOG->BSRR = (1<<14);	//przyblokuj i zaswiec czerwona LED dopoki niebieski p. nacisniety
	
	GPIOG->BSRR = (1<<30);												// wygas czerwona DEL i powrot z ISR
}
