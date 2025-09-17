/* -> 46

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
*/

/* 
Approach:- same as we did in [Week8 -> 02_backTracing(all permutation of string)]
    -- swapping 
*/

#include<iostream>
#include<vector>
using namespace std;

void permute_helper(vector<vector<int>>& ans, vector<int>& nums, int i)
{
    // base case
    if(i>=nums.size()){
        ans.push_back(nums);
        return;
    }


    for(int j=i ; j<nums.size(); j++)
    {
        swap(nums[i],nums[j]);
        permute_helper(ans, nums, i+1);
        swap(nums[i],nums[j]);//-> backtracking
    }
 
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;

    permute_helper(ans, nums, 0);

    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};
    
    vector<vector<int>> ans = permute(nums);

    for(vector<int> arr:ans)
    {
        for(int num:arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}