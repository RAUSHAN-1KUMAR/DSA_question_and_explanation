/*
passing array to function
*/

#include<iostream>
using namespace std;

void display(int arr[], int size)
{
    for(int i = 0 ; i<size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << sizeof(arr) << endl;
}


int main()
{
    int arr[5] = {2,3,4,6,10};
    int size = 5;

    // array is passed in function with its size.
    // and if we pass an array to a function then it will always be pass by reference because array name points to its first element of array.
    display(arr, size);

    cout << sizeof(arr) << endl;


    return 0;
}