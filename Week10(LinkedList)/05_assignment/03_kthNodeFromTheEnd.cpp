/*
Return the kth node from the end, assuming 0 index position
*/

/*
Appraoch:- iterative approch
    -- reverse the list
    -- now iterate on the list k times
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

Node* reverseLL(Node* &head)
{
    if(head==NULL) return head;
    if(head->next == NULL) return head;

    Node* prev = NULL;
    Node* curr = head;

    while (curr!=NULL)
    {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
    return prev;
}

int kthNodeFromEnd(Node* &head, int k)
{
    int len = lengthLL(head);
    if(len<k) return -1;

    Node* endHead = reverseLL(head);
    if(k==0) return endHead->data;
    while (k>0)
    {
        endHead=endHead->next;
        k--;
    }
    
    return endHead->data;
}

int main()
{
    Node* first = new Node(5);
    Node* second = new Node(10);
    Node* third = new Node(15);
    Node* forth = new Node(40);
    Node* fifth = new Node(2);
    Node* sixth = new Node(3);
    Node* seventh = new Node(20);

    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    int ans = kthNodeFromEnd(head,3);
    cout << ans << endl;

    deleteAllNode(head);;

    return 0;
}