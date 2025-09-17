/*
To align the posetive element on the left side and negative element on the right side
*/

/*
Approach:- two pointer approach
*/

#include<iostream>
#include<vector>
using namespace std;


int main()
{
    int arr[] = {23, -7, 12, -10, -11, 40, 60};
    int start = 0;
    int end = sizeof(arr)/sizeof(int) - 1;

    while(start<end){
        if(arr[start] > 0) start++;
        else if(arr[end] < 0) end--;
        else{
            swap(arr[start],arr[end]);
            start++;
            end--;
        }
    }

    //printing array
    for(int i = 0 ; i<=6 ; i++){
        cout << arr[i] << " ";
    }

    return 0;
}