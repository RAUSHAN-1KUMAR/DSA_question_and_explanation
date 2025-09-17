/* -> 204

Given an integer n, return the number of prime numbers that are strictly less than n.
 

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0

*/


/*
Appraoches:-
    2. Sqrt approach:- discribed in notecopy
        -- finding factor till root(n)

Time complecity:- still the time complexity is large: O(n * sqrt(n))
*/


#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int n) 
{
    // 0 and 1 are not prime numbers
    if (n <= 1) return false; 

    // checking factor till root(n)
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0){
            return false;
        }
    }

    return true;
}

int countPrimes(int n)
{
    int count = 0;
    for(int i=2; i<n ; i++)
    {
        if(isPrime(i)) count++;
    }

    return count;
}

int main()
{
    int num;
    cout << "Enter the limit: ";
    cin >> num;

    cout << "Prime numbers upto " << num << " are: ";
    cout << countPrimes(num) << endl;

    return 0;
}