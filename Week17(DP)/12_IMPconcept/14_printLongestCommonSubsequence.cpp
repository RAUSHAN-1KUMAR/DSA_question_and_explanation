/* -> 1143
Given two strings text1 and text2, Your task is to print the longest common subsequence.
*/

/*
Approach:- Using the code of tabulation method of longestCommonSubsequence i.e., previous question
    -- specially we will use the dp array of tabulation method to find the longest common subsequences because dp array would contain the track of each (i,j).

Lets solve it recursion only -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

void printDpArray(vector<vector<int>> &dp);


// bottom-up approach(tabulation method)
int longestCommonSubsequence1(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    string a=text1;
    string b=text2;

    vector<vector<int>> dp(n+1 , vector<int> (m+1,-1));

    // if i>=n return 0
    for(int col=0 ; col<=m ; col++)
    {
        dp[n][col]=0;
    }

    // if j>=m return 0
    for(int row=0 ; row<=n ; row++)
    {
        dp[row][m]=0;
    }

    for(int i=n-1 ; i>=0 ; i--) //-> i used as row
    {
        for(int j=m-1 ; j>=0 ; j--) //-> j used as col
        {
            int ans=0;
            if(a[i]==b[j]) 
            {
                ans = 1+dp[i+1][j+1];
            }
            else
            { 
                int caseOne = dp[i][j+1];
                int caseTwo = dp[i+1][j];

                ans = 0 + max(caseOne, caseTwo);
            }

            // STEP2: store the result in dp array
            dp[i][j] = ans; 
        }
    }

    // now printing the LCS
    string ans;
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(text1[i]==text2[j])// if equal then its confirm that the answer for(i,j) came from (i+1, j+1);
        {
            ans.push_back(text1[i]);// we can also use text2[i]
            i = i+1;
            j = j+1;
        }
        else // if not equal then either the answer for (i,j) came from max of (i,j+1) or (i+1, j), if both are same then there might be multiple answer, but we can only find the one from the dp array
        {
            if(dp[i][j+1] > dp[i+1][j])
                j = j+1;
            else
                i = i+1;
        }
    }

    cout << ans << endl;

    return dp[0][0];
}


int main()
{
    string text1 = "abcde";
    string text2 = "bdgek";

    int ans = longestCommonSubsequence1(text1, text2);

    cout << ans << endl;

    return 0;
}


void printDpArray(vector<vector<int>> &dp)
{
    for(auto vec:dp)
    {
        for(int num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
