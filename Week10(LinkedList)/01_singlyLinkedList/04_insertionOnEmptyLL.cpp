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

// if LL is empty(tail and head both are null)
void insertHead(Node* &head, Node* &tail, int data)
{
    if(head == NULL){
        // create a new node
        Node *newNode = new Node(data);

        // update head and tail
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);

        newNode->next = head;

        head = newNode;
    }
}


int main()
{
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
    Node* tail = fifth; 


    cout << "Printing Before insertion: " << endl;
    printLL(head);


    insertHead(head, tail, 500);

    cout << "Printing after insertion: " << endl;
    printLL(head);

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;
    
    return 0;
}