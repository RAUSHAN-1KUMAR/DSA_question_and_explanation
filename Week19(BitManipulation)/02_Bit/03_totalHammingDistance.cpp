/* -> 477 (good question)

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
    EX: 10 -> (1010)
        7  -> (0111)
        HD => 3

Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums.

 

Example 1:
    Input: nums = [4,14,2]
    Output: 6
    Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010 (just showing the four bits relevant in this case).
    The answer will be:
    HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6.

Example 2:
    Input: nums = [4,14,4]
    Output: 4
*/

/*
Approach:-
    1. Brute force:- run two nested loops and then find hamming distance for each pair
        TC:- O(n^2)*log31

    2. Better approach:- observation based
        -- formula:- (no. of set bit X no. of unset bit) for each pair and then add all
        -- for each bit position from right to left we are gonna count the no. of set and unset bits till 0th to 31th position

        TC:- O(31*n)
*/

#include<bits/stdc++.h>
using namespace std;

int totalHammingDistance(vector<int>& nums)
{
    int ans=0;
    for(int pos=0; pos<31; pos++)
    {
        int zeros=0;
        int ones=0;

        // for each position 'pos' we are gonna count zeros and ones for each element
        for(int &num:nums)
        {
            if(num&(1<<pos)){
                zeros++;
            }
            else{
                ones++;
            }
        }

        ans+=ones*zeros;
    }

    return ans;
}

int main()
{
    vector<int> nums = {4,14,2};
    cout << totalHammingDistance(nums) << endl;
    return 0;
}

