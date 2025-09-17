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
    -- To optimize the TC, we can the logic of 'merge interval' question
    -- we have loop for both x and y directions
*/


#include<bits/stdc++.h>
using namespace std;


bool checkValidCuts(int n, vector<vector<int>>& rectangles) 
{
    // rectangles: x1, y1, x2, y2
    int size = rectangles.size();

    // lets check for x direction first(0_2_)
    sort(rectangles.begin(), rectangles.end(), [](vector<int> &a, vector<int>&b){
        return a[0]<b[0];
    });

    vector<vector<int>> result;
    result.push_back(rectangles[0]);//intitializing the result vector
    int i=1;
    while(i<size)
    {
        if(result.back()[2]>rectangles[i][0]){
            result.back()[2] = max(result.back()[2], rectangles[i][2]);
        }
        else{
            result.push_back(rectangles[i]);
        }
        i++;
    }
    
    if(result.size()>=3) return true;



    // lets check for y direction (_1_3)
    sort(rectangles.begin(), rectangles.end(), [](vector<int> &a, vector<int>&b){
        return a[1]<b[1];
    });

    result.clear();
    result.push_back(rectangles[0]);//intitializing the result vector
    i=1;
    while(i<size)
    {
        if(result.back()[3]>rectangles[i][1]){
            result.back()[3] = max(result.back()[3], rectangles[i][3]);
        }
        else{
            result.push_back(rectangles[i]);
        }
        i++;
    }

    if(result.size()>=3) return true;

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