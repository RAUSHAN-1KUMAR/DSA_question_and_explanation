
#include<iostream>
using namespace std;

int main()
{
    int a = 2;
    int b = 1;
    int c = a || --b;// --b will not evaluated because in case of ||(OR) operator if expression1 is true then it will not go for expression2.
    int d = a-- && --b;// first d = a = 2 then a = 2 - 1 = 1 && b = 1 - 1 = 0 then d = b = 0 is checked, it is false so the value of d is 0.

    cout << a << b << c << d << endl;// output: 1010
    // value of c is 1 because value of c is assigned using OR(||) logical operator. So, true means 1.
    // value of d is 0 because vlue of d is assigned using AND(&&) logical operator. S0, false means 0.

    return 0;
}
