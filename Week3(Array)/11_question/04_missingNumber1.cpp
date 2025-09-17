/*-> 268
Given an array nums containing 'n' distinct numbers in the range [0,n], return the only number in the range that is missing from the array.

Example:-
    Input: nums = [3,0,1]
    Output: 2
    Explanation: As n = 3, so the elements in the array lie between [0,3] but 2 is not present in nums that's why 2 is the output number.
*/

/*
Best Approach:- [sum of all elments in actual array containing all elments] - [sum of given nums having missing element]

Time complexity will be O(n);
*/

#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int size = nums.size();
    int sum1=(size*(size+1))/2;// for actual array
    int sum2=0;// for given array

    for(int i = 0 ; i<size ; i++){
        sum2 += nums[i];
    }

    return sum1-sum2;

}

int main()
{
    vector<int> vec = {5,0,4,1,3,6};

    int num = missingNumber(vec);

    cout << "The missing number in your array is: " << num << endl;

    return 0;
}