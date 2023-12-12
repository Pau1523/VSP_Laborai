#include "stm32f3xx.h"

void TIM1_PWM_Init(int duty) {
    RCC->AHBENR |= RCC_AHBENR_GPIOEEN; // Enable GPIOE clock
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN; // Enable TIM1 clock

    GPIOE->MODER &= ~(GPIO_MODER_MODER9); // Clear mode bits for PE9
    GPIOE->MODER |= GPIO_MODER_MODER9_1; // Set alternate function mode for PE9
    GPIOE->AFR[1] |= 0x02 << ((9 - 8) * 4); // AF2 for PE9 (TIM1_CH1)

    TIM1->PSC = 0; // Prescaler value
    TIM1->CCR1 = duty;
    TIM1->ARR = 999; // Auto-reload value (period - 1)
    TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; // PWM mode 1
    TIM1->CCMR1 |= TIM_CCMR1_OC1PE; // Enable preload register on CCR1
    TIM1->CCER |= TIM_CCER_CC1E; // Enable capture/compare channel 1 output
    TIM1->BDTR |= TIM_BDTR_MOE; // Main output enable
    TIM1->CR1 |= TIM_CR1_CEN; // Enable TIM1
}

int main(void) {
    TIM1_PWM_Init(999); // Initialize PWM on PE9 using TIM1

    while (1) {
    TIM1_PWM_Init(100);// Your main code can be added here
    }
}
