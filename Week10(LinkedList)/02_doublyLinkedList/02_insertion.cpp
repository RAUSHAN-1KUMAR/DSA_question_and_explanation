#include<iostream>
using namespace std;

// creating node
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(){
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// printing DLL
void printDLL(Node* &head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// length of DLL
int lengthDLL(Node* &head)
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

// insertion at head
void insertionHead(Node* &head, Node* &tail, int data)
{
    //DLL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{//DLL is  non-empty
        Node *newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// insertion at tail
void insertionTail(Node* &head, Node* &tail, int data)
{
    //DLL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{//DLL is  non-empty
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// insertion at any position
void insertionPosition(Node* &head, Node* &tail, int data, int position)
{
    int len = lengthDLL(head);

    // DLL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{//-> DLL is not empty
        if(position==1){
            insertionHead(head, tail, data);
        }
        else if(position == len+1){
            insertionTail(head, tail, data);
        }
        else{
            Node *newNode = new Node(data);

            Node *prevNode = NULL;
            Node *currNode = head;

            while(position!=1){
                prevNode = currNode;
                currNode = currNode->next;
                position--;
            }

            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
}

int main()
{
    // creating node
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *forth = new Node(40);

    // connecting nodes
    Node *head = first;
    first->prev = NULL;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = forth;
    forth->prev = third;
    forth->next = NULL;
    Node *tail = forth;

    cout << "Printing DLL: " << endl;
    printDLL(head);

    insertionHead(head, tail, 40);
    insertionTail(head, tail, 25);
    insertionPosition(head, tail, 65, 3);

    cout << "Printing DLL: " << endl;
    printDLL(head);

    delete first;
    delete second;
    delete third;
    delete forth;

    return 0;
}