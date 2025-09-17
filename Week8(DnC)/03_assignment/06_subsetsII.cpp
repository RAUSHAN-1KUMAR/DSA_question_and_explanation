/* 90
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]
*/

/*
Appraoch->
    -- Again we have to remove the dublicates combination, So the main logic is same as we did in combination sum II i.e., we will sort the given array and then we will use backtracking to find all the possible subsets.
    -- the only difference is that in combination sum II we applied loop to find our solution but in this case we are apply include and exclude logic
*/

#include <bits/stdc++.h>
using namespace std;

void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &child, int i, int &n)
{
    if (i >= n)
    {
        ans.push_back(child);
        return;
    }

    // include
    child.push_back(nums[i]);
    helper(nums, ans, child, i + 1, n);
    child.pop_back();

    // exclude
    int c = i + 1;
    while (c < n && nums[i] == nums[c])
        c++;

    helper(nums, ans, child, c, n);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> child;
    int i = 0;

    helper(nums, ans, child, i, n);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(nums);
    for(vector<int> &arr : ans)
    {
        for(int num : arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}