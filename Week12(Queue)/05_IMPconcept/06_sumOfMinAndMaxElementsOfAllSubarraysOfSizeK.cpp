/* GFG
Given an array of both positive and negative integers, the task is to compute sum of minimum and maximum elements of all sub-array of size k.

Example:-
    Input: arr[] = {2,5,-1,7,-3,-1,-2}, k = 4
    Output: 18
    Explanation : Subarrays of size 4 are : 
     {2, 5, -1, 7},   min + max = -1 + 7 = 6
     {5, -1, 7, -3},  min + max = -3 + 7 = 4      
     {-1, 7, -3, -1}, min + max = -3 + 7 = 4
     {7, -3, -1, -2}, min + max = -3 + 7 = 4 
*/

/*
Approach:- 
1. using minHeap and maxHeap:
    - TC: O(nlogk), SC: O(2*k)

2. using a single multiSet: 
    - TC: O(nlogk), SC O(k)
    - using st.begin() and st.rbegin() to point the min and max element in set
    - remember these are pointer so we need -> (arrow operator) to access actual element

3. using deque: optimal approach 
    -- TC: O(n), SC: O(2*k)
    -- using two deque
    -- to find max in each subarray apply the same approach as we did int question-> maximum sliding window
    -- to find min in each subarray apply the same appraoch as to find max in each subarray, just a little change is required
*/

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

// using deque
long long sumOfMinMaxOfAllWindowOfSizeK(vector<int> &nums, int k) 
{
    int n = nums.size();
    deque<int> maxdq, mindq;

    long long ans=0LL;
    int i=0, j=0;
    while(j<n)
    {
        while(!maxdq.empty() && nums[maxdq.back()]<=nums[j])
            maxdq.pop_back();

        maxdq.push_back(j);

        while(!mindq.empty() && nums[mindq.back()]>=nums[j]) 
            mindq.pop_back();
            
        mindq.push_back(j);

        if(j-i+1==k){
            ans += (nums[maxdq.front()] + nums[mindq.front()]);
            i++;
        }

        while(!maxdq.empty() && maxdq.front()<i) maxdq.pop_front();
        while(!mindq.empty() && mindq.front()<i) mindq.pop_front();

        j++;
    }

    return ans;
    
}

int main()
{
    vector<int> v = {2,5,-1,7,-3,-1,-2};
    int k=4;

    cout << sumOfMinMaxOfAllWindowOfSizeK(v,k);

    return 0;
}

