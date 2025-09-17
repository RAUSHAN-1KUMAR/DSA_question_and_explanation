/* -> 779

Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    Output: true


Example 2:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    Output: true


Example 3:
    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
    Output: false

*/

#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, int &size, int index, int &n, int &m, vector<vector<char>>& board, string &word, vector<vector<bool>> &visited)
{
    if(index==size)
    {
        return true;
    }

    if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || board[i][j]!=word[index])
    {
        return false;
    }

    visited[i][j] = true;

    bool up = dfs(i-1, j, size, index+1, n, m, board, word, visited);
    bool down = dfs(i+1, j, size, index+1, n, m, board, word, visited);
    bool left = dfs(i, j-1, size, index+1, n, m, board, word, visited);
    bool right = dfs(i, j+1, size, index+1, n, m, board, word, visited);

    visited[i][j] = false;

    return up || down || left || right;
}

bool exist(vector<vector<char>>& board, string word)
{
    int n=board.size();
    int m=board[0].size();
    int size = word.size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(dfs(i, j, size, 0, n, m, board, word, visited))
            {
                return true;
            }

        }
    }

    return false;
}

int main()
{


    return 0;
}