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
Approach:- using set Data structure
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_set>
using namespace std;

int longestConsective(vector<int> &nums)
{
    int n = nums.size();

    // if no element is in nums
    if(n==0) return 0;

    // creating set of given data
    unordered_set<int> st;
    for(int i=0 ; i<n ; i++)
    {
        st.insert(nums[i]);
    }

    // finding longest consecutive sequence
    int longest = 1;
    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                cnt++;
                x++;
            }
            longest = max(longest, cnt);
        }
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