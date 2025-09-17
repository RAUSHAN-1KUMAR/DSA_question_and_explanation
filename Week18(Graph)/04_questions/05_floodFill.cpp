/* -> 733

You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill:
    1. Begin with the starting pixel and change its color to color.
    2. Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
    3. Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
    4. The process stops when there are no more adjacent pixels of the original color to update.

RETURN the modified image after performing the flood fill.

 

Example 1:
    Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
    Output: [[2,2,2],[2,2,0],[2,0,1]]
    Explanation:
    From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

    Note the bottom corner is not colored 2, because it is not horizontally or vertically connected to the starting pixel.


Example 2:
    Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
    Output: [[0,0,0],[0,0,0]]
    Explanation:
    The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.
*/

/*
Approach:- using BFS or DFS
    -- previous question, we did it using BFS. So, lets solve this question using DFS
*/

#include<bits/stdc++.h>
using namespace std;

// using dfs
void dfs(vector<vector<int>>& image, int row, int col, int &color, vector<vector<int>> &ans, int &n, int &m)
{   
    // base case(below case ke wajah se visited matrix ki need nhi)
    if(ans[row][col]==color) return;

    ans[row][col]=color;

    // all four direction movement
    if(row-1>=0 && image[row][col]==image[row-1][col])
        dfs(image, row-1, col, color, ans, n, m); // up

    if(row+1<n && image[row][col]==image[row+1][col])
        dfs(image, row+1, col, color, ans, n, m); // down

    if(col-1>=0 && image[row][col]==image[row][col-1])
        dfs(image, row, col-1, color, ans, n, m); // left

    if(col+1<m && image[row][col]==image[row][col+1])
        dfs(image, row, col+1, color, ans, n, m); // right

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    int n=image.size();
    int m=image[0].size();

    vector<vector<int>> ans = image;

    // in this we are not calling for each cell like previous question, because  in question it is given that from which cell we have to start
    dfs(image, sr, sc, color, ans, n, m);
    
    return ans;
}


int main()
{
    vector<vector<int>> image = {
        {0,0,0},
        {0,0,0}
    };
    int sr=1;
    int sc=0;
    int color=2;

    for(auto vec:floodFill(image, sr, sc, color))
    {
        for(int num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

