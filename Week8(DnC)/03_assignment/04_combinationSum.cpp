/* -> 39

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 
Example 1:
    Input: candidates = [2,3,6,7], target = 7
    Output: [[2,2,3],[7]]
    Explanation:
    2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
    7 is a candidate, and 7 = 7.
    These are the only two combinations.

Example 2:
    Input: candidates = [2,3,5], target = 8
    Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
    Input: candidates = [2], target = 1
    Output: []

Given that all elements of candidates are distinct
*/


/*
Appraoch:-
    -- yese question, jisme bhut saare number diye gaye h aur hame target banana h usme se integer pick kerke ya pick nhi kerke:- 
        to aese question m ham pick and drop strategy use krengen means ya to usko pick krengen ya to pick nhi krengen i.e., we have to go through the all possiblities for each element, just like normal recursion(like coin change problem)

    -- for example:- [2,3,6,7] target=7,
        -> to ham simple jaise recursoin m kerte the ki her ek element ko leke explore kerenge i.e., 2 ke liye exlore krengen(and 2 ke liye her baar char possible ways hoga 2,3,6,7), then 3 ke liye(and 3 ke liye her baar teen possibel ways hoga 3,6,7), phir 6(possible ways 6,7 ) and then 7(possible way 7).

    but to reduce the time and space complexity we will do backtracking i.e., value sum kerte kerte ager sum target se greater ho gya to wapas aate waqt last sum ko sum mese minus kerdengen i.e., we will do pass by reference and for this we require backtracking 

Note:- Ham sum ko target tak leke jane ke jagah target ko minus kerte kerte 0 tak laye to??-> ye bhi ker sakte h to ham target ko zero tak layengen
    -- to iss case m hamare pass do base hoga
        1. target-> negative ho jaye
        2. target-> zero ho jaye

TC-> (2^target * n), 2^target because the depth of recusion is dependent on target, and n is the number of candidates we are exploring at each level.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void combinationSum_helper(vector<int>& candidates, int target, vector<int> &v, vector<vector<int>> &ans, int index)
{
    // base case
    if(target==0){
        ans.push_back(v);
        return;
    }
    if(target<0) return;

    // solve one case(jo index pass hus h ussi index se check kerna h naki her baar 0 index se, nhi to phir answer m dublicate combinations aa jayengen )
    for(int i=index ; i<candidates.size() ; i++)
    {
        v.push_back(candidates[i]);

        combinationSum_helper(candidates, target-candidates[i],v,ans,i);
        
        v.pop_back();//-> backtracking
    }

}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    vector<vector<int>> ans;
    vector<int> v;

    combinationSum_helper(candidates, target,v,ans,0);

    return ans;
}


int main()
{
    vector<int> nums = {2,3,6,7};
    int target = 7;

    vector<vector<int>> ans = combinationSum(nums,target);

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


