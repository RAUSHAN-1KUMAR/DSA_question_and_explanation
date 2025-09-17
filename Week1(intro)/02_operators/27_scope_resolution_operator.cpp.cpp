
#include<iostream>
using namespace std;

int c = 45;

int main()
{
    int a,b,c;

    cout << "Enter the value of a: " << endl;
    cin >> a;

    cout << "Enter the value of b: " << endl;
    cin >> b;

    c = a+b;
    cout << "The sum is " << c << endl;
    cout << "The global c is " << ::c; //--> :: is scope resolution operator, to bring the global value inside function.

    return 0;
}
