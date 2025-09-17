/* GFG

Geek is a software engineer. He is assigned with the task of calculating average waiting time of all the processes by following shortest job first policy.

The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next.

Given an array of integers bt of size n. Array bt denotes the burst time of each process. Calculate the average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.

Note: Consider all process are available at time 0.

Example 1:
    Input:
    n = 5
    bt = [4,3,7,1,2]
    Output: 4
    Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 4.

Example 2:
    Input:
    n = 4
    arr = [1,2,3,4]
    Output: 2
    Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 2.
*/

#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int> &bt)
{
    sort(bt.begin(), bt.end());
    long long totalWait = 0;
    int n = bt.size();
    for(int i=0 ; i<n ; i++)
    {
        totalWait += (n-i-1)*bt[i];
    }
    return totalWait/n;
}

int main()
{
    vector<int> bt = {4,3,7,1,2};
    cout << solve(bt) << endl;
    return 0;
}

