
#include<iostream>
using namespace std;

int search(int arr[][3], int rows, int cols, int k)
{
    for(int i = 0 ; i<rows ; i++)
    {
        for(int j = 0 ; j<cols ; j++)
        {
            if(k==arr[i][j])
                return 1;
        }
    }
    return 0;
}

int main()
{   
    int arr[3][3] ={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int key = 10;

    if(search(arr,3,3,key))
    {
        cout << "found";
    }
    else
    {
        cout << "not found";
    }

    return 0;
}


