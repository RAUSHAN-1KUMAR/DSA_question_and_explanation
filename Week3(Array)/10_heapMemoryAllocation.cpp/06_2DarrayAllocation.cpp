/*
Allocation 2D array inside heap wihtout using new keyword
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
    // using an array of pointers
    {
        int rows = 3;
        int cols = 4;
        int** ptr = (int**)malloc(rows*sizeof(int*));//-> allocates memoroy for array of pointers

        if(ptr == nullptr){
            cout << "Memory allocation failed" << endl;
            return 1;
        }

        for(int i=0 ; i<rows ; i++)
        {
            ptr[i] = (int*)malloc(cols*sizeof(int));//-> allocates memory for each row
            if(ptr[i]==nullptr){
                cout << "Memory allocation failed" << endl;
                return 1;
            }
        }

        // assigning values to the 2D array
        for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<cols; j++)
            {
                ptr[i][j] = i*cols+j;
            }
        }

        // output the 2D array
        for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<cols; j++)
            {
                cout << ptr[i][j] << " ";
            }
            cout << endl;
        }

        // deallocating the memory
        for(int i=0 ; i<rows; ++i)
        {
            free(ptr[i]);//-> deallocating each row
        }
        free(ptr);//-> deallocating the array of pointers
    }


    // using a single allocated block
    {
        int rows=3;
        int cols=4;
        int *ptr = (int*)malloc(rows*cols*sizeof(int));//-> allocates a single block of memory(i.e., 2D array represented as 1D array)

        if(ptr == nullptr){
            cout << "Memory allocation failed" << endl;
            return 1;
        }

        // assigning values to the 2D array
        for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<cols; j++)
            {
                ptr[i*cols+j] = (i*cols+j+1)*10;
            }
        }

        // output the 2D array
        for(int i=0 ; i<rows ; i++)
        {
            for(int j=0 ; j<cols; j++)
            {
                cout << ptr[i*cols+j] << " ";
            }
            cout << endl;
        }

        // deallocates the memory
        free(ptr);
    }

    return 0;
}