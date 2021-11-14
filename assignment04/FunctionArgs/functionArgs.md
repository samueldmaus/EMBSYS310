### Create a function “func1” with 5 arguments and call “func1” from within another function “func2”. Trace thru the assembler and note
    a. How does the calling function “func2” pass the values to the called function “func1”?
       It does so by moving the value of the parameters into the registers R0-R3 and the stack pointer (SP)

    b. What extra code did the compiler generate before calling the function “func1” with the multiple arguments?
       The extra code is 'STR  R0, [SP]' which is storing the 5th variable on the stack because the scratch registers are being used for the other four parameters

    c. What extra code did the compiler generate inside the called function “funct1” with the list of multiple arguments?
       The extra code is 'LDR  R5, [SP, #0x18]' which goes and gets the value of the 5th parameter from the stack where it was stored

    d. Any other observations? 