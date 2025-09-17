/*
Relational operators
    Ex-> is equals to(==), not equals to(!=), greater than(>), less than(<), greater than or equals to(>=), lesser than or equals to(<=)
              4==5             4!=5                5>4            4<5                  9>=5                         5<=5

        -- equals to operator(==) is used to check whether the numbers are equals or not, in sense of true or false.
        -- not equals to operator(!=) is used to check whether one number is equal to other number or not, in sense of true or false.
*/

#include<iostream>
using namespace std;

int main()
{
    int num1, num2, num3, num4;
    num1 = 3;
    num2 = 4;
    num3 = 3;
    num4 = 9;

    cout << (num1==num2) << endl;//- false
    cout << (num1!=num2) << endl;//- true
    cout << (num1<num4) << endl;//- true
    cout << (num3>num2) << endl;//- false
    cout << (num1<=num3) << endl;//- true
    cout << (num2>=num4) << endl;//- false

    return 0;
}
