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
Approach:- BFS
    -- just like rotting oranges, for each 0 value cell we are gonna apply BFS to find the 1 value cell, 
    -- i was stuck in applying BFS on 1 value cell, but not you have to apply bfs on 0 value cell, and then there by if trigger a 1 value cell update its min dist
    -- in this question weight of each cell to cell connection is 1 i.e., constant

TC:- O(n*m)
SC:- O(n*m)

An another approach-> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

bool safeMove(int &i, int &j, int &n, int &m){
    if(i<0 || j<0 || i>=n || j>=m) return false;
    return true;
}

vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dist(n, vector<int>(m,-1));
    queue<pair<int,pair<int,int>> > que;// {dist, {pos}};

    // initialize que and dist
    for(int i=0 ; i<n ; i++){ //-> O(n*m)
        for(int j=0 ; j<m ; j++){
            if(mat[i][j]==0){
                que.push({0,{i,j}});
                dist[i][j]=0;
            }
            else{
                dist[i][j] = 1e9;
            }
        }
    }


    // now BFS
    while(!que.empty()){ //-> O(n*m)
        auto qPair = que.front();
        que.pop();

        int currX=qPair.second.first;
        int currY=qPair.second.second;
        int currD=qPair.first;

        // all four direction
        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};
        for(int i=0 ; i<4 ; i++){ //-> O(4)
            int newX = currX+X[i];
            int newY = currY+Y[i];
            if(safeMove(newX, newY, n, m) && currD+1<dist[newX][newY]){
                que.push({currD+1, {newX, newY}});
                dist[newX][newY] = currD+1;
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

