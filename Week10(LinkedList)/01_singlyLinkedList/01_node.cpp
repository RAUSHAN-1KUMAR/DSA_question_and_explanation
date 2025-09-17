/*
In this code, we are going to implement our LL by manually creating and connecting each node.
*/

#include<iostream>
using namespace std;

// creating node
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

// pass by reference
void printLL(Node* &head)
{
    // temporary ptr to traverse our LL
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    cout << endl;
}


int main()
{
    // creating node
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* forth = new Node(40);
    Node* fifth = new Node(50);

    // currently each node's nextPTR pointing to null

    // so lets join the node
    Node* head = first;// head
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    Node* tail = fifth;// tail

    //printing LL
    cout << "Printing the entire LL; " << endl;
    printLL(head);


    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;

    return 0;
}