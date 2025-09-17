/* -> 41

Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.


Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.

Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.

Example 3:
Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
*/

/*
Approach:- negative marking approach
    -- previously we were using set to store data, but now we will use our own input array as extra memory but how??
    -- we can use our answer range i.e., [1 to len(arr)+1] as index in our original array, but before using the answer range as index we will subtract it with -1 then use it and then applly nagative marking approach.
    -- negative marking method(but array may contain negative number initially so will convert them into 0 at starting)

How we are solving this question:-
    -- ham sabse pehle jo negative number h given array m usko replace ker rhe h zero se,
    -- replace kerne ke baad, given array m iterate ker rhe h 0 se last tak aur negative marking apply ker rhe h. wo kaise,-> her index p jo value aa rha h uss index(value-1) p jake uske element ko negative ker rhe h only if it is not negative already. ager index p jo value h aur wo as index(value-1) overflow ker rhe h to usko leave kerdo.(overflow ker rhe matlab ki value-1 ya to negative ho ja rha ya array ke max length ke bahar chale ja rha)
    -- negative mark kerne ke baad, ab ham answer set m iterate ker rhe h aur her ek answer set ka value ko as a index(value-1) leke given array m check ker rhe ki kya uss index(value-1) p value negative h ya posetive h, ager posetive h iska matlab wo index(value-1) uss array m present nhi tha tabhi wo negative nhi hua h, iska matlab hamara answer-> index(value-1) + 1  hai.
    -- but but but, what if the value is 0 at index which coming to mark negetive on our given array in step 2, how can we convert it to negative number and also we must not change the value of given array, kyunki ager 0 ki jagah koi value de dete ho to phir uss value ke respective index(value-1) p phir wo negative mark ker dega but actual m to wo value wanha tha hi nhi, waanha to zero tha
            - to iss problem ko solve kerne ke liye hame janha bhi value 0 aa rha h wanha p -(len(arr)+1) store ker denge, kyunki jab wo is index(value-1) p jayega to out of bound ho jayega.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{
    // step1-> converting negative numbers to zero
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
            nums[i] = 0;
    }

    // step2-> negative marking
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);
        // checking the overflow of index
        if (index >= 1 && index <= nums.size())
        {
            if (nums[index - 1] > 0) 
                nums[index - 1] *= -1;
            else if (nums[index - 1] == 0)
                nums[index - 1] = -1 * (nums.size() + 1);
        }
    }

    // step2-> iterating through answer set
    for (int i = 1; i <= nums.size(); i++)
    {
        if (nums[i - 1] >= 0)
            return i;
    }

    // ager 1 se lekar size(arr) tak answer nhi mila matlab answer size+1 h.
    return nums.size() + 1;
}

int main()
{
    vector<int> num = {-5};

    cout << "The missing first smallest positive integer: " << firstMissingPositive(num) << endl;

    return 0;
}