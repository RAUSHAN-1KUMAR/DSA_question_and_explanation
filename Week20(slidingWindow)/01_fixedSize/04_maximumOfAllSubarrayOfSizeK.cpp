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

 1,3,-1,-3,-5,3,6,7

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/


#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    int startWindow=0;
    int endWindow=0;
    int windowSize = k;

    vector<int> ans;
    deque<int> dq;// index store krengen

    while (endWindow<nums.size())
    {
        while (!dq.empty() && nums[endWindow]>=nums[dq.back()]) dq.pop_back();
        dq.push_back(endWindow);

        if(endWindow-startWindow+1 == windowSize)
        {
            ans.push_back(nums[dq.front()]);

            int front = dq.front();
            startWindow++;
            if(front < startWindow) dq.pop_front();
        }

        endWindow++;
    }
    
    return ans;
}

int main()
{
    vector<int> nums = {1,3,1,2,0,5};
    int k=3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for(int num:ans)
    {
        cout << num << " ";
    }

    return 0;
}