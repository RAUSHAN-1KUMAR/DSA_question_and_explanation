
/*
Guess the output
*/

#include<iostream>
using namespace std;

int main()
{
    // first question
    cout << "first question: " << endl;
    int arr[] = {4,5,6,7};
    int *p = (arr+1);

    cout << p << endl;
    cout << p[2] << endl;
    cout << *p << endl;
    cout << *arr + 9 << endl;



    // second question
    cout << "second question: " << endl;
    char b[] = "xyz";
    char *c = &b[0];
    char *z = &b[1];

    cout << c << endl;
    cout << *(c+1) << endl;
    cout << z << endl;
    cout << *z << endl;

    return 0;
}