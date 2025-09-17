/* -> 21

Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.

Note: lakshay bhaiyaa code (iteratively and recursively both)
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


// iteratively
Node* sortedMerge(Node* left, Node* right)
{
    // base cases
    if(left == NULL) return right;
    if(right == NULL) return left;

    Node* ans = new Node(-1);
    Node* mptr = ans;

    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else
        {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }

    // if left bacha hua h
    if(left!=NULL)
    {
        mptr->next = left;
    }

    // if right bacha hua h
    if(right!=NULL)
    {
        mptr->next = right;
    }

    return ans->next;
}


// recursively
Node* mergeSortedLL1(Node* head1, Node* head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;

    Node* newHead = NULL;
    if(head1->data < head2->data)
    {
        newHead = head1;
        newHead->next = mergeSortedLL1(head1->next, head2);
    }
    else
    {
        newHead = head2;
        newHead->next = mergeSortedLL1(head1, head2->next);
    }

    return newHead;
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

    Node* head1 = first;
    first->next = second;
    second->next = third;
    third->next = forth;

    Node* head2 = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    cout << "Printing LL: " << endl;
    printLL(head1);
    printLL(head2);

    Node* mergeHead = sortedMerge(head1, head2);

    printLL(mergeHead);

    // deleting all Node
    deleteAllNode(mergeHead);

    return 0;
}

