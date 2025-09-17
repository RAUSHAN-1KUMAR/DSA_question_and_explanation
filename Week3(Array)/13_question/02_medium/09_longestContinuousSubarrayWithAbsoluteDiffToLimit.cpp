/* -> 1438

Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

 

Example 1:
Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.

Example 2:
Input: nums = [10,1,2,4,7,2], limit = 5
Output: 4 
Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.

Example 3:
Input: nums = [4,2,2,2,4,4,2,2], limit = 0
Output: 3
*/

/*
Time limit exceeded
    -- better appraoch, heap/queue
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int longestSubarray(vector<int>& nums, int limit)
{
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    int maxCount = 0;
    int count = 0;

    int i=0;
    for(int j=i ; j<nums.size() ; j++)
    {
        if(nums[j]>maxVal){
            maxVal = nums[j];
        }

        if(nums[j]<minVal){
            minVal = nums[j];
        }

        if(maxVal-minVal <= limit){
            count++;
        }
        else{
            maxCount = max(maxCount, count);
            count = 0;
            maxVal = INT_MIN;
            minVal = INT_MAX;
            i++;
            j = i-1;
        }
    }

    maxCount = max(maxCount, count);

    return maxCount;
}

int main()
{
    vector<int> nums = {8,2,4,7};
    int limit = 4;

    int ans = longestSubarray(nums, limit);

    cout << ans << endl;

    return 0;
}
