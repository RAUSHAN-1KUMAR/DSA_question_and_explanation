/* -> 485

Given a binary array nums, return the maximum number of consecutive 1's in the array.


Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
*/

/*
Appraoch:- two pointer
    -- jaisehi ek 1 mila, wanha se ek loop chala diye jabtak 1 milte gya aur count ko bhi +1 kerte gye aur jaise hi 0 mila loop terminated and if count is max then store it in countOnes aur next check whi se hoga janha se loop terminate hua kynki wanha tak to iterate ker chuke h consecutive 1s ke wajah se. 
*/

#include<iostream>
#include<vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) 
{
    int countOnes = 0;

    int j=0;
    while(j<nums.size())
    {
        if(nums[j]==1)
        {
            int i=j;
            int count = 0;
            while (i<nums.size() && nums[i]!=0)
            {
                count++;
                i++;
            }
            countOnes = max(countOnes,count);
            j=i+1;
        }
        else{
            j++;
        }
    }

    return countOnes;
}

int main()
{
    vector<int> nums = {1,1,0,1};

    cout << findMaxConsecutiveOnes(nums) << endl;

    return 0;
}