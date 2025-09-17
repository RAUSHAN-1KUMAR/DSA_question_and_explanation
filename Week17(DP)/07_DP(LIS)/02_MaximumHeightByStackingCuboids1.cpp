/* -> 1691

Given n cuboids where the dimensions of the ith cuboid is cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose a subset of cuboids and place them on each other.

You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating it to put it on another cuboid.

Return the maximum height of the stacked cuboids.


Example 1:
    Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
    Output: 190
    Explanation:
    Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
    Cuboid 0 is placed next with the 45x20 side facing down with height 50.
    Cuboid 2 is placed next with the 23x12 side facing down with height 45.
    The total height is 95 + 50 + 45 = 190.


Example 2:
    Input: cuboids = [[38,25,45],[76,35,3]]
    Output: 76
    Explanation:
    You can't place any of the cuboids on the other.
    We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.


Example 3:
    Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
    Output: 102
    Explanation:
    After rearranging the cuboids, you can see that all cuboids have the same dimension.
    You can place the 11x7 side down on all cuboids so their heights are 17.
    The maximum height of stacked cuboids is 6 * 17 = 102.
*/

/*
Approach:
    1. Top-Down appraoch
    2. Bottom-up approach
    3. space optimization
    4. More Space optimazation
*/

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &curr, vector<int> &prev)
{
    // curr -> bada wala dabba
    // prev -> chotte wala dabba
    
    if(prev[0] <= curr[0] && prev[1] <= curr[1] && prev[2] <= curr[2])
        return true;
    
    return false;
}


// top-down appraoch
int lengthOfLIS1(vector<vector<int>> &cuboids, int curr, int prev, vector<vector<int>> &dp)
{
    if(curr>=cuboids.size()) return 0;

    //Step3:  return the answer if already exists in dp array
    if(dp[curr][prev+1]!=-1)
    {
        return dp[curr][prev+1];
    }

    int include = 0;
    if(prev == -1 || check(cuboids[curr], cuboids[prev]))
    {
        int heightCurr = cuboids[curr][2];
        include = heightCurr + lengthOfLIS1(cuboids, curr+1, curr, dp);
    }

    int exclude = 0 + lengthOfLIS1(cuboids, curr+1, prev, dp);

    //Step2: store the result in dp array
    dp[curr][prev+1] = max(include, exclude);

    return dp[curr][prev+1];
}

int maxHeight1(vector<vector<int>> &cuboids)
{
    for(auto &cuboid : cuboids)
    {
        sort(cuboid.begin(), cuboid.end());
    }

    sort(cuboids.begin(), cuboids.end());

    // Step1: create dp array
    int n = cuboids.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    int curr = 0;
    int prev = -1;
    int ans = lengthOfLIS1(cuboids, curr, prev, dp);

    return ans;
}


// Bottom-up Appraoch
int maxHeight2(vector<vector<int>> &cuboids)
{
    for(auto &cuboid : cuboids)
    {
        sort(cuboid.begin(), cuboid.end());
    }

    sort(cuboids.begin(), cuboids.end());

    // Step1 and 2: create dp array and initialize it using the base case of top-down appraoch
    int n = cuboids.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // Step3: fill the remaining dp array using the logic of top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int curr = n-1 ; curr>=0 ; curr--) // curr -> as row 
    {
        for(int prev = curr-1 ; prev>=-1 ; prev--) // prev -> as col
        {
            int include = 0;
            if(prev == -1 || check(cuboids[curr], cuboids[prev]))
            {
                int heightCurr = cuboids[curr][2];
                include = heightCurr + dp[curr+1][curr+1];
            }
            int exclude = 0 + dp[curr+1][prev+1];

            dp[curr][prev+1] = max(include, exclude);
        }
    }

    return dp[0][-1+1];
}


// space optimization
int maxHeight3(vector<vector<int>> &cuboids)
{
    for(auto &cuboid : cuboids)
    {
        sort(cuboid.begin(), cuboid.end()); 
    }

    sort(cuboids.begin(), cuboids.end()); 

    // Step1: remove the dp array
    // int n = cuboids.size();
    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    int n = cuboids.size();

    // Step2:
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    // Step3: use the code of bottom-up apprach
    for(int curr_index=n-1 ; curr_index>=0 ; curr_index--)
    {
        for(int prev_index=curr_index-1 ; prev_index>=-1 ; prev_index--)
        {
            int include = 0;
            if(prev_index==-1 || check(cuboids[curr_index],cuboids[prev_index]))
            {
                int heightToAdd = cuboids[curr_index][2];
                include = heightToAdd + nextRow[curr_index+1]; //dp[curr+1][curr+1] -> curr+1 matlab nextRow
            }

            int exclude = 0 + nextRow[prev_index+1]; //dp[curr+1][prev+1] -> curr+1 matlab nextRow

            currRow[prev_index+1] = max(include, exclude); //dp[curr][prev+1] -> curr matalb currRow
        }

        // shifting
        nextRow = currRow;
    }

    return nextRow[0];
}

// More space optimazation
int maxHeight4(vector<vector<int>> &cuboids)
{
    for(auto &cuboid : cuboids)
    {
        sort(cuboid.begin(), cuboid.end()); 
    }

    sort(cuboids.begin(), cuboids.end()); 

    int n = cuboids.size();

    // bas ek row se kaam ho jayega: on Doing Change1 only
    vector<int> singleRow(n+1, 0);

    // use the code of space optimization
    for(int curr_index=n-1 ; curr_index>=0 ; curr_index--)
    {
        //Change1 -> prev_index -1 se (curr_index-1) tak le jao
        for(int prev_index=-1 ; prev_index<=curr_index-1 ; prev_index++)
        {
            int include = 0;
            if(prev_index==-1 || check(cuboids[curr_index],cuboids[prev_index]))
            {
                int heightToAdd = cuboids[curr_index][2];
                include = heightToAdd+singleRow[curr_index+1];
            }

            int exclude = 0 + singleRow[prev_index+1];

            singleRow[prev_index+1] = max(include, exclude);
        }

        // no shifting-> only one row to shifting kya kerna
    }

    return singleRow[0];
}

int main()
{
    vector<vector<int>> cuboids = {
        {50,45,20},
        {95,37,53},
        {45,23,12},
        {54,65,38},
        {39,75,55}
    };

    int ans = maxHeight4(cuboids);

    cout << ans << endl;

    return 0;
}