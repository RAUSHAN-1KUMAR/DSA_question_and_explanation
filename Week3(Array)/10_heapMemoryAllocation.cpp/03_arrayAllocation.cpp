/*
Allocation array inside heap using new keyword
*/

#include<iostream>
using namespace std;

int main()
{
    int size = 5;

    int *arr = new int[size]; //-> allocate an array of integers

    cout << *arr << endl; // output the address of the first element

    // assigning the values to the array
    for(int i=0; i < size ; i++)
    {
        arr[i]  = (i+1)*10;
    }

    // output the array values
    for(int i=0 ; i<size ; i++)
    {
        cout << arr[i] << endl;
    }

    // deallocate the array
    delete[] arr;

    return 0;
}