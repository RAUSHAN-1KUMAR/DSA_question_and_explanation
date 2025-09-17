/* 
In place merge sort is merge sort using O(1) space.
*/

/*
Approach1:- using swap and quick sort logic if pivot is first element

Approach2:- shell sort's gap method(includes swap and two pointer)
    -- gap(variable) = ceil((n+m)/2);
            n-> length of first array,
            m-> length of second array
    -- now we will swap our element taking gap(let gap=5) between two pointer i(let i=0) and j(i+gap=5):
        swap only if(a[i]>a[j])
    -- after one iteration of swapping i.e., after swapping done to last element, then now gap = ceil(gap/2);
    -- now apply the same step 2 for new gap and then after swapping now again gap=ceil(gap/2), i.e., we will apply step2 and step3 till gap become 1 but do compute the step2 for gap=1 then pause.


Note:- ceil((totalSize)/2) = (totalSize/2) + (totalSize%2);
    -- Still the time comp. is O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std; 

// applying 2nd approach
void mergeInPlace(vector<int> &arr, int start, int mid, int end)
{
    int total_len = end-start+1;
    int gap = total_len/2 + total_len%2;

    while (gap>0)
    {
        int i=start;
        int j=start+gap;
        while (j<=end)
        {
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
            i++;
            j++;
        }
        gap = gap<=1 ? 0 : (gap/2 + gap%2);
    }
}


void mergeSort(vector<int> &arr, int s, int e)
{
    if(s>=e){
        return;
    }

    // breaking the array into two halves
    int mid = (s+e)/2;

    // (s->mid) tak ek half
    mergeSort(arr,s,mid);

    // (mid+1->end) tak next half
    mergeSort(arr,mid+1,e); 

    // merge the sorted halves
    mergeInPlace(arr,s,mid,e);
}

void display(vector<int> &arr, int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {21,6,10,12,11,10,15,18,3};
    int size = arr.size();

    cout << "Before merge sort: " << endl;
    display(arr, size);

    mergeSort(arr, 0, size-1);

    cout << "After merge sort: " << endl;
    display(arr, size);

    return 0;
}

