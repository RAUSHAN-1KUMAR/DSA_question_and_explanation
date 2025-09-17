
// FCFS

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arrival, vector<int> &burst, int n)
{
    vector<int> waitingTime(n, 0);
    vector<int> turnaroundTime(n, 0);
    vector<int> completionTime(n, 0);

    // lets do the calculation of completion time, turnaround time and waiting time
    // Calculate completion time
    completionTime[0] = arrival[0] + burst[0];
    for (int i = 1; i < n; i++) {
        if (arrival[i] > completionTime[i - 1]) {
            completionTime[i] = arrival[i] + burst[i];
        } else {
            completionTime[i] = completionTime[i - 1] + burst[i];
        }
    }

    // Calculate turnaround time and waiting time
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = completionTime[i] - arrival[i];
        waitingTime[i] = turnaroundTime[i] - burst[i];
    }

    // Print results
    cout << "Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << (i + 1) << "\t" << arrival[i] << "\t" << burst[i] << "\t"
             << completionTime[i] << "\t\t" << turnaroundTime[i] << "\t\t" 
             << waitingTime[i] << endl;
    }
}


int main()
{
    vector<int> arrival = {0, 1, 2};
    vector<int> burst = {20,2,2};
    int n = arrival.size();

    solve(arrival, burst, n);

    return 0;
}
