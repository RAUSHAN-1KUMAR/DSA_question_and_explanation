/* -> 3098

You are given an integer array nums of length n, and a positive integer k.

The power of a subsequence is defined as the minimum absolute difference between any two elements in the subsequence.

Return the sum of powers of all subsequences of nums which have length equal to k.

Since the answer may be large, return it modulo 10^9 + 7.

 

Example 1:
    Input: nums = [1,2,3,4], k = 3
    Output: 4
    Explanation: There are 4 subsequences in nums which have length 3: [1,2,3], [1,3,4], [1,2,4], and [2,3,4]. The sum of powers is |2 - 3| + |3 - 4| + |2 - 1| + |3 - 4| = 4.

Example 2:
    Input: nums = [2,2], k = 2
    Output: 0
    Explanation: The only subsequence in nums which has length 2 is [2,2]. The sum of powers is |2 - 2| = 0.

Example 3:
    Input: nums = [4,3,-1], k = 2
    Output: 10
    Explanation: There are 3 subsequences in nums which have length 2: [4,3], [4,-1], and [3,-1]. The sum of powers is |4 - 3| + |4 - (-1)| + |3 - (-1)| = 10.
*/

/*
Approach:
    1. first lets get a another approach to solve it in O(n^5) Time complexity:
        -- first we will calculate all posible absolute difference of our given array i.e., between any two elements ->seperate O(n^2)
        -- and then we will iterate to all this possible diff and then we will check how many subsequences having differece b/w every element >= that diff, of length k subsequence, but in sequence there must be at least one diff as d so that it can be used as power of that subsequence
            - >= signify that, the diff is minimum
        -- and we will also calculate our answer when we get the no. of possible subsequence for that diff, ans += count*diff

        Note: you have to look for -> these should be at least one diff as d. How we can figure it out:- using prev_count('d' will be superset of 'd-1')
            -> count = (count-prev_count)
            -- we will iterate reverse of set, or we can use set<int, greater<int>> st;

    2. optimisation to O(n^4)
        -- we can't optimise to find all possible diff, so it will be O(n^2), so we have to optimise our recursive function from O(n^3) to O(n^2)
        -- k, we can't becuase k will check the length, and index we can't because it is used to iterate over the arra, so lets come to prev index
        -- last taken as used to compute the nums[index]-nums[prev_index] and then we are deciding that we can take that index or not
        -- so when we choose our include index, we directly send our index to correct possible value instead of sending index+1
*/

#include<bits/stdc++.h>
using namespace std;

// recursive solution-> O(n^5)
int helper(vector<int> &nums, int index, int prev, int k, int &d)
{
    if(index==nums.size()) return (k==0);

    // exclude
    int ans = helper(nums, index+1, prev, k, d);

    // include
    if(prev==-1 || nums[index]-nums[prev]>=d){
        ans += helper(nums, index+1, index, k-1, d);
    }

    return ans;
}

int sumOfPowers(vector<int>& nums, int k)
{
    int n=nums.size();

    // lets find all possible unique diff
    set<int, greater<int>> st;// to store in descending order
    for(int i=0 ; i<n ; i++){
        for(int j=i+1;j<n ; j++){
            int diff = abs(nums[i]-nums[j]);
            st.insert(diff);
        }
    }

    sort(nums.begin(), nums.end());

    // now lets call for each diff
    int ans=0;
    int prev_cnt=0;
    for(int d:st)
    {
        // so we are counting all subsequence of length k, having diff>=d
        int count = helper(nums, 0, -1, k, d);
        ans += (count-prev_cnt)*d;
        prev_cnt = count;
    }

    return ans;
}


// recursive solution-> O(n^4)
int helper1(vector<int> &nums, int index, int prev, int k, int &d)
{

}

int sumOfPowers1(vector<int>& nums, int k)
{

}


int main()
{
    vector<int> nums={4,3,-1};
    int k=2;
    cout << sumOfPowers(nums, k) << endl;
    return 0;
}

