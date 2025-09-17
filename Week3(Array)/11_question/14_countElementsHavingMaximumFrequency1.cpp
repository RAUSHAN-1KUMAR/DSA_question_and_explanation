/*
You are given an array 'nums' consisting of positive integers. Return the total frequencies of elements in 'nums' such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.


Example 1:
    Input: nums = [1,2,2,3,1,4]
    Output: 4
    Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.So the number of elements in the array with maximum frequency is 4.

Example 2:
    Input: nums = [1,2,3,4,5]
    Output: 5
    Explanation: All elements of the array have a frequency of 1 which is the maximum.So the number of elements in the array with maximum frequency is 5.
*/

/*
Approach:- hashtable but the use of map.
*/

#include<bits/stdc++.h>
using namespace std;

int maxFrequencyElements(vector<int>& nums) 
{
    int size = nums.size();

    //storing the count of occurence in map
    map<int, int>freq;
    for(int i = 0 ; i<size ; i++)
    {
        freq[nums[i]]++;
    }

    // finding maximum freq
    int maxFreq = 0;
    for(int i = 0; i<freq.size() ; i++)
    {
        if(freq[i]>maxFreq) maxFreq = freq[i];
    }

    // finding total elements having max Freq
    int totalMaxFreqElemets = 0;
    for(int i = 0 ; i<freq.size() ; i++)
    {
        if(freq[i]==maxFreq) totalMaxFreqElemets += freq[i];
    }

    return totalMaxFreqElemets;
}

int main()
{
    vector<int> nums = {1,2,2,1,4,5};

    int ans = maxFrequencyElements(nums);

    cout << ans;

    return 0;
}