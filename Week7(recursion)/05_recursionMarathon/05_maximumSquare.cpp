/* -> 221

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:
Input: matrix = [["0"]]
Output: 0

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi)
{ 
    // base case
    if(i>=row || j>=col)
    {
        return 0;
    } 

    // before processing explore all direction(head recursion)
    int right = solve(matrix,i,j+1,row, col, maxi);
    int diagonal = solve(matrix,i+1,j+1,row, col, maxi);
    int down = solve(matrix,i+1,j,row, col, maxi);

    if(matrix[i][j]=='1')
    {
        int ans = 1 + min(right, min(down, diagonal));
        maxi = max(maxi, ans);
        return ans;
    }
    else{ 
        return 0;
    }
}

int maximalSquare(vector<vector<char>>& matrix)
{
    int i=0;
    int j=0;
    int row = matrix.size();
    int col = matrix[0].size();
    int maxi = 0;
    int ans = solve(matrix, i, j, row, col, maxi);

    return maxi*maxi;//-> we are asked to return area
}

int main()
{
    vector<vector<char>> matrix = { 
        {'1','1','0','1'},
        {'1','1','0','1'},
        {'1','1','1','1'},
    };


    cout << maximalSquare(matrix) << endl;

    return 0;
}