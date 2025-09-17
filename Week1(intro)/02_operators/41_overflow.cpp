#include<iostream>
using namespace std;

int main()
{
    char x = 127;

    cout << x << endl;

    ++x;/* As x is a character data types so the range of x is -128 to 127, so the question is that what will the value of ++x?? -> the value of 
    ++x will be -128 and if x = -128 and then the value of --x will be 127, this is called overflow. Same thing is also applied in case int or 
    long int. */
    
    cout << (int)x << endl;
    cout << x << endl;

    return 0;
}

/*
Lets discuss about the overflow at binary level.
--> char x = 127;
    and then ++x;
1. The value of x(127) is stored in memory -> 01111111 as size of char data types is 1 byte(8 bits)
2. ++x means increase by 1. So, 01111111
                                ______+1
                                10000000 -> this is now the value of x is stored in memeory after the increment, as MSB is 1 so the value is 
                                            stored with negative sign
3. the value of 10000000 or ++x = -128

--> if char x = -128;
       and then --x;
1. The value of x(-128) is stored in memory -> 10000000 (how it is stored, discussed before)
2. --x means decrement by 1, it done by first taking 2's compliment and then 1's compliment.
3. for 2's compliment first take 1's compliment and then add +1, -> 01111111 => 1's compliment of 10000000
                                                                    ______+1
                                                                    10000000 => 2's compliment of 10000000
4. Now 1's compliment of obtained 2's compliment => 01111111 as MSB is 0 so the value is stored with posetive sign
5. the value of --x or 01111111 = 127
*/