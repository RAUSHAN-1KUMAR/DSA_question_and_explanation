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


int main()
{
    // creating node
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *forth = new Node(40);

    // connection nodes
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

    delete first;
    delete second;
    delete third;
    delete forth;

    return 0;
}