/* -> 2429
Given two positive integers num1 and num2, find the positive integer x such that:
    1. x has the same number of set bits as num2, and

    2. The value x XOR num1 is minimal.

Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

 

Example 1:
    Input: num1 = 3, num2 = 5
    Output: 3
    Explanation:
    The binary representations of num1 and num2 are 0011 and 0101, respectively.
    The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.


Example 2:
    Input: num1 = 1, num2 = 12
    Output: 3
    Explanation:
    The binary representations of num1 and num2 are 0001 and 1100, respectively.
    The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
*/

#include<bits/stdc++.h>
using namespace std;

int minimizeXor(int num1, int num2) 
{
    // __builtin_popcount is an inbuilt function that counts the no. of set bits in a given number in O(1) time
    int bitCountNum1 = __builtin_popcount(num1);
    int bitCountNum2 = __builtin_popcount(num2);

    int diffBitCount = bitCountNum1-bitCountNum2;

    if(diffBitCount>0)
    {
        // if num1 has more set bits than num2, then we need to remove the right most diffBitCount set bits to minimize the num1
        while(diffBitCount && num1){
            num1 = (num1 & (num1-1));
            diffBitCount--;
        }
    }
    else if(diffBitCount<0)
    {
        // if num1 has less set bits than num2, then we just need to convert the left most unset diffBitCoutn bits to minimize the num1
        diffBitCount *= -1;
        for(int i=0 ; i<32 && diffBitCount ; i++){
            if((num1&(1<<i))==0){
                num1 = num1 | (1<<i);
                diffBitCount--;
            }
        }
    } 

    // if diffBitCount==0 it menas we can return num1 to minimum the XOR of num1^(x=num1)
    return num1;
}

int main()
{
    cout << minimizeXor(332, 24) << endl;
    return 0;
}