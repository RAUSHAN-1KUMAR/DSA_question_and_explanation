/* -> 120

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are at index j in row i, then you move to i+1 index in j or j+1 in each step.

 

Example 1:
    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    Output: 11
    Explanation: The triangle looks like:
       2
      3 4
     6 5 7
    4 1 8 3
    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).


Example 2:
    Input: triangle = [[-10]]
    Output: -10
*/


/*
Approach:-
    -- Previously we were calling on the basis of prev index, 
    -- we can also do this-> at every index, call only two recursive function:- 
        1. func(i+1,j)
        2. func(i+1,j+1)

        Means we are doing the call on the basis of What was the previously chosen index, now we are just making two calls for each index
*/

#include<bits/stdc++.h>
using namespace std;


// Recursice method
int helper(vector<vector<int>> &triangle, int &m, int row, int col)
{
    // base case
    if(row>=m) return 0;

    // adding the current index can only call the next two different index
    
    int oneDown = triangle[row][col] + helper(triangle, m, row+1, col);

    int oneDiagonal = triangle[row][col] + helper(triangle, m, row+1, col+1);

    return min(oneDown, oneDiagonal);
}

int minimumTotal(vector<vector<int>>& triangle)
{
    int row=0;
    int col=0;
    int m=triangle.size();

    return helper(triangle, m, row, col);
}


// space optimization
int minimumTotal1(vector<vector<int>>& triangle)
{
    int m=triangle.size();

    //Step1 and Step2
    vector<int> singleArray(m+1, 0);

    //Step3:
    for(int row=m-1 ; row>=0 ; row--)
    {
        for(int col=0 ; col<=row ; col++)
        {
            int oneDown = triangle[row][col] + singleArray[col];

            int oneDiagonal = triangle[row][col] + singleArray[col+1];

            singleArray[col] = min(oneDown, oneDiagonal);
        }
    }

    return singleArray[0];
}


int main()
{
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    cout << minimumTotal1(triangle) << endl;

    return 0;
}



