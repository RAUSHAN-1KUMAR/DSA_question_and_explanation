/* -> 268

Given an array nums containing 'n' distinct numbers in the range [0,n], return the only number in the range that is missing from the array.

Example:-
    Input: nums = [3,0,1]
    Output: 2
    Explanation: As n = 3, so the elements in the array lie between [0,3] but 2 is not present in nums that's why 2 is the output number.
*/

/*
Approach:- Brute force
    -- traversing a loop form '0 to nums.size()' and checking each value in nums using linear search but time complexity will be O(n^2)
*/

#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int size = nums.size();
    int num;
    int j;

    for(int i = 0 ; i<=size ; i++){
        for(j = 0 ; j<size ; j++)
        {
            if(nums[j]==i){
                break;
            }
        }
        if(j==(size)) num = i; // this is catch, the necessary condition.
    }

    return num;
}

int main()
{
    vector<int> vec = {5,2,0,4,3,6};

    int num = missingNumber(vec);

    cout << "The missing number in your array is: " << num << endl;

    return 0;
}