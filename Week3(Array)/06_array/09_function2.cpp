/*

In array: if we pass array to a function the it will always be pass by reference because array name points to its first element.

*/


#include<iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for(int i = 0 ; i<size ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inc(int prr[] , int size)
{
    prr[0] = prr[0]+10;
    printArray(prr,size);
}

int main()
{   
    int arr[] = {5,6};

    inc(arr,2);
    
    printArray(arr,2);

    return 0;
}
