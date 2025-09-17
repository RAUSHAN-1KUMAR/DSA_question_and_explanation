/* -> 72

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

/*
Approach: DP
    1. Top-Down approach
    2. Bottom-Up approach
    3. sapce optimization
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// Top-Down approach
int solve(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if(i>=word1.length())
        return word2.length()-j;

    if(j>=word2.length())
        return word1.length()-i;

    // return the answer that is already exits in dp array
    if(dp[i][j]!=-1) return dp[i][j];

    int ans = 0;
    if(word1[i]==word2[j])
    {
        ans = 0 + solve(word1,word2,i+1,j+1, dp);
    }
    else
    {
        int insert = 1 + solve(word1, word2, i, j+1, dp);
        int remove = 1 + solve(word1, word2, i+1, j, dp);
        int replace = 1 + solve(word1, word2, i+1, j+1, dp);

        ans = min(insert, min(remove, replace));
    }

    //Step2: store the result in dp array
    dp[i][j] = ans;

    return ans;
}

int minDistance(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();

    int i=0;
    int j=0;

    // Step1: create dp array
    vector<vector<int>> dp (n, vector<int>(m, -1));

    int ans = solve(word1, word2, i, j, dp);

    return ans;
}


// Bottom-up appraoch
int minDistance1(string word1, string word2)
{
    int n=word1.length();
    int m=word2.length();

    //Step1: create dp array
    vector<vector<int>> dp (n+1, vector<int>(m+1, -1));

    //Step2: initialize the dp array using the base case of top-down approach
    // initializing nth row i.e., if i==n(word1.size())
    for(int j=0 ; j<=m ; j++)
    {
        dp[n][j] = word2.length()-j;
    }

    // initializing mth col i.e., if j==m(word2.size())
    for(int i=0 ; i<=n ; i++)
    {
        dp[i][m] = word1.length()-i;
    }
    

    //Step3: fill the remaining dp array using the logic of top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int j=m-1 ; j>=0 ; j--) // -> j treated as col
    {
        for(int i=n-1 ; i>=0 ; i--) // -> i treated as row
        {
            int ans = 0;

            if(word1[i]==word2[j])
            {
                ans = 0 + dp[i+1][j+1];
            }
            else
            {
                int insert = 1 + dp[i][j+1];
                int remove = 1 + dp[i+1][j];
                int replace = 1 + dp[i+1][j+1];

                ans = min(insert, min(remove, replace));
            }

            dp[i][j] = ans;
        }
    }

    return dp[0][0];
}

// space optimization (in this question, we can do space optimization but it will be a little bit different from what we have till now in space optimization of other question)
int minDistance2(string word1, string word2)
{
    int n=word1.length();
    int m=word2.length();

    vector<int> nextCol(n+1, 0);
    for(int i=n ; i>=0 ; i--)
    {
        nextCol[i] = word1.length()-i;
    }

    vector<int> currCol(n+1, 0);


    for(int j=m-1 ; j>=0 ; j--)
    {
        // The little different, i.e, we are assigning the top index of curr array for each column
        currCol[n] = word2.length()-j;// Most important line

        for(int i=n-1 ; i>=0 ; i--)
        {
            int ans = 0;

            if(word1[i]==word2[j])
            {
                ans = 0 + nextCol[i+1];// dp[i+1][j+1] -> j+1 matlab nextCol wala array
            }
            else
            {
                int insert = 1 + nextCol[i];// dp[i][j+1] -> j+1 matlab nextCol wala array

                int remove = 1 + currCol[i+1];// dp[i+1][j] -> j matlab currCol wala array

                int replace = 1 + nextCol[i+1];// dp[i+1][j+1] -> j+1 matlab nextCol wala array

                ans = min(insert, min(remove, replace));
            }

            currCol[i] = ans; //dp[i][j] -> j matlab currCol wala array
        }

        nextCol = currCol;
    }


    return nextCol[0];
}


int main()
{
    string word1 = "";
    string word2 = "a";

    cout << minDistance2(word1, word2) << endl;


    return 0;
}