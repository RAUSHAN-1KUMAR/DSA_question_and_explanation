/*
Given a 'm x n' binary matrix 'mat', find the O-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.

In case there are multiple row that have the maximum count of one, the row with the smallest row number should be selected.

Returns an array containing the index of the row, and the number of ones in it.

Example:-
    Input: mat = [[0,1],[1,0]]
    Output: [0,1]
    Explanation: Both rows have the same number of 1's. so we return the index of the smaller row '0' and the maximum no of 1's count is 1.
*/

/*
Approach:- by taking a sum and index variable, to store ones count, I will check the sum in each row and store it and also assign the index accordingly
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    int sum = 0;
    int sum1 = 0;
    int index;

    for(int row = 0 ; row<mat.size() ; row++)
    {

        for(int col = 0 ; col<mat[row].size() ; col++)
        {
            sum1 += mat[row][col];
        }

        if(sum1>sum) {
            sum = sum1;
            index = row;
        }
        sum1 = 0;
    }

    vector<int> answer{index,sum};

    return answer;
}


int main()
{
    vector<vector<int>> mat = {
        {1,0,1},
        {0,0,0,1},
        {0,0,1,1}
    };

    vector<int> answer = rowAndMaximumOnes(mat);

    cout << "Index is: " << answer[0] << endl;
    cout << "Ones count: " << answer[1] << endl;

    return 0;
}



