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
Appraoch:- optimizing space
    -- pichle question m ham (i,j) ke zero ko track kerne ke liye alag se row aur col array liye but now ab O(1) space m kaam kerna h to ham apn matrix ke first row aur first col ko use kerengen mark kerne m aur zero ka use krengen mark kerne m

    -- but there is some catch in this appraoch:-> in first and last index of col array which will make whole matrix zero so:
        - jab dubara matrix m itrate krengen zero kerne ke liye tab ham first row aur first col ko leave kerke iterate krengen i.e., uske ander re rhe matrix ke elements ko zero ker rhe h.

    -- now at last handle the col(0) and row(0)-> first handle col(0) then row(0).
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    // seperate memory for first index of col array
    int col0 = 1;

    for(int i=0 ; i<matrix.size() ; i++)
    {
        for(int j=0 ; j<matrix[0].size() ; j++)
        {
            // zero mil gya to ab matrix ke first row([?][0]) aur first col([0][?]) ko mark kerdo
            if(matrix[i][j]==0)
            {
                matrix[i][0] = 0;//-> marking row

                // handling first index of col
                if(j!=0)
                    matrix[0][j] = 0;//-> marking col
                else
                    col0 = 0;
            }
        }
    }


    // iterate into matrix without first row and first col.
    for(int i=1 ; i<matrix.size() ; i++)
    {
        for(int j=1 ; j<matrix[0].size() ; j++)
        {
            if(matrix[i][j] != 0){
                // check for col and row
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
    }

    // ab first row and col ko zero kerna h, but sabse pehle col ko
    if(matrix[0][0]==0)
    {
        for(int j=0 ; j<matrix[0].size() ; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if(col0==0)
    {
        for(int i=0 ; i<matrix.size() ; i++)
        {
            matrix[i][0] = 0;
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