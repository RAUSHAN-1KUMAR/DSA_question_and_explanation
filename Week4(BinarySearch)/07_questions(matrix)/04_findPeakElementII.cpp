/* 1901

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.


Example 1:
    Input: mat = [[1,4],
                  [3,2]]
    Output: [0,1]
    Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.


Example 2:
    Input: mat = [[10,20,15],
                  [21,30,14],
                  [7, 16,32]]
    Output: [1,1]
    Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.
*/

/*
Approach:- use the logic of "find peak element I"
    -- logic is to apply BS on col 0->n and then we will choose the maximum element of that mid col for the binary search movement
    -- why max?? -> choosing the max, says that it is greater than its top and bottom cell and then we just have to move our start or end by comparing maxEle with its adjacent right and left cell

TC:- O(nlogm)
*/

#include<bits/stdc++.h>
using namespace std;

int maxElem(vector<vector<int>> &mat, int &n, int &m, int col){
    int maxValue=-1;
    int index=-1;
    for(int i=0;i<n;i++){
        if(mat[i][col]>maxValue){
            maxValue=mat[i][col];
            index=i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>>& mat)
{
    int n=mat.size();
    int m=mat[0].size();//col

    int low=0, high=m-1;
    while(low<=high)
    {
        int mid=(low+high)/2;// we got the mid column

        int rowMax=maxElem(mat, n, m, mid);// and we got the index of max ele of that mid column

        int left=mid-1>0?mat[rowMax][mid-1]:-1;
        int right=mid+1<m?mat[rowMax][mid+1]:-1;
        
        // now BS movement w.r.t rowMax left and right element
        if(mat[rowMax][mid]>left && mat[rowMax][mid]>right){
            return {rowMax, mid};
        }
        else if(mat[rowMax][mid]<left)
            high=mid-1;
        else 
            low=mid+1;
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {
        {4,2,5,1,4,5},
        {10,9,3,2,3,2},
        {1,7,6,0,1,3},
        {3,6,2,3,7,2}
    };

    vector<int> ans = findPeakGrid(mat);

    for(int num:ans){
        cout << num << " ";
    }

    return 0;
}

