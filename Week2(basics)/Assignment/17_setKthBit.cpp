/*
Question:-
    -- Given a number N and a value K. From the right, set the kth bit in the binary representation of N. The position of Least Significant Bit(or last bit) is 0, the second last bit is 1 ans so on.

    explanation:-
        -- question says that if the kth bit of the given number N is not 1 then convert it to 1.
*/

#include<iostream>
using namespace std;

int set(int N, int K)
{
    int mask = 1<<K;
    int ans = N | mask; // | -> this is bitwise OR operator
    return ans;
}

int main()
{
    int num,k;
    cout << "enter number: ";
    cin >> num;
    cout << "which bit: ";
    cin >> k;

    cout << "Your number became: " << set(num,k);

    return 0;
}