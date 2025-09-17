/* -> 136

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 
Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/

/*
Approach:- using XOR
*/

#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int single = 0;
    for(auto each:nums){
        single ^= each;
    }

    return single;
}

int main()
{
    vector<int> nums = {1};

    cout << singleNumber(nums) << endl;

    return 0;
}