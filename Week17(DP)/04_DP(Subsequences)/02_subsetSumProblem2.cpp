/*
Given an array of positive integers, arr[] and a value, target, determine if there is a subset of the given set with sum equal to given target. 

Examples:
    Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
    Output: true 
    Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.


    Input: arr[] = [3, 34, 4, 12, 5, 2], target = 30
    Output: false
    Explanation: There is no subset with target sum 30.


    Input: arr[] = [1, 2, 3], sum = 6
    Output: true
    Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
*/

/*
Approach:-
    -- meet in the middle, storing all possible sum of half of the given array into other vectors and then using binary search to find the target sum

But it would give TLE, because arr.size()<=200; half of it would be 100 and still 2^(100) is very large. 

So, the previous DP solution is correct way to solve it
*/

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr);

// we can also use a recursive function to find all different subset sum
void calculateSum(vector<int>&arr, vector<int> &half, int n, int offset)
{
    int subset_ct=(1<<n);

    for(int i=0 ; i<subset_ct ; i++)
    {   
        int sum=0;
        for(int j=0 ; j<n ; j++)
        {
            if(i & (1<<j))
                sum+=arr[j+offset];
        }
        half.push_back(sum);
    }
}


bool isSubsetSum(vector<int> &arr, int target)
{
    int n=arr.size();

    vector<int> leftSum;
    vector<int> rightSum;

    calculateSum(arr, leftSum, (n+1)/2, 0);
    calculateSum(arr, rightSum, n/2, (n+1)/2);

    sort(rightSum.begin(), rightSum.end());

    // lets find the sum
    for(int i=0 ; i<leftSum.size() ; i++)
    {
        int lSum = leftSum[i];
        int reqSum = target-lSum;

        auto it = lower_bound(rightSum.begin(), rightSum.end(), reqSum);

        if(it!=rightSum.end() && *it==reqSum)
            return true;

    }

    return false;
}


int main()
{
    vector<int> arr = {4, 3, 5, 10};
    int target = 10;

    cout << isSubsetSum(arr, target) << endl;

    return 0;
}


void printArray(vector<int> &arr)
{
    for(int num:arr)
    {
        cout <<  num << " ";
    }
    cout << endl;
}
