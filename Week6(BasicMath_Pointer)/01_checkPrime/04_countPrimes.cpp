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
    2. Sieve of Eratosthenes theorem:- discribed in notecopy

Time complexity:- O(nlog(logn))
*/



#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int countPrimes(int n)
{
    if(n==0) return 0;

    vector<bool> prime(n,true);
    prime[0] = prime[1] = false; //-> as our prime number starts from 2

    int ans = 0;

    for(int i=2 ; i<n ; i++)
    {
        //-> take a prime number and mark all its multiple as nonPrime except that number
        if(prime[i])
        {
            ans++;//-> COUNTING THE PRIMES

            int j = i+i;//-> OR j = i*2
            while(j<n){
                prime[j] = false;
                j += i;
            }
        }
    }

    return ans;

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