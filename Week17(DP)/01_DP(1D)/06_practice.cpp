/*
Geek jumps
*/

#include<bits/stdc++.h>
using namespace std;

int minimizeCost(int &k, vector<int> &nums)
{
    int n=nums.size();

    // Step1
    vector<int> dp(k, -1);

    // Step2: using base case
    dp[k-1]=0;

    // Step3: for loop in place of recursion for each changing parameter
    for(int i=n-2 ; i>=0 ; i--)
    {
        int ans=INT_MAX;
        for(int j=1 ; j<=k ; j++)
        {
            if(i+j < k){
                int callAns = dp[(i+j)%k];
                if(callAns!=INT_MAX){
                    ans=min(ans, ((abs(nums[i]-nums[i+j]))+callAns));
                }
            }
        }
        dp[i%k]=ans;
    }

    return dp[0];
}



int main()
{
    vector<int> arr = {10,30,40,50,20};
    int k=10;

    cout << minimizeCost(k, arr) << endl;
    return 0;
}

