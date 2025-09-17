/* -> 231

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Example 1:
Input: n = 1
Output: true
Explanation: 2^0 = 1

Example 2:
Input: n = 16
Output: true
Explanation: 2^4 = 16

Example 3:
Input: n = 3
Output: false
*/

#include<iostream>
using namespace std;

bool isPowerOfTwo(int n)
{
    // base case
    if(n==1) return true;
    if(n<1) return false;
    if(n&1) return false;

    return isPowerOfTwo(n/2);
}

int main()
{
    int n = 18;

    if(isPowerOfTwo(n)) cout << "Yes";
    else cout << "No";

    return 0;
}