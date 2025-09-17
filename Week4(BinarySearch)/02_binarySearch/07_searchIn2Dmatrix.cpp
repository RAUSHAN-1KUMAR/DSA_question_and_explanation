/* -> 74

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
    -- the actual implementation of 2D array in our memory is w.r.t 1D array indexing, so will proceed the binary search to find the target element.
    -- we will apply the binary search from 0 to n(row*col)-1 index, whenever we get mid index we will find the element w.r.t that index from 2D array, and then check the conditions of BS on that element.

Note:-
    Conversion on 1D to 2D:-(We know the no. of coloumn = C).
        1. let say any index from 1D array.
        2. the rowIndex will be index/C.
        3. and the colIndex will be index%C.
*/


#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();


    int s = 0;
    int e = (row*col)-1;

    while(s<=e)
    {
        int mid = s + (e-s)/2;

        int rowIndex = mid/col;
        int colIndex = mid%col;
        int currNumber = matrix[rowIndex][colIndex];

        if(currNumber == target) return true;
        else if(target > currNumber) s = mid + 1;
        else e = mid-1;

    }

    return false;
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
