/* -> 215
Given an array, find the kth largest element in it
*/

/*
Appraoch:-
    1. use sort() and then find the answer -> O(nlogn)
    2. using heap -> O(1)
        i) using max heap will take extra of O(n) space
            -- create the max heap of whole vector, and then pop the heap k-t times and the req. answer will be the top element.
             
        ii) but min heap will take extra of O(k) space
            -- create the min heap of first k elements of given vector, this will contain the min element of first k elements at the top of heap but we don't need it, so for remaining element
                i) if the new element is greater than the top of pq then replace it with the top of the pq and then heapify it
                ii) if lesser, then don't do anything because we need largest element

            -- at last we will have the kth smallest element in the max heap, and the top of the heap will be our answer
*/

#include<bits/stdc++.h>
using namespace std;

int kthLargestElement(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int> > pq;

    // process first k elements
    for(int i=0 ; i<k ; i++)
    {
        int element = nums[i];
        pq.push(element);
    }

    // push the remaining element into the heap it is greater than the root
    for(int i=k ; i<nums.size() ; i++)
    {
        int element = nums[i];
        if(element>pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }

    int ans = pq.top();

    return ans;
}


int main()
{
    vector<int> nums = {3,7,4,5,6,8,9};
    int k = 4;

    cout << kthLargestElement(nums, k) << endl;

    return 0;
}


