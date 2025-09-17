/* -> 41

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

 
Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
*/

/* 
Question Type-> observation 

Approach:- brute force
    -- the answer will always lie within [1 to len(array)+1], because we are asked to find smallest.
    -- So our answer set belongs to 1 to len(arr)+1, so we will have a for loop from i=1 to i<=len(arr)+1 and for each value of i we will find it in our set STL, but for this first we have to insert all our data into SET.
    
but it has asked to solve it in O(n) time and uses O(1) space
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<climits>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    // inserting all the data into a set
    unordered_set<int> myset;
    for(int i=0 ; i<nums.size() ; i++)
    {
        myset.insert(nums[i]);
    }

    //searching for output answer
    for(int i=1; i<=nums.size()+1 ; i++)
    {
        if(myset.find(i) == myset.end()) return i;
    }

    return 0;
}

int main()
{
    vector<int> num = {1,2,6,5,8,3,4};

    cout << "The missing first smallest positive integer: " << firstMissingPositive(num) << endl;

    return 0;
}