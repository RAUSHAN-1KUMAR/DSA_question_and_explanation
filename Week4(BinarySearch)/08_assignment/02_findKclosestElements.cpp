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
Approach:- brute force
    -- storing the difference of each element to given_element(x) and that element in a vector of pair(int,int) i.e., making a pair of difference and respective element and storing it into a vector.
    -- sorting that vector using sort() i.e., in ascending order.
    -- storing the second element of each pair from that vector to other vector(ans) till k.
    -- sorting the vector ans using sort().
    -- return vector ans.

Time complexity:- O(nlogn) due to sort() function
*/

#include<iostream>
#include<vector>
#include<set> 
#include<utility>
#include<algorithm>

using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int n = arr.size();

    vector<pair<int,int>> pr;

    for(int i=0 ; i<n ; i++)
    {
        pr.push_back({abs(arr[i]-x),arr[i]});
    }

    sort(pr.begin(), pr.end());

    vector<int> ans;
    for(int i=0 ; i<k ; i++){
        ans.push_back(pr[i].second);
    }

    sort(ans.begin(), ans.end());

    return ans;
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