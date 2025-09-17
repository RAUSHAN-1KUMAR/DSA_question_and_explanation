/* GFG (job squencing problem)

You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.

Examples :
    Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
    Output: [2, 60]
    Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

    Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
    Output: [2, 127]
    Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

    Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
    Output: [3, 100]
    Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).
*/

/*
Approach:
    1.  brute force : using brute force
        -- O(n^2) time complexity
        -- O(1) space complexity
    
    2.  Greedy: using minHeap
        -- O(nlogn) time complexity
        -- O(n) space complexity

    3. Optimal
        -- using DSU approach in graph
*/

#include<bits/stdc++.h>
using namespace std;

// brute force
vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
{
    int n = deadline.size();

    vector<pair<int, int>> jobs; // {profit, deadline}
    for(int i=0 ; i<n ; i++)
        jobs.push_back({profit[i], deadline[i]});

    // sort jobs in decreasing order of profit
    sort(jobs.begin(), jobs.end(), [](pair<int,int> &a, pair<int,int> &b){
        return a.first > b.first;
    });

    
    int maxDeadline = 0;
    for(int i=0 ; i<n ; i++)
        maxDeadline = max(maxDeadline, jobs[i].second);

    vector<int> slot(maxDeadline+1, -1); // to keep track of free slots

    // now we will iterate through all the jobs and assign each job to the latest free slot before its deadline
    int countJobs = 0;
    int maxProfit = 0;
    for(int i=0 ; i<n ; i++)
    {
        // find a free slot for this job (starting from its deadline)
        for(int j=jobs[i].second ; j>0 ; j--)
        {
            if(slot[j]==-1) // free slot found
            {
                slot[j] = i; // assign this job to the slot
                countJobs++;
                maxProfit += jobs[i].first;
                
                break; // move to the next job
            }
        }
    }

    return {countJobs, maxProfit};
}


// using minHeap
vector<int> jobSequencingGreedy(vector<int> &deadline, vector<int> &profit)
{
    int n = deadline.size();

    vector<pair<int, int>> jobs; // {deadline, profit}: -> uper m {profit, deadline} se sort kar rhe the but isme pehle deadline ko le rha h
    for(int i=0 ; i<n ; i++)
        jobs.push_back({deadline[i], profit[i]});

    // sort jobs in increasing order of deadline
    sort(jobs.begin(), jobs.end());

    // minHeap to keep track of profits
    priority_queue<int, vector<int>, greater<int>> minHeap; 

    for(int i=0 ; i<n ; i++)
    {
        if(minHeap.size() < jobs[i].first) // if we can schedule this job
        {
            minHeap.push(jobs[i].second); // add its profit to the heap
        }
        else if(!minHeap.empty() && minHeap.top() < jobs[i].second) // if we can replace a job with upcoming higher profit
        {
            minHeap.pop(); // remove the job with the lowest profit
            minHeap.push(jobs[i].second); // add the current job's profit
        }
    }

    int countJobs = minHeap.size();
    int maxProfit = 0;
    while(!minHeap.empty())
    {
        maxProfit += minHeap.top(); minHeap.pop();
    }

    return {countJobs, maxProfit};
}


int main()
{
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};
    vector<int> ans = jobSequencing(deadline, profit);
    cout << "Maximum number of jobs: " << ans[0] << endl;
    cout << "Maximum profit: " << ans[1] << endl;
    return 0;
}