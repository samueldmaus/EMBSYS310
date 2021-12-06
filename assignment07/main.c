#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class

// ************ Using CMSIS ************ //
#if 0
volatile int counter=0;

void main(void)
{     
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral
    
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    GPIOB->MODER &= ~GPIO_MODER_MODE14_1;
    GPIOB->MODER |= GPIO_MODER_MODE14_0;
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF
    
    while(1)
    {
        GPIOB->ODR |= GPIO_ODR_OD14;
        delay(100000);
        
        GPIOB->ODR &= ~GPIO_ODR_OD14;
        delay(100000);
    }    
}
#endif

#if 1

volatile int counter=0;

void main(void)
{     
    
    //RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
   
    
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    
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
#endif

