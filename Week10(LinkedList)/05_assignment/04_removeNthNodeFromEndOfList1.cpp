/* -> 19
Given the head of a linked list, remove the nth node from the end of the list and return its head.(assuming 1th index list)
*/

/*
Appraoch:- recursive appraoch
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

    ~ListNode(){
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


// solution from here
void solve(ListNode* prev, ListNode* curr, int &n)
{
    // base case
    if(curr==NULL) return;

    // solve one case
    prev = curr;
    curr = curr->next;
    solve(prev, curr, n);//head recursion

    if(n==0){
        prev->next = curr->next;
        delete curr;
    }
    
    // decrement
    n--;
}


ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *prev = NULL;
    ListNode *curr = head;

    solve(prev, curr, n);

    if(n==0) return head->next;

    return head;
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

    head = removeNthFromEnd(head,7);

    printLL(head);

    deleteAllNode(head);

    return 0;
}

