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
Approach:- using map i.e., hashing
    -- hame kya rokna h-> ager koi element(nums[i]) starting element ke sath swap hua h to next element(nums[i+1 or +2]) jo starting se swap hone wala h, ager ye value(nums[i+1 or +2]) pehle swap ho chuka h to ab iss swap ko rokna h.
    -- matlab ager koi number kisi position se swap hua to wahi same value wala next number ussi position p swap nhi hon chahiye
    -- we are gonna avoid it using map STL
*/

#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

void permuteUnique_helper(vector<vector<int>>& ans, vector<int>& nums, int start)
{
    // base case
    if(start>=nums.size()){
        ans.push_back(nums);
        return;
    }

    unordered_map<int, bool> visited;//change1

    for(int i=start ; i<nums.size(); i++)
    {
        //change2
        if(visited.find(nums[i]) != visited.end()){
            continue;
        }
        visited[nums[i]] = true;

        swap(nums[start],nums[i]);
        permuteUnique_helper(ans, nums, start+1);
        swap(nums[start],nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> ans;

    permuteUnique_helper(ans, nums, 0);

    return ans;
}

int main()
{
    vector<int> nums = {1,1,2};
    
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