/* GFG

Given an array arr[] of size N where every element is in the range from 0 to n-1. Rearrange the given array so that the transformed array arrT[i] becomes arr[arr[i]].

NOTE: arr and arrT are both same variables, representing the array before and after transformation respectively.

Example 1:
    Input:
    N = 2
    arr[] = {1,0}
    Output: 0 1
    Explanation: 
    arr[arr[0]] = arr[1] = 0
    arr[arr[1]] = arr[0] = 1
    So, arrT becomes {0, 1}

Example 2:
    Input:
    N = 5
    arr[] = {4,0,2,1,3}
    Output: 3 4 2 0 1
    Explanation: 
    arr[arr[0]] = arr[4] = 3
    arr[arr[1]] = arr[0] = 4
    arr[arr[2]] = arr[2] = 2
    arr[arr[3]] = arr[1] = 0
    arr[arr[4]] = arr[3] = 1
    and so on
    So, arrT becomes {3, 4, 2, 0, 1}
*/

/*
Appraoch:
    -- the appraoch of swapping using addition operator, we are not swapping, we are just using that approach
         a <=> b
            1. a = a+b;
            2. b = a-b;
            3. a = a-b;

    -- so what we are doing is:-
        arr[i] = arr[i] + (arr[arr[i]]*arr.size());
*/

#include<iostream>
#include<vector>
using namespace std;

void arrange(vector<int> &nums)
{
    if(nums.size()<=1) return;

    int i=0;
    int j=1;
    int k = nums[i];// initializing k

    while (true)
    {
        if(j == nums.size()){
            j=0;
        }

        if(i==j) break;

        if(nums[j]==i && nums[j] >= 0)
        {
            nums[j]=k;
            k=i;
            i=j;

            // jo change kiye usko minus ker dengen
            if(nums[j] != 0) nums[j] = (-1)*nums[j];
            else nums[j] = (-1)*nums.size();

            cout << nums[j] << endl;
        }

        j++;
    }

    // ba jo minus kiye usko posetive bhi kerna h
    for(int i = 0 ; i<nums.size() ; i++)
    {
        if(nums[i] < 0)
        {
            nums[i] *= -1;
            if(nums[i]==nums.size()) nums[i]=0;
        }
    }
}


int main()
{
    vector<int> nums = {3,0,4,2,1};

    arrange(nums);

    for(int num:nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}