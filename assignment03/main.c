#include "main.h"

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4c)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define ODR5 (1<<5)

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x0)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))
#define ODR14 (1<<14)

int main()
{
  //blinking led two for spaces in between characters for ease of viewing
  while(1)
  {
      // S
      morseDot(3);
      blinkLEDTwoForSpaces();
      
      // A
      morseDot(1);
      morseDash(1);
      blinkLEDTwoForSpaces();
      
      // M
      morseDash(2);
      blinkLEDTwoForSpaces();
      
      // U
      morseDot(2);
      morseDash(1);
      blinkLEDTwoForSpaces();
      
      // E
      morseDot(1);
      blinkLEDTwoForSpaces();
      
      // L
      morseDot(1);
      morseDash(1);
      morseDot(2);
      
      delayMorseSevenUnit();
  }
  return 0;
}

void morseDot(int num)
{
   RCC_AHB2ENR |= 0x1;
   GPIOA_MODER &= 0xFFFFF7FF;
  for(int i = 0; i < num; ++i)
  {
    delayMorseOneUnit();
    GPIOA_ODR |= ODR5;
    delayMorseOneUnit();
    GPIOA_ODR &= ~ODR5;
  }
}

void morseDash(int num)
{    
  RCC_AHB2ENR |= 0x1;
  GPIOA_MODER &= 0xFFFFF7FF;
  for(int i = 0; i < num; ++i)
  {
    delayMorseOneUnit();
    GPIOA_ODR |= ODR5;
    delayMorseThreeUnit();
    GPIOA_ODR &= ~ODR5;
  }
}

void delayMorseOneUnit()
{
  int counter = 0;
  while(counter < 200000)
  {
    ++counter;
  }
}

void delayMorseThreeUnit()
{
  int counter = 0;
  while(counter < 600000)
  {
    ++counter;
  }
}

void delayMorseSevenUnit()
{
  int counter = 0;
  while(counter < 1400000)
  {
    ++counter;
  }
}

void blinkLEDTwoForSpaces()
{
   RCC_AHB2ENR |= 0x2;
   GPIOB_MODER &= 0xDFFFFFFF;
  int counter = 0;
  GPIOB_ODR |= ODR14;
  while(counter < 600000) {
    counter++;
  }
  GPIOB_ODR &= ~ODR14;
}