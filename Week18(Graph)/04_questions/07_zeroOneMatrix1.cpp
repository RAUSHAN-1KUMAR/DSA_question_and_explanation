/* -> 542

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:
    Input: mat = [
            [0,0,0],
            [0,1,0],
            [0,0,0]
          ]
    Output: [
            [0,0,0],
            [0,1,0],
            [0,0,0]
            ]


Example 2:
    Input: mat = [
            [0,0,0],
            [0,1,0],
            [1,1,1]
        ]
    Output: [
            [0,0,0],
            [0,1,0],
            [1,2,1]
            ]

*/

/*
Approach:- 
    -- in this approach, we are neither applying dfs or bfs, we will iterate to each cell in two iterations,
        i) top-left to bottom-right
        ii) bottom-right to top-left

    -- on each iteration, if we trigger a value!=0, it means it's that cell for which we have to find the answer, so we will store the min of its all four direction movement into that cell
    -- in both iteration we will do the same thing
*/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dist(n, vector<int>(m,-1));

    // initialize dist
    for(int i=0 ; i<n ; i++){ //-> O(n*m)
        for(int j=0 ; j<m ; j++){
            if(mat[i][j]==0){
                dist[i][j]=0;
            }
            else{
                dist[i][j] = 1e9;
            }
        }
    }

    // top-left to bottom-right
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(mat[i][j]!=0)
            {
                // all four direction minimum
                if(j-1>=0)
                    dist[i][j] = min(dist[i][j], dist[i][j-1]+1);

                if(i-1>=0)
                    dist[i][j] = min(dist[i][j], dist[i-1][j]+1);

                if(j+1<m)
                    dist[i][j] = min(dist[i][j], dist[i][j+1]+1);

                if(i+1<n)
                    dist[i][j] = min(dist[i][j], dist[i+1][j]+1);
            }
        }
    }


    // bottom-right to top-left
    for(int i=n-1 ; i>=0 ; i--){
        for(int j=m-1 ; j>=0 ; j--){
            if(mat[i][j]!=0)
            {
                // all four direction minimum
                if(j-1>=0)
                    dist[i][j] = min(dist[i][j], dist[i][j-1]+1);

                if(i-1>=0)
                    dist[i][j] = min(dist[i][j], dist[i-1][j]+1);

                if(j+1<m)
                    dist[i][j] = min(dist[i][j], dist[i][j+1]+1);

                if(i+1<n)
                    dist[i][j] = min(dist[i][j], dist[i+1][j]+1);
            }
        }
    }

    return dist;
}


int main()
{
    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    vector<vector<int>> ans = updateMatrix(mat);

    for(auto vec:ans){
        for(int num:vec){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

