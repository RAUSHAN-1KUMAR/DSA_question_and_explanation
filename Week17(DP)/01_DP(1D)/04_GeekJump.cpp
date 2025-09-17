/* -> GFG
Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.


Example:
    Input: n = 4, height = {10 20 30 10}
    Output: 20
    Explanation: Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost). Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost). So, total energy lost is 20 which is the minimum.
*/

/*
Approach:-
    -- similar to climbStair, we just have to add the abs(difference) of the steps taken, and then return minimum
        1. recursion -> TC: O(2^n), SC: O(n)
        2. top-down -> TC: O(n), SC: O(n)+O(n)
        3. bottom-up -> TC: O(n), SC: O(n)
        4. space Opti -> TC: O(n), SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

// recursive solution
int minimumEnergyHelper(vector<int> &height, int m)
{
    if(m==0) return 0;
    if(m==1) return abs(height[0]-height[1]);

    int oneStep = abs(height[m]-height[m-1]) + minimumEnergyHelper(height, m-1);
    
    int twoStep = abs(height[m]-height[m-2]) + minimumEnergyHelper(height, m-2);
    
    return min(oneStep, twoStep);  
}

int minimumEnergy(vector<int> &height, int n)
{
    return minimumEnergyHelper(height, n-1);
}


// top-down approach
int minimumEnergyHelper1(vector<int> &height, int m, vector<int> &dp)
{
    if(m==0) return 0;
    if(m==1) return abs(height[0]-height[1]);

    // Step3:
    if(dp[m]!=-1)
        return dp[m];

    int oneStep = abs(height[m]-height[m-1]) + minimumEnergyHelper1(height, m-1, dp);
    int twoStep = abs(height[m]-height[m-2]) + minimumEnergyHelper1(height, m-2, dp);

    // Step2:
    dp[m] = min(oneStep, twoStep);
    
    return dp[m];  
}

int minimumEnergy1(vector<int>& height, int n) 
{
    // Step1:
    vector<int> dp(n, -1);

    return minimumEnergyHelper1(height, n-1, dp);
}


// tabulation (bottom-up approach)
int minimumEnergy2(vector<int>& height, int n)
{
    // Step1:
    vector<int> dp(n, -1);

    // Step2:
    dp[0] = 0;
    dp[1] = abs(height[0]-height[1]);

    // Step3: fill the remaining using recusive logic of top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int i=2 ; i<n ; i++)
    {
        int oneStep = abs(height[i]-height[i-1]) + dp[i-1];
        int twoStep = abs(height[i]-height[i-2]) + dp[i-2];

        dp[i] = min(oneStep, twoStep);
    }

    return dp[n-1];
}


// space optimzation
int minimumEnergy3(vector<int>& height, int n)
{
    // Step1:
    int prevPrev = 0;
    int prev = abs(height[0]-height[1]);

    // Step2: use the same for loop of tabulation method
    for(int i=2 ; i<n ; i++)
    {
        int oneStep = abs(height[i]-height[i-1]) + prev;
        int twoStep = abs(height[i]-height[i-2]) + prevPrev;

        prevPrev = prev;
        prev = min(oneStep, twoStep);
    }

    return prev;
}


int main()
{
    vector<int> height = {10,20,30,10};
    int n = 4;

    cout << minimumEnergy(height, n) << endl;

    return 0;
}