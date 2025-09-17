/* -> 287

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
Approach:- sorting the given array and then checking nums[i]==nums[i+1].
   Catch:- loop will run till nums.size()-1

Note:- But we are modifying our array and time complexity will be O(nlogn).
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findDublicate(vector<int> &nums)
{
    sort(nums.begin(), nums.end());//T.C -> O(nlogn)

    for(int i = 0 ; i<nums.size()-1 ; i++){
        if(nums[i]==nums[i+1]) return nums[i];
    }
    return -1;
}

int main()
{
    vector<int> vec = {1,3,4,2,2};

    cout << findDublicate(vec);

    return 0;
}


