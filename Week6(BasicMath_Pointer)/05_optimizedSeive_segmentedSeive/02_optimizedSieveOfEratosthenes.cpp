/*
To count prime numbers till a given number N
*/

/*
Optimized sieve of eratosthenes:-
    -- previously we were running our inner while loop from j = i+i, but now we will run our inner loop from j = i*i because we have already marked the i*(i-1), i*(i-2),....,i*(2) when j was (i-1), (i-2),....,2.
    -- previously we were running our outer for loop till n, but now we will run our outer for loop till sqrt(n), because:
            let say we have n=25, and i=6 at outer for loop. As inner loop starts form i*i=36 till n=25 so it will not run then why need to check for further i. So, lets run our outer for loop  from i=2 to i=sqrt(n) or i=2 to i*i<=n

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

    for(int i=2 ; i<=sqrt(n) ; i++)//-> change2
    {
        if(sieve[i])
        {
            int j = i*i;//-> change1
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