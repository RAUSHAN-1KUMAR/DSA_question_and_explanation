/* -> 130

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
    1. Connect: A cell is connected to adjacent cells horizontally or vertically.
    2. Region: To form a region connect every 'O' cell.
    3. Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.

To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

 

Example 1:
    Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
    Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
    Explanation:
    In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:
    Input: board = [["X"]]
    Output: [["X"]]

*/

// using bfs-> see next solution

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &board, int i, int j, int &n, int &m){
    if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='X' || board[i][j]=='#') return;

    board[i][j]='#';

    dfs(board, i+1, j, n, m);
    dfs(board, i-1, j, n, m);
    dfs(board, i, j+1, n, m);
    dfs(board, i, j-1, n, m);
}

void solve(vector<vector<char>> &board){
    int n=board.size();
    int m=board[0].size();

    // first converting connected corners 'O' -> '#' using dfs
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<m ; j++){
            if((i==0 || i==n-1) && board[i][j]=='O'){
                dfs(board, i, j, n, m);
            }
            else if((j==0 || j==m-1) && board[i][j]=='O'){
                dfs(board, i, j, n, m);
            }
        }
    }

    // then coverting all left 'O' to 'X' and '#' to 'O'
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<m ; j++){
            if(board[i][j]=='#'){
                board[i][j]='O';
            }
            else if(board[i][j]=='O'){
                board[i][j]='X';
            }
        }
    }
}

int main()
{
    vector<vector<char>> board = {
        {'X','X','O','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    solve(board);

    for(auto &vec:board){
        for(char &ch:vec){
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}