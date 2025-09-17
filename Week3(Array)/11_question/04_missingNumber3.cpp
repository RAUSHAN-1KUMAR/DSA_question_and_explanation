/* -> 268
Given an array nums containing 'n' distinct numbers in the range [0,n], return the only number in the range that is missing from the array.

Example:-
    Input: nums = [3,0,1]
    Output: 2
    Explanation: As n = 3, so the elements in the array lie between [0,3] but 2 is not present in nums that's why 2 is the output number.
*/

/*
Approach:- using XOR operator
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int ans = 0;
    for(int i=0 ; i<=nums.size() ; i++)
    {
        if(i<nums.size()) ans = ans^nums[i];
        ans = ans^i;
    }

    return ans;
}

int main()
{
    vector<int> vec = {5,6,4,1,0,2};

    int num = missingNumber(vec);

    cout << "The missing number in your array is: " << num << endl;

    return 0;
}