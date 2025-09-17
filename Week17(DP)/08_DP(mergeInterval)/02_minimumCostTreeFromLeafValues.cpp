/* -> 1130

Given an array arr of positive integers, consider all binary trees such that:
    1. Each node has either 0 or 2 children;

    2. The values of arr correspond to the values of each leaf in an in-order traversal of the tree.

    3. The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.

Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.

A node is a leaf if and only if it has zero children.


Example 1:
    Input: arr = [6,2,4]
    Output: 32
    Explanation: There are two possible trees.
    The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

Example 2:
Input: arr = [4,11]
Output: 44
*/


/* --> explained in note copy
Approach: DP , same as we did in Question guessNumberHigherOrLowerII bas thoda sa return max and min of calls me change
    0. recursive approach
    1. top-down approach
    2. bottom-up appproach
    4. space optimization -> not possible
*/

#include<bits/stdc++.h>
using namespace std;


// recursive approach
int solveUsingRecursion(vector<int>&arr, map<pair<int,int>, int> &maxi, int start, int end)
{
    // base case
    if(start>=end) return 0;

    int ans = INT_MAX;

    // i is used for partitioning
    for(int i=start ; i<end ; i++)
    {
        int leftCall = solveUsingRecursion(arr, maxi, start, i);
        int rightCall = solveUsingRecursion(arr, maxi, i+1, end);

        int currentLeafNodeValue = maxi[{start,i}] * maxi[{i+1,end}] + leftCall + rightCall;

        ans = min(ans, currentLeafNodeValue);
    }

    return ans;
}

int mctFromLeafValues(vector<int>& arr) 
{
    // pre computation of maxLeafNode for every possible pair of index
    map<pair<int,int>, int> maxi;
    for(int i=0 ; i<arr.size() ; i++)
    {
        maxi[{i,i}] = arr[i];
        for(int j=i+1 ; j<arr.size() ; j++)
        {
            maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }

    int n = arr.size();
    int start=0;
    int end = n-1;
    int ans = solveUsingRecursion(arr, maxi,start,end);

    return ans;
}


// top-down approach
int solveUsingRecursion1(vector<int>&arr, map<pair<int,int>, int> &maxi, int start, int end, vector<vector<int>> &dp)
{
    // base case
    if(start>=end) return 0;

    // Step3: return answer if already exits in dp array
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;

    for(int i=start ; i<end ; i++)
    {
        int leftCall = solveUsingRecursion1(arr, maxi, start, i, dp);
        int rightCall = solveUsingRecursion1(arr, maxi, i+1, end, dp);

        int currentLeafNodeValue = (maxi[{start,i}]*maxi[{i+1,end}]) + leftCall + rightCall;

        ans = min(ans, currentLeafNodeValue);
    }

    //Step2: store the result in dp array
    dp[start][end] = ans;

    return dp[start][end];
}

int mctFromLeafValues1(vector<int>& arr) 
{
    // pre computation of maxLeafNode for every positble pair of index
    map<pair<int,int>, int> maxi;
    for(int i=0 ; i<arr.size() ; i++)
    {
        maxi[{i,i}] = arr[i];
        for(int j=i+1 ; j<arr.size() ; j++)
        {
            maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }

    int n = arr.size();
    int start=0;
    int end = n-1;

    //Step1: create dp array
    vector<vector<int>> dp(n+1 , vector<int> (n+1, -1));

    int ans = solveUsingRecursion1(arr, maxi,start,end, dp);

    return ans;
}


// Bottom-up appraoch
int mctFromLeafValues2(vector<int>& arr) 
{
    // pre computation of maxLeafNode for every possible pair of index
    map<pair<int,int>, int> maxi;
    for(int i=0 ; i<arr.size() ; i++)
    {
        maxi[{i,i}] = arr[i];
        for(int j=i+1 ; j<arr.size() ; j++)
        {
            maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
        }
    }


    int n = arr.size();
    int start=0;
    int end = n-1;

    //Step1: create dp array
    vector<vector<int>> dp(n+1 , vector<int> (n+1, -1));

    //Step2: initialize the dp array using the base case of top-down appraoch
    for(int start=0 ; start<n+1 ; start++)
    {
        for(int end=0 ; end<n+1 ; end++)
        {
            if(start>=end)
            {
                dp[start][end]=0;
            }
        }
    }


    // Step3: fill the remaining dp array using the logic of top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int start_i = n-1 ; start_i >= 0 ; start_i--) // start -> 0 se n-1 tak
    {
        for(int end_i = start_i+1 ; end_i < n ; end_i++) // end -> n se start tak
        {
            int ans = INT_MAX;

            for(int i=start_i ; i<end_i ; i++)
            {
                int leftCall = dp[start_i][i];
                int rightCall = dp[i+1][end_i];

                int currentLeafNodeValue = (maxi[{start_i,i}]*maxi[{i+1,end_i}]) + leftCall + rightCall;

                ans = min(ans, currentLeafNodeValue);
            }

            dp[start_i][end_i] = ans;
        }
    }

    // for(auto vec:dp)
    // {
    //     for(auto num:vec)
    //     {
    //         if(num!=-1) cout << " " << num << " "; 
    //         else cout << num << " ";
    //     }
    //     cout << endl;
    // }

    return dp[0][n-1];
}

int main()
{
    vector<int> arr = {6, 2, 4};

    cout << mctFromLeafValues2(arr) << endl;



    return 0;
}