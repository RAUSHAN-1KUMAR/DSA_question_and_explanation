/* -> 485

Given a binary array nums, return the maximum number of consecutive 1's in the array.


Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
*/

/*
Approach:- one pointer
    -- increment a count variable till i encounter 1, if i get 0 then store the max count on countOnes and count=0 to start with a fresh count for another consecutive 1s
*/

#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) 
{
    int countOnes = 0;
    int j=0;
    int count = 0;
    
    while (j<nums.size())
    {
        if(nums[j]==1) count++;
        else{
            countOnes = max(countOnes,count);
            count=0;
        }

        j++;
    }

    // if at last count is left by maximum than countOnes
    countOnes = max(countOnes,count);
    
    return countOnes;
}

int main()
{
    vector<int> nums = {1,1,0,1,1,1};

    cout << findMaxConsecutiveOnes(nums) << endl;

    return 0;
}