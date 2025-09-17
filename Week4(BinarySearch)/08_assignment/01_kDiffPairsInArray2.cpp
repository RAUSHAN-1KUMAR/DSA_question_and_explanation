/* -> 532

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array. 

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
    -> 0 <= i, j < nums.length
    -> i != j
    -> |nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.


Examples:
    Input: nums = [3,1,4,1,5], k = 2
    Output: 2
    Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).Although we have two 1s in the input, we should only return the number of unique pairs.

    Input: nums = [1,2,3,4,5], k = 1
    Output: 4
    Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

    Input: nums = [1,3,1,5,4], k = 0
    Output: 1
    Explanation: There is one 0-diff pair in the array, (1, 1).
*/

/*
Note:- kabhi bhi ager aese do sum ya subtract ka kuch find kerne ko bole to try to find:
    a = target+b
instead of finding 'target = a-b'
*/

/*
My Approach:- binary search
    -- first sort the given array(if sorting then we can use binary search?).

    We are given to find someting like this: a[j]-a[i] = k,
        So, Why we don't do like this, we are at element a[i] and is there any a[j](right side of a[i]), so that a[i]+k = a[j]

        (discribed properly in notecopy)

    -- we will use set of pair STL to avoid the same pair.

Time Complexity:- O(nlogn)
*/

#include<iostream>
#include<vector>
#include<set> 
#include<utility>
#include<algorithm>

using namespace std;

int binarySearch(vector<int> &nums, int start, int x)
{
    int end = nums.size()-1;

    while(start<=end)
    {
        int mid = (start+end)/2;
        
        if(nums[mid] == x) return mid;
        else if(x>nums[mid]) start = mid+1;
        else end = mid-1;
    }

    return -1;
}

int findPairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    set<pair<int,int>> ans;

    for(int i=0; i<nums.size() ; i++)
    {
        if(binarySearch(nums, i+1, nums[i]+k) != -1)
        {
            ans.insert({nums[i], nums[i]+k});
        }
    }

    return ans.size();
}

int main()
{
    vector<int> vec = {1,2,4,4,3,3,0,9,2,3};
    int k = 3;

    int result = findPairs(vec, k);

    cout << result << endl;

    return 0;
}