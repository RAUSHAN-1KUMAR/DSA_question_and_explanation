/*
if  No. of set bits in A = X
    No. of set bits in B = Y
and No. of set bits in (A^B) = Z ; (^)-> XOR
then
    i) Z is even if X+Y is even
    ii) Z is odd if X+Y is odd
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a=5;//101 -> X=2
    int b=7;//111 -> Y=2  total=4(even)

    int z = a^b;//010 -> Z=1 odd(proved)

    cout << z << endl;

    return 0;
}
