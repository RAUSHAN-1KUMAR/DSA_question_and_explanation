/* -> 375

We are playing the Guessing Game. The game will work as follows:

    1. I pick a number between 1 and n.
    2. You guess a number.
    3. If you guess the right number, you win the game.
    4. If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
    5. Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.

Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I pick.


Example 1:
    Input: n = 10
    Output: 16
    Explanation: The winning strategy is as follows:
    - The range is [1,10]. Guess 7.
        - If this is my number, your total is $0. Otherwise, you pay $7.
        - If my number is higher, the range is [8,10]. Guess 9.
            - If this is my number, your total is $7. Otherwise, you pay $9.
            - If my number is higher, it must be 10. Guess 10. Your total is $7 + $9 = $16.
            - If my number is lower, it must be 8. Guess 8. Your total is $7 + $9 = $16.
        - If my number is lower, the range is [1,6]. Guess 3.
            - If this is my number, your total is $7. Otherwise, you pay $3.
            - If my number is higher, the range is [4,6]. Guess 5.
                - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $5.
                - If my number is higher, it must be 6. Guess 6. Your total is $7 + $3 + $5 = $15.
                - If my number is lower, it must be 4. Guess 4. Your total is $7 + $3 + $5 = $15.
            - If my number is lower, the range is [1,2]. Guess 1.
                - If this is my number, your total is $7 + $3 = $10. Otherwise, you pay $1.
                - If my number is higher, it must be 2. Guess 2. Your total is $7 + $3 + $1 = $11.
    The worst case in all these scenarios is that you pay $16. Hence, you only need $16 to guarantee a win.


Example 2:
    Input: n = 1
    Output: 0
    Explanation: There is only one possible number, so you can guess 1 and not have to pay anything.


Example 3:
    Input: n = 2
    Output: 1
    Explanation: There are two possible numbers, 1 and 2.
    - Guess 1.
        - If this is my number, your total is $0. Otherwise, you pay $1.
        - If my number is higher, it must be 2. Guess 2. Your total is $1.
    The worst case is that you pay $1.
*/


/*-- explained in note copy

Appraoch:- DP
    0. recursion approach
    1. Top-down approach
    2. Bottom-up approach
    3. space optimization (not possible)
*/

#include<bits/stdc++.h>
using namespace std;

// recursion
int solveUsingRecursion(int start, int end)
{
    // base case
    // range se bahar, zero penalty
    // sirf ek hi number hai, zero penalty
    if(start>=end) return 0;
        
    int ans = INT_MAX;

    for(int i=start; i<=end; i++)
    {
        int lower = solveUsingRecursion(start, i-1);
        int higher = solveUsingRecursion(i+1, end);

        // i -> current wala wrong penalty
        int newAns = i + max(lower, higher);

        ans = min(ans, newAns);
    }

    return ans;
}

int getMoneyAmount(int n) 
{
    int start = 1;
    int end = n;

    int ans = solveUsingRecursion(start, end);

    return ans;
}


// top-down appraoch
int solveUsingRecursion1(int start, int end, vector<vector<int>> &dp)
{
    if(start>=end) return 0;

    // Step3: return answer if already exits
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }

    int ans = INT_MAX;

    for(int i=start; i<=end; i++)  
    {
        int lower = solveUsingRecursion1(start, i-1, dp); 
        int higher = solveUsingRecursion1(i+1, end, dp);

        int newAns = i + max(lower, higher);

        ans = min(ans, newAns);
    }

    //Step2: store the result in dp array
    dp[start][end] = ans;

    return dp[start][end];
}

int getMoneyAmount1(int n) 
{
    int start = 1;
    int end = n;

    //Step1: create dp array
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    int ans = solveUsingRecursion1(start, end, dp);

    // for(auto eachVec:dp)
    // {
    //     for(auto num:eachVec)
    //     {
    //         if(num!=-1) cout << " " << num << " ";
    //         else cout << num << " ";
    //     }
    //     cout << endl;
    // }

    return ans;
}


// Bottom-up approach
int getMoneyAmount2(int n) 
{
    int start = 1;
    int end = n;

    //Step1: create dp array
    vector<vector<int>> dp(n+2, vector<int>(n+1, -1));

    //Step2: initialize the dp array using the base case of top-down approach
    for(int start=0 ; start<n+2 ; start++)
    {
        for(int end=0 ; end<n+1 ; end++)
        {
            if(start>=end)
            {
                dp[start][end]=0; 
            }
        }
    }

    // Step3: fill the remaining dp array using the logic of top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int start_i = n ; start_i >= 1 ; start_i--) // start -> 1 se n tak
    {
        for(int end_i = start_i+1 ; end_i <= n ; end_i++) // end -> n se start tak  
        {
            int ans = INT_MAX;

            for(int i=start_i; i<=end_i; i++)
            {
                int lower = dp[start_i][i-1];
                int higher = dp[i+1][end_i];

                int newAns = i + max(lower, higher);

                ans = min(ans, newAns);
            }

            dp[start_i][end_i] = ans;


        }
    }

    // cout << endl;
    // for(auto eachVec:dp)
    // {
    //     for(auto num:eachVec)
    //     {
    //         if(num!=-1) cout << " " << num << " ";
    //         else cout << num << " ";
    //     }
    //     cout << endl;
    // }

    return dp[1][n];
}


int main()
{
    int n = 5;

    cout << getMoneyAmount2(n) << endl;

    return 0;
}