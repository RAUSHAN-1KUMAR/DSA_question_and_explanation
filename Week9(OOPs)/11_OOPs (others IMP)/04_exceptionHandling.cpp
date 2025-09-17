/*
Exception Handling in C++: (mainly for runtime errors)
    -- An exception is an unexpected event/error that happens while a program is running.

    -- Exception handling is the mechanism that lets you detect, handle, and recover from those errors gracefully, instead of crashing.


TRY: It represents a block of code that may throw an exception placed inside the try block. It's followed by one or more catch blocks.

CATCH: It represents a block of code that is executed when a particular exception is thrown from the try block.

THROW: An exception in c++ can be thrown using the "throw" keyword. when a program encounters a throw statement then it immediately terminates the current function and starts finding a matching catch block to handle the thrown exception.
*/


#include<bits/stdc++.h>
using namespace std;

int division(int x, int y){
    if(y==0){
        throw "Division by zero condition!";
    }
    return x/y;
}

int main()
{
    int a=10, b=0;
    int c=5, d=2;

    try{
        cout << division(a,b) << endl;
    }catch(const char *msg){ // should match with the throw type, for any type -> see next
        cout << msg << endl;
    }

    try{
        cout << division(c,d) << endl;
    }catch(const char *msg){
        cout << msg << endl;
    }

    return 0;
}

