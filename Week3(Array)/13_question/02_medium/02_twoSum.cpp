/* -> 01

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.


Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/


/*
Note:- kabhi bhi ager aese do sum ka kuch find kerne ko bole to try to find:
    a = target-b
instead of finding 'target = a+b'
*/

/*
Apraoach:- hashing using map STL(hashing is done between element and it's index)
    -- hame bola gya h ki aesa do index find kro jiska corresponding element ka sum = target ho,
        let say a and b is the element: a+b = target, to ham apne map m 'a' ko push kerne se pehle ye find krengen ki kya koi aesa elment tha jisko 'b' = target-a ho jaye.

        so we will iterate through starting to end to form hashing of our given array but before every pushing to map we will check that ki kya target-nums[i] present h ya nhi, ager present h to uska index aur aur nums[i] ka index ko ans vector m push kerke break kerdo.

Note:- it's optimal solution will be without using map.
*/

/*
Time complexity of below code is O(n) if we use unordered_map but in worst case it will be O(n^2) and O(nlogn) if we use map.
*/


#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
    unordered_map<int,int> hashTable;
    vector<int> ans;

    for(int i=0 ; i<nums.size(); i++)
    {
        int findEle = target-nums[i];
        auto it = hashTable.find(findEle);

        if(it!=hashTable.end())
        {
            ans.push_back(it->second);
            ans.push_back(i);
            break;
        }
        
        hashTable[nums[i]] = i;
    }

    return ans;
}

int main()
{
    vector<int> nums = {3,3};

    vector<int> ans = twoSum(nums, 6);

    for(auto each:ans){
        cout << each << endl;
    }

    return 0;
}