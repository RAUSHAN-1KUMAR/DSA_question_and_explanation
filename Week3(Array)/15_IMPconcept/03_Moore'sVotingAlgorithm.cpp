/* -> 169

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:
    Input: nums = [3,2,3]
    Output: 3

Example 2:
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2
*/

/*
Optimal Approach:- Moore's Voting algorithm
    -- if it is occuring > n/2 times, then it will surely overpass all other elements
*/


#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums){
    int count=1;
    int ele=nums[0];
    int i=1;
    while(i<nums.size())
    {
        if(count==0){
            ele=nums[i];
        }

        if(nums[i]==ele){
            count++;
        }
        else{
            count--;
        }

        i++;
    }

    // now lets verify the answer
    for(int i=0 ; i<nums.size(); i++){
        if(nums[i]==ele) count++;
    }

    if(count > nums.size()/2) return ele;

    return -1;
}


int main()
{
    vector<int> nums={1,1,1,1,2,2,2};
    cout << majorityElement(nums) << endl;
    return 0;
}

