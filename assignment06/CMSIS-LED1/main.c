#include <stdint.h>
#include "delay.h"
#include "stm32l475xx.h"

// ************ Using CMSIS ************ //

volatile int counter=0;

void main(void)
{     
    
    //RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
   
    
    GPIOB->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOB->MODER |= GPIO_MODER_MODE5_0;
    
    
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