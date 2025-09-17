/*
Using static memory allocation

Concept:- Merge Sort follows the divide-and-conquer strategy to sort an array or list of elements. It divides the input array into two halves, recursively sorts the two halves, and then merges the sorted halves to produce a single sorted array.

Time Complexity:- In the case of merge sort, the average, best, and worst-case time complexities are all O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;

void finalMerge(int arr[], int l, int mid, int r)
{
    int n1 = mid-l+1;
    int n2 = r-mid;
    
    // creating array, so first copy the array element
    int a[n1];
    int b[n2];

    // copying the first half
    for(int i = 0 ; i<n1 ; i++)
    {
        a[i]=arr[l+i];
    }

    // copying the second half
    for(int i = 0 ; i<n2 ; i++)
    {
        b[i]=arr[mid+1+i];
    }

    // now modifying the original array
    int i=0;
    int j=0;
    int k=l;//-> catch
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }

    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }

    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l>=r) return;

    // finding the mid
    int mid = (l+r)/2;

    // mergeSort for the first half
    mergeSort(arr, l, mid);

    // mergeSort for the second half
    mergeSort(arr, mid+1, r);

    // Now merge the sorted halves
    finalMerge(arr, l, mid, r);
}

void measuringTC(int arr[], int n)
{
    clock_t start, end;
    double cpu_time;

    start = clock();
    mergeSort(arr, 0, n-1);
    end = clock();

    cpu_time = double(end-start)/CLOCKS_PER_SEC;

    cout << "Time taken: " << cpu_time << " ms"<< endl;
}

void display(int arr[], int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {21,6,10,12,11,10,15,18,3};
    int size = sizeof(arr)/sizeof(int);

    measuringTC(arr, size);

    cout << "after mergesort: " << endl;
    display(arr , size);

    return 0;
}