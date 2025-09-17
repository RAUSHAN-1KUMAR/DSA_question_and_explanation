/* -> 2375

You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.

 

Example 1:
    Input: pattern = "IIIDIDDD"
    Output: "123549876"
    Explanation:
    At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
    At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
    Some possible values of num are "245639871", "135749862", and "123849765".
    It can be proven that "123549876" is the smallest possible num that meets the conditions.
    Note that "123414321" is not possible because the digit '1' is used more than once.


Example 2:
    Input: pattern = "DDD"
    Output: "4321"
    Explanation:
    Some possible values of num are "9876", "7321", and "8742".
    It can be proven that "4321" is the smallest possible num that meets the conditions.
*/

/*
Approach:-
    2. recursion + backtracking
        -- approach described in code

        TC:- O(n!)
        TC:- O(n)

    3. Optimal approach -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

bool rec(string &pattern, int i, int prev, string &ans, vector<bool> &vis)
{
    // base case
    if(i>=pattern.size()) return true;

    
    if(pattern[i]=='I'){
        // I->increment so again we have a loop from prev+1 to 9
        for(int j=prev+1 ; j<=9 ; j++){
            if(!vis[j]){// take only if it is not used before
                ans.push_back(j+'0');
                vis[j]=true;
                if(rec(pattern,i+1,j,ans,vis))
                    return true;
                ans.pop_back();
                vis[j]=false;
            }
        }
    }
    else{
        // same for D also
        for(int j=prev-1;j>=1 ;j--){
            if(!vis[j]){
                ans.push_back(j+'0');
                vis[j]=true;
                if(rec(pattern, i+1, j, ans, vis))
                    return true;
                ans.pop_back();
                vis[j]=false;
            }
        }
    }

    return false;
}

string smallestNumber(string pattern)
{
    int n=pattern.size();
    string ans="";

    // visited vector to check the used digit
    vector<bool> vis(10,false);

    // at first we are starting from the lowest digit, so that we can have the smallest string pattern
    for(int i=1 ; i<=9 ; i++)
    {
        ans.push_back(i+'0');
        vis[i]=true;

        // i is working as previous used digit, so that in recursive call we can choose the next digit accordingly
        if(rec(pattern, 0, i, ans, vis))
            break;

        ans.pop_back();//backtrack
        vis[i]=false;//backtrack
    }

    return ans;
}


int main()
{
    string pattern="IIIDDI";
    cout <<smallestNumber(pattern) << endl;
    return 0;
}