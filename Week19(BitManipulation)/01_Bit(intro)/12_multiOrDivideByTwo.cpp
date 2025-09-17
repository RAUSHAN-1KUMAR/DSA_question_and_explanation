/*
We can use left shift operator to multiply by 2
OR we can use right shift operator to divide by 2

Ex: x<<y => x * 2^y
    x>>y => x / 2^y
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a = 5;
    cout << (a<<1) << endl;
    cout << (a>>1) << endl;
    return 0;
}