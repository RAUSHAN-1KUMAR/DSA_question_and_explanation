/* -> 621

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label due to cooling time.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:
    Input: tasks = ["A","A","A","B","B","B"], n = 2
    Output: 8
    Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

    After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.


Example 2:
    Input: tasks = ["A","C","A","B","D","B"], n = 1
    Output: 6
    Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

    With a cooling interval of 1, you can repeat a task after just one other task.


Example 3:
    Input: tasks = ["A","A","A", "B","B","B"], n = 3
    Output: 10
    Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

    There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.
*/


/*
Approach:- 
    2. Using Heap:- In greedy approach we had vector for the tasks and after sorting we got the max freq at the end, now in maxHeap we can also get the max freq from the top.
        -- pop n+1 tasks from the heap and then place it one after another, 
        -- after that if freq left than push it in heap again, we don't directly push the freq-1 in heap, first we push it in a temp vector and then from temp vector to heap, why this ?? -> because at the last step we need the size of temp for the last task whose freq is zero and not pushed to heap
        -- each time when we pop n+1 task from heap, will add n+1 to the cpu time but at the end when heap is empty we will add task.size() to the cpu time for the last left task

    TC:- O(N*log26) -> O(n)
    SC:- O(26) -> O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) 
{
    // storing the freq of each character in a vector
    vector<int> mp(26,0);
    for(char &ch:tasks){ //-> O(n)
        mp[ch-'A']++;
    }

    // storing freq in maxHeap
    priority_queue<int> pq;
    for(int i=0 ; i<26 ; i++) //-> O(26)
    {
        if(mp[i]>0)
            pq.push(mp[i]);
    }

    // now building our answer
    int time=0;
    while (!pq.empty())
    {
        vector<int> temp; //-> to store the popped freq-1

        // we will take out n+1 tasks at a time
        for(int i=1 ; i<=n+1 ; i++)
        {
            if(!pq.empty()) // this is important, i.e., n+1 tasks pq m hone bhi to chahiye
            {
                int freq=pq.top(); pq.pop();

                freq--;
                
                temp.push_back(freq);// pushed the freq-1
            }
        }

        // insert the modified freq into heap again
        for(int &f:temp)
        {
            if(f>0)
                pq.push(f);
        }

        // this is important -> time calculating
        if(pq.empty())//-> this is for last step
        {
            // When will pq got empty, when we were taking out the n+1 tasks at the starting and we were not able to push any freq in the heap again because it become zero
            // In that case we will add the no. of tasks which is in temp vector, no need for extra idle time, because this is the last step when no freq is left.
            time += temp.size();
        }
        else
        {
            // if there is still the freq in heap, then it means we have given the n intervals, this is the case of all steps except the last one
            time += n+1;
        }
    }
    
    return time;
}


int main()
{
    vector<char> tasks = {'A', 'A', 'A', 'A', 'B', 'C', 'D', 'G'};
    int n=1;

    cout << leastInterval(tasks, n) << endl;

    return 0;
}

