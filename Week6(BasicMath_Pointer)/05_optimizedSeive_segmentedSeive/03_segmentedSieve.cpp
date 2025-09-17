/*
To count prime numbers within a given range (l,r)
*/

/*
Normal segmented sieve:- already explained in notecopy using the optimized concept of sieve of eratosthenes
    -- but what if r is very large(10^9), our system can't declare array of size 10^9.
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// creating a sieve array of n size telling isPrime.
vector<bool> Sieve(int n)
{
    vector<bool> sieve(n+1, true);
    sieve[0] = sieve[1] = false;

    for(int i=2 ; i<=sqrt(n) ; i++)
    {
        if(sieve[i])
        {
            int j = i*i;
            while(j<=n){
                sieve[j]=false;
                j += i;
            }
        }
    }

    return sieve;
}


int main()
{
    int low = 10;
    int high = 25;

    vector<bool> sieve = Sieve(high);

    // now printing those primes who lie within given range
    for(int i=low ; i<=high ; i++)
    {
        if(sieve[i]==true) cout << i << " ";
    }


    return 0;
}