/*
Linear search
*/

#include<iostream>
using namespace std;

bool linearSearch(int arr[], int size, int target)
{
    for(int i = 0 ; i<size ; i++)
    {
        if(arr[i]==target) return true;
    }
    return false;
}

int main()
{
    int arr[5] = {2,3,4,6,10};
    int size = 5;
    int target = 10;

    bool ans = linearSearch(arr, size, target);

    if(ans == 1) cout << "Target found";
    else cout << "Target not found";

    return 0;
}