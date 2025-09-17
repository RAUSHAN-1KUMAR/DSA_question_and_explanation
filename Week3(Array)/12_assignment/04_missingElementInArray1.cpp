/*
Question:- Find the missing elements from an array with dublicates, size of array is n and the elements of array lie b/w [1-n].
        -- What if more than one element is missing
*/

/*
Approach:- I have applied three steps to solve this for time complexity < O(n^2)
        1. Find the dublicate element in the given array(nums).
        2. Subtract that dublicate number from the sum of elements of the given array(nums).
        3. Now substract that obtained sum from the sum of 1-n.

Note:- but this approach is only applicable if there is only one missing element
*/

#include<iostream>
#include<vector>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int size = nums.size();

    // sum of 1-n
    int totalSum = (size*(size+1))/2;

    // finding dublicateElement
    while(nums[0]!=nums[nums[0]]){
        swap(nums[0],nums[nums[0]]);
    }
    int dublicateElement = nums[0];

    // subtracting dublicate element
    int sum = 0;
    for(int i = 0; i<size ; i++){
        sum += nums[i];
    }
    sum = sum-dublicateElement;

    // returning the missing element
    return totalSum-sum;
}


int main()
{
    vector<int> vec = {1,3,5,3,4};

    int num = missingNumber(vec);

    cout << "The missing number in your array is: " << num << endl;

    return 0;
}