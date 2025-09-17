/* -> 26

Given an integer array 'nums' sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in 'nums'.
    
-- Consider the number of unique elements of 'nums' to be 'k', to get accepted, you need to do the following things:
    1. Change the array 'nums' such that the first 'k' elements of 'nums' contain the unique elements in the order they were present in 'nums' initially. The remaining elements of 'nums' are not important as well as the size of 'nums'.
    2. Return k.


Custom Judge:- The judge will test your solution with the following code.
    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct length

    int k = removeDuplicates(nums); // Calls your implementation

    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }
If all assertions pass, then your solution will be accepted.

 
Example 1:
    Input: nums = [1,1,2]
    Output: 2, nums = [1,2,_]
    Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively. It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
    Input: nums = [0,0,1,1,1,2,2,3,3,4]
    Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
    Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively. It does not matter what you leave beyond the returned k (hence they are underscores).
*/

/*
Approach:- two pointer approach
    -- taking two variable i=1 and j=0; i.e, j is the position of unique element
    -- ager nums[i] equal hota h nums[j] ke iska matlab dublicate h, i ko i++ kerdo.
    -- ager nums[i] equal nhi hota h nums[j] ke iska matlab we got an unique element then j ko j++ kerke nums[j] m nums[i] store kerdo.
    -- array arranged ho chuka h ab bas k ka value return kerna, k = j+1.
*/

#include<bits/stdc++.h>
using namespace std;

int removeDublicates(vector<int> &nums)
{
    int i = 1;
    int j = 0;

    while(i < nums.size())
    {
        if(nums[i] == nums[j]) ++i;
        else 
        {
            j++;
            nums[j]=nums[i];
            i++;
        }
    }

    return j+1;
}

int main()
{
    vector<int> vec = {0,0,1,1,1,2,2,3,3,4};

    int k = removeDublicates(vec);

    cout << k;

    return 0;
}

