/* -> 31

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
    - For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.


Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]
*/

/*
Appraoch:- full observation type
    1. Find the first dip form last:
        a[i]<a[i+1]

    2. find something > a[i], ahead of i, and then swap it but the smallest one so that you stay close.

    3. Now sort the elements from i to end or reverse the array from i to end.

    4. if at step 1, we don't get any dip then our given array is the last permutation. In that case return the array by reversing it
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums)
{
    int n = nums.size();

    // finding dip
    int index=-1;
    for(int i = n-2 ; i>=0 ; i--)
    {
        if(nums[i]<nums[i+1]){
            index = i;
            break;
        }
    }

    // if dip not found
    if(index==-1){
        reverse(nums.begin(), nums.end());
        return;
    }

    // if dip found, now found first greater no. than nums[index] form last
    for(int i = n-1 ; i>=index ; i--)
    {
        if(nums[i]>nums[index]){
            swap(nums[i],nums[index]);// swap them
            break;
        }
    }
    
    reverse(nums.begin()+index+1, nums.end());// reverse from index to last
}

int main()
{
    vector<int> nums = {1,2,3,4,6,7,5};

    nextPermutation(nums);

    for(auto i:nums)
    {
        cout << i << " ";
    }

    return 0;
}