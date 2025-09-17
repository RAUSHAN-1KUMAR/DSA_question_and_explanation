/* -> 1019

You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

Example 1:
Input: head = [2,1,5]
Output: [5,5,0]

Example 2:
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
*/

/*
Appraoch:- question is similar to next smaller in array: so to solve this question to find next greater but in linked list i applied recursive appraoch:
    -- list ke last tak gye and then uske her ek node ke liye check kiye stack m, jaise check kerte the next smaller in array walle question m

Better appraoch:- see next solution
*/

#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        this->val = 0;
        this->next = nullptr;
    }

    ListNode(int x)
    {
        this->val = x;
        this->next = NULL;
    }

    ~ListNode()
    {
        cout << "dtor called for: " << this->val << endl;
    }
};

void printLL(ListNode* &head)
{
    ListNode *temp = head;

    while(temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lengthLL(ListNode* &head)
{
    ListNode *temp = head;

    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void deleteAllNode(ListNode* &head)
{
    ListNode* temp = head;

    while (head!=NULL)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
    
    delete temp;
}

// solution from here
void solve(ListNode* head, stack<int> &st, vector<int> &ans)
{
    // base case
    if(head==NULL) return;

    // RE(head recursion)
    solve(head->next, st, ans);

    // solve one case
    int data = head->val;

    while (st.top()<=data && st.size()>1)
    {
        st.pop();
    }

    ans.push_back(st.top());
    st.push(data);
}

vector<int> nextLargerNodes(ListNode* head)
{
    // initializing stack
    stack<int> st;
    st.push(0);

    vector<int> ans;

    solve(head, st, ans);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    ListNode* first = new ListNode(9);
    ListNode* second = new ListNode(1);
    ListNode* third = new ListNode(3);
    ListNode* forth = new ListNode(5);
    ListNode* fifth = new ListNode(9);
    ListNode* sixth = new ListNode(4);
    ListNode* seventh = new ListNode(10);
    ListNode* eighth = new ListNode(1);

    ListNode* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;

    printLL(head);

    vector<int> ans = nextLargerNodes(head);

    for(int num:ans)
    {
        cout << num << " ";
    }
    cout << endl;

    deleteAllNode(head);

    return 0;
}