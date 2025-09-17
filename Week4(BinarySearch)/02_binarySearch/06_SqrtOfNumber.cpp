/* -> 69
Given a non-negative integer x, return the square root of x, answer should NOT BE rounded down to the nearest integer. The returned integer should be non-negative as well

Example 1:
    Input: x = 4
    Output: 2

Example 2:
    Input: x = 8
    Output: 2.828
*/

/*
Approach:-
    -- first we will find the nearest integer(ans) and then we will deal with fractional part seperately outside of the while loop.
    -- for fractional part, we will run a for loop for each precision and for each precision i.e., for each iteration we will run a while loop inside it for the end value of that precision by checking the condition ans*ans <= number.
    -- for first precision we will take a variable 'increment = 0.1' and then for second precision will modify it to '0.01' same for third precision '0.001' and like this.
    -- observe the solution code, you will get it.
*/

#include<iostream>
#include<vector>
using namespace std;

float mySqrt(int x, int p)
{
    int s = 0;
    int e = x;
    float ans = 0;

    while(s<=e)
    {
        long int mid = s + (e-s)/2;

        if(mid*mid == x) return mid;
        else if(mid*mid > x) e = mid-1;
        else{
            ans = mid;
            s = mid+1;
        }
    }

    // for fractional part
    float increment = 0.1;
    for(int i=0 ; i<p ; i++)
    {
        while(ans*ans<=x){
            ans += increment;
        }

        ans = ans-increment; 
        increment = increment/10;
    }

    return ans;
}

int main()
{
    int num;
    int prec;
    
    cout << "number: ";
    cin >> num;

    cout << "precision: ";
    cin >> prec;

    cout << mySqrt(num, prec) << endl;

    return 0;
}