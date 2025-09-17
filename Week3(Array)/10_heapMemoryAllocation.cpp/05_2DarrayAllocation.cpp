/*
Allocation 2D array inside heap using new keyword
*/

#include<iostream>
using namespace std;

int main()
{
    // using an array of pointers
    {
        int rows = 3;
        int cols = 4;
        int **ptr = new int*[rows];//-> allocates an array of pointers inside heap

        for(int i=0 ; i<rows ; i++)
        {
            ptr[i] = new int[cols];//-> allocates an array of each row inside heap
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
            delete[] ptr[i];//-> deallocating each row
        }
        delete[] ptr;//-> deallocating the array of pointers
    }


    // using a single allocated block
    {
        int rows=3;
        int cols=4;
        int *ptr = new int[rows*cols];//-> allocates a single block of memory(i.e., 2D array represented as 1D array)

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
        delete[] ptr;
    }

    return 0;
}