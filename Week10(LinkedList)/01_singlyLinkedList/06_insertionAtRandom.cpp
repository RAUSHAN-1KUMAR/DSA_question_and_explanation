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

int lengthLL(Node *head)
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

// crating tail pointer
void createTail(Node* &head, Node* &tail)
{
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    tail = temp;
}

// insertion at head
void insertHead(Node* &head, Node* &tail, int data)
{
    if(head == NULL)
    {
        Node *newNode = new Node(data);

        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);

        newNode->next = head;

        head = newNode;
    }
}

// insertion at tail
void insertTail(Node* &head, Node* &tail, int data)
{
    if(head==NULL)
    {
        Node* newNode = new Node(data);

        tail = newNode;
        head = newNode;
    }
    else{
        Node* newNode = new Node(data);

        tail->next = newNode;

        tail = newNode;
    }
}


// Solution from here
void insertAtPosition(Node* &head, Node* &tail, int data, int position)
{
    int length = lengthLL(head);

    if(position<1){
        cout << "Enter a valid position" << endl;
        return;
    }

    if(position>length+1){
        cout << "Enter a valid position" << endl;
        return;
    }

    if(position==1){
        insertHead(head, tail, data);
    }
    else if(position==length+1){
        insertTail(head, tail, data);
    }
    else{ //-> insertion at middle  

        //traverse prev/curr to positon
        Node* prev = NULL;
        Node* curr = head;
        while (position!=1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        
        //create a node
        Node* newNode = new Node(data);
        // insert new Node
        prev->next = newNode;
        newNode->next = curr;
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
    insertAtPosition(head, tail, 150, 6);

    cout << "Printing after insertion: " << endl;
    printLL(head);

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;

    return 0;
}

/*
what if we want to insert the element at head if position is less than 1 and insert the element at tail if position is greater than length.
*/