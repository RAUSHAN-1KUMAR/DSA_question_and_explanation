/* GFG
You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

Example1:
    Input: 2<->2<->10<->8<->4<->2<->5<->2, key=2
    Output: 10<->8<->4<->5
    Explanation: All Occurences of 2 have been deleted.

    Input: 9<->1<->3<->4<->5<->1<->8<->4, key=9
    Output: 1<->3<->4<->5<->1<->8<->4
    Explanation: All Occurences of 9 have been deleted.
*/

/*
Approach:- single pointer
    -- just like we did in remove dublicate in singly LL
    -- in this case we have doubly LL, so we have to handle the prev pointer also
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next=NULL;
    Node* prev=NULL;

    Node(){}

    Node(int data)
    {
        this->val = data;
    }

    ~Node(){cout << "dtor called for: " << this->val << endl;}
};

void printNodeOfLL(Node *head);
Node* arrayToLL(vector<int> &nums);

// solution 
void deleteAllOccurOfX(Node* &head, int x)
{
    Node* newHead = new Node(-1);
    Node* nptr = newHead;

    nptr->next=head;
    head->prev=nptr;

    while(head!=NULL)
    {
        if(head->val!=x)
            nptr = head;
        else
        {
            nptr->next=head->next;

            if(head->next!=NULL)
                head->next->prev=nptr;

            delete head;//-> delete the node
            head = nptr;
        }

        head=head->next;
    }

    head = newHead->next;
    delete newHead; // also not forgot to delete this head
}

int main()
{
    vector<int> nums = {9,1,3,4,5,1,8,4};

    Node* head = arrayToLL(nums);

    printNodeOfLL(head);
    deleteAllOccurOfX(head, 9);
    printNodeOfLL(head);
    return 0;
}



void printNodeOfLL(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->val << "<->";
        head = head->next;
    }
    cout << head->val << "->";
    cout << "NULL" << endl;
}

Node* arrayToLL(vector<int> &nums)
{
    Node* head;
    Node* temp = new Node(nums[0]);// next, prev
    head = temp;// head is pointing the first node

    for(int i=1 ; i<nums.size() ; i++)
    {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    return head;
}

