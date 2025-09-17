/*
--> signed:-
    1. this represents negative or posetive numbers including zero.
    2. the types int, short, long, long long are all signed.(but in case of character, char and signed char are not same. So, what is the difference?
       if it is signed char then it is signed or if it is unsigned char then it is unsigned but if it is only char it means it can either be signed
       or unsigned and that will depend upon the compiler that we use)
--> unsigned:-
    1. they represents only values greater than or equal to zero.(that is posetive number)
    2. we obtain the corresponding unsigned type by adding unsigned to the type. ex:- unsigned short int
*/

#include<iostream>
using namespace std;

int main()
{
    unsigned int num = -1;// We have declared an unsigned integer but we are storing a negative value.
    int x = num;// x is a signed integer so it will store value -1
    cout << num << ", " << x << endl;
    return 0;
}

/*
1. -1 is converted into it's 2's complement.(2's complement because it is a negative number)

Steps to find 2's compliment:-
2. first ignore the negative sign and then convert 1 in 32 bits format:- 00000000000000000000000000000001 that is 31 zeroes and 1 one
3. coverting the above binary representation of 1 into 2's complement.
4. first convert it into 1's complement,
    by inverting all the  0's and 1's -> 1111111111111111111111111111110 => 1's complement of 1
5. for 2's complement after obtaining the 1's complement,
    we have to add 1 bit to it's 1's complement -> 11111111111111111111111111111110
                                                   ______________________________+1
                                                   11111111111111111111111111111111 => 2's complement of 1
6. Now we will convert the above 2's complement into decimal equivalent.
    => 4294967295 (this was the output of num)
*/
