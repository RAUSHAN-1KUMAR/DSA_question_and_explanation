/*
To reverse given integer
*/

#include<iostream>
using namespace std;

void reverse(int n, int c)
{
    for(int i = c ; i>=1 ; i--)
    {
        int remainder = n%10;
        cout << remainder;
        n /= 10;
    }

}


int main()
{

    int num;
    cout << "Enter a number: ";
    cin >> num;

    int n = num;
    int count = 0;

    while(n>0)
    {
        count++;
        n /= 10;
    }

    reverse(num,count);

    return 0;
}
