/* -> 152

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:
    Input: nums = [2,3,-2,4]
    Output: 6
    Explanation: [2,3] has the largest product 6.

Example 2:
    Input: nums = [-2,0,-1]
    Output: 0
    Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

*/

/*
Approach:- observation + intuition based (prefix and suffix product)
    -- what can be the possible cases
        1. all +ve elements in array: product all
        2. even -ve, rest +ve: product all
        3. odd -ve, rest +ve: remove 1 -ve out of odd number of negatices will leave us with even number of negatices, hence the idea is to remove 1 negatice, so we now see which 1 negatice to remove, and on removal how is the array shaped
*/

#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &nums){
    int n = nums.size(); //size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= nums[i];
        suff *= nums[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    
    return ans;
}

int main()
{
    vector<int> nums= {2,3,-2,4};
    cout << maxProduct(nums) << endl;
    return 0;
}