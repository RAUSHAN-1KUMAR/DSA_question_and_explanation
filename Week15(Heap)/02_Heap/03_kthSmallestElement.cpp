/*
Given an array, find the kth smallest element in it
*/

/*
Appraoch:-
    1. use sort() and then find the answer -> O(nlogn)

    2. using heap: less than O(nlogn)
        i) using min heap will take extra of O(n) space
            -- create the min heap of whole vector, and then pop the heap k-1 times and the req answer will be the top element.
            
            TC:- O(nlogn + klogn) -> O(nlogn)

        ii) but max heap will take extra of O(k) space
            -- create the max heap of first k elements of given vector, this will contain the max element of first k elements at the top of heap but we don't need it, so for remaining element
                i) if the new element is less than the top of pq then pop the top of the pq and then push the new element
                ii) if greater, then don't do anything

            -- at last we will have the kth smallest element in the max heap, and the top of the heap will be our answer

            TC:- O(klogk + (n-k)*logk) -> O(n-k)logk => o(nlogk)

    3. one approach is there, using partitioning method of quick sort algorithm: AVG: O(n), Worst:O(n^2)
        -- take any pivot element and place it its correct position, such that the elements less than the PIVOT are shifted toward the left side of the PIVOT and greater ones are shifted toward the right side of the PIVOT.
        -- After that if PIVOT at index k(1-based indexing): then we can say that 
            i) it is the kth smallest elment -> for kth smallest element
            ii) (N-k)th largest element -> for (N-k)th largest element

        see this code -> next solution
*/

#include<bits/stdc++.h>
using namespace std;

// using second logic
int kthSmallestElement(vector<int> &nums, int k)
{
    priority_queue<int> pq;

    // process first k elements
    for(int i=0 ; i<k ; i++) //-> O(klogk)
    {
        int element = nums[i];
        pq.push(element);
    }

    // push the remaining element into the heap it is smaller than the root
    for(int i=k ; i<nums.size() ; i++)//->O((n-k)*logk)
    {
        int element = nums[i];
        if(element<pq.top())
        {
            pq.pop();// pehle pop
            pq.push(element);//then push
        }
    }

    int ans = pq.top();

    return ans;
}


int main()
{
    vector<int> nums = {3,7,4,5,6,8,9,10};
    int k = 4;

    cout << kthSmallestElement(nums, k) << endl;

    return 0;
}


