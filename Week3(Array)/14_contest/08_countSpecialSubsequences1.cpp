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
    -- we will follow the rule p*r = q*s and ultimately we will check p/q==s/r
    -- we will move our p,q and s w.r.t r which can move from (4 to (n-2))
    -- So r and s can be handled easily
        if r = x: then s=x+2 to n

        the only thing comes to handle p and q
    
    -- as r is moving forward at every step, so we can fix the position of q as just r-2 and then p will move from 0 to q-2 => it will ultimately include the all posible pair of q and p also

    TC-> O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

long long numberOfSubsequences(vector<int>& nums) 
{
    int n = nums.size();
    long ans = 0;

    // took map to store the p/q count, not index of vector
    unordered_map<double, int> p_q_cnt;

    // taking r as parent, and then q p s will move w.r.t it
    for (int r = 4; r < n - 2; ++r) 
    {
        int q = r - 2;// fixed q

        for (int p = 0; p <= q - 2; ++p)
        {
            double key = (1.0 * nums[p]) / nums[q];
            p_q_cnt[key]++;// store the current p/q
        }

        for (int s = r + 2; s < n; ++s)
        {
            double key = (1.0 * nums[s]) / nums[r];
            
            //p/q==s/r, so if we get s/r, increment ans to its freq
            ans += p_q_cnt[key];// freq[p/q]
        }
    }

    
    return ans;
}


// using gcd i.e., we are not computing p/q to its decimal form, we are finding is lowest p/q form and then store it in form of string("p-q")
long long gcd(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long numberOfSubsequences1(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;

    // key is string now
    unordered_map<string, int> p_q_string;

    for (int r = 4; r < n - 2; ++r)
    {
        int q = r - 2;

        for (int p = 0; p <= q - 2; ++p)
        {
            // Calculate GCD and generate the key
            int gcd_val = gcd(nums[p], nums[q]);

            string key = to_string(nums[p] / gcd_val) + "-" + to_string(nums[q] / gcd_val);

            p_q_string[key]++;
        }

        for (int s = r + 2; s < n; ++s)
        {
            // Calculate GCD and generate the key
            int gcd_val = gcd(nums[s], nums[r]);

            string key = to_string(nums[s] / gcd_val) + "-" + to_string(nums[r] / gcd_val);

            ans += p_q_string[key];
        }
    }

    return ans;
}


int main()
{
    vector<int> nums = {2, 2, 2, 2, 2, 2, 2};
    cout << numberOfSubsequences(nums) << endl;
    return 0;
}
