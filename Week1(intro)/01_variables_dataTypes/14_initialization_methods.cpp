#include<iostream>
using namespace std;

int main()
{
    int a = 6;
    a = (1,2,3);//-> a = 3
    cout << a << endl;

    int b(2);
    cout << b << endl;

    int c = (3);
    cout << c << endl;

    int d{4};
    cout << d << endl;

    int e = {5};
    cout << e << endl;

    return 0;
}

/*
We can't use:-
    int a = 1,2,3; -> error
    int b(2,3); -> error
    int e = {5,6}; -> error
    int d{4,5,6}; -> error
*/