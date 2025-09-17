/* GFG

Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

Examples:
    Input: arr[] =  [5, 2, 6, 4], d = 3
    Output: 1
    Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.


    Input: arr[] = [1, 1, 1, 1], d = 0 
    Output: 6 
    Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and remaning two 1's in sum2.
    Thus there are total 6 ways for partition the array arr. 


    Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
    Output: 2
*/


/*
Approach:-
    1. resursion:- taking two indexes: (i, sum(from 0))
        -- exclude, include wala case

    2. recursion + some mathematics:- next solution
        -- let s1+s2=totalSum
               s1-s2=d

               => s1 = (totalSum+d)/2 ; (totalSum+d) must be even

               so now question is similar to count_the_perfect_sum for s1 -> see next solution

    3. Meet in the middle:- only if arr[i]>=1
*/

#include<bits/stdc++.h>
using namespace std;


// recursive solution
int helper(vector<int>& arr, int i, int sum1, int &totalSum, int &d)
{
    // base case
    if(i>=arr.size()) return 0;


    sum1+=arr[i]; // include
    int sum2 = totalSum-sum1;

    int include;
    if(sum1-sum2==d)
        include = 1 + helper(arr, i+1, sum1, totalSum, d);
    else 
        include = 0 + helper(arr, i+1, sum1, totalSum, d);

    sum1-=arr[i]; // exclude
    int exclude = helper(arr, i+1, sum1, totalSum, d);

    return include+exclude;
}

int countPartitions(vector<int>& arr, int d)
{
    int i=0;
    int sum=0;
    int totalSum=accumulate(arr.begin(), arr.end(), 0);

    return helper(arr, i, sum, totalSum, d);
}


// memoization
int helper1(vector<int>& arr, int i, int sum1, int &totalSum, int &d, vector<vector<int>> &dp)
{
    // base case
    if(i>=arr.size()) return 0;

    //Step3:
    if(dp[i][sum1]!=-1)
        return dp[i][sum1];


    sum1+=arr[i];
    int sum2 = totalSum-sum1;

    int include;
    if(sum1-sum2==d)
        include = 1 + helper1(arr, i+1, sum1, totalSum, d, dp);
    else 
        include = 0 + helper1(arr, i+1, sum1, totalSum, d, dp);

    sum1-=arr[i];
    int exclude = helper1(arr, i+1, sum1, totalSum, d, dp);

    //Step2:
    dp[i][sum1] = include+exclude;

    return dp[i][sum1];
}

int countPartitions1(vector<int>& arr, int d)
{
    int i=0;
    int sum=0;
    int totalSum=accumulate(arr.begin(), arr.end(), 0);

    //Step1:
    vector<vector<int>> dp(arr.size(), vector<int>(totalSum+1, -1));

    return helper1(arr, i, sum, totalSum, d, dp);
}


// tabulation
int countPartitions2(vector<int>& arr, int d)
{
    int sum=0;
    int totalSum=accumulate(arr.begin(), arr.end(), 0);
    int n=arr.size();

    //Step1:
    vector<vector<int>> dp(arr.size()+1, vector<int>(totalSum+1, -1));

    //Step2: initialization
    for(int col=0 ; col<=totalSum ; col++)
    {
        dp[n][col]=0;
    }

    //Step3: i and sum
    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int sum1=totalSum; sum1>=0 ; sum1--)
        {
            sum1+=arr[i];
            int sum2 = totalSum-sum1;

            int include;
            if(sum1-sum2==d)
                include = 1 + dp[i+1][sum1];
            else 
                include = 0 + dp[i+1][sum1];

            sum1-=arr[i];
            int exclude = helper1(arr, i+1, sum1, totalSum, d, dp);

            dp[i][sum1] = include+exclude;
        }
    }
    
    return dp[0][0];
}


int main()
{
    vector<int> arr = {1,1,1,1};
    int d=0;

    cout << countPartitions(arr, d) << endl;

    return 0;
}

