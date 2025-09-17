/* -> 2
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Example:
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.

    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]

*/

/*
Approach:- lakshay bhiyaa
    -- he has stored the result in another node and then joined them..

TC:- O(max(n, m))
SC:- O(max(n, m)+1)
*/

#include<iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next=NULL;

    ListNode(){}
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
    ~ListNode(){}
};

void printLL(ListNode* &head);
void deleteAllNode(ListNode* &head);

// solution starts from here
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* ans = new ListNode(-1);//-> this node will join to next newNode and with this we will form our resultant list.
    ListNode* it = ans;//-> to go next node

    int carry = 0;

    while(l1 || l2 || carry)
    {
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;

        int sum = a+b+carry;
        int digit = sum%10;
        carry = sum/10;

        // forming newNode to connect the it pointer
        it->next = new ListNode(digit);
        it = it->next;

        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        
    }
    
    return ans->next;
}


int main()
{
    // creating node
    ListNode* first1 = new ListNode(9);
    ListNode* second1 = new ListNode(9);
    // ListNode* third1 = new ListNode(9);

    ListNode* first2 = new ListNode(9);
    ListNode* second2 = new ListNode(9);
    ListNode* third2 = new ListNode(9);

    ListNode* head1 = first1;
    first1->next = second1;
    // second1->next = third1;

    ListNode* head2 = first2;
    first2->next = second2;
    second2->next = third2;


    ListNode* newHead = addTwoNumbers(head1, head2);


    printLL(newHead);

    deleteAllNode(newHead);
    
    return 0;
}

// function definition starts here
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

