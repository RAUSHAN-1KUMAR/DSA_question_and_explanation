/* -> 1368

Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

    - 1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])

    - 2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])

    - 3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])

    - 4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])

Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

Example 1:
    Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
    Output: 3
    Explanation: You will start at point (0, 0).
    The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
    The total cost = 3.


Example 2:
    Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
    Output: 0
    Explanation: You can follow the path from (0, 0) to (2, 2).


Example 3:
    Input: grid = [[1,2],[4,3]]
    Output: 1
*/

#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int c;
    int x;
    int y;

    node(){}

    node(int c, int x, int y) : c(c), x(x), y(y) {}
};

class comparator{
public:
    bool operator()(node &a, node &b){
        return a.c > b.c;
    }
};

class Solution {
public:
    bool isCorrect(int &newX, int &newY, int &n, int &m){
        if(newX<0 || newY<0 || newX>=n||newY>=m)
            return false;

        return true;
    }

    int minCost(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> minGrid(n, vector<int> (m, 1e9));  
        priority_queue<node, vector<node>, comparator> minHeap;

        int startX=0;
        int startY=0;
        int startingCost = 0;

        minHeap.push(node(startingCost, startX, startY));
        minGrid[0][0]=0;

        while(!minHeap.empty())
        {
            node currMin=minHeap.top();
            minHeap.pop();

            int currC=currMin.c;
            int currX=currMin.x;
            int currY=currMin.y;
            
            int refX;// refuse x
            int refY;// refuse y
            if(grid[currX][currY]==1){
                refX=0;
                refY=1;
            }
            else if(grid[currX][currY]==2){
                refX=0;
                refY=-1;
            }
            else if(grid[currX][currY]==3){
                refX=1;
                refY=0;
            }
            else{
                refX=-1;
                refY=0;
            }

            int A[]={-1,0,1,0};//row
            int B[]={0,1,0,-1};//col
            for(int i=0 ; i<4; i++)
            {
                int newX=currX+A[i];
                int newY=currY+B[i];
                int newC=currC+1;
                if(A[i]==refX && B[i]==refY){
                    newC=currC;// refuse the incremented cost
                }
                if(isCorrect(newX, newY, n, m) && minGrid[newX][newY]>newC){
                    minGrid[newX][newY]=newC;
                    minHeap.push(node(newC, newX, newY));
                }
            }
        }

        return minGrid[n-1][m-1];
    }
};


int main()
{
    vector<vector<int>> grid = {
        {1,1,3},
        {3,2,2},
        {1,1,4}
    };

    cout << Solution().minCost(grid) << endl;

    return 0;
}


