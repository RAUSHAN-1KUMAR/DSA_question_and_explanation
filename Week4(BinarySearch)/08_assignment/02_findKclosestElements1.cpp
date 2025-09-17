/* -> 658

Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:
    1. |a - x| < |b - x|, or
    2. |a - x| == |b - x| and a < b
 

Examples
    Input: arr = [1,2,3,4,5], k = 4, x = 3
    Output: [1,2,3,4]

    Input: arr = [1,2,3,4,5], k = 4, x = -1
    Output: [1,2,3,4]
*/

/*
Approach:- two pointer
    -- l=0, and h=n-1, run the while loop till h-l>=k i.e., the size of the vector ans.
    -- if difference at l is greater than h then l++, if difference at h is greater than l or equal than h-- till h-l>k, this will lead to the k closest interger to x.
    -- return the vector from l to h.

Time complexity:- O(n-k)
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int l = 0, h = arr.size()-1;

    while(h-l >= k)
    { 
        if(x-arr[l] > arr[h]-x) l++;
        else h--;
    }

    return vector<int>(arr.begin()+l, arr.begin()+h+1);
}


int main()
{
    vector<int> vec = {1,2,3,4,5};
    
    vector<int> ans = findClosestElements(vec, 4, -1);

    for(auto it:ans){
        cout << it << " ";
    }

    return 0;
}

