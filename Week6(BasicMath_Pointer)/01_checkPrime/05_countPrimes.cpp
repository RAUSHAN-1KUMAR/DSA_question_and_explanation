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
    2. Segmented Sieve:- discribed in notecopy
        -- priviously we were finding primes from 2 to N, but in this approach we have to find primes in a given range

Time complexity:- O(nlog(logn))
*/



#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void countPrimes(int l, int r)
{

    vector<bool> prime(r,true);
    prime[0] = prime[1] = false; //-> as our prime number starts from 2

    // till r, marking the non-primes using normal sieve
    for(int i=2 ; i<r ; i++)
    {
        if(prime[i])
        {
            int j = i+i;  
            while(j<r){
                prime[j] = false;
                j += i;
            }
        }
    }

    // now printing those primes who lie within given range
    for(int i=l ; i<r ; i++)
    {
        if(prime[i]) cout << i << " ";
    }
}

int main()
{
    int left, right;
    cout << "Enter the low and high: ";
    cin >> left >> right;

    cout << "Prime numbers from " << left << " to " << right << " are: ";
    countPrimes(left, right);

    return 0;
}