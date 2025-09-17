/*
What's different from previous recursive solution?
    - previously it was tail recursion, now it is head recursion
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printNodeOfLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* arrayToLL(vector<int> &nums)
{
    Node* head;
    Node* temp = new Node(nums[0]);// next, prev

    head = temp;

    for(int i=1 ; i<nums.size() ; i++)
    {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

// solution from here
Node* reverseLL(Node* head)
{
    if(head==NULL || head->next == NULL) return head;

    // head recursion
    Node* newHead = reverseLL(head->next);
    
    // solve one case
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    vector<int> nums = {5,10,15,6,21};

    Node* head = arrayToLL(nums);

    printNodeOfLL(head);

    printNodeOfLL(reverseLL(head));

    return 0;
}