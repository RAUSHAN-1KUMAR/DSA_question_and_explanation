/* -> 907

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.


Example 1:
    Input: arr = [3,1,2,4]
    Output: 17
    Explanation: 
    Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
    Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
    Sum is 17.

Example 2:
    Input: arr = [11,81,94,43,3]
    Output: 444
*/

/*
Approach:-
    -- hame actually find kerna h ki ek element kitne baar add hoga
    -- for each element, find next and prev smaller element index

TC:- O(5n)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmallerFun(vector<int> &arr)
{
    int n=arr.size();

    stack<int> st;
    vector<int> ans(n);

    for(int i=0 ; i<n ; i++)
    {
        while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();

        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    return ans;
}

vector<int> nextSmallerFun(vector<int> &arr)
{
    int n = arr.size();

    stack<int> st;
    vector<int> ans(n);

    for(int i=n-1 ; i>=0 ;  i--)
    {
        while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();

        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    return ans;
}

int sumSubarrayMins(vector<int>& arr)
{
    int n = arr.size();

    vector<int> prevSmaller = prevSmallerFun(arr);//-> O(2n)
    vector<int> nextSmaller = nextSmallerFun(arr);//-> O(2n)

    int total = 0;
    int mod = 1e9 + 7;
    for(int i=0 ; i<n ; i++)//-> O(n)
    {
        int left = i - prevSmaller[i];
        int right = nextSmaller[i] - i;

        total  = (total + (right*left*arr[i])%mod)%mod;
    }

    return total;
}

int main()
{
    vector<int> arr = {3,1,2,4};

    cout << sumSubarrayMins(arr) << endl;

    return 0;
}
