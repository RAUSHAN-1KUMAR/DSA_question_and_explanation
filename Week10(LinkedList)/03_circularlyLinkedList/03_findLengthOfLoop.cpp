/*
Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0. C is the position of the node to which the last node is connected. If it is 0 then no loop.
*/

/*
Approach:- First detect loop then find count of the nodes present in that loop
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
};

int countNodesinLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    // detection loop
    while(fast!=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    // if loop not found
    if(fast==NULL || fast->next==NULL) return 0;

    // if loop found
    int count = 1;
    slow = fast->next;
    while(slow != fast){
        count++;
        slow = slow->next;
    }

    return count;
}


int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* forth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    Node* seventh = new Node(70);
    Node* eighth = new Node(80);

    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = forth;

    cout << countNodesinLoop(head) << endl;


    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;
    delete sixth;
    delete seventh;
    delete eighth;

    return 0;
}

