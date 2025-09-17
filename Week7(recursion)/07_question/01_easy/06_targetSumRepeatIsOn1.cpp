/*
Given an array and a target, we have to return the total number of subset whose sum makes the target.

Note:- repeatition is on but element choosen to make sum must be continuous

Hint:- call back depends on the no. of elements in array.
*/

/*
Appraoch:- similar to subSequence of string i.e., two time call back
*/

#include<iostream>
#include<vector>
using namespace std;

int perfectSum(vector<int> &nums, int sum, int i)
{
    // base case
    if(sum==0) return 1;
    if(i == nums.size() || sum<0) return 0;

    //exclude
    int ans = 0;
    ans = ans + perfectSum(nums, sum, i+1);

    //include
    ans = ans + perfectSum(nums,sum-nums[i],i);//-> change 'i' instead of 'i+1'

    return ans;
}

int main()
{
    vector<int> nums = {2,3,4};
    int sum = 8;

    cout << perfectSum(nums, sum, 0) << endl;

    return 0;
}