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
Appraoch:- binary search
    1. Question type-> classical binary search + indexing bases. So, observation type
        -- if arr[mid]-mid <= k h iska matlab koi bhi missing nhi hua h to 
                                s=mid+1; 
        -- if arr[mid]-mid > k h iska matlab total missing element exceed ho gya h to ans iske under lie krega:
                                ans = mid; 
                                e = mid-1;
        -- last m return  ans+k, i.e., uss mid se +k wala element is the missing one
        -- but if last tak arr[mid]-mid <= k aya to, ager ye case hoga to isko alag se loop ke bahar handle ker lenge
                                if(k==-1){
                                    ans = arr[e]+jitna_baki_reh_gya_hai;
                                    rerurn ans;
                                }

Note:- one more appraoch of time O(logn) and O(n)
*/

#include<iostream>
#include<vector>
using namespace std;

int findKthPosition(vector<int>& arr, int k)
{
    int s = 0;
    int e = arr.size()-1;
    int ans = -1;

    while (s<=e)
    {
        int mid = (s+e)/2;

        int diff = arr[mid]-mid;

        // cout << diff << endl;

        if(diff <= k) 
            s = mid+1;
        else{
            ans = mid;
            e=mid-1;
        }
    }

    // catch condition
    if(ans == -1){
        int data = arr[e]-e-1;
        int kth = k-data;
        ans = arr[e]+kth;
        return ans;
    }    

    return ans+k;
}

int main()
{
    vector<int> arr = {2,3,4,7,11};
    int k = 5;

    int ans = findKthPosition(arr, k);

    cout << ans << endl;

    return 0;
}