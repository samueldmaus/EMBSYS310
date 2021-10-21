### 1. Inject 0x7FFFFFFF for the “counter” value in the variable window, then step thru the program only once to increment “counter”.
    a. -2147483648
    b. 0x80000000
    c. The 'N' flag set to 1 because our counter became a negative number thus causing the most significant bit to become 1 and the flag to be set to 1. The 'V' flag is set to 1 because we had overflow by adding 1 to the largest positive integer we could represent.

### 2. If your write all Fs (0XFFFFFFFF) in the Register value for “counter” then step thru the program once to increment “counter”.
    a. Counter is equal to 0
    b. The 'Z' flag is set to 1 because result is 0. The 'C' flag is set to 1 because our instruction of incrementing the counter by 1 caused a carry due to -1 going to 0.