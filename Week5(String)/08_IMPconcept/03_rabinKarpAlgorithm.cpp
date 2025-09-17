/* string matching algorithm
    1. KMP alog -> already discussed: TC-> O(m+n)
    2. Rabin karp alogrithm or we can say rolling hash technique: TC-> < O(n*m)
*/

/* lets understand rolling hash
A rolling hash is a hash function designed to enable efficient recomputation of the hash value when the window of text shifts by one character.

Instead of recalculating the entire hash for each substring, you can:
    - Remove the leftmost character’s contribution.
    - Add the new rightmost character’s contribution.

This saves time and is the core reason why Rabin-Karp can run in linear time on average.

TC:- less than O(n*m)
*/

// theory and code explanation by aryan mittal

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define MOD 1000000007

ll hashValue(string str, ll RADIX, ll m)
{
    ll ans=0, factor=1;// factor will be used RADIX^2 and then RADIX^3, initially RADIX^0 = 1, that's why its intial value is 1.

    // iterating from back of the needle, must
    for(ll i=m-1 ; i>=0 ; i--){
        ans += ((str[i]-'a')*factor)%MOD;
        factor = (factor*RADIX)%MOD;
    }

    return ans%MOD;
}


int strStr(string haystack, string needle)
{
    ll n=haystack.length(), m=needle.length();

    if(n<m) return -1;// base case

    ll RADIX=26;
    ll MAX_WEIGHT=1;// will be used for shifting purpose

    // calculating: (26^m) % MOD
    for(ll i=1 ; i<=m ; i++)
        MAX_WEIGHT = (MAX_WEIGHT*RADIX)%MOD;

    // first find the hash value of needle
    ll hashNeedle = hashValue(needle, RADIX, m);

    ll hashHay=0;// used to compare with  hashNeedle

    for(ll i=0 ; i<=n-m ; i++){
        if(i==0){
            hashHay = hashValue(haystack, RADIX, m);
        }
        else{
            hashHay = ((hashHay*RADIX)%MOD - ((haystack[i-1]-'a')*MAX_WEIGHT)%MOD + (haystack[i+m-1]-'a') + MOD) % MOD;
        }

        // if hash of needle matches with hashHay, we still have the check the character inidividually
        if(hashNeedle==hashHay){
            for(ll j=0 ; j<m ; j++){
                if(needle[j]!=haystack[j+i]) break;
                if(j==m-1) return i;
            }
        }
    }

    return -1;
}


int main()
{
    string text = "birhdayboybirthbirtdh";
    string pattern = "birth";
    cout << strStr(text, pattern) << endl;
    return 0;
}

