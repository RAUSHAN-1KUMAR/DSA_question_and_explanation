/*
Given the head of a singly linked list, the task is to check if the linked list has a loop. A loop means that the last node of the linked list is connected back to a node in the same list.  So if the next of the last node is null. then there is no loop. We need to return true if there is a loop, otherwise false.
*/

/*
Better approach: tortoise algorithm
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

//approach1: using map
bool detectLoop1(Node* &head)
{
    Node* curr = head;
    unordered_map<Node*, bool> mp;

    while (curr != NULL)
    {
        if(mp[curr]==1)
            return true;

        mp[curr] = 1;
        curr = curr->next;
    }
    
    return false;
}

//approach2: tortoise algorithm
bool detectLoop2(Node* &head)
{
    Node* slow = head;
    Node* fast = head;

    // detection loop
    while(fast!=NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return 1;
    }
    
    return 0;
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

    if(detectLoop1(head)){
        cout << "Loop found";
    }
    else{
        cout << "Loop not found";
    }

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

