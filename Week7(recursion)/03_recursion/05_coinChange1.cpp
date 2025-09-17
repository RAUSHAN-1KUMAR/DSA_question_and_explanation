/* -> 322

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.


Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
*/

/*
Note:- Little bit optimised, notice the change w.r.t previous solution
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int solve(vector<int>& coins, int amount, int index)
{
    if(amount == 0) return 0;
    if(amount < 0) return INT_MAX;

    int mini = INT_MAX;

    //Change3
    for(int i=index ; i<coins.size() ; i++)
    {
        int aageKaAns = solve(coins, amount-coins[i], i);//Change4
        if(aageKaAns != INT_MAX){
            int ans = 1+aageKaAns;
            mini = min(mini, ans);
        }
    }

    return mini;
}

int coinChange(vector<int>& coins, int amount)
{
    int index = 0;//Change1
    int ans = solve(coins, amount, index);//Change2

    return ans==INT_MAX ? -1 : ans;
}


int main()
{
    vector<int> coins = {1,2,5};
    int amount = 11;

    cout << coinChange(coins, amount) << endl;

    return 0;
}



