/* -> 142
Given head, the head of a linked list, determine if the linked list has a cycle in it and the strating node of the cycle.
*/

/*
Appraoch:- tortoise algorithm / slow and fast apprach
    -- first detected the loop
    -- when loop found then take slow pointer to the head and the move slow and fast forward step by step, eventually they will meet at the starting point
    -- the starting point of the loop will be the meeting point of slow and fast pointer.
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

// solution from here
ListNode* hasCycleLoopPointer(ListNode *head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    // detecting loop
    while (fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow){
            break;
        }
    }

    // if loop not find
    if(fast == NULL || fast->next == NULL){
        cout << "Loop Not found" << endl;
        return NULL;
    }

    // if loop found
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
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
    sixth->next = third;

    ListNode* loopStartingPoint = hasCycleLoopPointer(head);

    cout << loopStartingPoint->val << endl;


    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;
    delete sixth;
    
    return 0;
}