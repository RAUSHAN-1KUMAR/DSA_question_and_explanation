/* -> 53 (Week3 -> 12_question -> 03_hard)

Given an integer array nums, find the subarray with the largest sum, and return its sum.

 
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

/*
Appraoch:- DnC
    -- In each call we are dividing our array just like we did in merge sort, and then calculating eachcrossMidSum(maxOfMidSeLeftSum + maxOfMidSeRightSum) and then returning max of (eachcrossMidSum, leftCall, rightCall).
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxSumArrayHelper(vector<int> &v, int start, int end)
{
    // base case
    if(start==end) return v[start];

    int maxOfMidSeLeftSum = INT_MIN;//-> for maxOfMidSeLeftSum
    int maxOfMidSeRightSum = INT_MIN;//-> for maxOfMidSeRightSum
    
    int mid = start+(end-start)/2;
    
    // (head recursion)
    int midLeftCall = maxSumArrayHelper(v,start,mid);
    int midRightCall = maxSumArrayHelper(v,mid+1,end);

    // solve one case
    // calculating max cross border sum
    int midSeLeftSum = 0, midSeRightSum = 0;
    for(int i=mid ; i>=start ; i--){
        midSeLeftSum += v[i];
        if(midSeLeftSum > maxOfMidSeLeftSum) maxOfMidSeLeftSum = midSeLeftSum;
    }
    for(int i=mid+1 ; i<=end ; i++){
        midSeRightSum += v[i];
        if(midSeRightSum > maxOfMidSeRightSum) maxOfMidSeRightSum = midSeRightSum;
    }
    
    int crossBorderSum = maxOfMidSeLeftSum+maxOfMidSeRightSum;

    return max(midLeftCall, max(midRightCall, crossBorderSum));
}

int maxSubArray(vector<int> &nums)
{
    return maxSumArrayHelper(nums, 0, nums.size()-1);
}


int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int ans = maxSubArray(nums);

    cout << ans << endl;

    return 0;
} 