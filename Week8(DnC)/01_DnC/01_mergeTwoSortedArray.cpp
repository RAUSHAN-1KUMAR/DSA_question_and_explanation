/*
We are given two sorted array, we have two merge them to form a single sorted array
*/

#include<iostream>
#include<vector>
using namespace std;

void mergeTwoSortedArray(int arr1[], int s1, int arr2[], int s2, int merge[], int s3)
{
    int i=0;
    int j=0;
    int k=0;
    while (i<s1 && j<s2)
    {
        if(arr1[i]<arr1[j]){
            merge[k]=arr1[i];
            i++;
            k++;
        }
        else{
            merge[k]=arr2[j];
            k++;
            j++;
        }
    }

    while(i<s1)
    {
        merge[k]=arr1[i];
        k++;
        i++;
    }

    while(j<s2)
    {
        merge[k]=arr2[j];
        k++;
        j++;
    }
}

int main()
{
    int arr1[] = {2,4,8};
    int s1 = sizeof(arr1)/sizeof(int);

    int arr2[] = {1,3,5,10};
    int s2 = sizeof(arr2)/sizeof(int);

    int merge[s1+s2];

    mergeTwoSortedArray(arr1, s1, arr2, s2, merge, s1+s2);



    for(auto i:merge)
    {
        cout << i << " ";
    }

    /*
    can you sort this if arr1 and arr2 is combined in one like this:
        arr ={2,4,8,1,3,5,10}, given index:0,2,6
    and we have asked to sort in arr itself.
    */
        

    return 0;
}