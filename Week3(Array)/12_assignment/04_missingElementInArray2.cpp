/*
Question:- Find the missing elements from an array with dublicates, size of array is n and the elements of array lie b/w [1-n].
        -- What if more than one element is missing
*/


/*
Approach:- negative marking method
    - For this approach we are subtracting 1 before using elements of array as index.(not changing the elements of the array)
    - using negative marking method, one of the element will be remained posetive, this means that the index of that element is the missing element.(if you can't get it then dry run by taking the index of array from 1 and do not subtract 1 before using elements of array as index).
*/

#include<iostream>
#include<vector>
using namespace std;

void findMissing(int *a, int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        int index = abs(a[i]);
        if(a[index-1]>0){
            a[index-1] *= -1;
        }
    }

    for(int i = 0 ; i<n ; i++)
    {
        if(a[i]>0) cout << i+1 << " "; 
    }
}


int main()
{
    int n;
    int a[] = {1,3,3,3,4};
    n = sizeof(a)/sizeof(int);
    findMissing(a,n);

    return 0;
}