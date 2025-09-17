/* -> 37
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:
    1. Each of the digits 1-9 must occur exactly once in each row.
    2. Each of the digits 1-9 must occur exactly once in each column.
    3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

The '.' character indicates empty cells.
*/

/*
Approch:- brute force
    - her ek box p jao and then, check kro
        i) row m wo number h ya nhi
        ii) column m wo number h ya nhi
        iii) 3X3 ke matrix m wo number h ya nhi

Time Comp: totalEmptyBox * 9 * 9
*/

#include<bits/stdc++.h>
using namespace std;

bool check(int num, vector<vector<char>> &board, int i, int j)
{
    char c = '0'+num;

    // check at same row
    for(int col=0 ; col<=8 ; col++)
    {
        if(board[i][col]==c) return false;
    }

    // check at same column
    for(int row=0 ; row<=8 ; row++)
    {
        if(board[row][j]==c) return false;
    }

    // check at same box
    int row = (i/3)*3; // starting row
    int col = (j/3)*3; // starting column
    for(int a=row ; a<(row+3) ; a++)
    {
        for(int b=col ; b<(col+3) ; b++)
        {
            if(board[a][b]==c) return false;
        }
    }

    return true;
}

bool find(int i, int j, vector<vector<char>> &board)
{
    // base condition
    if(i==9) return true;
    if(j==9) return find(i+1, 0, board);
    if(board[i][j]!='.') return find(i, j+1, board);

    // for every position we have 1-9 value to check
    for(int num=1 ; num<=9 ; num++)
    {
        if(check(num,board,i,j))
        {
            board[i][j] = '0'+num;

            // if the return value is false then we have to check for another number.
            if(find(i, j+1, board)==true)
                return true;

            board[i][j] = '.';
        }
    }

    // if we are not able to fill the box
    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    find(0,0,board);
}

int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);

    for(auto vec:board)
    {
        for(char ch:vec)
        {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}