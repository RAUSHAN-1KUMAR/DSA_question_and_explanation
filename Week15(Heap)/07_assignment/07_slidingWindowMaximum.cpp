/* -> 239

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

/*
Appraoch:- We have already solve this questio in deque week
    -- Now we will solve it using Heap

TC:- O(nlogn)
SC:- O(n)
*/

#include<bits/stdc++.h>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> ans;

    priority_queue<pair<int,int>> pq;// element,index

    int i=0;
    int j=0;
    while(j<nums.size())
    {
        // lets push the element, index into heap
        pq.push({nums[j], j});

        // whenever size hits to k
        if(j-i+1 == k)
        {
            // first push the max for that k
            ans.push_back(pq.top().first);
            i++;

            // now whoever topIndex<i we have to pop that
            while(!pq.empty() && i>pq.top().second)
                pq.pop();
        }

        j++;
    }

    return ans;
}


int main()
{
    vector<int> nums = {3,1,-1,-3,5,3,6,7};  
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for(int num:ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


