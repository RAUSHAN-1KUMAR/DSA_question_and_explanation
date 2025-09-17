     
// printing colume wise sum

#include<iostream>
using namespace std;

void printRowWiseSum(int arr[][3], int rows, int cols)
{
    // column sum -> column-wise traversal
    for(int i = 0 ; i<rows ; i++)
    {
        int sum = 0;
        for(int j = 0 ; j<cols ; j++)
        {
            sum += arr[j][i];
        }
        cout << sum << " ";
    }
}

int main()
{   
    int arr[3][3] ={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    printRowWiseSum(arr,3,3);

    return 0;
}


