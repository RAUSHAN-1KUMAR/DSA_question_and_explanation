/* Lakshaay bhiyaa optimization

Previously we were declaring two array dynamically and deleting it on each finalMerge call. These operation of creating heap memory and deleting it are costly i.e., heavy to CPU. So, in this appraoch we will create a temp array in mainCall and then store aur answer in it.

Appraoch:- two pointer to merge the array into temp array

Note:- we are not using push_back() and pop_back() to put element in temp array because those operation is similar to dynamic operations
*/

#include<bits/stdc++.h>
using namespace std; 

void finalMerge(int arr[], vector<int>& temp, int s, int mid, int e)
{
    int i=s;//-> our first array starts at s
    int j=mid+1;//-> our second array starts at mid+1

    // comparing the array element and directly storing it into the temp vector
    int k=s;
    while(i<=mid && j<=e)
    {
        if(arr[i]<=arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }
        else{
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    // if first array is large
    while(i<=mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    // if sencond array is large
    while (j<=e)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }  

    // lets copy data of temp to arr:-> necessary
    while(s<=e)
    {
        arr[s] = temp[s];
        s++;
    }
}


void mergeSort(int arr[], vector<int> &temp, int s, int e)
{
    if(s>=e){
        return;
    }

    // breaking the array into two halves
    int mid = (s+e)/2;

    // (s->mid) tak ek half
    mergeSort(arr,temp,s,mid);

    // (mid+1->end) tak next half
    mergeSort(arr,temp,mid+1,e); 

    // merge the sorted halves
    finalMerge(arr,temp,s,mid,e);
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

    vector<int> temp (size,0);// already declared the size, so that we don't need to do pushback()
    mergeSort(arr, temp, 0, size-1);

    cout << "After merge sort: " << endl;
    display(arr, size);

    return 0;
}