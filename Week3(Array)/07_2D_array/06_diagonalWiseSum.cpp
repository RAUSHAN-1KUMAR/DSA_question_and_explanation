     
// printing diagonal wise sum

#include<iostream>
using namespace std;

void printRowWiseSum(int arr[][3], int rows, int cols)
{
    // diagonal sum -> just choose diagonal elements
    int sum = 0;
    for(int i = 0 ; i<rows ; i++)
    {
        for(int j = 0 ; j<cols ; j++)
        {
            if(i==j) sum += arr[j][i];
        }
    }

    cout << sum << endl;
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


