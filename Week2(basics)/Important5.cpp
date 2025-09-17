#include <iostream>
#include <limits.h>
#include<bitset>

using namespace std;

int main()
{
    // overflow
    char x = 234234;
    cout << "The actual binary of 234234 is: " << bitset<sizeof(int)*8>(234234) << endl;
    cout << "The binary of char x is: " << bitset<sizeof(int)*8>(x) << endl; // but the size of char is two byte => 8bit
    cout << "The actual binary of char x is: " << bitset<sizeof(char)*8>(x) << endl; // first 8 bit will be taken.
    cout << "The character stored in char x is: " << x << endl;
    cout << "The equivalent number stored in char x is: " << int(x) << endl;

    cout << endl;

    char ch = 235;
    cout << "The actual binary of 235 is: " << bitset<sizeof(int)*8>(235) << endl;
    cout << "The binary of char ch is: " << bitset<sizeof(char)*8>(ch) << endl;
    cout << "The character stored in char ch is: " << ch << endl;
    cout << "The equivalent number stored in char ch is: " << int(ch) << endl;

    cout << endl;

    char ch2 = -150;
    cout << "The actual binary of -150 is: " << bitset<sizeof(int)*8>(-150) << endl;
    cout << "The binary of char ch2 is: " << bitset<sizeof(char)*8>(ch2) << endl;
    cout << "The character stored in char ch2 is: " << ch2 << endl;
    cout << "The equivalent number stored in char ch2 is: " << int(ch2) << endl;
    
    return 0;
}


/*
Explanation:-
    -- As the value of char is from -128 to 127, so if we store value greater than 127, overflow occurs and value starts like a cyclic order,So if the value of x is 127 then the question is that what will the value of ++x?? -> the value of ++x will be -128 and if x = -128 and then the value of --x will be 127, this is called overflow. Same thing is also applied in case int or long int.

    -- the total ASCII code is from 0 to 255 = total 256 ASCII code, which fits equalled in case of unsigned char.

    -- but the main twist is that the char value lies between -128 to 127 because the last one bit is reserve for MSB and the ASCII code is not for negative number, So if we want the character for char = 235, the value stored in the memory is -21 but the ASCII code will be same as 235 of unsigned char or the ASCII code of  256-(|value stored in memroy|) = 256-21 = 235.

    -- In case of char x = 234234, the binary equivalent of 234234 is 00000000111001001011111010 but the first 8 bit will be taken = 11111010 this is the stored bit in memory.(11111010 equivalent to 250) as the MSB is one in stored bit so it will treat it as a negative number and the output value will be -6 and the stored character will be same as 250 of unsigned char or the ASCII code of 256-(|value stored in memroy|) = 256-6 = 250.

    -- In case of char x = -150, the binary equicalent of -150 is 111111111111101101010 but the stored bit in memeory is 01101010 (the first 8 bit and 01101010 equivalent to 106), as the MSB is 0 so it will treat it as a negative number and so the output value will be 106 and the stored character will be same is 106 of ASCII table.
*/

