/* -> 268
Given an array nums containing 'n' distinct numbers in the range [0,n], return the only number in the range that is missing from the array.

Example:-
    Input: nums = [3,0,1]
    Output: 2
    Explanation: As n = 3, so the elements in the array lie between [0,3] but 2 is not present in nums that's why 2 is the output number.
*/

/*
Approach:- we will sort the given array and then we will run a loop and check the index of the array is equal to its corresponding elements of sorted array or not, if index is not equal to the its corresponding element then that index is the missing element.

Note:- Time complexity will be O(nlogn) due to sorting;
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    
    for(int i = 0 ; i<nums.size() ; i++){
        if(i==nums[i]) continue;
        else return i;
    }

    return nums.size();
}

int main()
{
    vector<int> vec = {5,0,4,1,3,2};

    int num = missingNumber(vec);

    cout << "The missing number in your array is: " << num << endl;

    return 0;
}