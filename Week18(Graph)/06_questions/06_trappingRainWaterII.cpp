/* 407

Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

Example 1:
    Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
    Output: 4
    Explanation: After the rain, water is trapped between the blocks.
    We have two small ponds 1 and 3 units trapped.
    The total volume of water trapped is 4.


Example 2:
    Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
    Output: 10
*/


/*
Approach: Dijkstra
    -- push all the boundary cell into minHeap, and start from the min height of boundary cell..
        Why boundary? -> yahi to iss question ki jaan h, how-> koi bhi overflow boundary p hi to hoga
*/


/*
Approach:- BFS + dijkstra(logic)
    --> logic is to first traverse all the boundary only and push its height and cooredinates in minHeap, and then we choose minHeight cooredinate from top of the minHeap, and we apply BFS on it
        -- if(adjacent cell is visited) then return
        -- if(adjacent cell has largest or equal height than me) then push its height and coordinate into minHeap
        -- if(adjacent cell has smaller height than me) then water will be filled, store the diff in height as water filled, push the that same largest height with the coordinate as smaller height cell into the minHeap
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> PP;

bool isPossible(int &newX, int &newY, int &n, int &m)
{
    if (newX < 0 || newY < 0 || newX >= n || newY >= m)
        return false;

    return true;
}

int trapRainWater(vector<vector<int>> &heightMap)
{
    int n = heightMap.size();
    int m = heightMap[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    priority_queue<PP, vector<PP>, greater<>> minHeap;

    // pushing only boundary cells
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0){
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
            else if (i == n - 1){
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
            else if (j == 0){
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
            else if (j == m - 1){
                minHeap.push({heightMap[i][j], {i, j}});
                visited[i][j] = true;
            }
        }
    }

    int A[] = {0, 0, 1, -1};
    int B[] = {1, -1, 0, 0};

    int water = 0;
    while (!minHeap.empty())
    {
        auto p = minHeap.top(); minHeap.pop();
        
        int currh = p.first, currx = p.second.first, curry = p.second.second;

        for (int i = 0; i < 4; i++)
        {
            int newx = currx + A[i];
            int newy = curry + B[i];

            if (isPossible(newx, newy, n, m) && !visited[newx][newy])
            {
                water += max(currh, heightMap[newx][newy]) - heightMap[newx][newy];

                visited[newx][newy] = true;

                minHeap.push({max(currh, heightMap[newx][newy]), {newx, newy}});
            }
        }
    }

    return water;
}


int main()
{
    vector<vector<int>> heightMap = {
        {12, 13, 1, 12},
        {13, 4, 13, 12},
        {13, 8, 10, 12},
        {12, 13, 12, 12},
        {13, 13, 13, 13}
    };

    cout << trapRainWater(heightMap) << endl;

    return 0;
}

