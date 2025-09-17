#include<iostream>
using namespace std;

int main()
{
    int a= 5;
    int b= 6;
    cout << a << " " << b << endl;

    //swapping
    int temp = b;
    b = a;
    a = temp;

    cout << a << " " << b << endl;
    cout << a << " " << b << endl;
    return 0;
}