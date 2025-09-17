/* GFG
Given a linked list, delete N nodes after skipping M nodes each time of a linked list until the last of the linked list.
*/

/*
My Appraoch:- Iteratively
*/


#include<iostream>
#include<vector>
#include<unordered_map>
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

    ~Node()
    {
        cout << "Dtor called for:" << this->data << endl;
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

int lengthLL(Node* &head)
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

// solution starts
void linkdelete(Node* head, int M, int N)
{
    if(N==0) return;

    Node* prev = NULL;
    Node* curr = head;

    int countM = 0;
    int countN = 1;

    while (curr!=NULL)
    {
        prev = curr;
        curr = curr->next;
        countM++;

        if(countM==M && curr!=NULL)
        {
            while (curr->next != NULL && countN<N)
            {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
                countN++;
            }

            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            countM = 0;
            countN = 1;   
        }
    }

    
}

void deleteAllNode(Node* &head)
{
    Node* temp = head;

    while (head!=NULL)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
    
    delete temp;
}

int main()
{
    Node* first = new Node(9);
    Node* second = new Node(1);
    Node* third = new Node(3);
    Node* forth = new Node(5);
    Node* fifth = new Node(9);
    Node* sixth = new Node(4);
    Node* seventh = new Node(10);
    Node* eighth = new Node(1);

    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;

    cout << "Printing LL: " << endl;
    printLL(head);

    int M=2;
    int N=0;
    linkdelete(head, M, N);

    cout << "Printing LL: " << endl;
    printLL(head);


    // deleting all Node
    deleteAllNode(head);


    return 0;
}

