/*
Given an array of positive integers, arr[] and a value, target, determine if there is a subset of the given set with sum equal to given target.

Examples:
    Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
    Output: true
    Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.


    Input: arr[] = [3, 34, 4, 12, 5, 2], target = 30
    Output: false
    Explanation: There is no subset with target sum 30.


    Input: arr[] = [1, 2, 3], sum = 6
    Output: true
    Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
*/

/*
Approach:-
    -- here we are taking our target from target->0, but more preferable is to take a sum = 0; and then sum->target tak le jao,, later on many question is similar to this where in which arr[i] can be 0, so that's why sum->target -> see next solution
*/

#include <bits/stdc++.h>
using namespace std;

void printDP(vector<vector<int>> &dp);

// recurive solution
bool helper(vector<int> &arr, int i, int target)
{
    // base case
    if (target == 0) return true;
    if (i >= arr.size()) return false;

    // include
    bool caseA = false;
    if (target - arr[i] >= 0)
        caseA = helper(arr, i + 1, target - arr[i]);

    // exclude
    bool caseB = helper(arr, i + 1, target);

    return (caseA || caseB);
}

bool isSubsetSum(vector<int> &arr, int target)
{
    int i = 0;

    return helper(arr, i, target);
}

// memoization
bool helper1(vector<int> &arr, int i, int target, vector<vector<int>> &dp)
{
    if (target == 0) return true;
    if (i >= arr.size()) return false;

    // Step3:
    if (dp[i][target] != -1)
        return dp[i][target];

    bool caseA = false;
    if (target - arr[i] >= 0)
        caseA = helper1(arr, i + 1, target - arr[i], dp);

    bool caseB = helper1(arr, i + 1, target, dp);

    // Step2:
    dp[i][target] = caseA || caseB;

    return dp[i][target];
}

bool isSubsetSum1(vector<int> &arr, int target)
{
    int i = 0;
    int n = arr.size();

    // Step1:
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    int ans = helper1(arr, i, target, dp);

    return ans;
}

// tabulation(taking target: target->0)
bool isSubsetSum2(vector<int> &arr, int target)
{
    int n = arr.size();

    // Step1:
    vector<vector<int>> dp(n, vector<int>(target + 1, false));

    // Step2: if i was going from i=n->0, and i==0
    dp[0][arr[0]] = true; // when target == arr[0]

    // and if target==0
    for (int row = 0; row < n; row++)
        dp[row][0] = true;

    printDP(dp);
    cout << endl;

    // nested loops
    for (int i = 1; i <= n - 1; i++)
    {
        for (int tgt = 1; tgt <= target; tgt++)
        {
            bool notTake = dp[i - 1][tgt];

            bool take = false;
            if (arr[i] <= tgt)
                take = dp[i - 1][tgt - arr[i]];

            dp[i][tgt] = (take || notTake);
        }
    }

    printDP(dp);
    
    return dp[n - 1][target];
}

int main()
{
    vector<int> arr = {4, 3, 5, 3};
    int target = 6;

    cout << isSubsetSum2(arr, target) << endl;

    return 0;
}

void printDP(vector<vector<int>> &dp)
{
    for (auto &vec : dp)
    {
        for (int &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}
