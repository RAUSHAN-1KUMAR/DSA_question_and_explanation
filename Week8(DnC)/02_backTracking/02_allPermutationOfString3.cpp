/*
We have a given string -> abc, we have to print all permutation of the given string  i.e., all sequences
*/

/*
alternate method than swapping: just choosing the element, one by one if it is not used already
     for ex:- abc
        Output: at 0 index, we can use a, b, or c 

Time complexity:- n*n! (n for each traversal of 0 to n on each call and n! for total node)
*/

#include<iostream>
#include<vector>
using namespace std;

void helper(string &str, vector<bool> &visited, string &ans)
{
    if(ans.size() == str.size())
    {
        cout << ans << " ";
        return;
    }


    for(int i=0 ; i<visited.size() ; i++) 
    {
        if(visited[i]==false)
        {
            ans.push_back(str[i]);
            visited[i]=true;

            helper(str,visited, ans);

            // backtracking
            ans.pop_back();
            visited[i]=false;
        }
    }
}

void printPermutation(string &str)
{
    string ans = "";

    vector<bool> visited(str.size(), false);

    helper(str, visited, ans);
}

int main()
{
    string str = "abc";
    printPermutation(str);
    return 0;
}

