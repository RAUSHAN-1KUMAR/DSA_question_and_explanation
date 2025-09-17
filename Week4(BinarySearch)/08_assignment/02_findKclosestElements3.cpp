/* -> 658

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:
    1. |a - x| < |b - x|, or
    2. |a - x| == |b - x| and a < b
 

Examples
    Input: arr = [1,2,3,4,5], k = 4, x = 3
    Output: [1,2,3,4]

    Input: arr = [1,2,3,4,5], k = 4, x = -1
    Output: [1,2,3,4
*/

/*
Approach:- previously we did greatest lower bound, in this approch we will find smallest upper bound

Time complexity:- O(logn)

smallest upper bound:- a number which is <= a given number. If it is smaller, than maximum of smallest.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int smallestUpperBound(vector<int> &arr, int x)
{
    int start=0;
    int end = arr.size()-1;
    int ans = start;

    while(start<=end)
    {
        int mid = (start+end)/2;

        if(arr[mid]<x){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }

    return ans;
}

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    // finding upper bound
    int l = smallestUpperBound(arr,x);

    int h = l+1;

    while(k--){
        if(l<0) h++;// to maintain the overflow to the left
        else if(h >= arr.size()) l--;// to maintain the overflow to the right
        else if(x-arr[l] > arr[h]-x) h++;
        else l--;
    }

    return vector<int> (arr.begin()+l+1, arr.begin()+h);
}


int main()
{
    vector<int> vec = {11,12,13,19,20,29};
    
    vector<int> ans = findClosestElements(vec, 2, 18);

    for(int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }

    return 0;
}