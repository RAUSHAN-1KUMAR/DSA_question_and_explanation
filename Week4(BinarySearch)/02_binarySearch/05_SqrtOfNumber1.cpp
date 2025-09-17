/* -> 69
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well

Example 1:
    Input: x = 4
    Output: 2
    Explanation: The square root of 4 is 2, so we return 2.

Example 2:
    Input: x = 8
    Output: 2
    Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/

/*
Approach:- search space
    -- applying binary search from s = 0 to e = number (which will the search space of sqrt root).
    -- then apply the BS conditions on mid*mid w.r.t number.
*/

#include<iostream>
#include<vector>
using namespace std;

int mySqrt(int number)
{
    int s = 0;
    int e = number;
    int ans = 0;

    while(s<=e)
    {
        long int mid = s + (e-s)/2;

        if(mid*mid == number) return mid;
        else if(mid*mid > number) e = mid-1;
        else{
            ans = mid;
            s = mid+1;
        }
    }

    return ans;
}


int main()
{
    int num = 10;

    cout << mySqrt(num) << endl;

    return 0; 
}