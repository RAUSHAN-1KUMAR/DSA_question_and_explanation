/* -> 240

Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
 

Example 1:
    Input: matrix = [
            [1,4,7,11,15],
            [2,5,8,12,19],
            [3,6,9,16,22],
            [10,13,14,17,24],
            [18,21,23,26,30]
        ], target = 5
    Output: true


Example 2:
    Input: matrix = [
            [1,4,7,11,15],
            [2,5,8,12,19],
            [3,6,9,16,22],
            [10,13,14,17,24],
            [18,21,23,26,30]
        ], target = 20
    Output: false
*/

/*
Approach:-
    -- logic is so sweat, we will start from top-right corner(0,m-1), and then we can move left or down cell by cell towards target

    -- we can also start from bottom-left(n-1, 0) corner

TC:- O(n+m)
*/

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int row=0;
    int col=m-1;
    while (row<n && col>=0)
    {
        if(matrix[row][col]==target)
            return true;
        else if(matrix[row][col]<target)// if less, then move to next row
            row = row+1;
        else // if greater, then move to prev col
            col = col-1;
    }

    return false;
}


int main()
{
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };

    if(searchMatrix(matrix, 10)) cout << "True";
    else cout << "False";
    return 0;
}