#include "delay.h"
#include "stm32l475xx.h"

extern volatile uint32_t counter;

void delay(uint32_t iteration)
{
  if(counter >= iteration)
  {
    GPIOA->ODR ^= GPIO_ODR_OD5;
    counter = 0;
  }
}