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
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

// creating our tail pointer
void createTail(Node* &head, Node* &tail)
{
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    tail = temp;
}


void insertTail(Node* &head, Node* &tail, int data)
{
    if(head==NULL)
    {
        // create new node
        Node* newNode = new Node(data);

        // update tail and head
        tail = newNode;
        head = newNode;
    }
    else{
        // create a new node
        Node* newNode = new Node(data);

        // now tail's node point to new node
        tail->next = newNode;

        // tail point to new node
        tail = newNode;
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
    
    // forming tail pointer
    Node* tail = NULL;
    createTail(head, tail);


    // printing before insertion
    cout << "Printing Before insertion: " << endl;
    printLL(head);

    // insertion
    insertTail(head, tail, 500);

    cout << "Printing after insertion: " << endl;
    printLL(head);

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;

    return 0;
}