/* GFG
we have a maze and a rat in it, he have to reach in its destination but:
    - 0 (can't go to zero)
    - 1 (can only go to one)
    - rat has only four movement(up, down, right, left)
Return all possible ways..
*/

/*
In every movement we have three posibility that can cause unsage movement:-
    1. closed path i.e., if 0 is there
    2. out of bound chale gye
    3. if position is already visited
*/

/*
Note:-
    x -> row
    y -> col
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// a function that will handle the safe movement of rat
bool isSafe(int newx, int newy, int maze[][4], int row, int col, vector<vector<bool>> &visited)
{
    if(
        (newx >= 0 && newx < row) &&
        (newy >= 0 && newy < col) &&
        maze[newx][newy]==1 &&
        visited[newx][newy] == false
    ) return true;

    return false;
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string output, vector<vector<bool>> &visited)
{ 
    // base case
    // destination coordinates will be row-1, col-1
    if(srcx==row-1 && srcy==col-1){
        cout << output << endl;
        return;
    }

    // ek case solve kro

    // up movement(row will reduce by one)
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(newx,newy,maze,row,col,visited)){
        // mark visited
        visited[newx][newy]=true;
        output.push_back('U');

        // call recursion
        printAllPath(maze, row, col, newx, newy, output, visited);


        // backTracking
        output.pop_back();
        visited[newx][newy]=false;
    }

    // right movement(col will increase by one)
    newx = srcx;
    newy = srcy+1;
    if(isSafe(newx,newy,maze,row,col,visited)){
        // mark visited
        visited[newx][newy]=true;
        output.push_back('R');

        // call recursion
        printAllPath(maze, row, col, newx, newy, output, visited);

        // backTracking
        output.pop_back();
        visited[newx][newy]=false;
    }

    // down movement(row will increase by one)
    newx = srcx+1;
    newy = srcy;
    if(isSafe(newx,newy,maze,row,col,visited)){
        // backTracking
        visited[newx][newy]=true;
        output.push_back('D');

        // call recursion
        printAllPath(maze, row, col, newx, newy, output, visited);

        // mark visited
        output.pop_back();
        visited[newx][newy]=false;
    }

    // left movement(col will reduce by one)
    newx = srcx;
    newy = srcy-1;
    if(isSafe(newx,newy,maze,row,col,visited)){
        // mark visited
        visited[newx][newy]=true;
        output.push_back('L');

        // call recursion
        printAllPath(maze, row, col, newx, newy, output, visited);
        
        // backTracking
        output.pop_back();
        visited[newx][newy]=false;
    }
}


int main()
{
    int maze[4][4] = {
        {1,0,0,0},
        {1,1,0,0},
        {1,1,1,0},
        {1,1,1,1}
    };

    int row = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";

    vector<vector<bool>> visited(row, vector<bool>(col,false));

    // if src position is closed
    if(maze[0][0]==0){
        cout << "No Path Exists" << endl;
    }
    else{
        visited[srcx][srcy] = true;
        printAllPath(maze, row, col, srcx, srcy, output, visited);
    }

    return 0;
}
