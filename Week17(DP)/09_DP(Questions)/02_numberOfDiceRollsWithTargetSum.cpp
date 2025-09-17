/* -> 1155

You have n dice, and each dice has k faces numbered from 1 to k.
 
Given three integers n, k, and target, return the number of possible ways (out of the k^n total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 10^9 + 7.

 
Example 1:
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.

Example 2:
Input: n = 2, k = 6, target = 7
Output: 6
Explanation: You throw two dice, each with 6 faces.
There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:
Input: n = 30, k = 30, target = 500
Output: 222616187
Explanation: The answer must be returned modulo 109 + 7.
*/ 

 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long int MOD = 1000000007;

// top-down approach
int dpHelper(int n, int k, int target, vector<vector<int>> &dp)
{
    if(target<0) return 0;
    if(n==0 && target == 0) return 1;
    if(n==0 && target != 0) return 0;
    if(n!=0 && target ==0) return 0;

    //Step3: return if answer already exits
    if(dp[n][target]!=-1)
    {
        return dp[n][target];   
    }

    int ans = 0;
    for(int i=1 ; i<=k ; i++)
    {
        ans = (ans + dpHelper(n-1, k, target-i, dp))%MOD;
    }

    //Step2: store the result in dp array
    dp[n][target] = ans;
  
    return dp[n][target];
}

int numRollsToTarget(int n, int k, int target)
{
    //Step1: create dp array
    vector<vector<int>> dp(n+1, vector<int>(target+1, -1));

    int ans = dpHelper(n, k, target, dp);

    return ans;
}


// bottom-up approach
int numRollsToTarget1(int n, int k, int target)
{
    //Step1 and 2: create dp array and initilize it with the base case
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    // if(n==0 && target == 0) return 1;
    dp[0][0]=1;

    // fill remaining dp array using the logic of top-down approach
    for(int n_i=1 ; n_i<=n ; n_i++)
    {
        for(int target_i=1 ; target_i<=target ; target_i++)
        {
            int ans = 0;
            for(int i=1 ; i<=k ; i++)
            {   
                if(target_i-i >= 0)
                    ans = (ans + dp[n_i-1][target_i-i])%MOD;
            }

            dp[n_i][target_i] = ans;
        }
    }


    return dp[n][target];
}


int main()
{
    int n=2, k=6, target=7;

    cout << numRollsToTarget1(n,k,target) << endl;
    
    return 0;
}
