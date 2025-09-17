/* -> 959

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

Example 1:
    Input: grid = [" /","/ "]
    Output: 2

Example 2:
    Input: grid = [" /","  "]
    Output: 1

Example 3:
    Input: grid = ["/\\","\\/"]
    Output: 5
    Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.
*/

/*
Appraoch:- DFS + conversing of given slash to somethind that can be computed
    -- we have convert the input by using:-
                  001
        1. '/' => 010
                  100

                  100
        2. '\' => 010
                  001

                  000
        3. ' ' => 000
                  000

    -- and then applying the DFS for 0
*/              

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void numberOfIslandsDFS(vector<vector<int>> &matrix, int i, int j)
{   
    // base case
    if(i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size() || matrix[i][j]==1)
    {
        return;
    }

    matrix[i][j]=1;

    // RE
    numberOfIslandsDFS(matrix, i+1, j);//-> down
    numberOfIslandsDFS(matrix, i-1 , j);//-> up
    numberOfIslandsDFS(matrix, i, j+1);//-> left
    numberOfIslandsDFS(matrix, i, j-1);//-> right
}

int regionBySlashes(vector<string> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();


    // forming our 2D vector matrix to transform the given grid into computable grid
    vector<vector<int>> matrix(rows*3, vector<int>(cols*3, 0));

    // transforming
    for(int i=0 ; i<rows ; i++)
    {
        for(int j=0 ; j<cols; j++)
        {
            if(grid[i][j]=='/')
            {
                matrix[i*3][j*3+2] = 1;     //->  001
                matrix[i*3+1][j*3+1] = 1;   //->  010
                matrix[i*3+2][j*3] = 1;     //->  100
            }
            else if(grid[i][j]=='\\')
            {
                matrix[i*3][j*3] = 1;       //-> 100
                matrix[i*3+1][j*3+1] = 1;   //-> 010
                matrix[i*3+2][j*3+2] = 1;   //-> 001
            }
        }
    }


    // applying DFS
    int region = 0;
    for(int i=0 ; i<matrix.size() ; i++)
    {
        for(int j=0 ; j<matrix[0].size(); j++)
        {
            if(matrix[i][j]==0)
            {
                numberOfIslandsDFS(matrix, i, j);
                region++;
            }
        }
    }

    return region;
}

int main()
{
    vector<string> grid = {
        "/\\",
        "\\/"
    };


    return 0;
}