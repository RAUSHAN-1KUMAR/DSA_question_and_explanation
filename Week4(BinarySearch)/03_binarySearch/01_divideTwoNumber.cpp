/* -> 29

Given two number num1 and num2, we have to return the nearest integer to the answer of num1/num2 using binary search.

first code it for positive number only.

Hind:- 
    Quotient*Divisor + remainder = dividend
                     OR
        Quotient*Divisor <= Dividend
*/

/*
Approach:- let num1->dividend and num2->divisor 
    -- applying binary search from s = 0 to e = dividend (which will be the Search space of quotient).
    -- apply the BS condition on mid*divisor w.r.t dividend.
*/



#include<iostream>
using namespace std;

int getQuotient(int divisor, int dividend)
{
    int s = 0;
    int e = dividend;
    int ans = 0;


    while(s<=e)
    {
        int mid = s+(e-s)/2;

        if(mid*divisor==dividend) return mid;
        else if(mid*divisor < dividend){
            ans = mid;
            s = mid+1;
        }
        else e = mid-1;
    }   

    return ans;
}


int main()
{
    int dividend = 100;
    int divisor = 9;

    int ans = getQuotient(divisor, dividend);

    cout << ans << endl;


    return 0;
}