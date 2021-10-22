### 1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
    a. -2147483648
    b. 0x80000000
    c. The 'N' flag set to 1 because our counter became a negative number thus causing the most significant bit to become 1 and the flag to be set to 1. The 'V' flag is set to 1 because we had overflow by adding 1 to the largest positive integer we could represent.

### 2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”.
    a. Counter is equal to 0
    b. The 'Z' flag is set to 1 because result is 0. The 'C' flag is set to 1 because our instruction of incrementing the counter by 1 caused a carry due to -1 going to 0.

### 3. Change the “counter” variable type in your code to “unsigned int”. Inject the values “0x7FFFFFFF” then step thru the program to increment the “counter” once.
    a. 2147483648
    b. Both the 'N' and the 'V' flags are set to 1 because we had an overflow and the most significant bit become negative(1). However, since the 'counter' variable is now unsigned, the negative can be ignored and the value just incremented.

### 4. Change the “counter” variable type in your code to “unsigned”. Inject the values “0xFFFFFFFF” then step thru the program to increment the “counter” once.
    a. 0
    b. Both the 'Z' and 'C' flags are set to 1 because our result (counter) is equal to 0 and we had a carry going from 4294967295 to 0. 0xFFFFFFFF is largest possible integer we can represent, doesn't matter if it is signed or unsigned -- if signed then that value is equal to -1 and if unsigned it's equal to 4294967295. Incrementing that value will always result in the result being 0.

### 5. Move the “counter’ variable outside of main (at the top of the file).
    a. The 'counter' variable now has global scope
    b. The 'counter' variable is not visible in the 'Locals' view
    c. The 'counter' variable is visible in the 'Watch' view
    d. The address of the 'counter' variable is 0x20000000

### 6. Change the source code to the following, then run the program in the simulator.
    a. The value of 'counter' is 4
    b. 'Counter' is 4 because we created a pointer (p_int) that pointed to the address of 'counter'. Then we incremented the value at p_int 3 times and incremented 'counter' directly once to get to 4.

### 7. 