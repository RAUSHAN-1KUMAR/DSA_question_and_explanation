/*
Approach:- created an another 2D array and storing each value from original array to its transposed position in new array.
*/     


#include<iostream>
using namespace std;

void trans(int arr[][3], int r, int c, int transpose[][3])
{
    for(int i = 0 ; i<r ; i++)
    {
        for(int j = 0 ; j<c ; j++)
        {
            transpose[j][i] = arr[i][j];
        }
    }    
}

void printArray(int arr[][3], int r, int c)
{
    for(int i = 0 ; i<r ; i++)
    {
        for(int j = 0 ; j<c ; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{   
    int arr[3][3] ={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int transpose[3][3];

    cout << "Before transpose: " << endl;
    printArray(arr,3,3);

    // doing transpose
    trans(arr,3,3,transpose);

    cout << "After transpose: " << endl;
    printArray(transpose,3,3);

    return 0;
}


