/* -> 29

Given two number num1 and num2, we have to return the nearest integer to the answer of num1/num2 using binary search.

Now code it for positive as well as negative number also.

Hind:- 
    Quotient*Divisor + remainder = dividend
                     OR
        Quotient*Divisor <= Divident
*/

/*
Approach:-
    -- applying binary search from s = 0 to e = dividend (which will be the Search space of quotient).
    -- apply the BS condition on mid*divisor w.r.t dividend.


Note:-
    -- in case of negative number, we have now four conditions extra:
        1. p/p = p          2. n/n = p          ; p -> positive
        3. n/p = n          4. p/n = n            n -> negative

        So, when we apply the binary search in this question, apply it by passing positive numbers into the function, and when we got the answer, change it to negative or positive accordingly by checking the above four condition.
*/



#include<iostream>
using namespace std;

int getQuotient(int divisor, int dividend)
{
    int s = 0;
    int e = dividend;
    int ans = 0;

    int mid = s+(e-s)/2;

    while(s<=e)
    {
        if(mid*divisor==dividend) return mid;
        else if(mid*divisor < dividend){
            ans = mid;
            s = mid+1;
        }
        else e = mid-1;

        mid = s+(e-s)/2;
    }   

    return ans;
}


int main()
{
    int dividend = 65;
    int divisor = -9;

    int ans = getQuotient(abs(divisor), abs(dividend));

    // Now we have to decide the sign
    if((divisor>0 && dividend<0) || (divisor<0 && dividend>0)) ans *= -1;

    cout << ans << endl;


    return 0;
}