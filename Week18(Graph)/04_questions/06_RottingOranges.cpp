/* -> 994
You are given an m x n grid where each cell can have one of three values:
    - 0 representing an empty cell,
    - 1 representing a fresh orange, or
    - 2 representing a rotten orange.

Every minute, any fresh orange that is '4-directionally adjacent' to a rotten orange becomes rotten.

RETURN the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:
    Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
    Output: 4

Example 2:
    Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
    Output: -1
    Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
    Input: grid = [[0,2]]
    Output: 0
    Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

/*
Approach: BFS
    -- We can't solve it using DFS because initally it may be many rotten oranges will be there, so we will solve it using BFS only
    -- initially queue will be initalized by all the rotten oranges position so that we can pick all the rotten oranges existing at the same time
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int &newX, int &newY, vector<vector<int>> temp)
{
    if(newX >=0 && newY>=0 && newX<temp.size() && newY<temp[0].size() && temp[newX][newY]==1)
        return true;

    return false;
}

int orangesRotting(vector<vector<int>>& grid) 
{
    int n=grid.size();
    int m=grid[0].size();

    // created queue to store the rotting orange at the same time
    queue<pair<pair<int,int>, int> >que; // {{pos},time}

    // all the modification will be done at temp matrix
    vector<vector<int>> temp = grid;
    int minTime=0;


    // intiatilzing queue with all rotting oranges
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(temp[i][j]==2)
                que.push({{i,j}, minTime});
        }
    }

    while (!que.empty())
    {
        auto frontPair = que.front();
        que.pop();

        auto frontNodePos = frontPair.first;

        int currX = frontNodePos.first;
        int currY = frontNodePos.second;
        int currT = frontPair.second;

        // lets move in all direction
        int x[] = {-1,0,1,0};
        int y[] = {0,1,0,-1};
        for(int i=0 ; i<4 ; i++)
        {
            int newX = currX+x[i];
            int newY = currY+y[i];

            if(isSafe(newX, newY, temp))
            {
                // push the new rotten oranges
                que.push({{newX, newY}, currT+1});

                // update minTime
                minTime = max(minTime, currT+1);

                // update temp matrix
                temp[newX][newY] = 2;
            }   
        }
    }
    

    // iterating on temp matrix to check all the oranges are rotten or not
    int freshOrangeCount=0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(temp[i][j]==1)
                return -1;
        }
    }

    return minTime;
}

int main()
{
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << orangesRotting(grid) << endl;

    return 0;
}

