/* GFG

Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

Examples :
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
    recursion + some mathematics:-
        -- let s1+s2=totalSum
               s1-s2=d

               => s1 = (totalSum+d)/2 ; (totalSum+d) must be even

               so now question is similar to count_the_perfect_sum for s1
*/

#include<bits/stdc++.h>
using namespace std;

// recursive solution
int helper(vector<int>& arr, int i, int sum)
{
    // base case
    if(i==0)
    {
        if(sum==0 && arr[0]==0) return 2;// because we have two option either we take it or not take it

        if(sum==0 || sum==arr[0]) return 1;// if arr[i]==sum or sum==0, we have only one option

        return 0;
    }

    int exclude = helper(arr, i-1, sum);

    int include= 0;
    if(arr[i]<=sum)
        include = helper(arr, i-1, sum-arr[i]);

    return include+exclude;
}

int countPartitions(vector<int>& arr, int d)
{
    int n=arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    // if totalsum<d or totalSum is odd, return false
    if((totalSum-d<0) || (totalSum-d)%2) return false;

    // now we just have to count the subsets whose sum up to the target
    int target = (totalSum-d)/2;

    int ans = helper(arr, n-1, target);

    return ans;
}


// tabulation method
int countPartitions1(vector<int>& arr, int d)
{
    int n=arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    if((totalSum-d<0) || (totalSum-d)%2) return false;
    
    int target = (totalSum-d)/2;

    //Step1:
    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    //Step2: initalize dp array using the base case: dp(index, sum)
    if(arr[0]==0) dp[0][0] = 2; // if(sum==0 && arr[0]==0) return 2;
    else dp[0][0] = 1;          // if(sum==0 && arr[0]!=0) return 1;

    if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]] = 1; // if(at index 0 sum==arr[0]) return 1

    //Step3:
    for(int ind = 1; ind<n ; ind++)
    {
        for(int sum=0 ; sum<=target ; sum++)
        {
            int exclude = dp[ind-1][sum];

            int include=0;
            if(arr[ind]<=sum) include = dp[ind-1][sum-arr[ind]];

            dp[ind][sum] = exclude + include;
        }
    }

    return dp[n-1][target];
}


int main()
{
    vector<int> arr = {1,1,1,1};
    int d=0;

    cout << countPartitions1(arr, d) << endl;

    return 0;
}

