
/*
Guess the output
*/

#include<iostream>
using namespace std;

int main()
{
    // first question
    int a[5];
    int *c;
    cout << sizeof(a) << " " << sizeof(c) << endl;

    // second question
    int b[] = {1,2,3,4};
    cout << *b << " " << *(b+1) << endl;

    // third question
    int *p = b++;//-> error because b is a constant pointer 
    cout << *p << endl;

    return 0;
}