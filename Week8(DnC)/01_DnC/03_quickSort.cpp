/*
Concept:- 
    -- Devide and conquer rule.
    -- a pivot element form the array and partitioning the other elments into two sub-arrays accordingly to whether they are less than or greater than the pivot. The sub-arrays are then recursively sorted.

Time Complexity:- 
    1. Best case:- O(nlogn) when pivot element devides array into two sub equal parts
    2. worst case:- O(n^2) When pivot element is highest or lowest
    3. Average case:- O(nlogn) when pivot element is random element
*/

#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int partition(int arr[], int l, int r)
{
    // choosing last elment as pivot element
    int pivot = arr[r];
    int i = l-1;//-> catch

    // rearranging the elements w.r.t pivot element
    for(int j = l ; j<=(r-1) ; j++)
    {
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j); 
        }
    }

    // placing the pivot element at its right position
    swap(arr, i+1, r);

    // returning index of pivot element
    return i+1;
}


void quickSort(int arr[], int l, int r)
{
    // base case
    if(l>=r) return;

    // doing partition w.r.t pivot element and taking the index of pivot element
    int pi = partition(arr, l, r);

    // applying same pivot placing for first half
    quickSort(arr, l, pi-1);

    // applying same pivot placing for second half
    quickSort(arr, pi+1, r);
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
    int arr[] = {21,6,10,12,15,18,3};
    int size = sizeof(arr)/sizeof(int);

    cout << "Before quick sort: " << endl;
    display(arr, size);

    quickSort(arr, 0, size-1);

    cout << "After quick sort: " << endl;
    display(arr, size);

    return 0;
}