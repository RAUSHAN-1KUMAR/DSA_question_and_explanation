/*
Concept:- Insert an element form unsorted array to its correct position in sorted array
    -- boleto, selected element ke pehle ke elements usse chote hone chahiye aur uske baad ke elements usse bade.

Discribed in detail in notecopy

Time Complexity:-
    1. Best case:- O(n)
    2. worst case:- O(n^2)
    3. Average case:- O(n^2)
*/


#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i = 1 ; i<n ; i++)
    {
        int current = arr[i];
        int j = i-1;
        while(current<arr[j] && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1] = current;
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

    cout << "Before insertion sort: " << endl;
    display(arr, size);

    insertionSort(arr, size);

    cout << "After insertion sort: " << endl;
    display(arr, size);

    return 0;
}