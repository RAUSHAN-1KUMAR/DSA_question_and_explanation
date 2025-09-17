/*
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.

 
Example 1:
    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [2,3]

Example 2:
    Input: nums = [1,1,2]
    Output: [1]

Example 3:
    Input: nums = [1]
    Output: []
*/

/*
Approach:- 
    -- applied negative marking method, and we are subtracting 1 before using the elements of the array as index.
    -- if nums[index-1] is already vesited i.e., nums[index-1]<0 then will will push that index
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) 
{
    vector<int> dublicates;
    for(int i = 0 ; i<nums.size() ; i++)
    {
        int index = abs(nums[i]);
        if(nums[index-1]<0) dublicates.push_back(index);
        else nums[index-1] *= -1;
    }
    return dublicates;
}

int main()
{
    vector<int> num = {4,3,2,7,8,2,3,1};

    vector<int> ans = findDuplicates(num);

    for(int i = 0; i<ans.size() ; i++)
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}