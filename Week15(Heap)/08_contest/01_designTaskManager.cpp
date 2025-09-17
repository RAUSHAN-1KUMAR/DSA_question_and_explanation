/* -> 3408

There is a task management system that allows users to manage their tasks, each associated with a priority. The system should efficiently handle adding, modifying, executing, and removing tasks.

Implement the TaskManager class:
    1. TaskManager(vector<vector<int>>& tasks): 
        - initializes the task manager with a list of user-task-priority triples. Each element in the input list is of the form [userId, taskId, priority], which adds a task to the specified user with the given priority.

    2. void add(int userId, int taskId, int priority): 
        - adds a task with the specified taskId and priority to the user with userId. It is guaranteed that taskId does not exist in the system.

    3. void edit(int taskId, int newPriority): 
        - updates the priority of the existing taskId to newPriority. It is guaranteed that taskId exists in the system.

    4. void rmv(int taskId):
        - removes the task identified by taskId from the system. It is guaranteed that taskId exists in the system.

    5. int execTop():
        - executes the task with the highest priority across all users. If there are multiple tasks with the same highest priority, execute the one with the highest taskId. After executing, the taskId is removed from the system. Return the userId associated with the executed task. If no tasks are available, return -1.

Note that a user may be assigned multiple tasks.

 

Example 1:
    Input: ["TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"]
    [[[[1, 101, 10], [2, 102, 20], [3, 103, 15]]], [4, 104, 5], [102, 8], [], [101], [5, 105, 15], []]
    Output: [null, null, null, 3, null, null, 5]
    Explanation
    TaskManager taskManager = new TaskManager([[1, 101, 10], [2, 102, 20], [3, 103, 15]]); // Initializes with three tasks for Users 1, 2, and 3.
    taskManager.add(4, 104, 5); // Adds task 104 with priority 5 for User 4.
    taskManager.edit(102, 8); // Updates priority of task 102 to 8.
    taskManager.execTop(); // return 3. Executes task 103 for User 3.
    taskManager.rmv(101); // Removes task 101 from the system.
    taskManager.add(5, 105, 15); // Adds task 105 with priority 15 for User 5.
    taskManager.execTop(); // return 5. Executes task 105 for User 5.

*/

/*
Approach:
    -- storing the given data in maxheap and also in map to keep track of taskID and its (userID, priority)
*/

#include<bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(vector<int>& a, vector<int>& b) {
        if (a[2] == b[2]) 
            return a[1] < b[1];
        return a[2] < b[2];  
    }
};

class TaskManager {
public:
    unordered_map<int, pair<int,int>> taskIdToPriority;//({taskID, {userId, prio}})
    priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

    TaskManager(vector<vector<int>>& tasks)
    {
        for(auto t: tasks)
        {
            pq.push(t);// push task into heap
            taskIdToPriority[t[1]] = {t[0], t[2]};// mark taskId in map
        }
    }
    
    void add(int userId, int taskId, int priority)
    {
        vector<int> t= {userId, taskId, priority};

        pq.push(t);// push task into heap
        taskIdToPriority[t[1]] = {t[0], t[2]};// mark taskId in map
    }
    
    void edit(int taskId, int newPriority)
    {
        int userId = taskIdToPriority[taskId].first;
        vector<int> t= {userId, taskId, newPriority};

        pq.push(t);// we have pushed the new prio, but the old one also exists, don't worry, we will update the prio in map, and then we map wala prio heap wale we nhi mila to pop -> see in exit function

        taskIdToPriority[t[1]] = {t[0], t[2]};// updated the taskId in map
    }
    
    void rmv(int taskId)
    {
        // same-> updated the taskId in map
        taskIdToPriority[taskId].second = -1;
    }
    
    int execTop()
    {
        // if highest prio, not matches with the prio at map it means that was edited, pop it
        while(!pq.empty() && taskIdToPriority[pq.top()[1]].second != pq.top()[2]) pq.pop();

        if(pq.empty()) return -1;

        vector<int> t = pq.top(); 
        taskIdToPriority[t[1]].second = -1;
        pq.pop();

        return t[0];
    }
};

int main()
{


    return 0;
}