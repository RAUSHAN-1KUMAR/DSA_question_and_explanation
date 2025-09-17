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

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solve(string& a, string& b, int i, int j)
{
    // base case
    if(i >= a.length()){
        // word1 wali string end hogyi h
        // yani word1 ki length may be word2 se choti h
        return b.length()-j;
    }
    if(j >= b.length()){
        // word2 wali string end hogyi h
        // yani word2 ki length may be word1 se choti h
        return a.length()-i;
    }


    // solve one case
    int ans=0;
    if(a[i]==b[j]){// character matched
        ans = 0 + solve(a,b,i+1,j+1);
    }
    else{// character match nhi hua
    
        // insert
        int insert = 1+solve(a,b,i,j+1);
        // remove
        int remove = 1+solve(a,b,i+1,j);
        // replace
        int replace = 1+solve(a,b,i+1,j+1);

        ans = min(insert, min(remove, replace));
    }

    return ans;
}


int minDistance(string word1, string word2)
{
    int i=0;
    int j=0;

    int ans = solve(word1, word2, i, j);

    return ans;
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";

    cout << minDistance(word1, word2) << endl;


    return 0;
}