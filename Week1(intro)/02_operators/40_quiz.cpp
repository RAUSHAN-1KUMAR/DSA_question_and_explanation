
#include<iostream>
using namespace std;

int main()
{
    int a = 5, y = 10, z = 1;

    cout << "value of z before action: " << z << endl;

    z = a++*y;// increment is done after the value of a is taken. So, z = a*y = 50. remember the value of a has increased by 1

    cout << "value of z after action1: " << z << endl;

    z = ++a*y;// value of a is taken after the increment is done. So, z = ++a*y = 70. remember the value of a has again increased by 1

    cout << "value of z after action2: " << z << endl;

    z += (a++*++a*y--)/++y;

    cout << "value of z after action3: " << z << endl;
    
    cout << "value of a is " << a << " and the value of y is " << y << endl;

    return 0;
}