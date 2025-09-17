/*
Question:- Count subarrays where Max Element Appears at least k times.

You are given an integer array(nums) and a positive integer(k). Return the number of sub arrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 
Example 1:
    Input: nums = [1,3,2,3,3], k = 2
    Output: 6
    Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Example 2:
    Input: nums = [1,4,2,1], k = 3
    Output: 0
    Explanation: No subarray contains the element 4 at least 3 times.
*/

/*
Appraoch:- 
    -- sabse pehle ek for loop jo i=0 se n tak chala rha and then nested for loop j=i se n tak.
    -- to j wala loop i ke liye, j=i se n tak iterate ho rha h aur phir hamlog check ker the h nums[j]==max h, ager h to count++ aur ager count=k hota h iska matlab at least wala subarray uss j tak h aur uske baad wala her subarray at least k times to max element contain kerega hi issiliye jaisehi nums[j]==max hota h aur count=k hota h to ham ans = ans+nums.size()-j kerke aur break ker dete h next i ke liye.

Note:- 
    -- Time complexity -> O(n^2), which will exceed time limit if k is very large, So find another way.
    -- So another way to solve this problem is 'sliding Window concept'.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int countSubarrays(vector<int> &nums, int k)
{
    int ans = 0;

    //finding maximum element
    int max=nums[0];
    for(int i = 1; i<nums.size() ; i++)
    {
        if(nums[i]>max) max = nums[i];
    }

    //counting subarrays
    for(int i = 0 ; i<nums.size() ; i++)
    {
        int count = 0;

        for(int j = i ; j<nums.size() ; j++)
        {
            if(nums[j]==max)
            {
                count++;
                if(count=k)//jaisehi max count 'k' ke equal hua
                {
                    ans = ans + nums.size()-j;
                    break;
                }
            }
        }
    }

    return ans;
}


int main()
{
    vector<int> num = {28,5,58,91,24,91,53,9,48,85,16,70,91,91,47,91,61,4,54,61,49};

    int output = countSubarrays(num,2);

    cout << output << endl;

    return 0;
}