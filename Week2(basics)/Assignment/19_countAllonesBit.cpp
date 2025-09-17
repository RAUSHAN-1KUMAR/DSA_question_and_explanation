/*
Count all set bits that is to count all 1's bit using bitwise
*/

#include<iostream>
using namespace std;

int countSetBit(int n)
{
    int count = 0;
    while(n)
    {
        int bit = (n&1);
        if(bit==1) count++;
        n = n>>1;
    }

    return count;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int setBitCount = countSetBit(n);
    cout << setBitCount << endl;
    return 0;
}