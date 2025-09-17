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

// creating tail pointer
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

// solution from here
void insertAtPosition(Node* &head, Node* &tail, int data, int position)
{
    int length = lengthLL(head);

    // change1

    // if(position<1){
    //     cout << "Enter a valid position" << endl;
    //     return;
    // }


    // change2

    // if(position>length+1){
    //     cout << "Enter a valid position" << endl;
    //     return;
    // }


    if(position<=1){//-> change3
        insertHead(head, tail, data);
    }
    else if(position>length){//-> change4
        insertTail(head, tail, data);
    }
    else{ //-> insertion at middle  

        Node* newNode = new Node(data);

        Node* prev = NULL;
        Node* curr = head;
        
        while (position!=1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }

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
    insertAtPosition(head, tail, 150, -10);

    cout << "Printing after insertion: " << endl;
    printLL(head);

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;

    return 0;
}
