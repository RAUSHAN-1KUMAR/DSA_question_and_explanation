/*
Using GCD:-
    -- LCM(a,b) * HCF(a,b) = a * b

    So, first we will find the GCD using euclidean algorithm and then:
        LCM = (a*b)/GCD
*/

#include <iostream>
using namespace std;


int findingHCF(int a, int b)
{
    if(a==0) return a;
    if(b==0) return b;

    while(a>0 && b>0)
    {
        if(a>b) a = a-b;
        else b = b-a;
    }

    return a==0?b:a;
}

int lcmNaive(int a, int b) 
{
    int hcf = findingHCF(a,b);

    int lcm = (a*b)/hcf;

    return lcm;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "LCM of " << num1 << " and " << num2 << " is " << lcmNaive(num1,num2) << endl;

    return 0;
}