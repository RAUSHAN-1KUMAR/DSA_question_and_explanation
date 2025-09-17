/* 711

Question is same as number of distinct islands I, but here we can rotate and flip the island. (rotation allowed -> 90, 180 or 270 degree only) and we also have to consider its horizontal and vertical reflection as well.

Example
    Input: [[1,1,0,0,0],
            [1,0,0,0,0],
            [0,0,0,0,1],
            [0,0,0,1,1]]
    Output: 1

    Explanation: Notice that:
    11
    1
    and
    1
    11
    are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.


    Input: [
        [1,1,1,0,0],
        [1,0,0,0,1],
        [0,1,0,0,1],
        [0,1,1,1,0]]
    Output: 2
    Explanation: Notice that:
    111
    1
    and
    1
    111
    are considered same island shapes. Because if we flip the first array in the up/down direction, then they have the same shapes.
*/

/*
Approach:- using coordinates to identify equal shape
    -- we will be forming all possible rotations and reflection of a found shape, then to abvoid MLE, we will normalize those forms in such a way that a unique representation can be used to represent that perticular shape, and get stored in set.
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Point;
vector<int> directions = {-1, 0, 1, 0, -1};

vector<Point> normalizeShape(vector<Point> &shape)
{
    vector<vector<Point>> shapes(8);

    for(auto &point:shape){
        int x = point.first, y = point.second;
        shapes[0].push_back({x, y});// original
        shapes[5].push_back({y, -x});// 90 degree
        shapes[3].push_back({-x, -y});// 180 degree
        shapes[7].push_back({-y, x});// 270 degree
        shapes[1].push_back({x, -y});// reflect over x-axis (flip vertically)
        shapes[2].push_back({-x, y});// reflect over y-axis (flip horizontally)
        shapes[4].push_back({y, x});// reflect over y=x (main diagonal)
        shapes[6].push_back({-y, -x});// reflect over y=-x (anti-diagonal)
    }

    for(auto &e:shapes){
        sort(e.begin(), e.end());
        int baseX=e[0].first, baseY = e[0].second;
        for(auto &point:e){
            point.first -= baseX;
            point.second -= baseY;
        }
    }

    sort(shapes.begin(), shapes.end());

    return shapes[0];
}

void dfs(int x, int y, vector<vector<int>> &grid, vector<Point> &shape)
{
    shape.push_back({x, y});
    grid[x][y] = 0; // mark visited

    for(int k=0; k<4 ; ++k){
        int nextx = x+directions[k];
        int nexty = y+directions[k+1];

        if(nextx>=0 && nextx<grid.size() && nexty>=0 && nexty<grid[0].size() && grid[nextx][nexty]==1)
            dfs(nextx, nexty, grid, shape);
    }
}

int countDistinctIslands2(vector<vector<int>> &grid)
{
    set<vector<Point> > st;
    for(int row=0; row<grid.size(); ++row){
        for(int col=0; col<grid[0].size(); ++col){
            if(grid[row][col]){
                vector<Point> shape;
                dfs(row, col, grid, shape);
                st.insert(normalizeShape(shape));
            }
        }
    }

    return st.size();
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };

    cout << countDistinctIslands2(grid) << endl;
    return 0;
}

