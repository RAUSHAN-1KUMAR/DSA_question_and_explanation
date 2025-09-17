/*
unset/clear ith bit, means it it is 1 then make it 0
*/

/*
We can use & to change the ith bit: 1101 & 1011 to change the 2nd bit

How to obtain: 1011 = ~(1<<2)
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n = 13;
    int i = 2;

    n = n & ~(1<<i);// 1101 & 1011 = 1001

    cout << n << endl;

    return 0;
}