/*
To align the posetive element on the left side and negative element on the right side
*/

#include<iostream>
#include<vector>
using namespace std;

void shiftNegativeOneSide(int arr[], int size){
    int j = 0; //-> j is a memory block which is to store the index of posetive number

    for(int index = 0 ; index<size ; index++)
    {
        if(arr[index]>0){
            swap(arr[index], arr[j]);
            j++;
        }
    }
}

int main()
{
    int arr[] = {23, -7, 12, -10, -11, 40, 60};
    int n = 7;

    shiftNegativeOneSide(arr,n);

    //printing array
    for(int i = 0 ; i<n ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}