/* -> 1631

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size 'rows x columns', where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 

You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

RETURN the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

Example 1:
    Input: heights = [
                [1,2,2],
                [3,8,2],
                [5,3,5]
            ]
    Output: 2
    Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
    This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.


Example 2:
    Input: heights = [
                [1,2,3],
                [3,8,4],
                [5,3,5]
            ]
    Output: 1
    Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].


Example 3:
    Input: heights = [
                [1,2,1,1,1],
                [1,2,1,2,1],
                [1,2,1,2,1],
                [1,2,1,2,1],
                [1,1,1,2,1]
            ]
    Output: 0
    Explanation: This route does not require any effort.
*/

/*
Approach:- Dijkstra
    -- we can say that it follows a greedy technique like dijkstra algo, i.e., min diff walle ko pehle lo heap me se

    -- In previous question we were able to ably BFS on it, and we were able to do so becuase it was unweighted or constant weight, but in question the weight for a-->b is abs(val(a)-val(b))

TC:- O(m*n*log(m*n))
SC:- O(m*n)
*/

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int newX, int newY, int row, int col,vector<vector<int> >& diff, int currX, int currY ) 
{
    if(newX >=0 && newY >=0 && newX < row && newY < col && diff[currX][currY] < diff[newX][newY])
    {
        return true;
    }
    else
    {
        return false;
    }
}

int minimumEffortPath(vector<vector<int>>& heights) 
{
    int row = heights.size();
    int col = heights[0].size();

    vector<vector<int> > diff(row, vector<int>(col, INT_MAX));
    int destX = row-1;
    int destY = col-1;

    priority_queue< pair<int, pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int>>> > mini;

    //initial state of diff matrix
    diff[0][0] = 0;

    //initial state of min heap
    mini.push({0,{0,0}}); // maxDiff, {position}


    while(!mini.empty()) 
    {
        auto topPair = mini.top();
        mini.pop();

        pair<int,int>  currNodeIndexPair = topPair.second;

        int currX = currNodeIndexPair.first;
        int currY = currNodeIndexPair.second;
        int currMaxAbsDiff = topPair.first;
        
        //now we can travel to all nbr i.e. top, down, left, right
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        for(int i=0; i<4; i++) 
        {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            int absDiff = abs(heights[currX][currY] - heights[newX][newY]);
            if(isSafe(newX, newY,row,col,diff,currX, currY)) 
            { 
                int newMaxDiff = max(currMaxAbsDiff, absDiff);

                //check can we update diff array
                diff[newX][newY] = min(diff[newX][newY], newMaxDiff);

                //entry create karo min Heap me
                if(newX != destX || newY != destY) 
                {
                    mini.push({diff[newX][newY], {newX, newY}});
                }
            }
        }
    }

    return diff[destX][destY];
}


int main()
{
    vector<vector<int>> heights = {
        {1,2,1,1,1},
        {1,2,1,2,1},
        {1,2,1,2,1},
        {1,2,1,2,1},
        {1,1,1,2,1}
    };

    cout << minimumEffortPath(heights) << endl;

    return 0;
}

