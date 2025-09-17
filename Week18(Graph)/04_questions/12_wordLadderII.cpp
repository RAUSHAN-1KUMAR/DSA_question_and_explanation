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
Approach:- BFS + (tree ka level order traversal concept)
    -- we are gonna have queue<vector<string>> qu:- yes vector<string> so that we will store sequence into the que, and whenever we proceed to our solution 
        i) we will pick the last string of vector<string> and then suppose we got another two string so now we will push two different vector<string> into queue
        ii) we will not modify our map<string, bool> untill the entire level is completed

    SO how the BFS in this solution is different from word ladder I:
        - in word ladder I, we do BFS to reach first at destination that's why we were marking our map at each word/vertex, so that if someone has reached to the last node we can the return our answer and end the traversal
        - but in word ladder II, we have to find all other paths also that reach to our destination at the same time, so that's why we are traversing the whole level and then marking the visited as true in map.

        But this gives -> MLE or TLE


I think this can also give solution:-
    -- first find the minimum length to reach from beginWord to endWord and then
    -- use backtrack + recursion to find all sequences of minimum length
    -- i guess this is the optimised approach, -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
{
    // we can also use map like word ladder I
    unordered_set<string> st(wordList.begin(), wordList.end());

    queue<vector<string>> que;
    que.push({beginWord});// starting string "beginword"

    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);// root level

    int level=0;// level will justify the max level till now
    vector<vector<string>> ans;
    while(!que.empty())
    {
        vector<string> vec=que.front();
        que.pop();

        if(vec.size() > level){
            level++;
            for(auto it:usedOnLevel){
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        string word = vec.back();

        if(word == endWord){
            if(ans.size()==0){// if its the first, then it's the minimum one
                ans.push_back(vec);
            }
            else if(ans[0].size()==vec.size()){// or check the length is same as minimum or not
                ans.push_back(vec);
            }
        }

        for(int i=0 ; i<word.size() ;i++)
        {
            char original = word[i];
            for(char ch='a' ; ch<='z' ; ch++)
            {
                word[i]=ch;
                if(st.count(word)>0)
                {
                    // push new word into top vector of string
                    vec.push_back(word);

                    // push the vector into queue 
                    que.push(vec);

                    // also push the new word into usedOnLevel
                    usedOnLevel.push_back(word);

                    // back track the top vector for upcomming new word
                    vec.pop_back();
                }
            }
            word[i]=original;
        }
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


    return 0;
}