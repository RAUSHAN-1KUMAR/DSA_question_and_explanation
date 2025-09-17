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
My Approach:- two pointer approach + sliding window + sorting
    -- first sort the given array
    -- apply two pointer(i=0,j=1) i.e.,start with adjacent elements, if the difference is equal to k then store the answer and i++, j++(shifting of window), if the difference is greater then k then i++(shrinking of window), if the difference is less then k then j++(expansion of window).
    -- if in case i==j, we have to handle it seperately because it is asked in question..
but with only above steps we can't able to solve the problem because if the input: 1,1,1,1,1, the output will be 4, but answer must be for distinct pair i.e, output must be 1. So, to solve this problem we will use set_of_pair STL to look for the distinct incoming element.

Time Complexity:- O(nlogn) due to sorting
*/

#include<iostream>
#include<vector>
#include<set> 
#include<utility>
#include<algorithm>

using namespace std;

int findPairs(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());

    int count = 0;

    set<pair<int,int>> ans;//-> set stores unique values

    int i = 0;
    int j = 1;
    while(j<nums.size())
    {
        int diff = nums[j]-nums[i];

        if(diff == k){ //shifting of window
            ans.insert({nums[i], nums[j]});// array is sorted so no need to worry about (0,3) and (3,0).
            ++i,++j;
        }
        else if(diff > k){ //shrinking of window
            i++;
        }
        else{ //expansion of window
            j++;
        }

        // catch condition
        if(i==j) j++;
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