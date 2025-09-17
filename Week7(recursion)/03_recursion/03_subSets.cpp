/* -> 78

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

*/

#include<iostream>
#include<vector>
using namespace std;

void subSequences(vector<int> &nums, int index, int n, vector<vector<int>
> &ans, vector<int> &temp)
{
    if(index==n){
        ans.push_back(temp);
        return;
    }

    subSequences(nums, index+1, n, ans, temp);

    temp.push_back(nums[index]);
    subSequences(nums, index+1, n, ans, temp);

    temp.pop_back();//-> because temp is passed a referance variable
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> ans;
    vector<int> temp;

    subSequences(nums,0,nums.size(), ans , temp);

    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};

    vector<vector<int>> ans = subsets(nums);

    for(auto eachString:ans){
        for(auto eachChar:eachString){
            cout << eachChar;
        }
        cout << "," << endl;
    }

    return 0;
}