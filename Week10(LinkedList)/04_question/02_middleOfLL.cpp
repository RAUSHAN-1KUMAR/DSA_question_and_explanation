/* -> 876

Find middle of the linked list
    Case:-  
        1. if length is even-> middle will be the second one
        2. if length is odd-> middle will be middle

*/

/*
Appraoch:-
    -- find the length of the list
    -- required element will be at n/2 + 1;

Better appraoch:- slow and fast appraoch(two pointer/tortoise algorithm), already done in circularlyLL -> see next solution
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


// solution from here
ListNode* middleNode(ListNode* &head)
{
    // finding the lenght of the list
    int n = lengthLL(head);

    int position = n/2 + 1; // the middle element position
    int currPos = 1;
    ListNode* temp = head;
    while (currPos != position)
    {
        currPos++;
        temp = temp->next;
    }

    return temp;
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


