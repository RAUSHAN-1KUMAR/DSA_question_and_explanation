
/*
Toggle the ith bit means: if it is 0 change it to one, or if it is 1 then change it to 0
*/

// Using XOR operator: a^(1<<i)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=15;
    int i=2;

    n=n^(1<<i);

    cout << n << endl;

    n=n^(1<<i);

    cout << n << endl;
    
    return 0;
}

