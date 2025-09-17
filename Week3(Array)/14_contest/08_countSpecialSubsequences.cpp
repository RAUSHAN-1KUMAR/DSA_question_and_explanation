/* -> 3404

You are given an array nums consisting of positive integers.

A special subsequence is defined as a subsequence of length 4, represented by indices (p, q, r, s), where p < q < r < s. This subsequence must satisfy the following conditions:
    1. nums[p] * nums[r] == nums[q] * nums[s]

    2. There must be at least one element between each pair of indices. In other words, q - p > 1, r - q > 1 and s - r > 1.

Return the number of different special subsequences in nums.

 

Example 1:
    Input: nums = [1,2,3,4,3,6,1]
    Output: 1
    Explanation:
    There is one special subsequence in nums.
    (p, q, r, s) = (0, 2, 4, 6):
    This corresponds to elements (1, 3, 3, 1).
    nums[p] * nums[r] = nums[0] * nums[4] = 1 * 3 = 3
    nums[q] * nums[s] = nums[2] * nums[6] = 3 * 1 = 3

Example 2:
    Input: nums = [3,4,3,4,3,4,3,4]
    Output: 3
    Explanation:
    There are three special subsequences in nums.
    (p, q, r, s) = (0, 2, 4, 6):
    This corresponds to elements (3, 3, 3, 3).
    nums[p] * nums[r] = nums[0] * nums[4] = 3 * 3 = 9
    nums[q] * nums[s] = nums[2] * nums[6] = 3 * 3 = 9
    (p, q, r, s) = (1, 3, 5, 7):
    This corresponds to elements (4, 4, 4, 4).
    nums[p] * nums[r] = nums[1] * nums[5] = 4 * 4 = 16
    nums[q] * nums[s] = nums[3] * nums[7] = 4 * 4 = 16
    (p, q, r, s) = (0, 2, 5, 7):
    This corresponds to elements (3, 3, 4, 4).
    nums[p] * nums[r] = nums[0] * nums[5] = 3 * 4 = 12
    nums[q] * nums[s] = nums[2] * nums[7] = 3 * 4 = 12
*/

/*
Approach:
    -- brute force:
        1. we are asked to find p,q,r,s: p*r==q*s, why not to find p/q==s/r
        2. i stored all the possible index of p/q into map and then find s/r into that same map

        TC:- O(n^2) + O(n^2 X logn)
        SC:- O(n^2)

    -- better solution -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

long long numberOfSubsequences(vector<int>& nums)
{
    int n=nums.size();

    // first i stored all possible p/q and index q into vector
    unordered_map<double, vector<int>> p_q_value;// (p/q, qthIndex)  
    for(int p=0;p<=(n-7);p++){
        for(int q=p+2;q<=(n-5);q++){
            double divValue = (double)nums[p]/nums[q];
            p_q_value[divValue].push_back(q);
        }
    }   

    // sorted the indexes(q) so that we can apply BS on it
    for(auto it=p_q_value.begin(); it!=p_q_value.end(); it++){
        sort(it->second.begin(), it->second.end());
    }   

    // now taking all possible s/r and finding s/r in p_q map: s/r == p/q
    long long ans=0;
    for(int s=n-1 ; s>=6; s--){
        for(int r=s-2;r>=4;r--){
            double divValue = (double)nums[s]/nums[r];
            if(p_q_value.find(divValue)!=p_q_value.end())
            {
                int size = p_q_value[divValue].size();

                int q=r-2;// q should not be adjacent to r
                
                // applying BS to find in O(log(size))
                int lastIndex = lower_bound(p_q_value[divValue].begin(), p_q_value[divValue].end(), q+1)-p_q_value[divValue].begin();//q+1, so that we can find the index greater than q;

                if(lastIndex>=size){
                    ans+=size;
                }
                else{
                    ans+=lastIndex;
                } 
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 3, 3, 4};
    // cout << numberOfSubsequences(nums) << endl;

    int index = lower_bound(nums.begin(), nums.end(), 2)-nums.begin();
    cout << index << endl;

    return 0;
}
