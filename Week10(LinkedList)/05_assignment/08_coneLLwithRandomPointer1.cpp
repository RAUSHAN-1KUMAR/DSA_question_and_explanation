/* -> 138 (we have construct deep copy of the given list)

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.
*/

/*
Appraoch:- iterative join ker rhe h
    -- hame aesa kuch nhi given h ki bina diye hue list ko modify kiye kro, so ham kya kregen, ham purane wale list m combine kerengen naye wale list ko. So sabse pehle ek loop ka use kerke sabko combine ker denge.
        -- A->A'->B->B'->C->C'.... 
            A: purana node
            A': naya node

    -- combine kerne ke baad phir se ek loop ka use kerke ab ham random pointer of A'(naya node) ko ab point ker sakte h with the help of A(purana node)
    -- random pointer ho jane ke baad phir se ek loop ka use krengen, A ko A' se detach kerna h taki last m dono list alag ho jaye.
*/



#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(){
        this->next = NULL;
        this->random = NULL;
    }

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }

    ~Node()
    {
        cout << "Dtor called for:" << this->val << endl;
    }
};

void printLL(Node* &head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
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
Node* helper(Node *head)
{   
    // base case
    if(head == NULL) return 0;

    // step1: clone A->A'
    Node* it = head;// iterate over old node
    while (it!=NULL)
    {
        Node* cloneNode = new Node(it->val);
        cloneNode->next = it->next;
        it->next = cloneNode;
        it = it->next->next;// double next, because we inserted a cloneNode between them
    }
    
    // step 2; Assign random links of A' with the help of old A
    it = head;
    while(it!=NULL)
    {
        Node* cloneNode = it->next;
        cloneNode->random = it->random != NULL ? it->random->next : NULL;
        it = it->next->next;// double next, because there is a cloneNode between them
    }

    // step 3: detach A' form A
    it = head;
    Node* cloneHead = it->next;
    while (it!=NULL)
    {
        Node* cloneNode =  it->next;
        it->next = it->next->next;
        if(cloneNode->next!=NULL){
            cloneNode->next = cloneNode->next->next;
        }
        it = it->next;
    }
    
    return cloneHead;
}

Node* copyRandomList(Node* head)
{
    return helper(head);
}


int main()
{
    Node* first = new Node(7);
    Node* second = new Node(13);
    Node* third = new Node(11);
    Node* forth = new Node(10);
    Node* fifth = new Node(11);

    Node* root = first;

    first->next = second;
    first->random = NULL;

    second->next = third;
    second->random = first;

    third->next = forth;
    third->random = fifth;

    forth->next = fifth;
    forth->random = third;

    fifth->next = NULL;
    fifth->random = first;


    Node* randomList = copyRandomList(root);

    deleteAllNode(root);
    deleteAllNode(randomList);

    return 0;
}

