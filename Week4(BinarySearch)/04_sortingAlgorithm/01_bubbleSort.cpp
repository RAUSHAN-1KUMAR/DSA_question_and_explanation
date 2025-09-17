// In bubble sort:- the maximum element come to up(end) like a bubble.

/*
Bubble sort:- described in notecopy
*/

/*
Approach:
    -- we campare adjacent elements and swap them if they are not in order.

Time Complexity:-
    1. Best case:- O(n), when array is already sorted
    2. Worst case:- O(n^2)
    3. Average case:- O(n^2)
*/   

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i = 0 ; i<(n-1) ; i++)
    {
        bool swapped = false;

        for(int j = 0 ; j<(n-(i+1));j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;

                swapped = true;
            }
        }

        // if no swaps occured then it means array is sorted.
        if(swapped == false) break;
    }
}

void display(int arr[], int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int arr[] = {21,6,10,12,11,10,15,18,3};
    int size = sizeof(arr)/sizeof(int);

    cout << "Before bubble sort: " << endl;
    display(arr, size);

    bubbleSort(arr, size);

    cout << "After bubble sort: " << endl;
    display(arr, size);

    return 0;

}
