/* ->GFG and 1463

You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

You have two robots that can collect chocolates for you:
    1. Robot #1 is located at the top-left corner (0, 0), and
    2. Robot #2 is located at the top-right corner (0, cols - 1).

Return the maximum number of chocolates collection using both robots by following the rules below:
    - From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
    - When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
    - When both robots stay in the same cell, only one takes the chocolates.
    - Both robots cannot move outside of the grid at any moment.
    - Both robots should reach the bottom row in grid.


Example:
    Input: n = 4, m = 3, grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
    Output: 24
    Explanation: Path of robot #1 and #2 are described in color green and blue respectively. Chocolates taken by Robot #1, (3 + 2 + 5 + 2) = 12. Chocolates taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of Chocolates: 12 + 12 = 24.
*/

/*
Approach:-
    Step 1: Express the problem in terms of indexes.
        - we have two robots, so We need to define the function with four parameters  i1,j1,i2, and j2 to describe the positions of robo1 and robo2 at a time.

        - means it seem to have a 4D, but lets think of taking three indixes we can do or not => 3D

        - robo1 and robo2 are at the first row, and they always move to the row below them every time, so they will always be in the same row. So, We can just use single parameter i, which tells us in which row of the grid both of them are. Therefore, we can modify the function. It now takes three parameters: i,j1, and j2

    Step 2: Try out all possible choices at a given index.
        - At every cell, we have three options to go: to the bottom cell (↓), to the bottom-right cell(↘) or to the bottom-left cell(↙).

        - Now, we need to understand that we want to move robo1 and robo2 together. Both of them can individually move three moves but say robo1 moves to bottom-left, then robo2 can have three different moves for Alice’s move, and so on.
            => for move of robo1 there will be three move of robo2
        
        - we can manually write there 9 movements or we can use two nested for loop i.e, for each movement of robo1(i outer for loop) there will be three possible movement for robo2(j inner for loop)

    Step3: Question asked to return maximum, so we will return the maximum of all nine movements


    Memoization-> as we have three variable paramenter in function call, so we are gonna have 3D dp for each unique movement

    1. recursive solution:-
        - total unique states: n x m x m :n-> rows, m-> cols
        - recursive call per state is 9
        - at each row, there is m x m combinations of j1 and j2 
        
        So, TC:- O(9^(n) x m*m) : (3^n(robo1) x 3^n(robo2)) = 9^n
            -- we multiply 𝑚×𝑚 in Chocolate Pickup because j1 and j2 are independent state variables

    2. Memoization:- 
        TC:- O(n*m*m*9) = O(n*m*m)
        SC:- O(n) + O(n*m*m)

    3. Tabulation

    4. Space optimization:-
        -- In 1D we use two variable, In 2D we use two array, so In 3D we will be using two 2D array
*/

#include<bits/stdc++.h>
using namespace std;


// recurive method
int helper(int &n, int &m, vector<vector<int>> &grid, int roboi, int roboj1, int roboj2)
{
    // base case
    if(roboi>=n) return 0;
    if(roboj1<0 || roboj1>=m || roboj2<0 || roboj2>=m) return INT_MIN;

    int ans = INT_MIN;
    for(int i=-1 ; i<=1 ; i++)
    {
        for(int j=-1 ; j<=1 ; j++)
        {
            int recursiveCall; 
            if(roboj1==roboj2)
                recursiveCall = grid[roboi][roboj1] + helper(n, m, grid, roboi+1, roboj1+i, roboj2+j);
            else 
                recursiveCall = grid[roboi][roboj1] + grid[roboi][roboj2] + helper(n, m, grid, roboi+1, roboj1+i, roboj2+j);

            ans = max(ans, recursiveCall);
        }
    }

    return ans;
}

int solve(int n, int m, vector<vector<int>> &grid)
{
    int roboi = 0;
    int roboj1 = 0;
    int roboj2 = m-1;

    return helper(n, m, grid, roboi, roboj1, roboj2);
}


