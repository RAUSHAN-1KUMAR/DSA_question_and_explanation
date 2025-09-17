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
Approach:- Brute force approach
    -- creating an array till the square of i <= x, and then the last of element of the array is the required answer.
*/

#include<iostream>
#include<vector>
using namespace std;

int mySqrt(int x)
{
    vector<int> num;
    for(long long int i = 1 ; i*i<=x ; i++)
    {
        num.push_back(i);
    }

    auto it = num.end();

    return (x==0) ? 0 : *(it-1);
}

int main()
{
    int num = 2;

    cout << mySqrt(num) << endl;

    return 0;
}