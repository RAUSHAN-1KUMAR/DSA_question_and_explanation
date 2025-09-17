/*
You are given an m x n integer matrix matrix with the following two properties:
-- Each row is sorted in non-decreasing order.
-- The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

Note:- You must write a solution in O(log(m * n)) time complexity.

 
Example 1:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

Example 2:
    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false
*/

/*
Approach:-
    -- first finding the row in which our element lie.
    -- then appling the binary search in that row to find the target element.
*/

#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int foundRow;
    bool found = false;

    for(int i = 0 ; i<row ; i++)
    {
        if(target>=matrix[i][0] && target<=matrix[i][col-1])
        {
            foundRow = i;
            found = true;
        }
    }       

    // applying binary Search in foundRow
    if(found)
    {
        found=false;
        int l = 0;
        int h = col-1;
        while(l<=h)
        {
            int midCol = l + (h-l)/2;
            if(target == matrix[foundRow][midCol]){
                found=true;
                break;
            } 
            else if(target > matrix[foundRow][midCol]) l = midCol+1;
            else h = midCol-1;
        }
    }

    return found;
}

int main()
{
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    if(searchMatrix(matrix,0)) cout << "True";
    else cout << "False";

    return 0;
}