/* -> 126

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
    1. Every adjacent pair of words differs by a single letter.

    2. Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.

    3. sk == endWord

Given two words, beginWord and endWord, and a dictionary wordList, RETURN all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].
 

Example 1:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
    Explanation: There are 2 shortest transformation sequences:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"
    "hit" -> "hot" -> "lot" -> "log" -> "cog"

Example 2:
    Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
    Output: []
    Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/

/*
Approach:- BFS + (DFS with level order traversal adjList)
    -- optimised code:- 
        Step1: apply BFS and find shortest transformation from begin to end word, we will store each word's shortest level in a map
        Step2: Now apply DFS from endword to reach to the beginWord by using the level map, 
            if we got a word whose level is just 1 less than current word than
                make another DFS call
            else 
                don't make call
*/

#include<bits/stdc++.h>
using namespace std;

void DFS(string &beginWord, string endWord, unordered_map<string, int> &level, vector<string> &path, vector<vector<string>> &ans)
{
    if(endWord==beginWord){
        reverse(path.begin(), path.end());
        ans.push_back(path);
        reverse(path.begin(), path.end()); // catch, so that when it backtracks the sequence should be in correct order
        return;
    }

    int currLevel=level[endWord];

    for(int i=0 ; i<endWord.size() ; i++)
    {
        char original=endWord[i];

        for(char ch='a' ; ch<='z' ; ch++)
        {
            endWord[i]=ch;
            // if we got a word whose level is just less than 1, than only make another DFS call
            if(level.find(endWord)!=level.end() && level[endWord]==currLevel-1)
            {
                path.push_back(endWord);
                DFS(beginWord, endWord, level, path, ans);
                path.pop_back(); // backTrack
            }
        }

        endWord[i]=original;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{   
    unordered_set<string> st(wordList.begin(), wordList.end());

    if(st.find(endWord)==st.end()) return {};

    unordered_map<string, int> level; // to keep track of string,level
    queue<string> qu;
    qu.push(beginWord);

    st.erase(beginWord);
    level[beginWord]=1;// startnode level is 1
    
    int sz=beginWord.size();
    while(!qu.empty())
    {
        string uStr = qu.front();
        int currSteps = level[uStr];
        qu.pop();

        if(uStr==endWord) break;

        // u->v only if one character diff
        string vStr=uStr;
        for(int i=0 ; i<sz ; i++)
        {
            for(char ch='a' ; ch<='z' ; ch++)
            {
                if(vStr[i]==ch) continue;//catch

                vStr[i]=ch;

                if(st.count(vStr)){
                    qu.push(vStr);
                    st.erase(vStr);
                    level[vStr]=currSteps+1;
                }
            }

            vStr[i]=uStr[i];// back to original character
        }

    }


    // after preparing our adjList, now DFS
    vector<string> path;
    vector<vector<string>> ans;
    if(level.find(endWord)!=level.end()){
        path.push_back(endWord);// DFS from back
        DFS(beginWord, endWord, level, path, ans);
    }

    return ans;
}


int main()
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {
        "hot","dot", "dog","lot", "log", "cog"
    };

    vector<vector<string>> ans = findLadders(beginWord, endWord, wordList);
    for(auto vec:ans){
        for(auto c:vec){
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}

