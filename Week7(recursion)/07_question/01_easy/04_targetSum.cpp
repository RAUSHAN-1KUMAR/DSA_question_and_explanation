/*
Given an array and a target, if we can sum to the target using elements of array then return true otherwise false
*/

#include<iostream>
#include<vector>
using namespace std;

bool targetSum(vector<int> &nums, int &target, int i, int sum)
{
    // base case
    if(i==nums.size()){
        return (target==sum);
    }

    //exclude
    bool caseA = targetSum(nums, target, i+1, sum);

    //include
    sum += nums[i];
    bool caseB = targetSum(nums, target, i+1, sum);

    return caseA||caseB;

}

int main()
{
    vector<int> nums = {3,6,4,5};
    int target = 9;

    if(targetSum(nums, target, 0,0)) cout << "possible";
    else cout << "Not Possible";

    return 0;
}