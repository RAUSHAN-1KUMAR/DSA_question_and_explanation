/* -> 4

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 
Example 1:
    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000
    Explanation: merged array = [1,2,3] and median is 2.


Example 2:
    Input: nums1 = [1,2], nums2 = [3,4]
    Output: 2.50000
    Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

/*
Approach: Optimal solution(classic BS)
    -- let say total no. of elements (n+m) = n_m.
    -- We actually have to find half of n_m/2 which will contain some elements from nums1 and some from nums2, So the intuition lie here -> we have to take some elements from num1 and some from nums2 such that size = n_m/2. 
    -- So we will apply BS on size of one the given array and let say mid comes 2 then others will be taken from other array and we will verify that is this mid is valid or not, observe the code below
*/

#include<bits/stdc++.h>
using namespace std;


// better approach
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int n=nums1.size();
    int m=nums2.size();

    // becuase we always take minimum size array to apply BS
    if(n>m) return findMedianSortedArrays(nums2, nums1);

    int leftSize = (n+m+1)/2;// this is the first half size
    int n_m = n+m;// this is the total size

    int low=0, high=n;
    while(low<=high)
    {
        int mid1 = (low+high)/2; // first find the position from nums1
        int mid2 = leftSize-mid1;// and then position from nums2 

        // l1 and l2 are the elements till from nums1 and nums2 to form the left part of the full array
        // r1 and r2 are the size from nums1 and nums2 that not taken in left part => now they will be the start elements of right part
        int l1=INT_MIN; //l1 -> left from nums1
        int r1=INT_MAX; //r1 -> right from nums1 

        int l2=INT_MIN; //l2 -> left from nums2
        int r2=INT_MAX; //r2 -> right from nums2

        // assigning the values to l1,r1,l2,r2
        // out of bound check
        if(mid1-1>=0) l1 = nums1[mid1-1];
        if(mid1<n) r1 = nums1[mid1];

        if(mid2-1>=0) l2 = nums2[mid2-1];
        if(mid2<m) r2 = nums2[mid2];


        // now binary search movement
        if(l1<=r2 && l2<=r1)
        {
            if(n_m%2==1) return max(l1,l2);
            return (double)(max(l1,l2) + min(r1,r2))/2.0;
        }
        else if(l1>r2)
            high = mid1-1;
        else 
            low = mid1+1;
    }

    return 0;
}

int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}

