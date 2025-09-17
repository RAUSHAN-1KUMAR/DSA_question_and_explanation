/* 214

You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 
Example 1:
    Input: s = "aacecaaa"
    Output: "aaacecaaa"

Example 2:
    Input: s = "abcd"
    Output: "dcbabcd"

*/

/*
Approach:- using KMP algorithm
*/

#include<bits/stdc++.h>
using namespace std;

void LPS(int &n, string &s, vector<int> &lps){
    int pre=0;
    int suf=1;

    while(suf<n){
        if(s[suf]==s[pre]){
            lps[suf]=pre+1;
            pre++;
            suf++;
        }
        else{
            if(pre==0){
                lps[suf]=0;
                suf++;
            }
            else{
                pre = lps[pre-1];
            }
        }
    }
}

string shortestPalindrome(string s){
    int n=s.size();
    vector<int> lps(n, 0);

    LPS(n, s, lps);

    // using the same string from first and last,
    int first=0;
    int second=n-1;
    while(second>=0 && first<n){
        if(s[second]==s[first]){
            first++;
            second--;
        }
        else{
            if(first==0){
                second--;
            }
            else{
                first = lps[first-1];
            }
        }
    }

    string ans="";
    for(int k=n-1 ; k>=first ; k--){
        ans.push_back(s[k]);
    }


    return ans + s; // Concatenate the prefix with the original string to form the shortest palindrome
}



int main()
{
    string s = "aacecaaa";
    string result = shortestPalindrome(s);
    cout << result << endl; // Output: "aaacecaaa"
    return 0;
}