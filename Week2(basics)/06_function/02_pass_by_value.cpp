#include<iostream>
using namespace std;

void swap(int a, int b)// copy of x and y is passed so a and b are containing the value of x and y at their own memory box.
{
    cout << a << " " << b << endl;
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

int main()
{
    int x = 10, y = 20;
    swap(x,y);//-> copy of x and y is passed.
    cout << x << " " << y << endl;
    return 0;
}