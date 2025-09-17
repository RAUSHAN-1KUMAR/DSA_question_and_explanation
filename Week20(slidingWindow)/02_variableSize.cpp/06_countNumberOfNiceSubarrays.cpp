/* 1248

Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 
Example 1:
    Input: nums = [1,1,2,1,1], k = 3
    Output: 2
    Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

Example 2:
    Input: nums = [2,4,6], k = 1
    Output: 0
    Explanation: There are no odd numbers in the array.

Example 3:
    Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
    Output: 16
*/

/*
Approach:- 
Approach1: two pointer, optimal
    1. whenever we get the window having k odd numbers then we will count the number of even numbers before the first odd in the window and even numbers on the right side of endWindow
    2. total nice subarray will be (leftEvenCount+1)*(rightEvenCount+1)
    3. now move the startWindow to next position after odd number and decrease the oddCount by 1
    4. repeat the process till endWindow reaches to end of array

Approach2: 
    -- first we will convert the odd number into 1 and even number into 0
    -- now the question is to find the number of subarrays having sum k
    -- we can use the same approach as in 05_binarySubarraysWithSum.cpp
*/

#include<bits/stdc++.h>
using namespace std;

// Approach1
int numberOfSubarrays(vector<int>& nums, int k)
{
    int n = nums.size();

    int startWindow=0;
    int endWindow=0;

    int oddCount=0;

    int count=0;

    while(endWindow<n)
    {
        if(nums[endWindow]%2!=0)
            oddCount++;

        while(oddCount==k)
        {
            // we have to count the number of even numbers
            int leftEvenCount=0;
            int rightEvenCount=0;

            //on left side count even numbers till first odd number
            while(startWindow<n && nums[startWindow]%2==0)
            {
                leftEvenCount++;
                startWindow++;
            }

            //on right side count even numbers till first odd number
            int tempEnd = endWindow+1;
            while(tempEnd<n && nums[tempEnd]%2==0)
            {
                rightEvenCount++;
                tempEnd++;
            }

            // total nice subarray will be (leftEvenCount+1)*(rightEvenCount+1)
            count += (leftEvenCount+1)*(rightEvenCount+1);

            // now move the startWindow to next position after odd number
            startWindow++;
            oddCount--;
        }

        endWindow++;
    }

    return count;
}


// Approach2
int numberOfSubarrays1(vector<int> & nums, int k)
{
    int n = nums.size();

    for(int i=0 ; i<n ; i++)
    {
        if(nums[i]%2!=0)
            nums[i] = 1;
        else
            nums[i] = 0;
    }

    int startWindow=0;
    int endWindow=0;

    int prefixSum=0;
    int count=0;

    unordered_map<int,int> mp; // to store the prefix sum and its frequency
    mp[0] = 1; // to handle the case when prefixSum itself is equal to k

    while(endWindow<n)
    {
        prefixSum += nums[endWindow];

        int rem = prefixSum - k;

        if(mp.find(rem)!=mp.end())
        {
            count += mp[rem];
        }

        mp[prefixSum]++;

        endWindow++;
    }

    return count;
}


int main()
{
    vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
    int k=2;
    cout << numberOfSubarrays(nums, k) << endl;
    return 0;
}