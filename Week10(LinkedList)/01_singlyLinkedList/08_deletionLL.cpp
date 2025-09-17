/*
Deletion at Singly LL:- 
    1. At head
    2. At tail
    3. At any random position
*/

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

    ~Node(){
        cout << "dtor called for: " << this->data << endl;
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

void createTail(Node* &head, Node* &tail)
{
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    tail = temp;
}

// deletion of head
void deleteHead(Node* &head)
{
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

// deletion of tail
void deleteTail(Node* &head, Node* &tail)
{
    // reach till second last
    Node* prev = head;
    while (prev->next != tail)
    {
        prev = prev->next;
    }

    // now deleting
    prev->next = NULL;
    delete tail;
    tail = prev;
}

// delettion of given position
void deleteMid(Node* &head, Node* &tail, int position){
    // two pointer to reach given position
    Node *curr = head;
    Node *prev = NULL;

    while (position != 1)
    {
        prev = curr;
        curr = curr->next;
        position--;
    }

    // delete that curr mode
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void deleteNode(Node* &head, Node* &tail, int position)
{
    int len = lengthLL(head);

    // empty list
    if(head == NULL){
        cout << "cannot delete, coz LL is empty" << endl;
        return;
    }

    // single  element
    if(head == tail){
        Node *temp = head;
        delete temp;
        head == NULL;
        tail == NULL;
        return;
    }

    // delete from head
    if(position == 1){
        deleteHead(head);
    }
    else if(position == len){ // delete from tail
        deleteTail(head, tail);
    }
    else{// mid position
        deleteMid(head, tail, position);
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
 


    cout << "Printing Before deletion: " << endl;
    printLL(head);

    // deletion
    deleteNode(head, tail, 1);

    cout << "Printing after deletion: " << endl;
    printLL(head);

    delete second;
    delete third;
    delete forth;
    delete fifth;

    return 0;
}
