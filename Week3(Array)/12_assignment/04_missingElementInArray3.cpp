/*
Question:- Find the missing elements from an array with dublicates, size of array is n and the elements of array lie b/w [1-n].
        -- What if more than one element is missing
*/


/*
Approach:- sorting + swapping method
    -- For this approach also we are subtracting 1 before using elements of array as index.(not changing the elements of the array)
    -- sorting in the sense, we are placing the element on there respective index (first dry run this by assuming array index from 1).
    -- if the index does not match with the element then that index is the missing element
    -- so where is the use of swapping, we will it in sorting the elements of array to its index.
*/

#include<iostream>
#include<vector>
using namespace std;

void findMissing(int *a, int n)
{
    int i = 0;

    while(i<n)
    {
        int index = a[i];
        if(a[i] != a[index-1])
        {
            swap(a[i], a[index-1]);
        }
        else
        {
            ++i;
        }
    }

    for(int i = 0; i<n ; i++)
    {
        if(a[i]!=(i+1)) cout << i+1 << " ";
    }
}


int main()
{
    int n;
    int a[] = {4,3,2,7,8,2,3,1};
    n = sizeof(a)/sizeof(int);
    findMissing(a,n);

    return 0;
}