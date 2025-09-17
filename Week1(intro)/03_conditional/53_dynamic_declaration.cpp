
#include<iostream>
using namespace std;

int main()
{
    int a = 10, b = 5;

    if(true)
    {
        int c = a+b;
        cout << c << endl;
    }

    /* cout << c << endl; -> error because the variable c is declared inside the body of if, so as the compiler finish the body of if statement
    the declared variable c will be erased form the stack. */
    
    return 0;
}