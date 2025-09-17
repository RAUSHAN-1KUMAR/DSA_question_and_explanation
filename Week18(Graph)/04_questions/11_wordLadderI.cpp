/* -> 127
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
    1. Every adjacent pair of words differs by a single letter.

    2. Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.

    3. sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, RETURN the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: 5
    Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
    Output: 0
    Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/


/*
Approach:- BFS(each word in wordList can be treated as vertex)
    -- first marked all the wordList strings as true and then applied BFS on each string, and doing conversion at each position from a to z
    -- why BFS, because BFS explore all direction at once, so we will reach to destination fastly

    TC:- O(n*word.size()*26)

Why BFS -> becuase we have to reach our destination as fast as possible
Why not DFS -> Dfs is not used to find shortest distance in graph but only in Trees becuase we have unique paths between nodes in a tree, but we can have exponential no. of unique paths between two nodes in a graph -> TLE
*/

#include<bits/stdc++.h>
using namespace std;

// applying BFS
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
    unordered_map<string, bool> strMap;
    for(auto str:wordList){
        strMap[str]=true;
    }

    if(strMap[endWord]==false) return 0;

    queue<pair<string, int>> que; // string, count
    que.push({beginWord, 1});

    while (!que.empty())//-> O(n)
    {
        auto strPair = que.front();
        que.pop();

        string currStr = strPair.first;
        int cnt = strPair.second;

        if(currStr == endWord) return cnt;

        // lets insert the letter from a to z on each position, and at once i can change only one character
        for(int i=0 ; i<endWord.size() ; i++)
        {//-> O(m) everytime
            string st=currStr;
            for(char ch='a'; ch<='z' ; ch++) //-> 26 everytime
            {
                if(currStr[i]==ch) continue;//catch1

                st[i]=ch;
                if(strMap[st]){
                    que.push({st, cnt+1}); 
                    strMap[st]=false; //catch2
                } 
                
            }
        }
    }
    
    return 0;
}


int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {
        "hot","dot", "tog", "cog"
    };

    cout << ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}

