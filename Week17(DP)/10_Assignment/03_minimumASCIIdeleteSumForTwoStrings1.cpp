/* -> 712

Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

Example 1:
    Input: s1 = "sea", s2 = "eat"
    Output: 231
    Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
    Deleting "t" from "eat" adds 116 to the sum.
    At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.


Example 2:
    Input: s1 = "delete", s2 = "leet"
    Output: 403
    Explanation: Deleting "dee" from "delete" to turn the string into "let", adds 100[d] + 101[e] + 101[e] to the sum.
    Deleting "e" from "leet" adds 101[e] to the sum.
    At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
    If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
*/

/*
Approach:- recurive approach already discussed
    1. top-down approach
    2. bottom-up approach
    3. space optimization
*/

#include<bits/stdc++.h>
using namespace std;

// top-down approach
int helper(string &s1, int i, string &s2, int j, vector<vector<int>> &dp)
{
    // base case
    if(i>=s1.size()){
        int sum=0;
        while(j != s2.size()){
            sum += s2[j];
            j++;
        }
        return sum;
    }

    if(j>=s2.size()){
        int sum=0;
        while (i!=s1.size()){
            sum+=s1[i];
            i++;
        }
        return sum;
    }


    // Step3: return if answer already exits in dp array
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }


    int ans=0;
    if(s1[i]==s2[j])
    { 
        ans += helper(s1, i+1, s2, j+1, dp);
    }
    else
    {
        int caseA = s1[i] + helper(s1, i+1, s2, j, dp);

        int caseB = s2[j] + helper(s1, i, s2, j+1, dp);

        ans = min(caseA, caseB);
    }

    // STEP2: store the results in dp array
    dp[i][j] = ans;

    return dp[i][j];
}

int minimumDeleteSum(string s1, string s2)
{
    int i=0;
    int j=0;

    int n=s1.size();
    int m=s2.size();

    // Step1: create dp array
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    int ans = helper(s1, i, s2, j, dp);

    return ans;
}


// bottom-up approach
int minimumDeleteSum1(string s1, string s2)
{
    int i=0;
    int j=0;

    int n=s1.size();
    int m=s2.size();

    // Step1: create dp array
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

    // Step2: intializing dp array using the base case of top-down approach
    // if i>=s1.size();
    for(int col = 0; col<=m ; col++)
    {
        int sum = accumulate(s2.begin()+col, s2.end(), 0);
        dp[n][col] = sum;
    }

    // if j>=s2.size();
    for(int row=0; row<=n ; row++)
    {
        int sum = accumulate(s1.begin()+row, s1.end(), 0);
        dp[row][m] = sum;
    }


    // Step3: fill the remaining dp array: use the logic of top down approach and also index kha se kha tak ja rha tha, usko janha p ulta le jana h
    for(int i_n = n-1 ; i_n>=0 ; i_n--)
    {
        for(int j_m = m-1 ; j_m>=0 ; j_m--)
        {

            int ans=0;

            if(s1[i_n]==s2[j_m])
            { 
                ans = dp[i_n+1][j_m+1];
            }
            else
            {
                int caseA = s1[i_n] + dp[i_n+1][j_m];

                int caseB = s2[j_m] + dp[i_n][j_m+1];

                ans = min(caseA, caseB);
            }

            dp[i_n][j_m] = ans;
        }
    }

    return dp[0][0];
}


// space optimzation
int minimumDeleteSum2(string s1, string s2)
{
    int i=0;
    int j=0;

    int n=s1.size();
    int m=s2.size();

    // using nextRow and currRow
    vector<int> nextRow(m+1, 0);
    vector<int> currRow(m+1, 0);

    // filling nextRow using base case
    for(int i=m-1 ; i>=0 ; i--)
    {
        nextRow[i] = s2[i] + nextRow[i+1];
    }


    // Now using the same code of tabulation method
    for(int i_n = n-1 ; i_n>=0 ; i_n--)
    {
        // catch, i.e., for every i_n we have to fill curr[m]
        currRow[m] = currRow[m] + s1[i_n];

        for(int j_m = m-1 ; j_m>=0 ; j_m--) 
        {

            int ans=0;

            if(s1[i_n]==s2[j_m])
            { 
                ans = nextRow[j_m+1];// dp[i_n+1][j_m+1] -> i_n+1 matlab nextRow
            }
            else
            {
                int caseA = s1[i_n] + nextRow[j_m];// dp[i_n+1][j_m] -> i_n+1 matlab nextRow

                int caseB = s2[j_m] + currRow[j_m+1];// dp[i_n][j_m+1] -> i_n matlab currRow

                ans = min(caseA, caseB);
            }

            currRow[j_m] = ans;// dp[i_n][j_m] -> i_n matlab currRow
        }
        
        // shifting must
        nextRow = currRow;
    }

    return currRow[0];
}



int main()
{
    string s1 = "delete";
    string s2 = "leet";

    cout << minimumDeleteSum2(s1, s2) << endl;

    return 0;
}