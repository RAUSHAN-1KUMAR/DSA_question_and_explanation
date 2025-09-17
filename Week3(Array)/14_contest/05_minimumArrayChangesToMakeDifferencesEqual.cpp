/* -> 3224

You are given an integer array nums of size n where n is even, and an integer k.

You can perform some changes on the array, where in one change you can replace any element in the array with any integer in the range from 0 to k.

You need to perform some changes (possibly none) such that the final array satisfies the following condition:
    - There exists an integer X such that abs(a[i] - a[n - i - 1]) = X for all (0 <= i < n).

Return the minimum number of changes required to satisfy the above condition.

 

Example 1:
    Input: nums = [1,0,1,2,4,3], k = 4
    Output: 2
    Explanation: We can perform the following changes:
        Replace nums[1] by 2. The resulting array is nums = [1,2,1,2,4,3].
        Replace nums[3] by 3. The resulting array is nums = [1,2,1,3,4,3].
        The integer X will be 2.

Example 2:
    Input: nums = [0,1,2,3,3,6,5,4], k = 6
    Output: 2
    Explanation: We can perform the following operations:
        Replace nums[3] by 0. The resulting array is nums = [0,1,2,0,3,6,5,4].
        Replace nums[4] by 4. The resulting array is nums = [0,1,2,0,4,6,5,4].
        The integer X will be 4.
*/

/*
Approach:-
    -- In brute force, we can check for all possible diff which is present in given array
    -- but it will have time complexity of n*k, so can we reduce it-> yes.
    -- we have three cases for a diff:
        1. no changes required: 
            -- same as diff as i am looking for

        2. one changes required: (X 1)
            -- ??
            -- we will find the maximum possible diff of a pair: let say it is 4 then it means for this pair on one changes we can get diff 0,1,2,3,4 <= k. SO, we will mark for 0,1,2,3,4

        3. two changes required: (X 2)
            -- n/2 - no changes - one changes

        -- finally for a specific diff -> one chages + two changes

    -- So rather than finding for each diff of k, we are finding the maximum possible diff of each pair

    -- So now dikkat is that if a max. pos. diff for a k is let say 5 then so now we have to mark for all 0,1,2,3,4,5.-> using suffix sum

    -- end m, return minimum of changes
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<climits>
using namespace std;

int minChanges(vector<int>& nums, int k)
{
    int n = nums.size();

    // this map is for the count of the diff which is present in given array
    unordered_map<int, int> currDiffCount;

    // this vector is to mark all possible diff from maxDiff to 0
    vector<int> oneOp(k+1,0);

    // initializing the currDiffCount and oneOp
    for(int i=0 ; i<n/2 ; i++)
    {
        int diff = abs(nums[i] - nums[n-1-i]);
        currDiffCount[diff]++; //-> counted the diff which is present in array

        // now finding maxDiff of a pair on one changes
        int minEl = min(nums[i], nums[n-1-i]);
        int maxEl = max(nums[i], nums[n-1-i]);
        int maxPossibleDiff = max(k-minEl, maxEl-0);//-> got the maxPossDiff of a pair
        oneOp[maxPossibleDiff]++;//-> marking the maxPossDiff in vector oneOP
    }

    // now doing suffix sum to mark all 0 to maxPossDiff on one changes
    for(int maxPossibleDiff = k-1 ; maxPossibleDiff>=0 ; maxPossibleDiff--)
    {
        oneOp[maxPossibleDiff] += oneOp[maxPossibleDiff+1];
    }

    // now finding the answer w.r.t currDiffCount(i,e,. the diff which is present in array) not from 0 to k, 
    int ans = INT_MAX;
    for(auto each : currDiffCount)
    {
        // getting the data form currDiffCount
        int diff = each.first;
        int noChangesCount = each.second;

        // one chages required
        int oneChangesCount = oneOp[diff] - noChangesCount;

        // two changes required
        int two = n/2 - oneChangesCount - noChangesCount;

        // min of all changes for each diff in currDiffCount
        ans = min(ans, oneChangesCount + two*2);
    }

    return ans;
    
}

int main()
{
    // vector<int> nums = {1,0,0,1,0,1,1,0,0,0,1,1,1,1,0,0};
    // int k=1;

    vector<int> nums = {1,0,1,2,4,3};
    int k=4;

    cout << minChanges(nums, k) << endl;
    
    return 0;
}