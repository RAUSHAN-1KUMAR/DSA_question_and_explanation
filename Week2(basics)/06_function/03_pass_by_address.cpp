#include<iostream>
using namespace std;

void swap(int *a, int *b)// address of x and y is passed so as a and p are pointer so they are pointing to original memory of x and y.
{
    cout << *a << " " << *b << endl;
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    cout << *a << " " << *b << endl;
}

int main()
{
    int x = 10, y = 20;
    swap(&x,&y);//-> address of x and y is passed.
    cout << x << " " << y << endl;
    return 0;
}


