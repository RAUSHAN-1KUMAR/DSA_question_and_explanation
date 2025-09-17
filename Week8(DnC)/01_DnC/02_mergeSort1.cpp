/*
Using dynamic memory allocation

Time Complexity:- In the case of merge sort, the average, best, and worst-case time complexities are all O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std; 

void finalMerge(int arr[], int s, int mid, int e)
{
    int lenLeft = mid-s+1;
    int lenRight = e-mid;

    // creating array dynamically, this is the only difference
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    // copying value from original array to leftArray;
    int k=s;
    for(int i= 0; i<lenLeft ; i++)
    {
        left[i]=arr[k];
        k++;
    }

    // copying value from original array to rightArray;
    k=mid+1;
    for(int i= 0; i<lenRight ; i++)
    {
        right[i]=arr[k];
        k++;
    }

    // now modifying the original array 
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;//-> catch
    while (leftIndex<lenLeft && rightIndex<lenRight)
    {
        if(left[leftIndex]<right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // if rightArray is left
    while (rightIndex<lenRight)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    // if leftArray is left
    while (leftIndex<lenLeft)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }

    // good practice (deallocation)
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int s, int e)
{
    if(s>=e){
        return;
    }

    // finding the mid
    int mid = (s+e)/2;

    // mergeSort for the first half
    mergeSort(arr,s,mid);

    // mergeSort for the second half
    mergeSort(arr,mid+1,e); 

    // Now merge the sorted halves
    finalMerge(arr,s,mid,e);
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

    cout << "Before merge sort: " << endl;
    display(arr, size);

    mergeSort(arr, 0, size-1);

    cout << "After merge sort: " << endl;
    display(arr, size);

    return 0;
}