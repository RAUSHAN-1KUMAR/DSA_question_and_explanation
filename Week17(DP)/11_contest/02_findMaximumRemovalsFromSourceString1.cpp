/* -> 3316

You are given a string 'source' of size n, a string 'pattern' that is a subsequence of source, and a sorted integer array 'targetIndices' that contains distinct numbers in the range [0, n - 1].

We define an operation as removing a character at an index idx from source such that:
    1. idx is an element of targetIndices.
    2. pattern remains a subsequence of source after removing the character.

Performing an operation does not change the indices of the other characters in source. For example, if you remove 'c' from "acb", the character at index 2 would still be 'b'.

Return the maximum number of operations that can be performed.

 

Example 1:
    Input: source = "abbaa", pattern = "aba", targetIndices = [0,1,2]
    Output: 1
    Explanation:
    We can't remove source[0] but we can do either of these two operations:
    Remove source[1], so that source becomes "a_baa".
    Remove source[2], so that source becomes "ab_aa".

Example 2:
    Input: source = "bcda", pattern = "d", targetIndices = [0,3]
    Output: 2
    Explanation:

    We can remove source[0] and source[3] in two operations.

Example 3:
    Input: source = "dda", pattern = "dda", targetIndices = [0,1,2]
    Output: 0
    Explanation:
    We can't remove any character from source.

Example 4:
    Input: source = "yeyeykyded", pattern = "yeyyd", targetIndices = [0,2,3,4]
    Output: 2
    Explanation:
    We can remove source[2] and source[3] in two operations.
*/

/*
Appraoch:- DP
    1. recursive approach: observe the solution carefully
    2. top-down approach
*/

#include<bits/stdc++.h>
using namespace std;

// recursive approach
int helper(string& source, string &pattern, int i, int j, unordered_map<int,bool> &ump)
{
    // base case
    if(i>=source.size() && j<pattern.size()) return INT_MIN;
    if(i>=source.size() && j>=pattern.size()) return 0;
    if(i<source.size() && j>=pattern.size())
    {
        int leftRemovals=0;
        while (i<source.size())
        {
            if(ump[i]) leftRemovals++;
            i++;
        }
        return leftRemovals;
    }

    int caseRemove=INT_MIN; //don't forget to initalize with INT_MIN
    if(ump[i]){ // if index present then lets take a case of removing it
        caseRemove = 1+helper(source, pattern, i+1, j, ump);
    }

    // and another case is to not remove it, then we have cases to check string pattern exists in source or not
    int caseDontRemove=INT_MIN; //don't forget to initalize with INT_MIN
    if(source[i]==pattern[j]){
        caseDontRemove = helper(source, pattern, i+1, j+1, ump);
    }
    else{
        caseDontRemove = helper(source, pattern, i+1, j, ump);
    }

    return max(caseRemove, caseDontRemove);
}


int maxRemovals(string source, string pattern, vector<int> &targetIndices)
{
    int n = source.size();
    int m = pattern.size();

    unordered_map<int,bool> ump;
    for(int i=0;i<targetIndices.size();i++)
        ump[targetIndices[i]] = true; 

    int ans = helper(source, pattern, 0, 0, ump);

    return ans;
}


// memoization
int helper1(string& source, string &pattern, int i, int j, unordered_map<int,bool> &ump, vector<vector<int>> &dp)
{
    // base case
    if(i>=source.size() && j<pattern.size()) return INT_MIN;
    if(i>=source.size() && j>=pattern.size()) return 0;
    if(i<source.size() && j>=pattern.size())
    {
        int leftRemovals=0;
        while (i<source.size())
        {
            if(ump[i]) leftRemovals++;
            i++;
        }
        return leftRemovals;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    int caseRemove=INT_MIN;
    if(ump[i]){
        caseRemove = 1+helper1(source, pattern, i+1, j, ump, dp);
    }

    int caseDontRemove=INT_MIN;
    if(source[i]==pattern[j]){
        caseDontRemove = helper1(source, pattern, i+1, j+1, ump, dp);
    }
    else{
        caseDontRemove = helper1(source, pattern, i+1, j, ump, dp);
    }

    dp[i][j] = max(caseRemove, caseDontRemove);

    return dp[i][j];
}


int maxRemovals1(string source, string pattern, vector<int> &targetIndices)
{
    int n = source.size();
    int m = pattern.size();

    unordered_map<int,bool> ump;
    for(int i=0;i<targetIndices.size();i++)
        ump[targetIndices[i]] = true;

    vector<vector<int>> dp(n, vector<int>(m, -1)); 

    int ans = helper1(source, pattern, 0, 0, ump, dp);

    return ans;
}


int main()
{
    string source = "yeyeykyded";
    string pattern = "yeyyd";
    vector<int> targetIndices = {0,2,3,4};

    cout << maxRemovals(source, pattern, targetIndices) << endl;

    return 0;
}

