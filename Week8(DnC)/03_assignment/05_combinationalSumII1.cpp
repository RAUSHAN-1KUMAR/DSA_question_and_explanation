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
Approach:- without STL

Note:- Kya ham ye ker sakte hai?? -> jo use ho gya h ussko koi value se change kerdo(INT_MIN), aur phir ussi ko pick krenge jo INT_MIN ki equal na ho.

TC-> O(2^n), 2^n because the depth of recursion is dependent on the number of candidates, and at each level we have two choices: either to include the candidate or not.
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
        // change2 i.e., ek baar koi element use ho gya hai to dubara uss value wale similar element ko use nhi ker sakte
        if(i>index && candidates[i]==candidates[i-1]){
            continue;
        }

        v.push_back(candidates[i]);
        combinationSum_helper(candidates, target-candidates[i],v,ans,i+1);
        v.pop_back();
    }

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> v;

    combinationSum_helper(candidates, target,v,ans,0);

    // change1
    
    // set<vector<int>> st;
    // for(auto each:ans){
    //     st.insert(each);
    // }
    // ans.clear();
    // for(auto each:st){
    //     ans.push_back(each);
    // }

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

