/* -> 138 (we have to construct deep copy of the given list)

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.
*/

/*
Appraoch:- recursive join ker rhe h
    -- jab simple data node ko copy ker rhe honge tab, ham ek map m table bna rhe honge old_node aur new_node i.e., unke addresses ka mapping
    -- so ab isse ham naye node ka random kaise copy kre -> naye node ka random is equal to the mapped value of old node ka random.

TC:- O(n)
but the space complexity:- O(n), can we reduce it to O(1)-> see next solution
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

// dublicating list recursively
Node* helper(Node *head, unordered_map<Node*, Node*> &mp)
{
    // base case
    if(head==0) return 0;

    // solve one case
    Node* newHead = new Node(head->val);

    mp[head] = newHead;// mapped the newNode with oldNode
 
    // RE
    newHead->next = helper(head->next, mp);

    // last m pahunchne ke baad ab mp ka use kerke random ko bhi copy kro
    if(head->random != NULL)
    {
        newHead->random = mp[head->random];
    }

    return newHead;
}

Node* copyRandomList(Node* head)
{
    unordered_map<Node*, Node*> mp;
    return helper(head, mp);
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

