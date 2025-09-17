/* -> 876

Find middle of the linked list

*/

/*
Appraoch:- slow and fast appraoch(tortoise & hare alogrithm)
    -- slow-> one step movement
    -- fast-> two step movement

Note:- pehle fastPtr move hoga aur ager fastPtr move ho gya tab slowPointer move hoga.
    -- fast NULL tak ja sakta hai
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

    ListNode(int data){
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

// slow and fast algorithm(if length is even then second will be the middle node)
ListNode* middleNode(ListNode* &head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL)
    {
        // moving fastPtr two times
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;

            // ab slow ko one times
            slow = slow->next;
        }
    }

    return slow;
}

int main()
{
    // creating node
    ListNode* first = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(30);
    ListNode* forth = new ListNode(40);
    ListNode* fifth = new ListNode(50);
    ListNode* sixth = new ListNode(60);

    ListNode* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;

    // finding middle element
    head = middleNode(head);
    printLL(head);
    

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;
    delete sixth;
    
    return 0;
}