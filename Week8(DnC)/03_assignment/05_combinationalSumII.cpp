/* -> 40

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
 

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/

/*
Approach:- similar to combination sum I
    -- in combination sumI, we had given that all elements of candidates are distinct and we can use an element from candidates unlimited times but here:
        1. there may be dublicate elements in candidates
        2. each number in candidates may only be used once in the combination.
    -- the only common condition to combination sumI is that the solution set must not contain dublicate combinations.

How to proceed: sort + setSTL -> Memory limit exceeded
    -- sort the given array(to avoid the dublicate combination) and using setSTL(also to avoid same combination)
    -- So pehle her ek possible way m no. of elements in candidates jitna case ban rha tha ab jo element use ho gya h usko dubara use nhi ker sakte: ye chiz ham kaise kre
            -> jis ith index p value use hua next ab i+1 ke liye call kerdengen but iss case m bhi dubicate answer aa jayengen to last m ans ko set m insert ker dengen and then set se again ans m. but ye operation bhut heavy hoga CPU ke liye so TLE aa jayega so kya koi aur modification ker sakte h -> see next solution

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void combinationSum_helper(vector<int>& candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index)
{
    // base case
    if(target==0){
        ans.push_back(v);
        return;
    }
    if(target<0) return;

    // solve one case
    for(int i=index;i<candidates.size();i++)
    {
        v.push_back(candidates[i]);
        combinationSum_helper(candidates, target-candidates[i],v,ans,i+1);//-> change2 i.e., i+1 i.e., dubara se ussi element ko pick nhi ker sakte
        v.pop_back();
    }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());//-> change1

    vector<vector<int>> ans;
    vector<int> v;

    combinationSum_helper(candidates, target,v,ans,0);

    // change3(heavy operation)
    set<vector<int>> st;
    for(auto each:ans){
        st.insert(each);
    }
    ans.clear();
    for(auto each:st){
        ans.push_back(each);//-> only unique vectors
    }

    return ans;
}

int main()
{
    vector<int> nums = {2,5,2,1,2};
    int target = 5;

    vector<vector<int>> ans = combinationSum2(nums,target);

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

