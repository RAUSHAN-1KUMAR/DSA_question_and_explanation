
/*
Guess the output
*/

#include<iostream>
using namespace std;

void changeSign(int *p)
{
    *p = *p*-1;

}

void fun(int a[])
{
    cout << a[0] << " ";
}

void square(int *p)
{
    int c = 10;
    p = &c;
    *p = *p**p;
}

int main()
{
    // first question
    cout << "first question: " << endl;
    int a = 10;
    changeSign(&a);
    cout << a << endl;

    // second question
    cout << "second question: " << endl;
    int b[] = {1,2,3,4};
    fun(b+1);
    cout << b[0] << endl;

    // third question
    cout << "third question: " << endl;
    int c = 10;
    square(&c);
    cout << c << endl;

    return 0;
}