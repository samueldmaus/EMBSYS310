#include "stm32l4xx_it.h"

#pragma section="CSTACK"

void __iar_program_start(void);

void Unused_Handler(void);

void Unused_Handler(void)
{
    while(1);
}


int const __vector_table[] @ ".intvec" = {
    (int)__section_end("CSTACK"),          // Pointer to Top of Stack
    (int)__iar_program_start,              // Pointer to Reset Handler
    (int)NMI_Handler,
    (int)HardFault_Handler,
    (int)MemManage_Handler,
    (int)BusFault_Handler,
    (int)UsageFault_Handler,
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    0,      // Reserved
    (int)SVC_Handler,
    (int)DebugMon_Handler,
    0,      // Reserved
    (int)PendSV_Handler,
    (int)SysTick_Handler
};

void NMI_Handler(void)
{
    Unused_Handler();
}

// When the SP register drops below the start of RAM,
// the processor enters the HardFault exception
__weak void HardFault_Handler(void)
{
    Unused_Handler();
}

__weak void MemManage_Handler(void)
{
    Unused_Handler();
}

__weak void BusFault_Handler(void)
{
    Unused_Handler();
}

__weak void UsageFault_Handler(void)
{
    Unused_Handler();
}


// The below is another way of achieving the above...
#pragma weak SVC_Handler = Unused_Handler
#pragma weak DebugMon_Handler = Unused_Handler
#pragma weak PendSV_Handler = Unused_Handler
#pragma weak SysTick_Handler = Unused_Handler


//__weak void SVC_Handler(void)
//{
//    Unused_Handler();
//}
//
//__weak void DebugMon_Handler(void)
//{
//    Unused_Handler();
//}
//
//__weak void PendSV_Handler(void)
//{
//    Unused_Handler();
//}
//
//__weak void SysTick_Handler(void)
//{
//    Unused_Handler();
//}


// **** Overriding the default __low_level_init **** //
// Remember that this code, while written in C, it will execute
// before variable initialization is done
int __low_level_init(void);

int __low_level_init(void)
{
    // specify whatever low level setup needed in the hardware
    return 1;
}