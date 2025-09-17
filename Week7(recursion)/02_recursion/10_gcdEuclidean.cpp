


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int gcdEuclidean(int num1, int num2)
{
    // base case
    if(num1==0 || num2==0)
    {
        return num1==0 ? num2:num1;
    }

    // one case solve
    if(num1>num2) num1 %= num2;
    else num2 %= num1;

    // RE
    return gcdEuclidean(num1,num2);
}

int main()
{
    int num1 = 18;
    int num2 = 48;

    cout << gcdEuclidean(18,48) << endl;

    return 0;
}