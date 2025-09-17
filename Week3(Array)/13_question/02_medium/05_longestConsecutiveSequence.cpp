/* -> 128

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 
Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/

/*
Approach:- sorting + observation

Note:- but in question it has asked to solve it in O(n) time.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
using namespace std;

int longestConsective(vector<int> &nums)
{
    if(nums.size()==0) return 0;

    sort(nums.begin(), nums.end());

    int longest = 1;
    int curr = 0;
    int lastSmaller = INT_MIN;
    for(int i=0 ; i<nums.size(); i++)
    {
        if(nums[i]-1==lastSmaller){
            curr += 1;
            lastSmaller = nums[i];
        }
        else if(nums[i]!=lastSmaller){
            curr = 1;
            lastSmaller = nums[i];
        }

        longest = max(longest, curr);
    }

    return longest;
}

int main()
{
    vector<int> nums = {100,4,200,1,3,2};

    int ans = longestConsective(nums);

    cout << ans << endl;

    return 0;
}