// Memoization
int helper1(int &n, int &m, vector<vector<int>> &grid, int roboi, int roboj1, int roboj2, vector<vector<vector<int>>> &dp)
{
    // base case
    if(roboi>=n) return 0;
    if(roboj1<0 || roboj1>=m || roboj2<0 || roboj2>=m) return INT_MIN;

    //Step3: if answer already exists then return it
    if(dp[roboi][roboj1][roboj2]!=-1)
        return dp[roboi][roboj1][roboj2];

    int ans = INT_MIN;
    for(int i=-1 ; i<=1 ; i++)
    {
        for(int j=-1 ; j<=1 ; j++)
        {
            int recursiveCall; 
            if(roboj1==roboj2)
                recursiveCall = grid[roboi][roboj1] + helper1(n, m, grid, roboi+1, roboj1+i, roboj2+j, dp);
            else 
                recursiveCall = grid[roboi][roboj1] + grid[roboi][roboj2] + helper1(n, m, grid, roboi+1, roboj1+i, roboj2+j, dp);

            ans = max(ans, recursiveCall);
        }
    }

    //Step2: Store results in dp array
    dp[roboi][roboj1][roboj2] = ans;

    return dp[roboi][roboj1][roboj2];
}

int solve1(int n, int m, vector<vector<int>> &grid)
{
    int roboi = 0;
    int roboj1 = 0;
    int roboj2 = m-1;

    //Step1: 3D DP array
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    return helper1(n, m, grid, roboi, roboj1, roboj2, dp);
}


// tabulation
int solve2(int n, int m, vector<vector<int>> &grid)
{
    //Step1:
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m, vector<int>(m, -1)));

    //Step2: initialize it using the base case
    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            dp[n][i][j]=0;
        }
    }

    //Step3: number of loops in, before copying the code of memoization, tabulation method depends on the changing variable in memoization/recursive solution
    for(int roboi=n-1 ; roboi>=0 ; roboi--)
    {
        for(int roboj1=0 ; roboj1<m ; roboj1++)
        {
            for(int roboj2=0 ; roboj2<m ; roboj2++)
            {
                // now copy the code of memoization
                int ans = INT_MIN;
                for(int i=-1 ; i<=1 ; i++)
                {
                    for(int j=-1 ; j<=1 ; j++)
                    {
                        int recursiveCall; 
                        if(roboj1==roboj2)
                        {
                            recursiveCall = grid[roboi][roboj1];
                        }
                        else 
                        {
                            recursiveCall = grid[roboi][roboj1] + grid[roboi][roboj2];
                        }

                        if(roboj1+i<0 || roboj1+i>=m || roboj2+j<0 || roboj2+j>=m) 
                            recursiveCall=INT_MIN;
                        else 
                            recursiveCall +=  dp[roboi+1][roboj1+i][roboj2+j];

                        ans = max(ans, recursiveCall);
                    }
                }
                dp[roboi][roboj1][roboj2] = ans;
            }
        }
    }

    return dp[0][0][m-1];
}


// Space optimization
int solve3(int n, int m, vector<vector<int>> &grid)
{
    //Step1: for 3D DP we are gonna use 2D array
    vector<vector<int>> next(m, vector<int>(m, 0));
    vector<vector<int>> curr(m, vector<int>(m, -1));

    //Step2: initialize it using the base case
    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            next[i][j]=0;
        }
    }

    //Step3
    for(int roboi=n-1 ; roboi>=0 ; roboi--)
    {
        for(int roboj1=0 ; roboj1<m ; roboj1++)
        {
            for(int roboj2=0 ; roboj2<m ; roboj2++)
            {
                int ans = INT_MIN;
                for(int i=-1 ; i<=1 ; i++)
                {
                    for(int j=-1 ; j<=1 ; j++)
                    {
                        int recursiveCall; 
                        
                        if(roboj1==roboj2)
                        {
                            recursiveCall = grid[roboi][roboj1];
                        }
                        else 
                        {
                            recursiveCall = grid[roboi][roboj1] + grid[roboi][roboj2];
                        }

                        if(roboj1+i<0 || roboj1+i>=m || roboj2+j<0 || roboj2+j>=m) 
                            recursiveCall=INT_MIN;
                        else 
                            recursiveCall +=  next[roboj1+i][roboj2+j];// roboi+1 means next wala 2D array

                        ans = max(ans, recursiveCall);
                    }
                }

                curr[roboj1][roboj2] = ans; // roboi means curr wala 2D array
            }
        }

        // don't forget to shift
        next = curr;
    }

    return next[0][m-1];
}


int main()
{
    vector<vector<int>> grid = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };

    int n = grid.size();
    int m = grid[0].size();

    cout << solve3(n, m, grid) << endl;

    return 0;
}

