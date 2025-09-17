/* GFG

Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10 } and a target value n. Find the minimum number of coins and/or notes needed to make the change for Rs n. 

Examples:
    Input: n = 39
    Output: 6
    Explaination: 39 can be formed using 3 coins of 10 rupees, 1 coin of 5 rupees and 2 coins of 2 rupees so minimum coins required are 6.

    Input: n = 121
    Output: 13
    Explaination: 121 can be formed using 12 coins of 10 rupees and 1 coin of 1 rupees.
*/

#include<bits/stdc++.h>
using namespace std;

int findMin(int n)
{
    vector<int> coins = {10, 5, 2, 1};
    int ans=0;
    for(int i=0 ; i<4 && n>=0 ; i++)
    {
        if(coins[i]>n)
            continue;

        int times = n/coins[i];
        ans += times;
        n -= times * coins[i];
    }

    return ans;
}

int main()
{
    int n = 121;
    cout << findMin(n) << endl;
    return 0;
}

