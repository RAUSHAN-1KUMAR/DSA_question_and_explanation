#include<iostream>
using namespace std;

int reverse(int x)
{
    int ans = 0;
    bool isNeg = false;
    if(x<0)
    {
        isNeg = true;
        x = -x;
    }

    while(x>0){
        int digit = x%10;
        ans = ans*10+digit;
        x=x/10;
    }

    return isNeg ? -ans : ans ;
}

int main()
{
    int num;
    cout << "enter number: ";
    cin >> num;

    cout << "Reversed: " << reverse(num);

    return 0;
}