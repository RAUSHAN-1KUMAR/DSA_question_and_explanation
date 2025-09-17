/* -> 3413

There are an infinite amount of bags on a number line, one bag for each coordinate. Some of these bags contain coins.

You are given a 2D array coins, where coins[i] = [li, ri, ci] denotes that every bag from li to ri contains ci coins.

The segments that coins contain are non-overlapping.

You are also given an integer k.

Return the maximum amount of coins you can obtain by collecting k consecutive bags.

 

Example 1:
    Input: coins = [[8,10,1],[1,3,2],[5,6,4]], k = 4
    Output: 10
    Explanation: Selecting bags at positions [3, 4, 5, 6] gives the maximum number of coins: 2 + 0 + 4 + 4 = 10.

Example 2:
    Input: coins = [[1,10,3]], k = 2
    Output: 6
    Explanation: Selecting bags at positions [1, 2] gives the maximum number of coins: 3 + 3 = 6.

*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

long long maximumCoins(vector<vector<int>> &coins, int k)
{
    sort(coins.begin(), coins.end(), [](vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    });

    int n = coins.size();
    ll ans = 0;
    ll curr = 0;

    // first taking the starting point of each interval
    for(int i=0, j=0;  i<n; i++)
    {
        int reach = coins[i][0]+k-1;
        
        while(j<n && reach>=coins[j][1])
        {
            int interval = coins[j][1]-coins[j][0]+1;
            int coin = coins[j][2];

            curr += 1LL*(interval*coin);
            j++;
        }

        ans = max(ans, curr);

        if(j<n){
            int leftInterval = coins[i][0]+k-coins[j][0];// it can be negative
            ll leftPart = 1LL*(0, leftInterval)*coins[j][2];

            ans = max(ans, curr+leftPart);
        }

        // i will go to next interval so, remove the coin for current i
        curr -= 1ll*(coins[i][1]-coins[i][0]+1)*coins[i][2];
    }

    curr=0;

    // now taking the last point of each intervals
    for(int i=n-1, j=n-1; j>=0 ; j--)
    {
        int reach = coins[j][1]-k+1;
        
        while(i>=0 && reach<=coins[i][0])
        {
            int interval = coins[i][1]-coins[i][0]+1;
            int coin = coins[i][2];

            curr += 1LL*(interval*coin);
            i--;
        }

        ans = max(ans, curr);

        if(i>=0){
            int leftInterval = coins[i][1]-(coins[j][1]-k);// it can be negative
            ll leftPart = 1LL*(0, leftInterval)*coins[i][2];

            ans = max(ans, curr+leftPart);
        }

        // j will go to next interval so, remove the coin for current j
        curr -= 1ll*(coins[j][1]-coins[j][0]+1)*coins[j][2];
    }

    return ans;
}


int main()
{
    vector<vector<int>> coins = {
        {8,10,1},
        {1,3,2},
        {5,6,4}
    };

    cout << maximumCoins(coins, 4) << endl;

    return 0;
}

