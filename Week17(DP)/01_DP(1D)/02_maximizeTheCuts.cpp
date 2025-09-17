/* Exploring all possible ways

GFG(already done in recursion week(Week7))

Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Note: if no segment can be cut then return 0.

Example 1:
Input: N = 4, x = 2, y = 1, z = 1
Output: 4
Explanation: Total length is 4, and the cut lengths are 2, 1 and 1.  We can make maximum 4 segments each of length 1.

Example 2:
Input: N = 5, x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can make two segments of lengths 3 and 2.
*/

/*
Approach:- DP
    1. Top-down (recursion + memoization)
    2. Bottom-up (iterative appraoch)
    3. space optimiation not possible
*/


#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// Top-Down approach
int solve(int n, int x, int y, int z, vector<int> &dp)
{
    //base case
    if(n==0) return 0;
    if(n<0) return INT_MIN;

    //Step3:
    if(dp[n]!=-1){
        return dp[n];
    }

    int option1 = 1 + solve(n-x,x,y,z, dp);// x len ka cut
    int option2 = 1 + solve(n-y,x,y,z, dp);// y len ka cut
    int option3 = 1 + solve(n-z,x,y,z, dp);// z len ka cut

    int finalAns = max(option1, max(option2,option3));

    //Step2: memoization
    dp[n] = finalAns;

    return finalAns;
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    // Step1: 
    vector<int> dp (n+1, -1);

    int ans = solve(n,x,y,z, dp);

    return ans<0 ? 0 : ans;
}


// bottom-up approach
int maximizeTheCuts1(int n, int x, int y, int z)
{
    // Step1: create dp array 
    vector<int> dp (n+1, INT_MIN);

    // Step2: initial value using the base case of dp array
    dp[0] = 0;

    // Step3: fill the remaining using recusive logic of top-down approach and index kha se kha tak ja rha h wo dhayan m rakhna h
    for(int cut = 1 ; cut<=n ; cut++)
    {
        int ans = INT_MIN;

        if(cut-x >= 0)
        {
            int ans1 = 1+dp[cut-x];
            ans = max(ans, ans1);
        }

        if(cut-y >= 0)
        {
            int ans1 = 1+dp[cut-y];
            ans = max(ans, ans1);
        }
        
        if(cut-z >= 0)
        {
            int ans1 = 1+dp[cut-z];
            ans = max(ans, ans1);
        }

        dp[cut] = ans;
    }

    return dp[n]<0 ? 0 : dp[n];
}

int main()
{
    cout << maximizeTheCuts(49,5,6,7) << endl;
    return 0;
}