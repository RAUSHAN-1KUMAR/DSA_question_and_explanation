/*
To count prime numbers till a given number N
*/

/*
Normal sieve of eratosthenes:- already explained in first lecture

Time complexity: O(nlog(logn))
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

    for(int i=2 ; i<=n ; i++)
    {
        if(sieve[i])
        {
            int j = i+i;//-> OR j = i*2
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
    vector<bool> sieve = Sieve(25);

    for(int i=2 ; i<=25 ; i++)
    {
        if(sieve[i]==true) cout << i << " ";
    }


    return 0;
}