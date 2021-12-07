#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"
#include "stm32l4xx_it.h"

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

// ************ Using CMSIS ************ //
#define SYS_CLOCK_HZ 4000000u

void SysTick_Initialize(void);

volatile int counter=0;

void main(void)
{     
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
   
    
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    SysTick_Initialize();
    while(1)
    {
        //GPIOB->ODR |= GPIO_ODR_OD14;
      GPIOA->ODR |= GPIO_ODR_OD5;  
      delay(100000);
        
        // GPIOB->ODR &= ~GPIO_ODR_OD14;
      GPIOA->ODR &= ~GPIO_ODR_OD5;
      delay(100000);
    }    
}

void SysTick_Initialize(void)
{
    SysTick->LOAD = SYS_CLOCK_HZ - 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                    // 0xE000E010 - Enable interrupts
}


