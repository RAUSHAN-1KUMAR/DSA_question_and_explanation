/* -> 407

Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

Example 1:
    Input: heightMap = [
                [1,4,3,1,3,2],
                [3,2,1,3,2,4],
                [2,3,3,2,3,1]
            ]
    Output: 4
    Explanation: After the rain, water is trapped between the blocks.
    We have two small ponds 1 and 3 units trapped.
    The total volume of water trapped is 4.


Example 2:
    Input: heightMap = [
                [3,3,3,3,3],
                [3,2,2,2,3],
                [3,2,1,2,3],
                [3,2,2,2,3],
                [3,3,3,3,3]
            ]
    Output: 10
*/

/*
Approach:- BFS + dijkstra(logic)
    --> logic is to first traverse all the boundary only and push its height and cooredinates in minHeap, and then we choose minHeight cooredinate from top of the minHeap, and we apply BFS on it
        -- if(adjacent cell is visited) then return
        -- if(adjacent cell has largest or equal height than me) then push its height and coordinate into minHeap
        -- if(adjacent cell has smaller height than me) then water will be filled, store the diff in height as water filled, push the that same largest height with the coordinate as smaller height cell into the minHeap
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> PP;

bool isSage(int &newX, int &newY, int &n, int &m)
{
    if(newX<0 || newY<0 || newX>=n || newY>=m )
        return false;

    return true;
}

int trapRainWater(vector<vector<int>>& heightMap)
{
    int n=heightMap.size();
    int m=heightMap[0].size();

    // {height, {coordinates}}
    priority_queue<PP, vector<PP>, greater<>> pq;

    // visited cell
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // left most column and right most column
    for(int row=0 ; row<n ; row++){
        for(int col:{0,m-1}){
            pq.push({heightMap[row][col], {row, col}});
            visited[row][col]=true;
        }
    }

    // top most row and bottom most row
    for(int col=0;col<m;col++){
        for(int row:{0 , n-1}){
            pq.push({heightMap[row][col], {row, col}});
            visited[row][col]=true;
        }
    }

    // now BFS
    int water=0;
    while (!pq.empty())
    {
        PP trap = pq.top();
        pq.pop();

        int currH = trap.first;
        int currX = trap.second.first;
        int currY = trap.second.second;

        int A[]={-1,0,1,0};
        int B[]={0,1,0,-1};
        for(int i=0 ; i<4 ; i++)
        {
            int newX=currX+A[i];
            int newY=currY+B[i];

            if(isSage(newX, newY, n,m) && !visited[newX][newY])
            {
                water += max(currH-heightMap[newX][newY], 0);
                int newHeight = max(currH, heightMap[newX][newY]);
                pq.push({newHeight, {newX, newY}});
                visited[newX][newY]=true;
            }
        }

    }
    
    return water;
}


int main()
{
    vector<vector<int>> heightMap = {
        {12,13,1,12},
        {13,4,13,12},
        {13,8,10,12},
        {12,13,12,12},
        {13,13,13,13}
    };


    cout << trapRainWater(heightMap) << endl;

    return 0;
}