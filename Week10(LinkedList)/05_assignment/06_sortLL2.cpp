/*
In this code, we are going to sort given LL using quick sort
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next=NULL;

    Node(){}

    Node(int data)
    {
        this->val = data;
    }
};

void printNodeOfLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* arrayToLL(vector<int> &nums)
{
    Node* head;
    Node* temp = new Node(nums[0]);// next
    head = temp;

    for(int i=1 ; i<nums.size() ; i++)
    {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

// solution form here: 
Node* returnTail(Node* head)
{
    while(head!=NULL && head->next!=NULL){
        head=head->next;
    }

    return head;
}

// this is already a different problem to insert a given pivot into LL, such that left of it is less than him and right of it is greater than him
Node* insertIntoLL(Node* head, Node* tail)
{
    Node* pivot = head;
    Node* current = head;

    Node* prev = pivot->next;
    Node* curr = pivot->next;
    while(curr!=tail->next){
        if(curr->val < pivot->val){
            swap(prev->val, curr->val);
            current = prev;
            prev = prev->next;
        }
        curr = curr->next;
    } 

    swap(pivot->val, current->val);

    return current;
}

void quickSortLL(Node* head, Node* tail){
    if(head==NULL || head==tail)
        return;

    Node* pivot = insertIntoLL(head, tail);

    quickSortLL(head, pivot);
    quickSortLL(pivot->next, tail);
}

Node* quickSort(Node *head){
    if(head==NULL || head->next==NULL)
        return head;

    Node* tail = returnTail(head);

    quickSortLL(head, tail);

    return head;
}

int main()
{
    vector<int> nums = {6,10,15,4,21};

    Node* head = arrayToLL(nums);
    printNodeOfLL(head);
    
    head = quickSort(head);
    printNodeOfLL(head);
    
    return 0;
}




