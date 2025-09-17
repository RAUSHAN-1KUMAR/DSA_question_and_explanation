/*
Given sorted linked list, we have to remove dublicates
*/

/*
Appraoch:- one pointer
    -- iterative approach
*/

#include<iostream>
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
};

void printLL(ListNode* &head);
int lengthLL(ListNode* &head);
int getLength(ListNode* head);

// solution from here
ListNode* removeDublicate(ListNode* head)
{
    if(head == NULL) return head;
    if(head->next==NULL) return head;

    ListNode* temp = head;
    while (temp!=NULL)
    {
        // ager do node ki value same h to remove kerdo ek ko
        if(temp->next != NULL && temp->val == temp->next->val)
        {
            ListNode* nextNode = temp->next;
            temp->next = nextNode->next;
            nextNode->next = NULL;
            delete nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    

    return head;
}

int main()
{
    // creating node
    ListNode* first = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(20);
    ListNode* forth = new ListNode(40);
    ListNode* fifth = new ListNode(40);

    ListNode* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    head = removeDublicate(head);
    printLL(head);

    

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;
    
    return 0;
}


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

int getLength(ListNode* head)
{
    ListNode* temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}
