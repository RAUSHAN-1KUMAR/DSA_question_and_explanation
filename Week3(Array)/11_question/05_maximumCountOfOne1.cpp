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
Approach:- by taking a count and index variable, and we will increase the value of count from 0 to k for each row
*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
{
    vector<int> ans;
    int n = mat.size();

    // oneCount will store max number of 1's in a row
    int oneCount = INT_MIN;
    
    // rowNo will store index of max no. of 1's wali row
    int rowNo = -101;

    for(int i = 0; i<n ; i++){

        int count = 0;

        for(int j = 0 ; j<mat[i].size() ; j++){
            if(mat[i][j]==1){
                count++;
            }
        }

        if(count > oneCount){
            oneCount = count;
            rowNo = i;
        }
    }

    ans.push_back(rowNo);
    ans.push_back(oneCount);

    return ans;
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



