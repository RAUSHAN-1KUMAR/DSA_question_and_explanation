
/*
Given a number, count the number of set bits

EX:- 13 -> 1101: output-> 3

c++ build in function: O(1) time
    i) __builtin_popcount(x): for int
    ii) __builtin_popcountll(x): for long long
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n=13;

    int i=0;
    int ans=0;
    while(n)
    {
        if(n&1) ans++;
        i++;
        n=n>>1;// n=n/2
    }
    cout << ans << endl;
    

    // another way, for each first right set bit we are gonna increase ans1
    int m=13;
    int ans1=0;
    while(m){
        ans1++;
        m = m&(m-1);
    }
    cout << ans1 << endl;


    // using inbuilt function
    int x = 15; long long y = 15;
    cout << __builtin_popcount(x) << endl;
    cout << __builtin_popcountll(y) << endl;

    return 0;
}

