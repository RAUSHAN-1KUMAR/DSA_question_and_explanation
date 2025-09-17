/*
Bitwise operators 
    Ex-> bitwise compliment(~), left shift(<<), right shift(>>), bitwise OR(|), bitwise AND(&), bitwise exclusive OR(^)

        --(~), described below(after main function)
        --(<<), ex. 0101<<1 it means every bit in 0101 will shift left by 1 i.e, 1010 or multiply by 2 in actual value of 0101,,  0100<<1 = 1000
        --(>>), ex. 0100>>1 = 0010 i.e value will divide by 2,,
               =>SUMMARISING if a<<b --> a*(2^b) and if a>>b --> a/(2^b)

        --(|), If both input value is 0 then output will be 0 otherwise 1. ex. 1|1 -> 1, 1|0 -> 1, 0|1 -> 1, 0|0 -> 0
        --(&), If both input value is 1 then output will be 1 otherwise 0 ex. 1&1 -> 1, 1&0 -> 0, 0&1 -> 0, 0&0 -> 0
        --(^), If input value is same then output will be 0 otherwise 1 ex. 0^0 -> 0, 1^1 -> 0, 1^0 -> 1, 0^1 -> 1
*/

// In case of Bitwise OR(|) or Bitwise AND(&) operator, both the expressions will be executed. 

#include<iostream>
using namespace std;

int main()
{
    int num1 = 5;// 5 -> 0101 in B.R.

    cout << (~num1) << endl;//-> output:- -6
    cout << (num1<<1) << endl;//-> as discussed multiply 5 by 2 i.e., 10
    cout << (num1>>1) << endl;//-> as discussed divide 5 by 2 i.e., 2

    int num2 = 8;// 8 -> 1000 in B.R.

    cout << (num1&num2) << endl;//-> 0101 & 1000 => 0000 -> 0
    cout << (num1|num2) << endl;//-> 0101 | 1000 => 1101 -> 13
    cout << (num1^num2) << endl;//-> 0101 ^ 1000 =>  1101 -> 13
    
    return 0;
}


/*
How to take bitwise compliment:-
--> Bitwise compliment for positive number:- Ex:- ~5 that is bitwise compliment of -6
    1. As bitwise operator play on binary level so first binary representation of 5 --> 00000000000000000000000000000101
    2. for bitwise compliment of posetive number, we have to take 1's compliment of given number and that one's complement get stored in the memory.
       Note:- MSB will be decided by the 1's compliment.
    3. 1's comliment is obtained by inverting all the 0's and 1's, binary representation -> 11111111111111111111111111111010, (MSB is 1 it means the compliment of 5 will be a negative number)
    4. So the stored binary of ~5 is 111...11111010
    5. Now to obtain the number(as output, means in decimal form), we take 2's compliment of above obtained 1's compliment because MSB is 1 i.e., negative number
    6. for 2's complement first convert it into 1's complement,
        by inverting all the  0's and 1's of -> 11111111111111111111111111111010 => 00000000000000000000000000000101
    7. for 2's complement after obtaining the 1's complement,
        we have to add 1 bit to it's 1's complement -> 00000000000000000000000000000101
                                                       ______________________________+1
                                                       00000000000000000000000000000110
    8. So the answer will be the decimal equivalent with negative sign(because MSB was 1) of 00000000000000000000000000000110,output:- -6

--> Bitwise compliment for negatie numbers:- Ex:- ~(-5) that is bitwise compliment of 4
    1. First find the binary repersentation of -5 i,e negative number.
    2. the binary stored value of -5 is -> 1111...11111011
    3. for bitwise compliment of negative number, we have to take 1's compliment of given number and that one's complement get stored in the memory. 
       Note:- MSB will be decided by the 1's compliment.
    4. 1's comliment is obtained by inverting all the 0's and 1's, binary representation -> 0000...00000100, (MSB is 0 it means the compliment of 5 will be a posetive number)
    5. So the stored binary of ~(-5) is 0000..00000100
    6. Now to obtain the number(as output, measn in decimal form), we just find the decimal equivalent of stored binary number because MSB is 0 i.e., positive number.
    7. So the answet will be the decimal equivalent of 0000..00000100, outout:- 4
*/
