/* -> 3394

You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

    - (startx, starty): The bottom-left corner of the rectangle.
    - (endx, endy): The top-right corner of the rectangle.

Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

    - Each of the three resulting sections formed by the cuts contains at least one rectangle.
    - Every rectangle belongs to exactly one section.

Return true if such cuts can be made; otherwise, return false.

 

Example 1:
    Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
    Output: true
    Explanation: We can make horizontal cuts at y = 2 and y = 4. Hence, output is true.

Example 2:
    Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]
    Output: true
    Explanation:We can make vertical cuts at x = 2 and x = 3. Hence, output is true.

Example 3:
    Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]
    Output: false
    Explanation:We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.
*/

/*
Approach:-
    1. Brute force: 
        - suppose i want to check vertical cuts, then i have taken a vertical line(x from 1 to n-1) and checking for each x, that is it valid for each rectangle or not
        - similarly i did for horizontal cuts, i have taken horizantal line(y from 1 to n-1) and then checked for each y, that is valid for each rectangle or not
    
        TLE

    2. Better approach:- see next solution
*/


#include<bits/stdc++.h>
using namespace std;

bool cutCheckX(vector<vector<int>> &rectangles, int &x, int row)
{
    if(row>=rectangles.size())
    {
        return true;
    }

    int x1=rectangles[row][0];
    int x2=rectangles[row][2];

    bool ans = false;
    if(x<=x1 || x>=x2)
    {
        ans = cutCheckX(rectangles, x, row+1);
    }

    return ans;
}

bool cutCheckY(vector<vector<int>> &rectangles, int &y, int row)
{
    if(row>=rectangles.size())
    {
        return true;
    }

    int y1=rectangles[row][1];
    int y2=rectangles[row][3];

    bool ans = false;
    if(y<=y1 || y>=y2)
    {
        ans = cutCheckY(rectangles, y, row+1);
    }

    return ans;
}


bool checkValidCuts(int n, vector<vector<int>>& rectangles) 
{
    // start
    // checking for verticle cut
    int verticalCuts=0;
    for(int x=1; x<=n-1 ; x++)
    {
        bool check = cutCheckX(rectangles,x,0);
        if(check)
            verticalCuts++;
    }

    // wait
    if(verticalCuts>=2) return true;

    // checking for horizontal cur
    int horizontalCuts=0;
    for(int y=1;y<=n-1;y++)
    {
        bool check = cutCheckY(rectangles,y,0);
        if(check)
            horizontalCuts++;
    }

    if(horizontalCuts>=2) return true;

    // end
    return false;
}

int main()
{
    vector<vector<int>> rectangles = {
        {0,2,2,4},
        {1,0,3,2},
        {2,2,3,4},
        {3,0,4,2},
        {3,2,4,4}
    };
    int n=4;

    cout << checkValidCuts(n, rectangles) << endl;

    return 0;
}