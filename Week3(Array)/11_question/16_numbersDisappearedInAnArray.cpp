/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 
Example 1:
    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [5,6]

Example 2:
    Input: nums = [1,1]
    Output: [2]
*/

/*
Approach:- applied the negative marking concept(same as question no. 4 in assignment questions)
    - For this approach we are subtracting 1 before using elements of array as index.(not changing the elements of the array)
    - using negative marking method, one of the element will be remained posetive, this means that the index of that element is the missing element.(if you can't get it then dry run by taking the index of array from 1 and do not subtract 1 before using elements of array as index).
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    int size = nums.size();
    vector<int> missingElements;

    // marking negative
    for(int i=0 ; i<size ;i++)
    {
        int index = abs(nums[i]);
        if(nums[index-1]>0) nums[index-1] *= -1;
    }

    // finding missing element
    for(int i=0 ; i<size ; i++)
    {
        if(nums[i]>0) missingElements.push_back(i+1);
    }

    return missingElements;
}

int main()
{
    vector<int> num = {4,3,2,7,8,2,3,1};

    vector<int> ans = findDisappearedNumbers(num);

    for(int i = 0 ; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}