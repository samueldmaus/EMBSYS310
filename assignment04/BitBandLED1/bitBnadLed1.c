#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4c)))

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define ODR5 (1<<5)

void delay()
{
  volatile int counter = 0;
  while(counter < 100000)
  {
    counter++;
  }
}

int bitBandLedOne()
{
  // (offest * 32)+ (the the bit * 4) set it equal to 1 FORMULA
  *((unsigned int*) ((0x42000000) + (0x2104c * 32)+ (0 * 4))) = 0x1;
  //RCC_AHB2ENR |= 0x1;
  GPIOA_MODER &= 0xFFFFF7FF;
  while(1)
  {
    delay();
      
    // turn LED on
    //GPIOB_ODR |= ODR14;
    GPIOA_ODR |= ODR5;

    delay();

    // turn LED off
    //GPIOB_ODR &= ~ODR14;
    GPIOA_ODR &= ~ODR5;
  }
  return 0;
}