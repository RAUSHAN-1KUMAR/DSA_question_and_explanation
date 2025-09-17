/*
You are given an 'n x n' 2D matrix representing an image, rotate the image by 90 degrees(clockwise)

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. Do not allocate another 2D matrix and do the rotation.

Example:-
    input:- matrix = {{1,2,3},{4,5,6},{7,8,9}}
            1 2 3
            4 5 6
            7 8 9

    output:- {{7,4,1},{8,5,2},{9,6,3}}
            7 4 1
            8 5 2
            9 6 3
*/

/*
Approach:- 1st transpose and then reverse
*/

#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    // transpose
    for(int row = 0 ; row<matrix.size() ; row++){
        for(int col = row ; col<matrix[row].size() ; col++)
        {
            swap(matrix[row][col], matrix[col][row]);
        }
    }

    // reverse
    for(int row = 0 ; row<matrix.size() ; row++)
    {
        for(int col = 0 ; col<matrix[row].size() ; col++)
        {
            if(col<matrix.size()/2){
                swap(matrix[row][col], matrix[row][matrix.size()-col-1]);
            }
        }
    }   

    // printing
    for(int i = 0 ; i<matrix.size() ; i++)
    {
        for(int j = 0 ; j<matrix[i].size() ; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> mat = {
        {1,2,3},
        {5,6,7},
        {9,10,11},
    };

    rotate(mat);

    return 0;
}



