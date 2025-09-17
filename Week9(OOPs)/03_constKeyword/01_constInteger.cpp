
// The const keyword is used to declare that a variable, function, or object is immutable, i.e., its value cannot be changed after it has been initialized.

#include<iostream>
using namespace std;

int main()
{
    const int x = 10;
    cout << x << endl;

    x = 11;//-> error due to const data type
    
    return 0;
}

/*
lvalue -> variable having memory location.
        Ex: int x = 10;
        x = 11; // x is an lvalue because it has a memory location.

rvalue -> variable doesn't have memory location 
        Ex: 10, 11, 12, etc. are rvalues because they do not have a memory location.
*/