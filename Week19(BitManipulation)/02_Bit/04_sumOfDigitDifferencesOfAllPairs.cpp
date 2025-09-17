/* -> 3153

You are given an array nums consisting of positive integers where all integers have the same number of digits.

The digit difference between two integers is the count of different digits that are in the same position in the two integers.

Return the sum of the digit differences between all pairs of integers in nums.


Example 1:
    Input: nums = [13,23,12]
    Output: 4
    Explanation:
    We have the following:
    - The digit difference between 13 and 23 is 1.
    - The digit difference between 13 and 12 is 1.
    - The digit difference between 23 and 12 is 2.
    So the total sum of digit differences between all pairs of integers is 1 + 1 + 2 = 4.

Example 2:
    Input: nums = [10,10,10,10]
    Output: 0
    Explanation:
    All the integers in the array are the same. So the total sum of digit differences between all pairs of integers will be 0.

All integers in nums have the same number of digits.
*/

/*
Approach:-
    -- so this question will not be solved using 'bit manipulation', but we can apply the previous approach here i.e., one by one checking each position from right to left and counting unique characters, which can lead to our answer without finding each pair using nested loops

    TC:- (len(nums[0]*n)) = O(9*n)
    SC:- O(n)

    Better approach-> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

long long sumDigitDifferences(vector<int>& nums){
    int n=nums.size();
    
    // lets find the length of nums[i]
    int num=nums[0];
    int len = 0;
    while(num){
        len++;
        num/=10;
    }

    // now lets check for each position
    vector<int> copy=nums;
    long long ans=0;
    for(int i=0; i<len;i++)// running a loop for all position
    {
        // Step1: finding the freq of each integer 
        unordered_map<int,int> mp;
        
        for(int &num:copy)
        {
            mp[num%10]++;
            num/=10;// also updating the num so that next time next position will be determined
        }

        // catch case
        if(mp.size()<=1) continue;

        // Step2: calculating the possible count for current position
        auto it=mp.begin();
        long long dataCount=0;
        int prevCount=it->second;
        it++;
        while (it!=mp.end())
        {
            int currCount=it->second;

            dataCount += prevCount*currCount;
            prevCount += currCount;

            it++;
        }
        
        ans+=dataCount;
    }

    return ans;
}

int main()
{
    vector<int> nums = {12, 12, 12};
    cout << sumDigitDifferences(nums) << endl;
    return 0;
}