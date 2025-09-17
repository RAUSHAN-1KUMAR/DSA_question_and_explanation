/* -> 47

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

/* 
Note:- now dublicate is present, and asked to return unique permutations

Approach:- using set STL
    -- same as we did in combination sum2
    but the time complexity will get high, so is there any better approach -> next solution
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

void permuteUnique_helper(vector<vector<int>>& ans, vector<int>& nums, int i)
{
    // base case
    if(i>=nums.size()){
        ans.push_back(nums);
        return;
    }


    for(int j=i ; j<nums.size(); j++)
    {
        swap(nums[i],nums[j]);
        permuteUnique_helper(ans, nums, i+1);
        swap(nums[i],nums[j]);//-> backtracking
    }
 
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;

    permuteUnique_helper(ans, nums, 0);

    // storing unique data
    set<vector<int>> st;
    for(auto each:ans){
        st.insert(each);// dublicates will get remove
    }
    ans.clear();
    for(auto each:st){
        ans.push_back(each);//-> only unique vectors
    }

    return ans;
}

int main()
{
    vector<int> nums = {1,2,3};
    
    vector<vector<int>> ans = permuteUnique(nums);

    for(vector<int> arr:ans)
    {
        for(int num:arr)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}