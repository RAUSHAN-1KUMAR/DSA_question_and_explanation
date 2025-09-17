/* -> 283
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 
Example 1:
    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]

    Input: nums = [0]
    Output: [0]
*/

/*A
Appraoch:- two pointer
    -- ek pointer pure array m iterate krega, aur dusra pointer jaise hi pehle pointer ko non zero mila to usko swap kerne m,
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void moveZeroes(vector<int> &nums){

    int index = 0;
    int i=0;

    while(i<nums.size())
    {
        if(nums[i]!=0){
            swap(nums[index], nums[i]);
            index++;
            i++;
        }
        else{
            i++;
        }
    }

    // below code is also correct
    // int i = 0;
    // int j = 1;
    // int n = nums.size();
    // while(j<n){
    //     if(nums[i]!=0){
    //         i++;
    //     }
    //     if(nums[j]==0 || i==j){
    //         j++;
    //     }
    //     if(j==n){
    //         break;
    //     }
    //     if(nums[i]==0 && nums[j]!=0 && j>i){
    //         swap(nums[i],nums[j]);
    //         i++;
    //         j++;
    //     }
    // }
}

int main()
{
    vector<int> nums = {0,1,0,3,2};
    moveZeroes(nums);

    for(int i = 0 ; i<nums.size() ; i++){
        cout << nums[i] << " ";
    }

    return 0;
}