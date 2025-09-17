/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
    (i) a next pointer to the next node,
    (ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
*/

/*
Appraoch:- using merge two sorted list
    -- taking first two last list, merge them and then jo merged list bna ab usme third last list ko merge kro.
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
    Node *bottom;

    Node(){
        this->next = NULL;
        this->bottom = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
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
        temp = temp->bottom;
    }
    cout << "NULL" << endl;
}

void deleteAllNode(Node* &head)
{
    Node* temp = head;

    while (head!=NULL)
    {
        head = temp->bottom;
        delete temp;
        temp = head;
    }
    
    delete temp;
}

// mergeTwoSortedList function(recursively)
Node* sortedMerge(Node* head1, Node* head2)
{
    // base case
    if(head2 == NULL) return head1;
    if(head1 == NULL) return head2;


    // RE + one case solve
    Node* mainHead = NULL;
    if(head1->data < head2->data)
    {
        mainHead = head1;
        head1->bottom = sortedMerge(head1->bottom, head2);
    }
    else
    {
        mainHead = head2;
        head2->bottom = sortedMerge(head1, head2->bottom);
    }

    return mainHead;
}

// flatten function
Node* flatten(Node* root)
{
    // base case
    if(root->next == NULL) return root;

    //RE
    return sortedMerge(root,flatten(root->next));//-> merging from last
}


int main()
{
    Node* first = new Node(5);
    Node* second = new Node(10);
    Node* third = new Node(10);
    Node* forth = new Node(28);

    // connecting root list
    Node* root = first;
    first->next = second;
    second->next = third;
    third->next = forth;

    // bottom node of first
    Node* first1 = new Node(7);
    Node* first2 = new Node(8);
    Node* first3 = new Node(30);

    first->bottom = first1;
    first1->bottom = first2;
    first2->bottom = first3;

    // bottom node of second
    Node* second1 = new Node(20);

    second->bottom = second1;

    // bottom nodes of third
    Node* third1 = new Node(22);
    Node* third2 = new Node(50);

    third->bottom = third1;
    third1->bottom = third2;

    // bottom node of forth
    Node* forth1 = new Node(35);
    Node* forth2 = new Node(40);
    Node* forth3 = new Node(45);

    forth->bottom = forth1;
    forth1->bottom = forth2;
    forth2->bottom = forth3;


    root = flatten(root);

    printLL(root);

    return 0;
}

