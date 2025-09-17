
#include<iostream>
using namespace std;

int main()
{
    int a = 10, b = 5;

    {
    int c = a+b;
    if(c>10)
    {
        cout << c << endl;
    }
    }

    /* cout << c << endl; -> error because the variable c is declared inside a dummy body, so as the compiler finish that dummy body, the declared 
    variable c will be erased form the stack. */
    
    int d = 12;// this is stored in that memory where the c was stored.

    return 0;
}

/*
we can use this method to minimize our memory usage, as you can see we have used the value of c and after that it is erased, and the further
declared variable will use that memory to get stored.
*/