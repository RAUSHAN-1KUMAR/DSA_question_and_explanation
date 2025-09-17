/* -> 206
Actual linked list ko reverse kro
*/

/*
Approach:- iterative and recursive both

One more recursive approach -> next solution
*/

#include<iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(){
        this->next = NULL;
    }

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


void printLL(ListNode* &head)
{
    ListNode *temp = head;

    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lengthLL(ListNode* &head)
{
    ListNode *temp = head;

    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// TC: O(n)
void reverseSLLiteratively(ListNode* &head)
{
    ListNode* prev = NULL;
    ListNode*curr = head;

    while(curr!=NULL)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    head = prev;
}

// TC: O(n) + some space
void reverseSLLrecursively(ListNode* &head, ListNode* prev, ListNode* curr)
{
    // base case
    if(curr == NULL)
    {
        head = prev;
        return;
    }

    // ek case solve kro
    ListNode* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;

    // tail recursion
    reverseSLLrecursively(head, prev, curr);
}


// one more recursive approach -> head recursion
ListNode* reverseLL(ListNode* head)
{
    if(head==NULL || head->next == NULL) return head;

    // head recursion
    ListNode* newHead = reverseLL(head->next);
    
    // solve one case
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}


int main()
{
    // creating node
    ListNode* first = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(30);
    ListNode* forth = new ListNode(40);
    ListNode* fifth = new ListNode(50);

    ListNode* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    cout << "Before reverse: " << endl;
    printLL(head);

    reverseSLLiteratively(head);

    cout << "After iteratively reverse: " << endl;
    printLL(head);


    reverseSLLrecursively(head, NULL, head);

    cout << "After recursively reverse: " << endl;
    printLL(head);
    

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;
    
    return 0;
}