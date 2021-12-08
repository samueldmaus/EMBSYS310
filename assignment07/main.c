#include "delay.h"
#include "stm32l475xx.h"
#include "stm32l4xx_it.h"

#define SYS_CLOCK_HZ 4000000u

void SysTick_Initialize(void);

volatile uint32_t counter = 0;

void main(void)
{     
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
   
    
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    SysTick_Initialize();
    
    while(1)
    {
      delay(1000);
    }    
}

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_HZ/1000;
    SysTick->VAL = 0x0;
    SysTick->CTRL = 0x7;
}

void SysTick_Handler(void)
{
  __disable_irq();
  counter++;
  __enable_irq();
}