/* Q.no: 169

Given an array 'nums' of size n, return the majority element. 

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 
Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2

*/

/*
Approach:- Binary search
    -- sort the given array
    -- her unique elment ki first occurence aur last occurence nikal lo i.e., total occurence of each unique element and then check which one appears more than n/2 times.

    per isse behtar ek approach ye h ki, sort kerne ke baad jo middle element hoga wahi answer h. Kyunki answer m pucha h element appears more than > n/2 aur wo exist ker rha h. So, if any element appears more than n/2 then it is certain that it will cross the middle position of array,
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    return nums[(nums.size()-1)/2];
}

int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};

    cout << majorityElement(nums) << endl;

    return 0;
}

