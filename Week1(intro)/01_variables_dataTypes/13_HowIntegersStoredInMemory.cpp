/*
--> posetive number:-
    Ex:- int num = 25;
    1. 25 will be converted into its binary equivalent-> 00000000 00000000 00000000 00011001 and get stored in memory of size 4 bytes(32 bits).

--> negative number:-
    Ex:- int num = -25;
    1. first ignore negative sign and then convert 25 in 32 bits format-> 00000000 00000000 00000000 00011001
    2. coverting the above binary representation of 25 into 2's complement.
    3. first convert it into 1's complement,
        by inverting all the  0's and 1's -> 1111111111111111111111111100110 => 1's complement of 25
    4. for 2's complement after obtaining the 1's complement,
        we have to add 1 bit to it's 1's complement -> 11111111111111111111111111100110
                                                       ______________________________+1
                                                       11111111111111111111111111100111 => 2's complement of 25 and get stored in memory.

    * How we can get our negative number by this 2's complement??
    -> calculate 2's complement of obtained 2's complement to get back the negative number
            11111111111111111111111111100111 => obtained 2's complement which is stored in memory.(MSB is 1 it means it is a negative no.)
            00000000000000000000000000011000 => 1's complement
            ______________________________+1
            00000000000000000000000000011001 => 2's comlement and then get converted into its decimal equivalent with sign that is -25
*/

// MSB = Most Significant Bit