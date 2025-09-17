/* GFG
Given a linked list, delete N nodes after skipping M nodes each time of a linked list until the last of the linked list.
*/

/*
Lakshay Bhaiyaa approach:- recursively
*/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(){
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Dtor called for:" << this->data << endl;
    }
};


void printLL(Node* &head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lengthLL(Node* &head)
{
    Node *temp = head;

    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// solution starts
void linkdelete(Node* head, int M, int N)
{
    // base case
    if(head==NULL) return;

    // solve one case
    Node* it = head;
    for(int i=0 ; i<M-1 ; ++i)
    {
        if(it==NULL) return;

        it = it->next;
    }

    // it -> would be at Mth node
    if(it==NULL) return;

    Node* mthNode = it;
    it = mthNode->next;
    for(int i=0 ; i<N ; i++)
    {
        if(it==NULL) break;

        Node* temp = it->next;
        delete it;
        it = temp;
    }
    mthNode->next = it;

    // tail recusion
    linkdelete(it, M, N);
}

void deleteAllNode(Node* &head)
{
    Node* temp = head;

    while (head!=NULL)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
    
    delete temp;
}

int main()
{
    Node* first = new Node(9);
    Node* second = new Node(1);
    Node* third = new Node(3);
    Node* forth = new Node(5);
    Node* fifth = new Node(9);
    Node* sixth = new Node(4);
    Node* seventh = new Node(10);
    Node* eighth = new Node(1);

    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;

    cout << "Printing LL: " << endl;
    printLL(head);

    int M=2;
    int N=2;
    linkdelete(head, M, N);

    cout << "Printing LL: " << endl;
    printLL(head);

    // deleting all Node
    deleteAllNode(head);

    return 0;
}

