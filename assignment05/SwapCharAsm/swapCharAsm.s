/*******************************************************************************
File name       : swapCharAsm.s
Description     : Assembly language function for division by 2
*******************************************************************************/   
    
    PUBLIC swapCharAsm       // Exports symbols to other modules
                        // Making sqrAsm available to other modules.
    
// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables.
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.

// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : swapCharAsm
Description     : Swaps the values of two chars
C Prototype     : int swapCharAsm(char*, char*)
Parameters      : R0: char1 to swap
                : R1: char2 to swap
Return value    : 0 if chars are identical, 1 if they are not
*******************************************************************************/  
  
swapCharAsm
    LDR R2, [R0] // Load parameter R0 to R2
    LDR R3, [R1] // Load parameter R1 to R3
    STR R3, [R0] // Store R3 to R0 memory location
    STR R2, [R1] // Store R2 to R1 memory location
    CMP R3, R2 // compare chars
    BNE False // branch to false is chars are not equal
    MOV R0, #0 // return 0 if chars were equal
    B Exit // branch to exit
False
    MOVE R0, #1 // return 1 if the chars were not equal
Exit
    BX LR  // return (with function result in R0)
