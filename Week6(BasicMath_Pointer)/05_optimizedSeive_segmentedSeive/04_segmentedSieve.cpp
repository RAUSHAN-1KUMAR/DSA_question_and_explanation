/*
To count prime numbers within a given range (l,r)
*/

/*
Segmented sieve for large value of r, but (r-l) <= 10^6 is given in question.
*/

/*
Limitations:-(for CP)
    Within any function:-
        1. int/double/char array max size declaration -> 10^6
        2. bool array -> 10^7 

    Globaly:-
        1. int/double/char array max size declaration -> 10^7
        2. bool array -> 10^8

but this is not fixed varies upon system bit value
*/

/*
Appraoch:- 
    -- as r is very large so we can't make array of size r, so will form array of size (r-l) and then we will mark prime on that segmented seive logically.
    -- generate all prims resposible to mark segmented seive using normal optimized sieve method.
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


vector<bool> segSieve(int l, int r)
{
    // get me prime array, i will use it to mark seg sieve
    vector<bool> sieve = Sieve(sqrt(r));

    // collecting all primes till sqrt(r) int a integer array.
    vector<int> basePrimes;
    for(int i=0 ; i<sieve.size() ; i++){
        if(sieve[i]){
            basePrimes.push_back(i);
        }
    }

    // making an array of size r-l+1, for all prime number in above baseprime vector marks its multiple as false in vector segSeive
    vector<bool> sgSieve((r-l+1),true);
    if(l==1 || l==0)
    {
        sgSieve[l]==false;
    }
    for(auto pr:basePrimes)
    {
        int firstMul = (l/pr)*pr;
        if(firstMul < l) firstMul += pr;

        int j = max(firstMul, pr*pr);
        while(j<=r){
            sgSieve[j-l] = false;
            j += pr;
        }
    }

    return sgSieve;
}


int main()
{
    int low = 5;
    int high = 42;

    vector<bool> sgSeive = segSieve(low, high);

    // printing the primes
    for(int i=0 ; i<sgSeive.size() ; i++)
    {
        if(sgSeive[i]) cout << i+low << " ";
    }

    return 0;
}