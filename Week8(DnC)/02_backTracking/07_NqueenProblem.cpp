/* -> 51

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other. Means:-
    - koi bhi do queen same row m nhi honi chahiye
    - koi bhi do queen same column m nhi hone chahiye
    - koi bhi do queen diagonal m nhi honi chahiye

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.


Example:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Input: n = 1
Output: [["Q"]]
*/

/*
Appraoch:- backtracking 
    - initially we will fill our board with dot:-
        . . . .
        . . . .
        . . . .
        . . . .
    - and then we will use recursive call for each row with a for loop for each column to put Q in it.
    - to check in column, we are using column vector<boo>
    - and to check diagonally we have a seperate function to check for this

Time Comp: N * (N-1) * (N-2)...2*1 = N!
Space Comp: N*N due to chessBoard of dots

Optimized solution:- next solution
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool check(int n, vector<string> &Board, int i, int j)
{
    // upper left diagn, koi bhi queen present nhi hone chahiye
    int row=i, col=j;
    while (row>-1 && col>-1)
    {
        if(Board[row][col]=='Q')
            return 0;

        row--, col--;
    }
    
    // upper right diagn, koi bhi queen present nhi honi chahiye
    row=i, col=j;
    while (row>-1 && col<n)
    {
        if(Board[row][col]=='Q')
            return 0;

        row--, col++;
    }

    return 1;
}

void find(int row, int n, vector<vector<string>> &ans, vector<string> &Board, vector<bool> &column)
{
    // base case
    if(row==n)
    {
        ans.push_back(Board);
        return;
    }

    // put queen at any postion in given row
    for(int j=0 ; j<n ; j++)
    {
        if(column[j]==0 && check(n,Board,row,j))
        {
            column[j] = 1;
            Board[row][j] = 'Q';
            find(row+1, n, ans, Board, column);

            // backTracking
            column[j] = 0;
            Board[row][j] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;

    // sabse pehle ham apne chessBoard m saare jagah dot(.) fill ker rhe h
    vector<string> board(n);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            board[i].push_back('.');
        }
    }

    vector<bool> column(n,0);

    find(0,n,ans,board,column);
    
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);

    for(auto eachVec:ans)
    {
        for(string eachStr:eachVec)
        {
            cout << eachStr << " ";
        }
        cout << endl;
    }
    return 0;
}


