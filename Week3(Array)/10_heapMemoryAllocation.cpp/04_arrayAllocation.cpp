/*
Allocation array inside heap without using new keyword
*/

/* malloc();

Malloc stands for memeory allocation. It takes number of bytes to be allocated as an input and a pointer to type void.

    Syntax: int *ptr = (int*)malloc(30*sizeof(int));
            -- first bracket(int*)-> casting void pointer to int i.e., to tell the data type to point(it is like implicit type casting)
            -- second bracket(30*sizeof(int))-> space for 30 integer X its size i.e., to tell the total bytes to allocate 

    Note:- the expression returns a null pointer if the memeory cannot be allocated.
*/
 
#include<iostream>
using namespace std;

int main()
{
    int size = 5;

    int *ptr = (int*)malloc(size*sizeof(int)); //-> allocates memory for an array of integers
    
    if (ptr == nullptr) {
        cout << "Memory allocation failed" << endl;
        return 1;
    }

    // assigning the values to the array
    for(int i=0; i < size ; i++)
    {
        ptr[i]  = (i+1)*10;
    }

    // output the array values
    for(int i=0 ; i<size ; i++)
    {
        cout << ptr[i] << endl;
    }

    // deallocate the array
    free(ptr);

    return 0;
}


