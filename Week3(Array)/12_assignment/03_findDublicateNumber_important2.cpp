/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 
Example 1:
    Input: nums = [1,3,4,2,2]
    Output: 2

    Input: nums = [3,1,3,4,2]
    Output: 3

    Input: nums = [3,3,3,3,3]
    Output: 3
*/

/*
Approach:- We are sending the nums[0] value to the nums[nums[0]] but first we are checking that is nums[0]!=nums[nums[0]]

Note:- but we are modifying our array, to not modify we need to apply binary search.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findDublicate(vector<int> &nums)
{
    while(nums[0]!=nums[nums[0]]){
        swap(nums[0],nums[nums[0]]);
    }
    return nums[0];
}

int main()
{
    vector<int> vec = {1,3,4,2,2};

    cout << findDublicate(vec);

    return 0;
}


