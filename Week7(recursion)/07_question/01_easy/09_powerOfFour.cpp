/* -> 342

Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:
Input: n = 16
Output: true

Example 2:
Input: n = 5
Output: false

Example 3:
Input: n = 1
Output: true
*/

#include<iostream>
using namespace std;

bool isPowerOfFour(int n)
{
    // base case
    if(n==1) return true;
    if(n<1) return false;

    // solve one case
    if(n%4==0){
        return isPowerOfFour(n/4);
    }

    return false;
}

int main()
{
    int n = 16;

    if(isPowerOfFour(n)) cout << "Yes";
    else cout << "No";

    return 0;
}