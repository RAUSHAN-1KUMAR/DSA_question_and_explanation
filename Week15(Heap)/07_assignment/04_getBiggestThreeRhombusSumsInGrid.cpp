/* -> 1878

You are given an m x n integer matrix grid​​​.

A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell.

Note that the rhombus can have an area of 0, which will be a single cell

Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.


Example 1:
    Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
    Output: [228,216,211]
    Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
    - Blue: 20 + 3 + 200 + 5 = 228
    - Red: 200 + 2 + 10 + 4 = 216
    - Green: 5 + 200 + 4 + 2 = 211


Example 2:
    Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [20,9,8]
    Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
    - Blue: 4 + 2 + 6 + 8 = 20
    - Red: 9 (area 0 rhombus in the bottom right corner)
    - Green: 8 (area 0 rhombus in the bottom middle)


Example 3:
    Input: grid = [[7,7,7]]
    Output: [7]
    Explanation: All three possible rhombus sums are the same, so return [7].
*/

/*
Approach:- I SOLVED IT 
    -- explained in the code, go through the each function call one by one you will get it.

    We can also use set to store the distinct sum, but its a heap week so lets use heap
*/


#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<vector<int>> &grid, int &i, int &j, int &row, int &col, int &rhombus)
{
    // checking opposite cell for rhombus = i+(rhombus*2)<row
    // checking left most cell for rhombus = j-(rhombus)>=0
    // checking right most cell for rhombus = j+(rhombus)<col
    if((i + rhombus*2)<row && (j-rhombus)>=0 && (j+rhombus)<col)
        return true; // if all max cell exist then return true

    return false;
}

int gridSummer(vector<vector<int>> &grid, int &i, int &j, int &row, int &col, int &rhombus)
{
    int sum=0;
    int r=i;
    int c=j;

    // first adding left part of the rhombus
    int rh=rhombus;
    while(rh>-1)
    {
        sum+=grid[r][c];

        if(rh>0)
            sum+=grid[r+(rh*2)][c]; // adding two opposide at a time

        rh--;
        r++;
        c--;
    }
    
    // now adding right part of the rhombus
    rh=rhombus-1;
    r=i+1;
    c=j+1;
    while(rh>-1)
    {
        sum+=grid[r][c];

        if(rh>0)
            sum+=grid[r+(rh*2)][c]; // adding two opposite side a time

        rh--;
        r++;
        c++;
    }

    return sum;
}

void gridSumFinder(vector<vector<int>> &grid, int &i, int &j, int &row, int &col, priority_queue<int> &pq)
{
    // so at point (i,j), there can have rhombus of length 1,2,3...

    // i will take a rhombus variable, which will signify the length of rhombus
    int rhombus=1;

    while(true)
    {
        // isPossilbe will check, at point (i,j) can a rhombus of length rhombus is possible or not 
        if(isPossible(grid, i, j, row, col, rhombus))
        {
            // if possible then gridSummer will find the sum of that rhombus of length rhombus
            int sum = gridSummer(grid, i, j, row, col, rhombus);
            pq.push(sum);
        }
        else break;

        rhombus++;
    }
}

vector<int> getBiggestThree(vector<vector<int>>& grid) 
{
    int row=grid.size();
    int col=grid[0].size();

    // first lets compute the sum and store the sum into maxHeap
    priority_queue<int> pq;

    // we are gonna compute all posible rhombus at a particular (i,j)
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<col ;j++)
        {
            pq.push(grid[i][j]); // a single element is also a rhombus of area 0
            gridSumFinder(grid, i, j, row, col, pq);// with respect to cell (i,j) compute all the rhombus possible sum
        }
    }

    // now lets build our answer
    vector<int> ans;
    int three=3;
    while (!pq.empty() && three)
    {
        if(ans.size()>0 && pq.top()==ans[ans.size()-1])
        {
            // because we need three distinct top sum if possible
            pq.pop();
            continue;
        }

        ans.push_back(pq.top());    
        pq.pop();
        three--;
    }
    
    return ans;
}

int main()
{
    vector<vector<int>> grid = {
        {3,4,5,1,3},
        {3,30,1,199,3},
        {20,30,200,40,50},
        {1,5,5,11,4},
        {40,12,150,15,35}
    };

    vector<int> ans = getBiggestThree(grid);

    for(auto num:ans)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}