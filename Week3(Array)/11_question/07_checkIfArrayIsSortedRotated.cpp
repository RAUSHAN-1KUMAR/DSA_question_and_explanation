/* -> 1752

Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

Example 1:
    Input: nums = [3,4,5,1,2]
    Output: true
    Explanation: [1,2,3,4,5] is the original sorted array.
    You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

    Input: nums = [2,1,3,4]
    Output: false
    Explanation: There is no sorted array once rotated that can make nums.
*/

/*
Approach:- pehle given array(nums) ko koi dusre array(check) m store krke sort kiye and then her ek rotation ko check kiye given array(nums) m

Note: TC -> O(n^2)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(vector<int> &nums)
{
    vector<int> check = nums;
    sort(check.begin(), check.end());
    int wrong = 0;

    for(int i = 0 ; i<nums.size() ; i++){
        for(int j = 0 ; j<nums.size() ; j++){
            if(check[j]==nums[(j+i)%nums.size()]){
                continue;
            }
            else{
                wrong++;
                break;
            }
        }
    }

    if(wrong == nums.size()) return false;
    else return true;
}

int main()
{
    vector <int> num = {3,4,2,1,5};

    if(check(num)) cout << "true";
    else cout << "false";

    return 0;
}



