
/*
SRTN (shortest remaining time next)
    - it is the preemtive version of SJF
*/

// we can use pointer to the process in the heap to reduce the space complexity
// priority_queue<Process*, vector<Process*>, Compare> minHeap;
// minHeap.push(&processes[i]);
// Prcoess* currP = minHeap.top(); minHeap.pop();
// currP->remaining--;

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
    int remaining; // remaining BT
};

class Compare{
public:
    bool operator()(Process &p1, Process &p2){
        if(p1.remaining != p2.remaining)
            return p1.remaining > p2.remaining; // compare by remaining burst time
        else if(p1.arrival != p2.arrival)
            return p1.arrival > p2.arrival;
        else 
            return p1.id > p2.id; // if burst and arrival are same then compare by id
    }
};

void SRTN(vector<int> arrival, vector<int> burst, int n)
{
    vector<Process> processes(n);
    for(int i=0 ; i<n ;i++){
        processes[i] = {i+1, arrival[i], burst[i], 0, 0, 0, burst[i]}; // {P_id, arrival time, burst time, completion time, turnaround time, waiting time, remaining_BT}
    }

    // IMP1
    sort(processes.begin(), processes.end(), [](Process &p1, Process &p2){
        return p1.arrival < p2.arrival; // sort by arrival time
    });

    // IMP2
    unordered_map<int, int> processIndex; // to keep track of process index
    for(int i=0 ; i<n ; i++){
        processIndex[processes[i].id] = i; // map process id to index
    }


    priority_queue<Process, vector<Process>, Compare> minHeap;
    int currentTime = 0, completed = 0, j=0;
    while(completed<n)
    {
        while(j<n && currentTime >= processes[j].arrival){
            minHeap.push(processes[j]);
            j++;
        }

        if(minHeap.empty()){
            currentTime++;
            continue; // if no process is found then increment current time
        }

        // took out the process with minimum remaining burst time
        Process currP = minHeap.top(); minHeap.pop();
        if(j>=n){ // if all processes are pushed into the heap
            currentTime += currP.remaining;
            currP.remaining = 0;
        }
        else{
            currentTime++;
            currP.remaining--;
        }
        
        // based on remaining burst time, we can update the process
        if(currP.remaining == 0){
            currP.completion = currentTime;
            currP.turnaround = currP.completion - currP.arrival;
            currP.waiting = currP.turnaround - currP.burst;
            completed++;

            processes[processIndex[currP.id]]=currP; //IMP3, THE MOST IMP LINE
        }
        else{
            minHeap.push(currP); // push it back into the heap if it still has remaining burst time
        }
    }

    // print the results
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for(auto &p:processes){
        cout << "P" << p.id << "\t\t" << p.arrival << "\t\t" << p.burst << "\t\t"
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
    SRTN(arrival, burst, n);
    return 0;
}

