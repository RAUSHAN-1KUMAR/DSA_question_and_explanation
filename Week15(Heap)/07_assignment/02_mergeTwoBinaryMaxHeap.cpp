/* -> GFG

Given two binary max heaps as arrays, merge the given heaps to form a new max heap.

Input: n = 4, m = 3, a[] = {10, 5, 6, 2}, b[] = {12, 7, 9}
Output: {12, 10, 9, 2, 5, 7, 6}
*/


/*
Approach:-
    Approach1:- merge both heap vectors and then heapify(top-down) them from the last.

    Approach:- choose any of the heap vector and then push the elements from another vector into it, also took the pushed element into its right position i.e., heapification from bottom-up
*/

#include<bits/stdc++.h>
using namespace std;

// applying approach 1
void heapify(vector<int> &v, int i, int n)
{
    while(true)
    {
        int left=2*i+1;
        int right=2*i+2;

        int swapIndex=i;

        if(left<n && v[left]>v[swapIndex])
            swapIndex=left;
        if(right<n && v[right]>v[swapIndex])
            swapIndex=right;

        if(swapIndex==i)
            break;
        
        swap(v[i],v[swapIndex]);
        i=swapIndex;
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // merge vectors
    vector<int> c(a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    // heapify vector c
    for(int i=(c.size()/2)-1 ; i>=0 ; i--)
    {
        heapify(c, i, c.size());
    }

    return c;
}

int main()
{
    vector<int> a = {10,5,6,2};
    vector<int> b = {12,7,9};

    int n=a.size();
    int m=b.size();

    vector<int> ans = mergeHeaps(a, b, n, m);

    for(auto num:ans)
    {
        cout << num << " ";
    }

    return 0;
}

