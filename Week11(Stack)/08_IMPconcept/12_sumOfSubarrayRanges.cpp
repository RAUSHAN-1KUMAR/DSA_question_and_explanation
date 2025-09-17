/* -> 2104
You are given an integer array nums. The 'range' of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:
    Input: nums = [1,2,3]
    Output: 4
    Explanation: The 6 subarrays of nums are the following:
    [1], range = largest - smallest = 1 - 1 = 0 
    [2], range = 2 - 2 = 0
    [3], range = 3 - 3 = 0
    [1,2], range = 2 - 1 = 1
    [2,3], range = 3 - 2 = 1
    [1,2,3], range = 3 - 1 = 2
    So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.


Example 2:
    Input: nums = [1,3,3]
    Output: 4
    Explanation: The 6 subarrays of nums are the following:
    [1], range = largest - smallest = 1 - 1 = 0
    [3], range = 3 - 3 = 0
    [3], range = 3 - 3 = 0
    [1,3], range = 3 - 1 = 2
    [3,3], range = 3 - 3 = 0
    [1,3,3], range = 3 - 1 = 2
    So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.


Example 3:
    Input: nums = [4,-2,-3,4,1]
    Output: 59
    Explanation: The sum of all subarray ranges of nums is 59.
*/

/*
Approach:-
    -- Question is similar to 'sum of subarray Minimums', there we found how many a element is minimum for the others, but here we will find for maximum and minimum both
*/

#include<bits/stdc++.h>
using namespace std;

void nextSmallest(vector<int> &nums, vector<int> &next)
{
    int n = nums.size();
    stack<int> st;

    for(int i=n-1 ; i>=0 ; i--)
    {
        while (!st.empty() && nums[st.top()]>=nums[i])
        {
            st.pop();
        }

        next[i] = st.empty() ? n : st.top();
        st.push(i);
    }
}

void prevSmallest(vector<int> &nums, vector<int> &prev)
{
    int n = nums.size();
    stack<int> st;

    for(int i=0 ; i<n ; i++)
    {
        while (!st.empty() && nums[st.top()]>nums[i])
        {
            st.pop();
        }

        prev[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}

void nextLargest(vector<int> &nums, vector<int> &next)
{
    int n = nums.size();
    stack<int> st;

    for(int i=n-1 ; i>=0 ; i--)
    {
        while (!st.empty() && nums[st.top()]<=nums[i])
        {
            st.pop();
        }

        next[i] = st.empty() ? n : st.top();
        st.push(i);
    }
}

void prevLargest(vector<int> &nums, vector<int> &prev)
{
    int n = nums.size();
    stack<int> st;

    for(int i=0 ; i<n ; i++)
    {
        while (!st.empty() && nums[st.top()]<nums[i])
        {
            st.pop();
        }

        prev[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
}

long long subArrayRanges(vector<int>& nums)
{
    int n = nums.size();
    vector<int> next(n);
    vector<int> prev(n);

    // first finding the sum of occurence of each element to be minimum for subarrays
    nextSmallest(nums, next);
    prevSmallest(nums, prev);

    long long minSum=0;
    for(int i=0 ; i<n ; i++)
    {
        int left = i - prev[i];
        int right = next[i] - i;
        minSum = minSum+(left*right*nums[i]);
    }

    // now finding the sum of occurence of each element to be maximum for subarrays
    nextLargest(nums, next);
    prevLargest(nums, prev);

    long long maxSum=0;
    for(int i=0 ; i<n ; i++)
    {
        int left = i - prev[i];
        int right = next[i] - i;
        maxSum = maxSum+(left*right*nums[i]);
    }

    // now returning their absolute diff sum
    return maxSum-minSum;
}

int main()
{
    vector<int> nums = {4,-2,-3,4,1};

    cout << subArrayRanges(nums) << endl;

    return 0;
}

