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
Approach:
    2. mergeSort
*/

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};

// solution from here
ListNode *mergeTwoSortedLL(ListNode *l1, ListNode *l2)
{

    if (!l1)
        return l2;
    if (!l2)
        return l1;

    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoSortedLL(l1->next, l2);
        return l1;
    }

    else
    {

        l2->next = mergeTwoSortedLL(l1, l2->next);
        return l2;
    }

    return NULL;
}

ListNode *partitionAndMerge(int s, int e, vector<ListNode *> &lists)
{

    if (s > e)
        return NULL;

    if (s == e)
        return lists[s];

    int mid = s + (e - s) / 2;

    ListNode *L1 = partitionAndMerge(s, mid, lists);
    ListNode *L2 = partitionAndMerge(mid + 1, e, lists);

    return mergeTwoSortedLL(L1, L2);
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{

    int k = lists.size();

    if (k == 0)
        return NULL;

    return partitionAndMerge(0, k - 1, lists);
}



int main()
{

    return 0;
}