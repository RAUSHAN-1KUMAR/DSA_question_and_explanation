/*
Allocation integer inside heap without using new keyword
*/

/* malloc();

Malloc stands for memeory allocation. It takes number of bytes to be allocated as an input and a pointer to type void.

    Syntax: int *ptr = (int*)malloc(30*sizeof(int));
            -- first bracket(int*)-> casting void pointer to integer pointer i.e., to tell the data type to point(it is like implicit type casting)
            -- second bracket(30*sizeof(int))-> space for 30 integer and its size i.e., to tell the total bytes to allocate 

    Note:- the expression returns a null pointer if the memeory cannot be allocated.
*/

#include<iostream>
#include<cstdlib>// for malloc and free
using namespace std;

int main()
{
    int *ptr = (int*)malloc(sizeof(int));//--> We can also use 4 in place of sizeof(int).

    if (ptr == nullptr) {
        cerr << "Memory allocation failed" << endl;
        return 1;
    }

    *ptr = 5;

    cout << *ptr << endl;

    // deallocate the memory
    free(ptr);

    return 0;
}

/* cerr ?

The "c" in cerr refers to "character" and "err" means "error". Hence cerr means "character error". The cerr object is used along with the insertion operator << in order to display error messages.

*/