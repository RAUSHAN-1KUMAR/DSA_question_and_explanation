/*
We have a given number and we have to check, is this number is a power of two or not

EX:- 4 -> yes
     5 -> no
     6 -> no

    we know the number who will be a power of two, then it will definetely contain only single bit,
        EX:- 8   -> 0000 1000
             4   -> 0000 0100
             16  -> 0001 0000
             128 -> 1000 0000

             so we can use n&(n-1) to check if it is power of two or not
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n = 128;

    if((n&(n-1)) == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}


