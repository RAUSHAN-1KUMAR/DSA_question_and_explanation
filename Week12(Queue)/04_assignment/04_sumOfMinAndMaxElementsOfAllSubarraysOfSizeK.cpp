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
1. using minHeap and maxHeap: SC O(2*k)

2. using a single multiSet: SC O(k)
    - using st.begin() and st.rbegin() to point the min and max element in set
    - remember these are pointer so we need -> (arrow operator) to access actual element

3. using deque: optimal approach 
    -- using two deque
    -- to find max in each subarray apply the same approach as we did int question-> maximum sliding window
    -- to find min in each subarray apply the same appraoch as to find max in each subarray, just a little change is required
*/

#include<iostream>
#include<deque>
#include<vector>
using namespace std;

// using deque
int sumOfMinMaxOfAllWindowOfSizeK(vector<int>& nums, int k)
{
    int ans = 0;
    deque<int> dqForMax, dqForMin;

    // first window
    for(int i=0 ; i<k ; i++)
    {
        int element = nums[i];

        // dqForMax
        while(!dqForMax.empty() && element >= nums[dqForMax.back()]){
            dqForMax.pop_back();
        }

        // dqForMin
        while (!dqForMin.empty() && element <= nums[dqForMin.back()])
        {
            dqForMin.pop_back();
        }
        
        dqForMax.push_back(i);
        dqForMin.push_back(i);
    }


    // remaining window
    for(int i=k ; i<nums.size() ; i++)
    {
        // max and min sum of current window
        ans += nums[dqForMax.front()] + nums[dqForMin.front()];

        // Removing for dqForMax
        if(!dqForMax.empty() && i-dqForMax.front() >= k){
            dqForMax.pop_front();
        }

        while(!dqForMax.empty() && nums[i] >= nums[dqForMax.back()]){
            dqForMax.pop_back();
        }

        // Removing for dqForMin
        if(!dqForMin.empty() && i-dqForMin.front() >= k){
            dqForMin.pop_front();
        }

        while (!dqForMin.empty() && nums[i] <= nums[dqForMin.back()])
        {
            dqForMin.pop_back();
        }
        
        // Addition for dqForMax and dqForMin
        dqForMax.push_back(i);
        dqForMin.push_back(i);

    }

    // last window ka answer
    ans += nums[dqForMax.front()] + nums[dqForMin.front()];

    return ans;
}

int main()
{
    vector<int> v = {2,5,-1,7,-3,-1,-2};
    int k=4;

    cout << sumOfMinMaxOfAllWindowOfSizeK(v,k);

    return 0;
}

