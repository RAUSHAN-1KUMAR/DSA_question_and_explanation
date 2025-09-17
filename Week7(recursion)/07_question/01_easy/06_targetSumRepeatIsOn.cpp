/*
Given an array and a target, we have to return the total number of subset whose sum makes the target.

Note:- repeatition is on but element choosen to make sum must be continuous

Hint:- call back depends on the no. of elements in array.
*/

/*
Approach:- similar to coin change i.e., more than two call back(using for loop)
*/

#include<iostream>
#include<vector>
using namespace std;

int perfectSum(vector<int> &nums, int target,int j)
{
    // base case
    if(target==0) return 1;
    if(target<0) return 0;

    // solve one case
    int ans = 0;
    for(int i=j ; i<nums.size() ; i++)
    {
        ans = ans + perfectSum(nums, target-nums[i], i);
    }

    return ans;
}

int main()
{
    vector<int> nums = {2,3,4};
    int sum = 8;

    cout << perfectSum(nums, sum, 0) << endl;

    return 0;
}