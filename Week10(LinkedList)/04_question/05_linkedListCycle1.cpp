/* -> 141
Given head, the head of a linked list, determine if the linked list has a cycle in it.
*/

/*
Appraoch:- tortoise algorithm / slow and fast apprach
*/

#include<iostream>
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


// solution from here-> tortoise & hare algorithm
bool hasCycle(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow){
            return true;
        }
    }

    return false;
}

int main()
{
    // creating node
    ListNode* first = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(30);
    ListNode* forth = new ListNode(30);
    ListNode* fifth = new ListNode(20);
    ListNode* sixth = new ListNode(10);

    ListNode* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;

    if(hasCycle(head)) cout << "true";
    else cout << "false";


    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;
    delete sixth;
    
    return 0;
}