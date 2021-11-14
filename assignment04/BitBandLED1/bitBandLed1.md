### Follow the same steps as we did in the class to blink LED1 (PA5) at a visible rate using the bit-band region to enable the clock for Port A, then answer the following.
    a. What instructions does the compiler produce in assembly for “writing” to the RCC_AHB2ENR bit when using bit-band address?  
       MOVS   R0, #1
       LDR.N  R1, [PC, #0x30]
       STR    R0, [R1]
       
    b. What were the instructions produced when writing to the RCC_AHB2ENR without using bit-banding?
       LDR.N  R0, [PC, #0x34]
       LDR    R1, [R0]
       ORRS.W R1, R1, #1
       STR    R1, [R0]