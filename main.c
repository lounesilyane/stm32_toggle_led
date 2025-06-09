 //where is the LED connected
//Pin : 5
//Port : A
//PB0
/* #define PERIPH_BASE 			(0x58000000UL)
#define AHB4PERIPH_OFFSET 		(0x00020000UL)
#define AHB4PERIPH_BASE			(PERIPH_BASE + AHB4PERIPH_OFFSET )
#define GPIOA_OFFSET 			(0x0000UL)

#define GPIOA_BASE 				(AHB4PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET 				(0x00004400UL)
#define RCC_BASE 				(AHB4PERIPH_BASE + RCC_OFFSET)


#define AHB4EN_R_OFFSET		    (0x0E0UL)
#define RCC_AHB4EN_R			(*(volatile unsigned int *)(RCC_BASE + AHB4EN_R_OFFSET))

#define MODE_R_OFFSET			(0x00UL)
#define GPIOA_MODE_R 			(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET ))



#define OD_R_OFFSET				(0x14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN 					(1U<<0)//0b 0000 0000 0000 0000 0000 0000 0000 0001

#define PIN6 					(1U<<6)
#define LED_PIN 				 PIN6


  (1U<<10)//set bit 10 to1
  &=~(1u<<11) //set bit 11 to 0 */


#include "stm32h7xx.h"

#define GPIOAEN 		(1U<<0)
#define PIN5 			(1U<<5)
#define LED_PIN         PIN5

int main (void)
{
	RCC-> AHB1ENR |=GPIOAEN;

	GPIOA-> MODER |=(1U<<10);
	GPIOA-> MODER &=~(1U<<11);

	while (1)
	{

		GPIOA -> BSRR = LED_PIN;
		for(int i=0;i<100000;i++){}

		GPIOA -> BSRR = (1U<<21);
		for(int i=0;i<100000;i++){}




	}
}




