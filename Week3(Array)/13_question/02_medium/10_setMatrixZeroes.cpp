/* -> 73

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Could you devise a constant space solution?
 

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

/*
Appraoch:- 
    -- took two array, row and col to mark zero on it.
    -- ab matrix m iterate ker rhe h, and jis bhi (i,j) ke liye zero mila to uss row(i) ko mark ker rhe row wale array m and then uss col(j) ko mark ker rhe col wale array m.
    -- mark kerne ke baad, phirse matrix m iterate ker rhe, and jis bhi (i,j) ke liye zero mark tha row aur col wale array m, usko zero ker de rhe h

-- Ham row aur col array m mark kaise ker rhe h-> intially dono array m  zero h, aur jab mark kerna h to usme 1 bhar de rhe h

But this appraoch takes O(m+n) space, can we devise a solution taking O(1) space-> see next solution.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();

    // col array to mark zero at this column
    vector<int> col(m,0);

    // row array to mark zero at this row
    vector<int> row(n,0);


    // marking our row and col array
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(matrix[i][j]==0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }


    // converting our matrix
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(row[i] || col[j]){
                matrix[i][j]=0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {0,1,2,0},
        {3,4,5,2},
        {1,3,1,5}
    };

    setZeroes(matrix);

    for(vector<int> vec:matrix)
    {
        for(int num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}