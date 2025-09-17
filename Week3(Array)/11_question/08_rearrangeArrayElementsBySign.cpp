/*
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

1. Every consecutive pair of integers have opposite signs.
2. For all integers with the same sign, the order in which they were present in nums is preserved.
3. The rearranged array begins with a positive integer.
4. Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

Example 1:
    Input: nums = [3,1,-2,-5,2,-4]
    Output: [3,-2,1,-5,2,-4]
    Explanation:- The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4]. The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions


    Input: nums = [-1,1]
    Output: [1,-1]
    Explanation:- 1 is the only positive integer and -1 the only negative integer in nums.So nums is rearranged to [1,-1].
*/

/*
Approach:- stored the positive elements in an array(pos) and stored the negative elements in a other array(neg) and at last push one from posetive and one from negative to a different array.
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums) {
    vector<int> pos;
    vector<int> neg;

    for(int i = 0 ; i<nums.size() ; i++)
    {
        if(nums[i]>0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }

    nums.clear();

    for(int i = 0 ; i<pos.size() ; i++){
        nums.push_back(pos[i]);
        nums.push_back(neg[i]);
    }

    return nums;
}

int main()
{
    vector<int> num = {3,1,-2,-5,2,-4};
    vector<int> answer = rearrangeArray(num);

    for(int i = 0 ; i<answer.size() ; i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}
