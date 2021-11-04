// 1. Enable clock
    // RCC_BASE = 0x40021000 // Base Address for RCC registers
    // RCC_AHB2ENR_offset: 0x4C // Peripheral Clock Enable Register
    // Set bit[1] to 1
// 2. Set GPIOB to Output mode
    // GPIOB_BASE = 0x48000400 // Base Address for GPIOB registers
    // GPIOx_MODER offset is 0x00 // To enable port mode (IN, OUT, AF..)
    // Set bit[29:28] to 0x01  to enable PB14 as output
// 3. Write to GPIO Data Register to toggle LED
    // GPIOB_BASE = 0x48000400 // Base Address for GPIO registers
    // GPIOx_ODR offset: 0x14 // Port output data register
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4c)))

#define GPIOB_BASE 0x48000400
#define GPIOB_MODER (*((unsigned int*)(GPIOB_BASE + 0x0)))
#define GPIOB_ODR (*((unsigned int*)(GPIOB_BASE + 0x14)))
#define ODR14 (1<<14)

#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define ODR5 (1<<5)

int counter = 0;

int blinkLEDone()
{
  //RCC_AHB2ENR |= 0x2;
  //GPIOB_MODER &= 0xDFFFFFFF;
  RCC_AHB2ENR |= 0x1;
  GPIOA_MODER &= 0xFFFFF7FF;
  while(1)
  {
    counter = 0;
      while (counter < 100000)
      {
        counter++;
      }
      
      // turn LED on
      //GPIOB_ODR |= ODR14;
      GPIOA_ODR |= ODR5;
      
      counter = 0;
      while (counter < 100000)
      {
        counter++;
      }

      // turn LED off
      //GPIOB_ODR &= ~ODR14;
      GPIOA_ODR &= ~ODR5;
  }
  return 0;
}
