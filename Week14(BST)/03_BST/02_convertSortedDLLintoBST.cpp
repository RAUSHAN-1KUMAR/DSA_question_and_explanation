/*
Convert Sorted Doubly Linked List into BST

INPUT:-
    5 <-> 50 <-> 60 <-> 100 <-> 200 <-> 300

OUTPUT:-
    sorted Doubly LL -> BST
    LL:- prev, next
    LL into tree: prev->left, next->right
        100
       /   \
      50   200
     /  \    \
    5   60   300
*/

/*
Appraoch:- using map and Binary Search appraoch
    -- ager sorted array se BST banana hota to??-> wahi appraoch ko isme use kiye h
*/

#include<iostream>
#include<map>
#include<queue>
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

    cout << "NULL<-";
    while(temp->next != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << temp->data << "->";
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

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* front = q.front(); q.pop();

        if(front == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if(front->prev!=NULL) q.push(front->prev);
            if(front->next!=NULL) q.push(front->next);
        }
    }
}

Node* sorteDLLtoBST(map<int, Node*> &mp, int s, int e)
{
    if(s>e) return NULL;

    int mid = (s+e)/2;

    Node* temp = mp[mid];

    temp->next = sorteDLLtoBST(mp, mid+1, e);
    temp->prev = sorteDLLtoBST(mp, s, mid-1);

    return temp;
}

int main()
{
    // creating node
    Node *first = new Node(5);
    Node *second = new Node(50);
    Node *third = new Node(60);
    Node *forth = new Node(100);
    Node *fifth = new Node(200);
    Node *sixth = new Node(300);

    // connecting nodes
    Node *head = first;

    first->prev = NULL;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = forth;

    forth->prev = third;
    forth->next = fifth;

    fifth->prev = forth;
    fifth->next = sixth;

    sixth->prev = fifth;
    sixth->next = NULL;

    Node *tail = sixth;

    cout << "Printing DLL: " << endl;
    printDLL(head);

    // mapping the nodes w.r.t their index(1th index)
    map<int, Node*>mp;
    Node* temp = head;
    int i=1;
    while(temp!=NULL)
    {
        mp[i] = temp;
        i++;
        temp = temp->next;
    }

    // Now forming tree
    int s=1;
    int e = lengthDLL(head);
    Node* root = sorteDLLtoBST(mp, s, e);

    levelOrderTraversal(root);

    return 0;
}