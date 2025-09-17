/* GFG

You are given 2 numbers (n , m); the task is to find n√m (nth root of m).
 

Example 1:
    Input: n = 2, m = 9
    Output: 3
    Explanation: 3^2 = 9


Example 2:
    Input: n = 3, m = 9
    Output: -1
    Explanation: 3rd root of 9 is not integer.
*/

/*
Approach:- same as we did in case of sqrtofNumber
    -- to find the exponential, we are gonna use a logn approach for that

Time Comp:- O(logm*logn), if we use fast exponential method, otherwise it will be O(logm*n)

Note:- we are trying to find the exponential so there will be overflow, so we will use the linear exponential method, Time Comp: O(logm*n)
*/

#include<bits/stdc++.h>
using namespace std;

int fun(int mid, int n, int m)
{
    long long ans = 1;
    for(int i=1 ; i<=n ; i++)
    {
        ans = ans*mid;

        // if by doing multiplication, ans exceeds the value m then no need for further multiplication, just return
        if(ans>m) return 2;
    }

    if(ans==m) return 1;

    return 0;
}


int NthRoot(int n, int m)
{
    int low=1;
    int high=m;

    while(low<=high)
    {
        int mid = (low+high)/2;

        int result = fun(mid,n, m);

        if(result==1) return mid;
        else if(result==0) low=mid+1;
        else high=mid-1;
    }

    return -1;
}

int main()
{
    int m=4096;
    int n=6;

    cout << NthRoot(n, m) << endl;

    return 0;
}