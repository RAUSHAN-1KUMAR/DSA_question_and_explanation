/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 
Example 1:
    Input: nums = [1,3,4,2,2]
    Output: 2

    Input: nums = [3,1,3,4,2]
    Output: 3

    Input: nums = [3,3,3,3,3]
    Output: 3
*/

/*
Approach:- Negative marking method.(thinking array element as index, as range of elements lei b/w [1-n])
    - So if we visited the same index more than once using the elements of the array then there is a duplicate number which is equal to that index
    - why we are calling this as negative marking method because we will make negative to the visited elements

Note:- But we are modifying our array
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findDublicate(vector<int> &nums)
{
    int ans = -1;

    for(int i = 0; i<nums.size();i++){
        int index = abs(nums[i]);// absolute function abs() is used to make the index positive

        // already visited
        if(nums[index]<0)
        {
            ans = index;
            break;
        }

        // visisted mark
        nums[index] *= -1;
    }

    return ans;
}

int main()
{
    vector<int> vec = {1,3,4,4,2};

    cout << findDublicate(vec);

    return 0;
}


