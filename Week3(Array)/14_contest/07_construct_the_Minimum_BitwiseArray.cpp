
/* -> 3314

You are given an array nums consisting of n prime integers.

You need to construct an array ans of length n, such that, for each index i, the bitwise OR of ans[i] and (ans[i] + 1) is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

Additionally, you must minimize each value of ans[i] in the resulting array.

If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.

 

Example 1:
    Input: nums = [2,3,5,7]
    Output: [-1,1,4,3]
    Explanation:
    For i = 0, as there is no value for ans[0] that satisfies ans[0] OR (ans[0] + 1) = 2, so ans[0] = -1.
    For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 3 is 1, because 1 OR (1 + 1) = 3.
    For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 5 is 4, because 4 OR (4 + 1) = 5.
    For i = 3, the smallest ans[3] that satisfies ans[3] OR (ans[3] + 1) = 7 is 3, because 3 OR (3 + 1) = 7.

Example 2:
    Input: nums = [11,13,31]
    Output: [9,12,15]
    Explanation:
    For i = 0, the smallest ans[0] that satisfies ans[0] OR (ans[0] + 1) = 11 is 9, because 9 OR (9 + 1) = 11.
    For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 13 is 12, because 12 OR (12 + 1) = 13.
    For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 31 is 15, because 15 OR (15 + 1) = 31.
*/

/*
Appraoch:- Brute Force
    - for every value of nums[i], i will run a loop from 1 to nums[i] and then check which value satisfy the condition x|(x+1) = nums[i]

Better approch:- next solution
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> minBitwiseArray(vector<int> &nums)
{
    vector<int> ans;
    for(auto num:nums)
    {
        if(num==2){
            ans.push_back(-1);
            continue;
        }

        // for every num i am checking form 1 to num
        for(int j=1 ; j<num ; j++)
        {
            if((j|(j+1))==num)
            {
                ans.push_back(j);
                break;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2,3,5,7};

    vector<int> ans = minBitwiseArray(nums);

    for(int num:ans)
    {
        cout << num << " ";
    }

    return 0;
}