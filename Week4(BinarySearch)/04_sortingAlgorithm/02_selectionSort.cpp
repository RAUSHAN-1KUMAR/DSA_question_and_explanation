// In selection sort:- find the minimum element in unsorted array and swap it with element at begining then at begining+1 then at begining+2 like that

// described in detail in notecopy

/*
Time Complexity:- For all case: o(n^2), because as we are finding minimum element then swaping it, it will always carried out regardless of the initial order of the elements.
*/

#include<bits/stdc++.h>
using namespace std;
 

void selectionSort(int arr[], int n)
{
    for(int i = 0 ; i<(n-1) ; i++)
    {
        int min = i;
        for(int j = i+1 ; j<n ; j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }

        // swapping the found minimum element with the first element of the unsorted array.
        swap(arr[min], arr[i]);
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

    cout << "Before selection sort: " << endl;
    display(arr, size);

    selectionSort(arr, size);

    cout << "After selection sort: " << endl;
    display(arr, size);
    return 0;
}