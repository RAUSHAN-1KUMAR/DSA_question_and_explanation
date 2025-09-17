#include<iostream>
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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insertHead(Node* &head, int data)
{
    // create a new Node
    Node* newNode = new Node(data);

    // newNode point to first node
    newNode->next = head;

    // head point to new node
    head = newNode;
}


int main()
{
    // creating node
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* forth = new Node(40);
    Node* fifth = new Node(50);

    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth; 

    // printing before insertion
    cout << "Printing Before insertion: " << endl;
    printLL(head);

    // insertion
    insertHead(head, 500);

    cout << "Printing after insertion: " << endl;
    printLL(head);

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;

    return 0;
}