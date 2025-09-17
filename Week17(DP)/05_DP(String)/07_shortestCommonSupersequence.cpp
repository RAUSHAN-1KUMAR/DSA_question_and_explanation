/* -> 1092

Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:
    Input: str1 = "abac", str2 = "cab"
    Output: "cabac"
    Explanation: 
    str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
    str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
    The answer provided is the shortest such string that satisfies these properties.


Example 2:
    Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
    Output: "aaaaaaaa"
*/

/*
Approach:-
    -- we are gonna use the approach to print the longest common subsequence to print the shortest super sequence

    -- if they would have just asked to return "length of shortest super sequence": what we could do, Steps=> find the longest common subseqeunce(k) and then answer will be-> 
        k+(n-k)+(m-k) = n+m-k
            :n-> str1 length
            :m-> str2 length

    -- how we would figure out the string: IN LCS(tabulation)
        i) if char matches: then we move ahead both pointer
        ii) if not: then we move ahead to max of both pointer

    -- so the approach is that:
        i) if char matches: push the char into ans string
        ii) if not: then push that char which we are leaving to proceed to our answer
*/

#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2)
{
    int n=str1.size();
    int m=str2.size();

    // lets build tabulation first
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=n-1 ; i>=0; i--){
        for(int j=m-1; j>=0 ; j--){
            if(str1[i]==str2[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    // now lets build our answer string
    string ans = "";
    int i=0,j=0;
    while(i<n && j<m){
        if(str1[i] == str2[j]){//if char then push it
            ans.push_back(str1[i]);
            i++;
            j++;
        }
        else if(dp[i+1][j]>dp[i][j+1]){
            // i+1 is greates so we will move i++, we are leaving str1
            ans.push_back(str1[i]);
            i++;
        }
        else{
            // we are leaving str2
            ans.push_back(str2[j]);
            j++;
        }
    }

    // if some characters left
    while(i<n){
        ans.push_back(str1[i]);
        i++;
    }
    while(j<m){
        ans.push_back(str2[j]);
        j++;
    } 

    return ans;
}

int main()
{
    string str1 = "abdghimk";
    string str2 = "bgohpmz";

    cout << shortestCommonSupersequence(str1, str2) << endl ;

    return 0;
}