/*
Given an array and a target, we have to return the total number of subset whose sum makes the target.
*/

#include<iostream>
#include<vector>
using namespace std;

int perfectSum(vector<int> &nums, int target, int i)
{
    // base case
    if(i>=nums.size() && target==0) return 1;
    if(i>=nums.size() && target!=0) return 0;


    //exclude
    int ans = 0;
    ans = ans + perfectSum(nums, target, i+1);

    //include
    ans = ans + perfectSum(nums, target-nums[i], i+1);

    return ans;
}

int main()
{
    vector<int> nums = {2,5,6,8,2,3};
    int sum = 8;

    cout << perfectSum(nums, sum, 0) << endl;

    return 0;
}
