/* -> 1539

Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this array.

Could you solve this problem in less than O(n) complexity? 

Example 1:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

Example 2:
Input: arr = [1,2,3,4], k = 2
Output: 6
Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.
*/

/*
Appraoch:- BS
    -- finding two nearby index, in between our missing element lie.
    -- how to find:
        - with the help of difference i.e., nums[index]-index:
    -- after finding two nearby index(e and s), find the number:
                arr[e]+k-(arr[e]-(e+1));
                => e+k+1
*/

#include<iostream>
#include<vector>
using namespace std;

int findKthPosition(vector<int>& arr, int k)
{
    int s = 0;
    int e = arr.size()-1;

    while (s<=e)
    {
        int mid = (s+e)/2;

        int diff = arr[mid]-(mid+1);// total number of missing number at this mid index

        if(diff<k) 
            s = mid+1;
        else 
            e = mid-1;
    }
    
    return e+k+1;
}

int main()
{
    vector<int> arr = {12,15,23,25,35,66,78};
    int k = 57;

    int ans = findKthPosition(arr, k);

    cout << ans << endl;

    return 0;
}