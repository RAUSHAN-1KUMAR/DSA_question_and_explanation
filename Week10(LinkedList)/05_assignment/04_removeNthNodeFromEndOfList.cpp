/* -> 19
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

/*
Appraoch:-
    -- reverse the list
    -- remove the nth node
    -- reverse the list

Can we solve this question in one pass? -> see next solution
*/


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(){
        this->next = NULL;
    }

    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }

    ~ListNode()
    {
        cout << "Dtor called for:" << this->val << endl;
    }
};

void printLL(ListNode* &head)
{
    ListNode *temp = head;

    while(temp != NULL)
    {
        cout << temp->val << "->";
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

void deleteAllNode(ListNode* &head)
{
    ListNode* temp = head;

    while (head!=NULL)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
    
    delete temp;
}

ListNode* reverseLL(ListNode* &head)
{
    if(head==NULL) return head;
    if(head->next == NULL) return head;

    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr!=NULL)
    {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
    return prev;
}


// solution starts
ListNode* removeNthFromEnd(ListNode* head, int n)
{
    // reverse
    ListNode* endNode = reverseLL(head);

    // remove
    if(n==1)
    {
        ListNode* temp = endNode->next;
        delete endNode;
        endNode = temp;
    }
    else{
        ListNode *prev = NULL;
        ListNode* curr = endNode;
        while (n>1)
        {
            prev = curr;
            curr = curr->next;
            n--;
        }

        prev->next = curr->next;
        delete curr;
    }

    // again reverse
    ListNode* newHead = reverseLL(endNode);

    return newHead;
}


int main()
{
    ListNode* first = new ListNode(5);
    ListNode* second = new ListNode(10);
    ListNode* third = new ListNode(15);
    ListNode* forth = new ListNode(40);
    ListNode* fifth = new ListNode(2);
    ListNode* sixth = new ListNode(3);
    ListNode* seventh = new ListNode(20);

    ListNode* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    printLL(head);

    head = removeNthFromEnd(head,3);

    printLL(head);

    deleteAllNode(head);;

    return 0;
}

