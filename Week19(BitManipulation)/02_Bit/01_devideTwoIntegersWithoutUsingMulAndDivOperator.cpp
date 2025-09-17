/* -> 29

Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.

 

Example 1:
    Input: dividend = 10, divisor = 3
    Output: 3
    Explanation: 10/3 = 3.33333.. which is truncated to 3.


Example 2:
    Input: dividend = 7, divisor = -3
    Output: -2
    Explanation: 7/-3 = -2.33333.. which is truncated to -2.
*/

/*
Approach: bit manipulation
    -- let say dividend=22 and divisor=3; so how we can get the answer 7
    -- lets checkout using 3 till where i can reach close to 22 and less than 22 => 21 so how we can do it-> 3 X 2^0 = 3
         3 X 2^1 = 6
         3 X 2^2 = 12 -> till here(total 7 2's used)
         3 X 2^3 = 24

    -- 3 X 2^i => 3<<i

TC:- O(logn)^2
*/

#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor){
    if(dividend == divisor) return 1;

    bool sign=true;// true-> +ve
    if(dividend>0 && divisor<0) sign = false;
    else if(dividend < 0 && divisor>0) sign = false;

    long n = abs(dividend);
    long d = abs(divisor);

    divisor = abs(divisor);
    long quotient = 0;
    while(n>=d){
        int cnt=0;

        // we are increment cnt till we exceed n
        while (n>=(d << (cnt+1))){
            cnt+=1;
        }

        quotient += 1<<cnt;// 2^cnt, how many 2's used, add them

        n-=(d<<cnt);//d X 2^cnt, decrease the dividend
    }

    if(quotient==(1<<31) && sign)
        return INT_MAX;

    if(quotient==(1<<31) && !sign)
        return INT_MIN;

    return sign?quotient:-quotient;
}

int main()
{
    int dividend = 22;
    int divisor = 3;
    cout << divide(dividend, divisor) << endl;
    return 0;
}

