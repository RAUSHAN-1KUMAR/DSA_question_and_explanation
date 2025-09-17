/*
Exponential search or doubling search or galloping search or strajik search
 -- applied on sorted array

Example: 
    input: 3,4,5,6,11,13,14,15,56,70. find 13
    solution:
        1. linear search -> O(n)
        2. binary search -> O(logn)
        3. exponential search ?? -> discribed in notecopy (Exponential Search (also known as exponential binary search) is a search algorithm used to find the position of an element in a sorted array. It is particularly useful when the size of the array is unknown or infinite, such as in unbounded arrays or certain data streams.)
*/

#include<iostream>
using namespace std;

int binSearch(int a[], int start, int end, int x)
{
    while(start<=end)
    {
        int mid = (start+end)/2;

        if(a[mid]==x) return mid;
        else if(x>a[mid]) start = mid+1;
        else end = mid-1;
    }

    return -1;
}

int expSearch(int a[], int n, int x)
{
    if(a[0]==x) return 0;

    int i=1;
    while(i<n && a[i]<=x)
    {
        i *= 2;//-> i = i*2 OR i = i<<1;
    }

    return binSearch(a, i/2, min(i,n-1), x);
}

int main()
{
    int a[] = {3,4,5,6,11,13,14,15,56,70};
    int n = sizeof(a)/sizeof(a[0]);

    int x = 13;

    int answer = expSearch(a,n,x);

    cout << "At index " << answer << endl;

    return 0;
}