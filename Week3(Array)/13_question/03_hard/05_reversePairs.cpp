/* -> 493

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:
    - 0 <= i < j < nums.length and
    - nums[i] > 2 * nums[j].
 

Example 1:
    Input: nums = [1,3,2,3,1]
    Output: 2
    Explanation: The reverse pairs are:
        (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
        (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Example 2:
    Input: nums = [2,4,3,5,1]
    Output: 3
    Explanation: The reverse pairs are:
        (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
        (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
        (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

*/

/*
Approach:- mergeSort
    -- the approach that we did in previous question was full based on mergeSort, but now we need slight modification in logic because here the condtion is arr[i]>2*arr[j]
        -- so counting and merging will be now complete different step
*/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    
    int i=low;
    int j=mid+1;

    while (i<=mid && j<=high)
    {
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j<=high){
        temp.push_back(arr[j]);
        j++;
    }

    // transfering all elements from temporary to arr
    for(int i=low; i<=high ; i++){
        arr[i]=temp[i-low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int cnt = 0;
    for (int i = low; i <= mid; i++) {
        while (right <= high && arr[i]*1LL > 2*1LL*arr[right]) right++;
        cnt += (right - (mid + 1));
    }
    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt=0;
    
    if(low>=high) return cnt;

    int mid = (low + high)/2;
    cnt+=mergeSort(arr, low, mid);
    cnt+=mergeSort(arr, mid+1, high);

    // lets count the inversions before merging
    cnt+=countPairs(arr, low, mid, high);

    merge(arr, low, mid, high);

    return cnt;

}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size()-1);
}

int main()
{
    vector<int> a = {2,3,7,1,3,5};
    int cnt=reversePairs(a);
    cout << cnt << endl;
    return 0;
}