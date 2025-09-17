/* -> 1655

You are given an array of n integers, nums, where there are at most 50 unique values in the array. You are also given an array of m customer order quantities, quantity, where quantity[i] is the amount of integers the ith customer ordered. Determine if it is possible to distribute nums such that:
    - The ith customer gets exactly quantity[i] integers,
    - The integers the ith customer gets are all equal, and
    - Every customer is satisfied.
    - Return true if it is possible to distribute nums according to the above conditions.
 

Example 1:
Input: nums = [1,2,3,4], quantity = [2]
Output: false 
Explanation: The 0th customer cannot be given two different integers.

Example 2:
Input: nums = [1,2,3,3], quantity = [2]
Output: true
Explanation: The 0th customer is given [3,3]. The integers [1,2] are not used.

Example 3:
Input: nums = [1,1,2,2], quantity = [2,2]
Output: true
Explanation: The 0th customer is given [1,1], and the 1st customer is given [2,2].
*/

/*
Approach:- explained in notecopy
*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool canDistribute_helper(vector<int> &counts, vector<int> &quantity, int ithCustomer)
{
    // base case
    if(ithCustomer == quantity.size()) return true;

    for(int i=0 ; i<counts.size() ; i++)
    {
        // pehle check ker rh ki kya possible h, ager ha tabhi aage badho
        if(counts[i]>=quantity[ithCustomer])
        {
            counts[i]-=quantity[ithCustomer];
            if(canDistribute_helper(counts, quantity, ithCustomer+1))
            {
                return true;
            }
            counts[i] += quantity[ithCustomer];//-> backtracking
        }
    }

    return false;
}

bool canDistribute(vector<int>& nums, vector<int>& quantity) 
{
    // hashing of unique elements
    unordered_map<int,int> countMap;
    for(auto num:nums){
        countMap[num]++;
    }

    // storing the count of unique elements
    vector<int> counts;
    for(auto it:countMap){
        counts.push_back(it.second);
    }

    // sorting customer array in descending order to reduce the time complexity in case of false answer
    sort(quantity.rbegin(), quantity.rend());
 
    return canDistribute_helper(counts, quantity, 0);
}

int main()
{
    vector<int> nums = {1,2,3,3};
    vector<int> quantity = {2};

    if(canDistribute(nums,quantity)) cout << "True";
    else cout << "False";

    return 0;
}