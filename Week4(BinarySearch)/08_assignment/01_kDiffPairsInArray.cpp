/* -> 532

Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
    -> 0 <= i, j < nums.length
    -> i != j
    -> |nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.


Examples:
    Input: nums = [3,1,4,1,5], k = 2
    Output: 2
    Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).Although we have two 1s in the input, we should only return the number of unique pairs.

    Input: nums = [1,2,3,4,5], k = 1
    Output: 4
    Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

    Input: nums = [1,3,1,5,4], k = 0
    Output: 1
    Explanation: There is one 0-diff pair in the array, (1, 1).
*/

/*
My Approach:- brute force
    -- using two nested for loop, i have iterated through each pair and if the difference is equal to the k then checking the pair is already taken or not using map(pair, int), if not then count++. and then marking the pair as well as its reverse pair exist by increment its value

Note:- time complexity will be very large due to nested loop + find_in_map
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;


int findPairs(vector<int> &nums, int k)
{
    map<pair<int,int>,int> mp;

    int count = 0;

    for(int i = 0; i<(nums.size()-1) ; i++)
    {
        for(int j = i+1 ; j<nums.size(); j++)
        {
            if(abs(nums[i]-nums[j])==k){
                auto it1 = mp.find({nums[i],nums[j]});
                auto it2 = mp.find({nums[j],nums[i]});

                if(it1 == mp.end() || it2 == mp.end()) count++;

                mp[{nums[i],nums[j]}]++;
                mp[{nums[j],nums[i]}]++;
            }
        }
    }

    return count;
}


int main()
{
    vector<int> vec = {1,2,0,4,5,3};
    int k = 1;

    int result = findPairs(vec, k);

    cout << result << endl;

    return 0;
}