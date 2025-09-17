/*
gcd(a,b) = gcd(a-b ,b) ; a>b
           gcd(b-a, a) ; b>a

            OR

gcd(a,b) = gcd(a%b ,b) ; a>b
           gcd(b%a, a) ; b>a

*/

/*
Note:- we have to apply the formula till one of the parameter become 0.
    -- explained in notecopy 
*/

#include <iostream>
using namespace std;

int anotherMethod(int a, int b) 
{
    if(a==0) return b;
    if(b==0) return a;

    while(a>0 && b>0)
    {
        if(a>b) a = a%b;
        else b = b%a;
    }

    return a==0 ? b:a;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    int result = anotherMethod(num1, num2);
    
    cout << "GCD of " << num1 << " and " << num2 << " is " << result << endl;

    return 0;
}