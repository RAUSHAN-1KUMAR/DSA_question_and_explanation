/*
Given head of a linked list that may contain a loop.  A loops means that the last node of the linked list is connected back to a node in the same list.  So if next of the last node is null. then there is no loop.  Remove loop from the linked list, if it is present (we mainly need to make next of the last node as null). Otherwise keep the linked list as it is.
*/

/*
remove dhatan se kerna h, jab loop remove ho jaye to wo ek singlyLL form kre
*/

/*
Approach:- 
    -- check loop is present or not using slow and fast pointer.
    -- after finding loop, slow and fast will be pointing to the same address, so now make slow to point first element of list.
    -- now move slow and fast pointer one by one forward till they matches, when they meet it means this node is the starting node of loop.
    -- so now we have to break the connection of loop_ending_node to loop_starting_node.
    -- so will mode our slow pointer till its slow->next matches to fast and then slow->next = NULL.
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

void removeLoop(Node* head)
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

    // loop is not present
    if(fast==NULL || fast->next==NULL) return;

    // loop is present, move slow to head and move forward fast and slow step by step till they matches
    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }

    // breaking loop
    while (slow->next != fast)
    {
        slow = slow->next;
    }
    
    slow->next = NULL;
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

    // breaking loop
    removeLoop(head);

    // printing LL
    cout << "Linked list after loop removal: " << endl;
    printLL(head);



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