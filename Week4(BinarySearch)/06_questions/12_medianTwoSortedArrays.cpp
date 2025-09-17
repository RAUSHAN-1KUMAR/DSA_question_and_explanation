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
Approach:
    1. brute force:-
        -- take both array into a third array of size(n+m), and then get the median

    2. Better approach:-
        -- we actually just need the mid elements, so why to store them in a third array, while iterating through the both array using the pointers we are gonna store the mid element (n+m)/2 into a single variable, so two variable in case of even size
    
    3. Optimal approach -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;


// better approach
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int n = nums1.size();
    int m = nums2.size();

    int i=0; // for nums1
    int j=0; // for nums2
    int n_m = n+m;// total size -> let say 10

    // incase of even size we will take index2 and index1 both, but incase of odd size, we will just consider the index2
    int index2 = n_m/2; //-> 5
    int index1 = index2-1; //-> 4

    int cnt = 0;// cnt refers to the overall index
    int index1El = -1;
    int index2El = -1;
    while(i<n && j<m)
    {
        if(nums1[i]<nums2[j])
        {
            if(cnt==index1) index1El = nums1[i];
            if(cnt==index2) index2El = nums1[i];
            cnt++;
            i++; 
        }
        else
        {
            if(cnt==index1) index1El = nums2[j];
            if(cnt==index2) index2El = nums2[j];
            cnt++;
            j++;
        }
    }

    while(i<n)
    {
        if(cnt==index1) index1El = nums1[i];
        if(cnt==index2) index2El = nums1[i];
        cnt++;
        i++; 
    }

    while(j<m)
    {
        if(cnt==index1) index1El = nums2[j];
        if(cnt==index2) index2El = nums2[j];
        cnt++;
        j++;
    }

    if(n_m%2 == 1){
        return index2El;
    }

    return (double)((double)(index1El+index2El))/2.0;
}


int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};

    cout << findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}

