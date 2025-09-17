/* -> GFG

Geek is going for a training program. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points arr, corresponding to each day and activity.

Example:
    Input: n=3 and arr[]= [[1,2,5],[3,1,1],[3,3,3]]
    Output:11
    Explanation:Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum point is 11.
*/

/*
Approach:- DP
    1. recursive approach:
        - we have days and each day we have three different activity, so we will have a index 'i' to iterate the days, and for each day we need to know the previous action taken so we need a another index 'prev' which will tell the index of previously taken acitivety:

        So we need two index: i, prev -> 2D DP

        TC:- O(3^(n)) <- more preferable
            OR (confused)
        TC:- O(3^(n) x 4) -> As at each day, 3 choices are made. For n days(rows), this gives 3^n recursive calls, with four possible value of prev -1,0,1,2: -> the total number calls is: O(3^n x 4)
        So the net TC will be: O(3^n)
            -- SO power m wahi jayega jo recursive depth ko decide ker rha h
            -- and 4 issiliye multiply hua becuase prev is independent of the recursive process, so that't why it is acting like a multiplier here, if not then it wouldn't like in question Triangle and minimumPathFallingSum.

        SC:- O(n)

    2. Top-down approach:-
        TC:- O(n*4)*3 -> O(n)
        SC:- O(n) + O(n*4)

    3. Bottom-up approach
        TC:- O(n*4*3) -> O(n)
        SC:- O(n*4)

    4. space optimization
        TC:- O(n*4*3) -> O(n)
        SC:- O(4) -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void dpArray(vector<vector<int>>& dp)
{
    for(auto vec:dp)
    {
        for(auto num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

// recursive approach
int helper(vector<vector<int>>& arr, int &n, int i, int prev)
{
    if(i>=n) return 0;

    int maxi = 0;
    for(int index=0 ; index<3 ; index++)
    {
        int ans = 0;
        if(index!=prev){
            ans = arr[i][index] + helper(arr, n, i+1, index);
        }
        maxi = max(maxi,ans);
    }

    return maxi;
}

int maximumPoints(vector<vector<int>>& arr, int n)
{
    int i=0;
    int prev=-1;
    int ans = helper(arr, n, i, prev);

    return ans;
}


// memoization(top-down approach)
int helper1(vector<vector<int>>& arr, int &n, int i, int prev, vector<vector<int>> &dp)
{
    if(i>=n) return 0;

    // Step3:
    if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];

    int maxi = 0;
    for(int index=0 ; index<3 ; index++)
    {
        int ans = 0;
        if(index!=prev){
            ans = arr[i][index] + helper1(arr, n, i+1, index, dp);// now the prev will be index
        }
        maxi = max(maxi,ans);
    }

    // Step2:
    dp[i][prev+1]=maxi;

    return dp[i][prev+1];
}

int maximumPoints1(vector<vector<int>>& arr, int n)
{
    int i=0;
    int prev=-1;// as prev is -1, so index shifting will be required

    //Step1:
    vector<vector<int>> dp(n, vector<int>(3+1 ,-1));

    int ans = helper1(arr, n, i, prev, dp);

    // printing dp array
    dpArray(dp);

    return ans;
}


// tabulation method
int maximumPoints2(vector<vector<int>>& arr, int n)
{
    //Step1:
    vector<vector<int>> dp(n+1, vector<int>(3+1 ,-1));

    //Step2: initialize it; if(i>=n) return 0
    for(int col=0 ; col<4 ; col++)
    {
        dp[n][col]=0;
    }

    //Step3: use the code of top-down, take for loop of all the changing variable of top-down approach function parameter
    for(int i=n-1; i>=0 ; i--)
    {
        for(int prev=2 ; prev>=-1 ; prev--)
        { 
            int maxi = 0;
            for(int index=0 ; index<3 ; index++)
            {
                int ans = 0;
                if(index!=prev){
                    ans = arr[i][index] + dp[i+1][index+1];// prev was index, that's why index+1
                }
                maxi = max(maxi,ans);
            }

            dp[i][prev+1]=maxi;
        }
    }

    // printing dp array
    dpArray(dp);

    return dp[0][0];
}


// Space optimization
int maximumPoints3(vector<vector<int>>& arr, int n)
{
    //Step1 and Step2: declare and initialize it
    vector<int> currArray(3+1 , 0);
    vector<int> nextArray(3+1 , 0);

    //Step3: use the code of tabulation
    for(int i=n-1; i>=0 ; i--)
    {
        for(int prev=-1 ; prev<=2 ; prev++)
        {
            int maxi = 0;
            for(int index=0 ; index<3 ; index++)
            {
                int ans = 0;
                if(index!=prev){
                    ans = arr[i][index] + nextArray[index+1];// removed i+1 which represent next array
                }
                maxi = max(maxi,ans);
            }

            currArray[prev+1]=maxi; //updated the value of currArray
        }

        // shiftinng is must
        nextArray=currArray;
    }

    // printing single array
    // for(int num:currArray)
    // {
    //     cout << num << " ";
    // }
    // cout << endl;

    return currArray[0];
}



int main()
{
    vector<vector<int>> arr = {
        // {7,6,1},
        // {3,9,7},
        // {1,3,5},
        // {9,7,6},
        // {1,10,1},
        // {1,7,2},
        // {4,9,10},
        // {4,5,5},
        // {7,1,7},
        // {7,2,9},
        {1,2,5},
        {3,1,2},
        {3,2,5},
    };

    int n = arr.size();

    cout << maximumPoints3(arr, n) << endl;

    return 0;
}