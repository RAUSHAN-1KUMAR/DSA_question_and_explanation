/*
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:
    Input: nums = [10,5,2,6], k = 100
    Output: 8
    Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
    Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
    Input: nums = [1,2,3], k = 0
    Output: 0
*/

/*
Approach:- Brute Force
    -- ran nested for loop and declared a variable(check) and for each turn, I am storing the multiplied value in it and checking is it less than k.
    -- for single element of array, I applied a if condition inside first for loop.

Note:- Time complexity will be O(n^2)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int count = 0;
    int check;

    for(int i = 0 ; i<(nums.size()) ; i++)
    {
        if(nums[i]<k) count++;
        
        check = nums[i];

        for(int j = i+1 ; j<nums.size() ; j++)
        {
            check = check*nums[j];
            if(check<k) count++;
            else break; // this break statement is compulsory otherwise check will become greater than INT_MAX
        }
    }

    return count;
}

int main()
{
    vector<int> num = {10,5,2,6};

    int output = numSubarrayProductLessThanK(num,100);

    cout << output << endl;

    return 0;
}
