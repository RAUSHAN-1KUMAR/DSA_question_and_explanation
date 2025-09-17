/* -> 29

Given two number num1 and num2, we have to return answer in decimal form to the answer of num1/num2 using binary search.

Now code it for positive as well as negative number also.

Hind:- 
    Quotient*Divisor + remainder = dividend
                     OR
        Quotient*Divisor <= Divident
*/

/*
Approach:-
    -- to deal with the fractional part, apply the same concept as applied in fractional part for the square root of a number.

Note:-
    -- in case of negative number, we have now four conditions extra:
        1. p/p = p          2. n/n = p          ; p -> positive
        3. n/p = n          4. p/n = n            n -> negative

        So, when we apply the binary search in this question, apply it by passing positive numbers into the function, and when we got the answer, change it to negative or positive accordingly by checking the above four condition.
*/



#include<iostream>
using namespace std;

float getQuotient(float divisor, float dividend, int p)
{
    int s = 0;
    int e = dividend;
    float ans = 0;

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

    // for fractional part
    float increment = 0.1;
    for(int i=0 ; i<p ; i++)
    {
        float j = ans;

        while(j*divisor <= dividend){
            ans=j;
            j+=increment;
        }

        increment /= 10;
    }

    return ans;
}


int main()
{
    int dividend;
    cout << "Dividend: ";
    cin >> dividend;

    int divisor;
    cout << "Divisor: ";
    cin >> divisor;

    int prec;
    cout << "precision: ";
    cin >> prec;

    float ans = getQuotient(abs(divisor), abs(dividend), prec);

    // Now we have to decide the sign
    if((divisor>0 && dividend<0) || (divisor<0 && dividend>0)) ans *= -1;

    cout << endl <<  ans << endl;


    return 0;
}