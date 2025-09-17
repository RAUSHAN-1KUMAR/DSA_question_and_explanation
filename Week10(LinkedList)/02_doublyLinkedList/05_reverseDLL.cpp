/*
In this code, we are going to reverse a given DLL
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next=NULL;
    Node* prev=NULL;

    Node(){}

    Node(int data)
    {
        this->val = data;
    }
};

void printNodeOfLL(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->val << "<->";
        head = head->next;
    }
    cout << head->val << "->";
    cout << "NULL" << endl;
}

Node* arrayToLL(vector<int> &nums)
{
    Node* head;
    Node* temp = new Node(nums[0]);// next, prev
    head = temp;// head is pointing the first node

    for(int i=1 ; i<nums.size() ; i++)
    {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    return head;
}


// solution form here
void reverseDLL(Node* &head){
    Node* curr=head;
    Node* prev=curr->prev;

    while (curr!=NULL)
    {
        Node* temp=curr->next;

        curr->next=prev;
        curr->prev=temp;

        prev=curr;
        curr=temp;
    }
    
    // head pointer
    head=prev;
}

int main()
{
    vector<int> nums = {5,10,15,6,21};

    Node* head = arrayToLL(nums);

    printNodeOfLL(head);
    
    reverseDLL(head);
    
    printNodeOfLL(head);

    return 0;
}

