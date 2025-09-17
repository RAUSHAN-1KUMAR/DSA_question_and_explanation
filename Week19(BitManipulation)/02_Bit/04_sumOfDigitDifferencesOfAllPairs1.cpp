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
    -- 1. we can directly use 'n-mp[char]' to find the contribution of each char into our answer
    -- 2. we will use a 2D array to store the freq of each int at a perticular position: array[pos, freq]
*/

#include<bits/stdc++.h>
using namespace std;

long long sumDigitDifferences(vector<int>& nums)
{
    // this 2D array will store the freq of each num(0-9) for each position
    vector<vector<int>> cnts(9, vector<int>(10, 0));//(pos, freq_char)
    for(int num:nums){
        int i=0;// for each num, we are starting from position zero
        while(num!=0){
            cnts[i][num%10]++;
            i++;
            num/=10;
        }
    }

    // after calculating freq of each int, we will find our answer
    long long ans=0;
    for(int i=0 ; i<9 ; i++)// for each row/pos
    {
        // total size
        long long totalSize=nums.size();

        // for each freq/col, we are calculating its distribution to our answer
        for(int j=0 ; j<10 ; j++)
        {
            ans += cnts[i][j]*(totalSize-cnts[i][j]);
            totalSize-=cnts[i][j];
        }

    }

    return ans;
}

int main()
{
    vector<int> nums = {123, 456, 223};
    cout << sumDigitDifferences(nums) << endl;
    return 0;
}

