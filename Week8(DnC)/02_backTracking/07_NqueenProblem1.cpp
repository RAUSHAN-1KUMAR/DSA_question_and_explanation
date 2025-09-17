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
Appraoch:- 
    - we are gonnna optimised the diagonally checking 
    - HOW??: 
        1. for right diagonal check
           0 1 2 3 4 -> col index
           _________
        0 |0 1 2 3 4  -> sum of row and column index
        1 |1 2 3 4 5
        2 |2 3 4 5 6
        3 |3 4 5 6 7
        4 |4 5 6 7 8

            -- we can se that we just have to make an array of size 9 i.e., 0-8 and then we will mark true or false but using the sum of row and column index

    - for left diagonal check -> col-row index
            0  1  2  3 4 -> col index
            _____________
        0 | 0  1  2  3 4  -> subtract column and row
        1 |-1  0  1  2 3
        2 |-2 -1  0  1 2
        3 |-3 -2 -1  0 1
        4 |-4 -3 -2 -1 0

            -- but how we will manage the minus value, how can an array have negative index:
            -- add (n-1) to each subtract of row and column

Time Comp:- still N!

*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void find(int row, int n, vector<vector<string>> &ans, vector<string> &Board, vector<bool> &column, vector<bool> &LeftDig, vector<bool> &RightDig)
{
    if(row==n)
    {
        ans.push_back(Board);
        return;
    }


    for(int j=0 ; j<n ; j++)
    {
        // for left diagonal we do col-row+n-1
        // for right diagonal we do col+row
        if(column[j]==0 && LeftDig[j-row+n-1]==0 && RightDig[j+row]==0)
        {
            column[j] = 1;
            Board[row][j] = 'Q';
            LeftDig[j-row+n-1]=1;
            RightDig[j+row]=1;

            find(row+1, n, ans, Board, column, LeftDig, RightDig);

            // backTracking
            column[j] = 0;
            Board[row][j] = '.';
            LeftDig[j-row+n-1]=0;
            RightDig[j+row]=0;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;

    vector<string> board(n);
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            board[i].push_back('.');
        }
    }

    vector<bool> leftDig(2*n-1,0);
    vector<bool> rightDig(2*n-1,0);

    vector<bool> column(n,0);

    find(0,n,ans,board,column, leftDig, rightDig);
    
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