/* -> 1752

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

Example 1:
    Input: nums = [3,4,5,1,2]
    Output: true
    Explanation: [1,2,3,4,5] is the original sorted array.
    You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

    Input: nums = [2,1,3,4]
    Output: false
    Explanation: There is no sorted array once rotated that can make nums.
*/

/*
Approach:- we will check two condition which will satisfy our given condition for the given array
            1. if(nums[i-1]>nums[i]) that is, given array m kahin p aesa to nhi ki pehle wala element next element se bada h, aur ager aesa h to sahi h
            2. if(nums[n-1]>nums[0]) that is given array ka last element bada hua pehle element k to galat h.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;

    for(int i=1;i<n;i++)
    {
      if(nums[i-1] > nums[i]) cnt++;
    }
    
    if(nums[n-1] > nums[0]) cnt++;
    
    return (cnt <= 1);
}

int main()
{
    vector <int> num = {3,4,5,1,2};

    if(check(num)) cout << "true";
    else cout << "false";

    return 0;
}



