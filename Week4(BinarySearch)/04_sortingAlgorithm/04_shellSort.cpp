/*
Shell Sort is an in-place comparison-based sorting algorithm that generalizes Insertion Sort by allowing comparisons and exchanges of elements that are far apart. The idea is to reduce the gap between elements being compared gradually until it becomes 1 (which makes it similar to Insertion Sort, but more efficient for large data sets).

How Shell Sort Works:
    1. Start with a large gap and reduce it by a factor (usually 2 or 2.2) in each iteration.

    2. For each gap, perform a gapped insertion sort – compare and shift elements that are gap positions apart.

    3. Continue until gap = 1, at which point the array is nearly sorted, and Insertion Sort completes it efficiently.
*/

#include<bits/stdc++.h>
using namespace std;

void shellSort(vector<int> &nums)
{
    int n=nums.size();

    // start with a big gap
    for(int gap=n/2 ; gap>=1 ; gap/=2)
    {
        for(int j=gap; j<n ; j++)
        {
            for(int i=j-gap;i>=0 ; i-gap)
            {
                if(nums[i+gap]>nums[i]){
                    break;
                }
                else{
                    swap(nums[i+gap], nums[i]);
                }
            }
        }
    }
}

int main()
{
    vector<int> nums = {12,34,54,2,3};
    shellSort(nums);
    for(int num:nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}