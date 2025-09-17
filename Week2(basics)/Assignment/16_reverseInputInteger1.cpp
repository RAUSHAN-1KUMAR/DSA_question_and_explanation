/*
To reverse given integer

Actual question in leatCode:-
    -- Given a signed 32-bit integer x, return x with its digit reversed. if reversing x causes the value to go outside the signed 32-bit integer range [-2^31 to 2^31 - 1], then return 0.

Note:-
    integer range(32 bit) = -2,147,483,648 to 2,147,483,647
*/

#include<iostream>
#include<limits.h>
using namespace std;

class Solution{
    public:
        int reverse(int x){
            int ans = 0, res = 0;

            bool isNeg = false;

            // already given to maintain the range so if given x is less than equal to INT_MIN than return 0,
            if(x <= INT_MIN){
                return 0;
            }
            if(x >= INT_MAX)
            {
                return 0;
            }

            if(x<0)
            {
                isNeg = true;
                x = -x;
            }

            while(x>0){
                if(ans > INT_MAX/10)
                {
                    return 0;
                }
                int digit = x%10;
                ans = ans*10 + digit;
                x = x/10;
            }

            return isNeg ? -ans : ans;
        }
};


int main()
{

    return 0;
}
