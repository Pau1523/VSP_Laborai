#include "main.h"
#define BIT21 0B1000000000000000000000



int main(void)
{


	//RCC->AHBENR |= BIT21;

	//RCC->AHBENR |= GPIOAEN;
	RCC->AHBENR |= 1<<21;
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	GPIOE->MODER |= GPIO_MODER_MODER8_0;  // |= set bit  MODER8_0       ......1............
	GPIOE->MODER &=~ GPIO_MODER_MODER8_1; // &=~ reset bit (and-not)    .....0..............

	GPIOE->MODER |= GPIO_MODER_MODER9_0;
	GPIOE->MODER &=~ GPIO_MODER_MODER9_1;

	GPIOA->MODER &=~ GPIO_MODER_MODER0_0;
	GPIOA->MODER &=~ GPIO_MODER_MODER0_1;



  while (1)
  {
	  if(GPIOA -> IDR & GPIO_IDR_0)
	  {
		  GPIOE -> BSRR |= GPIO_BSRR_BS_8;
		  GPIOE -> BSRR |= GPIO_BSRR_BS_9;
	  }
	  else
	  {
		  GPIOE -> BSRR |= GPIO_BSRR_BR_8;
		  GPIOE -> BSRR |= GPIO_BSRR_BR_9;
	  }
	  //GPIOE ->BSRR |= 1<<8;
	  //GPIOE ->BSRR |= 1<<9;


  }
}
