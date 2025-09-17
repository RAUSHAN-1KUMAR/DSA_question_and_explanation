/* -> GFG

You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note:
    - The array follows 0-based indexing.
    - The number of rows and columns in the array are denoted by n and m respectively.


Examples:
    Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
    Output: 2
    Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.

        
    Input: arr[][] = [[0,0], [1,1]]
    Output: 1
    Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.
    Input: arr[][] = [[0,0], [0,0]]
    Output: -1
    Explanation: No row contains any 1s, so the output is -1.
*/

/*
Approach:
    -- The question is that how we can apply BS on this question, because rows are in sorted way w.r.t no. of ones
    -- so why to think of applying BS on rows why not column??
    -- so yes, we are gonna apply BS on column, because it's said that each row is sorted

TC:- (nlogm)
*/

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x){
    int low=0;
    int high=n-1;

    int ans=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        
        if(arr[mid]>=x){
            ans = mid;
            high = mid-1;
        }
        else{
            low=mid+1;
        }
    }

    return ans;
}

// we can't optimise row traversal, but we can optimie column traversal
int rowWithMax1s(vector<vector<int>> &arr){
    int n=arr.size();
    int m=arr[0].size();

    int cnt_max=0;
    int index=-1;
    for(int i=0 ; i<n ; i++){
        int cnt_ones = m-lowerBound(arr[i],m,1);// for each row we are applying BS to find the first occurence of 1
        if(cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            index = i;
        }
    }

    return index;
}

int main()
{
    vector<vector<int>> arr = {
        {0,1,1,1}, 
        {0,0,1,1}, 
        {1,1,1,1}, 
        {0,0,0,0}
    };

    cout <<rowWithMax1s(arr);

    return 0;
}