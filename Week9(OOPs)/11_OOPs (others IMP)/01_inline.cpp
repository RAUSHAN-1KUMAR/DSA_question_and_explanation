/*
Inline function:
    -- the function which expands in the same line where they are called. (happens during compile time)
*/

#include<iostream>
using namespace std;

inline void numberShow(int num)
{
    cout << num << endl;
}

int main()
{
    numberShow(10);
    return 0;
}

/*
Inline function:- used when there is small function body
    -- the code of an inline function is inserted directly into the code of the calling function by compiler while compiling, which can result faster execution and less overhead compared to regular function calls.
*/