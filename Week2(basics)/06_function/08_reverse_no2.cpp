#include<iostream>
#include<climits> // This library is used for managing and evaluating maximum and minimum values of several integer data-types.
using namespace std;

int reverse(int x)
{
    int ans = 0;
    bool isNeg = false;
    if(x <= INT_MIN){
        return 0;
    }
    if(x<0)
    {
        isNeg = true;
        x = -x;
    }

    while(x>0){
        if(ans > INT_MAX){
            return 0;
        }
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