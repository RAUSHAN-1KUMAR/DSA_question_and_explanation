/*
we have to return the sum of all the subset of given array:

Example:-
    input: nums = [3,4,5];
    output: 3,4,5,7,8,9,12,0
    explanation: the subsets of given array is:
        {3} -> sum = 3
        {4} -> sum = 4
        {5} -> sum = 5
        {3,4} -> sum = 7
        {3,5} -> sum = 8
        {4,5} -> sum = 9
        {3,4,5} -> sum = 12
        { } -> sum = 0
*/

#include<iostream>
#include<vector>
using namespace std;

void subsetSum(vector<int> &nums, int i, int sum)
{
    //base case
    if(i==nums.size()){
        cout << sum << endl;
        return;
    }

    // solve one case
    subsetSum(nums, i+1, sum);//-> exclude

    sum += nums[i];
    subsetSum(nums, i+1, sum);//-> include
}

int main()
{
    vector<int>nums = {3,4,5};

    subsetSum(nums,0,0);

    return 0;
}