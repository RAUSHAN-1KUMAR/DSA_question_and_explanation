/* -> 23

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.


Example 1:
    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
    Explanation: The linked-lists are:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    merging them into one sorted list:
    1->1->2->3->4->4->5->6


Example 2:
    Input: lists = []
    Output: []


Example 3:
    Input: lists = [[]]
    Output: []
*/

/*
Approach: similar to mergeKsortedArray
    1. using minHeap
    2. mergeSort -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode* next;

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};


// solution from here
class compare
{
public:
    bool operator()(ListNode*a, ListNode*b){
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

    // Step1: created minHeap of front Node of each list
    for(int row=0 ; row<lists.size() ; row++)
    {
        if(lists[row]!=NULL) //-> catch condition
            pq.push(lists[row]);
    }

    // Step2: now building our answer
    ListNode* ans = new ListNode(-1);
    ListNode* mptr=ans;
    while(!pq.empty())
    {
        ListNode* front = pq.top(); pq.pop();

        // connecting the ans node
        mptr->next = front;
        mptr = front;

        // now inserting next node of popped node
        if(front->next!=NULL)
            pq.push(front->next);
    }

    return ans->next;
}


int main()
{

    return 0;
}


