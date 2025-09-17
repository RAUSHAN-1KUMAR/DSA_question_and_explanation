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
    -- if r is large but (r-l)<=10^6

*/



#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void countPrimes(int l, int r)
{
    // an array to store the primes within sqrt(r)
    vector<bool> prime(sqrt(r),true);
    prime[0] = prime[1] = false;

    // till sqrt(r), marking the non-primes using normal sieve
    for(int i=2 ; i<sqrt(r) ; i++)
    {
        if(prime[i])
        {
            int j = i+i;
            while(j<sqrt(r)){
                prime[j] = false;
                j += i;
            }
        }
    }

    // making an array of size r-l+1
    vector<bool> ans((r-l+1),true);

    // for all prime number in above prime vector marks its multiple as false in vector ans
    for(int i=2 ; i<sqrt(r) ; i++)
    {
        int pr;

        if(prime[i]) pr = i;
        else continue;

        int firstMultiple = (l/pr)*pr;

        if(firstMultiple < l) firstMultiple += pr;

        for(int j = max(firstMultiple, pr*pr) ; j<=r ; j += pr){
            ans[j-l] = false;
        }
    }

    // getting all the primes
    for(int i=l ; i<=r ; i++)
    {
        if(ans[i-l]==true) cout << i << " ";
    }
    
    cout << endl;
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