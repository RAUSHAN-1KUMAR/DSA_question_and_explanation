/*
Given an sorted array, it might be rotated or not rotated, find the minimum element in the given array having time complexity equals O(logn)

*/

/*
Appraoch: 
    1. Identify the sorted half, just like we did in search_in_rotated_sorted_array
    2. the sorted half may or may not have the answer, so pick up the sortest element of the indetified sorted half and then move search to another half
*/

#include<bits/stdc++.h>
using namespace std;



int findMin(vector<int> &nums)
{
    int low=0;
    int high=nums.size()-1;
    int ans = INT_MAX;

    while(low<=high)
    {
        int mid=(low+high)/2;

        // left part is sorted
        if(nums[low]<=nums[mid])
        {
            ans=min(ans, nums[low]);
            low=mid+1;
        }
        else // right part is sorted
        {
            ans=min(ans, nums[mid]);
            high=mid-1;
        }

    }

    return  ans;
}


int main()
{
    vector<int> v = {7,8,1,2,3,4,5,6};

    cout << findMin(v) << endl;
    
    return 0;
}