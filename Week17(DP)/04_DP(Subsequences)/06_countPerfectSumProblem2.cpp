/* GFG 
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Note: It is guaranteed that the product of the length of arr and target will not exceed 106

Examples:
    Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
    Output: 3
    Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

    Input: arr[] = [2, 5, 1, 4, 3], target = 10
    Output: 3
    Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

    Input: arr[] = [5, 7, 8], target = 3
    Output: 0
    Explanation: There are no subsets of the array that sum up to the target 3.

    Input: arr[] = [35, 2, 8, 22], target = 0
    Output: 1
    Explanation: The empty subset is the only subset with a sum of 0.
*/

/*
Approach:- Lets solve it using meet in the middle
    -- count all possible sum whose: sum==S

Note:- So this approach will not pass all the test cases, so it will be not a feasible solution to pick for this particular question only where element and target may be 0:- 
    -- arr = {0,0,0}, target=0 ;
    -- output = 8, but we are only getting 4
*/

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &nums);

void calculateSum(vector<int> &arr, vector<int> &halfes, int n, int offset)
{
    for(int i=0 ; i<(1<<n) ; i++)//: 1<<n => 1*2^n
    {
        int sum=0;
        for(int j=0 ; j<n ; j++)
        {
            if(i&(1<<j))
                sum+=arr[j+offset];
        }
        halfes.push_back(sum);
    }
}

int perfectSum(vector<int> &arr, int target)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<int> firsthalfSum;
    vector<int> secondhalfSum;
    calculateSum(arr, firsthalfSum, (n+1)/2, 0);
    calculateSum(arr, secondhalfSum, n-(n+1)/2, (n+1)/2);


    sort(secondhalfSum.begin(), secondhalfSum.end());

    printArray(firsthalfSum);
    printArray(secondhalfSum);

    int count=0;
    for(int i=0 ; i<firsthalfSum.size(); i++)
    {
        int x = firsthalfSum[i];

        int y = target-x; // is y ke liye index find kro

        int LB = lower_bound(secondhalfSum.begin(), secondhalfSum.end(), y) - secondhalfSum.begin();

        // if we don't get y, it will point to secondhalfSum.end()
        if(LB==secondhalfSum.size() || (secondhalfSum[LB]!=y))
            continue;

        count++;
    }

    return count;
}


int main()
{
    vector<int> arr = {0,0,0};
    int target = 0;

    cout << perfectSum(arr, target) << endl;

    return 0;
}

void printArray(vector<int> &nums)
{
    cout << endl;
    for(auto num:nums)
        cout << num << " ";

    cout << endl;
}




