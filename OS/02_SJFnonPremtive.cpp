
// SJF -> shortest job first non-preemptive scheduling algorithm
// if burst time of two processes is same then process with lower arrival time will be executed first
// if arrival time of two processes is same then process with lower index will be executed first

/*
Below code TC-> O(n^2)

TC can be reduced to O(nlogn) using minHeap
*/

#include<bits/stdc++.h>
using namespace std;

class Process{
public:
    int id;
    int arrival;
    int burst;
    int completion;
    int turnaround;
    int waiting;
    bool done = false;
};

void solve(vector<int> &arrival, vector<int> &burst, int n)
{
    vector<Process> processes(n);

    for(int i=0 ; i<n ; i++){
        processes[i] = {i+1, arrival[i], burst[i], 0, 0, 0, false};// {P_id, arrival time, burst time, completion time, turnaround time, waiting time, done_or_not}
    }

    // now lets start the calculation
    int currentTime = 0, completed = 0;
    while(completed<n)
    {
        // find the process with minimum burst time which is not done yet and has arrived
        int minBurst = INT_MAX;
        int index = -1;

        // iterate through all processes to find the process with minimum burst time
        for(int i=0 ; i<n ; i++){
            if(!processes[i].done && processes[i].arrival <= currentTime){
                if(processes[i].burst < minBurst){
                    minBurst = processes[i].burst;
                    index = i;
                }
                else if(processes[i].burst == minBurst && processes[i].arrival < processes[index].arrival){
                    index = i; // if arrival time is less, then update index
                }
            }
        }


        if(index==-1){
            currentTime++;
            continue; // if no process is found then increment current time
        }

        currentTime += processes[index].burst; // increment current time by burst time of selected process
        processes[index].completion = currentTime; // set completion time of selected process
        processes[index].turnaround = processes[index].completion - processes[index].arrival; // calculate turnaround time
        processes[index].waiting = processes[index].turnaround - processes[index].burst; // calculate waiting time
        processes[index].done = true; // mark process as done

        completed++;
    }

    cout << "Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n";
    for(auto &p:processes){
        cout << "P" << p.id << "\t" << p.arrival << "\t" << p.burst << "\t"
             << p.completion << "\t\t" << p.turnaround << "\t\t" 
             << p.waiting << endl;
    }
}


int main()
{
    vector<int> arrival = {0, 3, 2, 0};// p1, p2, p3, p4
    // arrival time of process 1 is 0, process 2 is 3, etc
    vector<int> burst = {20, 1, 2, 2};
    int n = arrival.size();
    solve(arrival, burst, n);
    return 0;
}


