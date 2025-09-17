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

    ~Node(){
        cout << "dtor called for: " << this->data << endl;
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

// deletion at head
void deletionHead(Node* &head, Node* &tail)
{
    //DLL is empty
    if(head == NULL){
        cout << "DLL is empty, can't perform deletion" << endl;
        return;
    }
    else{//DLL is  non-empty
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;

    }
}

// deletion at tail
void deletionTail(Node* &head, Node* &tail)
{
    //DLL is empty
    if(tail == NULL){
        cout << "DLL is empty, can't perform deletion" << endl;
        return;
    }
    else{//DLL is  non-empty
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
}

// deletion at any position
void deletionPosition(Node* &head, Node* &tail, int position)
{
    int len = lengthDLL(head);

    // DLL is empty
    if(head == NULL){
        cout << "DLL is empty, can't perform deletion" << endl;
        return;
    }
    else{//-> DLL is not empty
        if(head==tail){
            Node* temp = head;
            delete temp;
            head = NULL;
            tail = NULL;
            return;
        }

        if(position==1){
            deletionHead(head, tail);
        }
        else if(position == len){
            deletionTail(head, tail);
        }
        else{
            Node *prevNode = NULL;
            Node *currNode = head;

            while(position!=1){
                prevNode = currNode;
                currNode = currNode->next;
                position--;
            }

            prevNode->next = currNode->next;
            (currNode->next)->prev = prevNode;
            currNode->next = NULL;
            currNode->prev = NULL;
            delete currNode;
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

    // deletionHead(head, tail);
    // deletionTail(head, tail);
    deletionPosition(head, tail,2);

    cout << "Printing DLL: " << endl;
    printDLL(head);

    delete first;
    delete third;
    delete forth;

    return 0;
}