/* -> 369

Given a linked list:- [1,3,9], we have add 1 it will become-> [1,4,0]

*/

/*
Appraoch:- recursively(head recursion)
    -- applying recursion so that we can remove applying revers() function.

TC:- O(n)
SC:- O(n)->recursion stack space
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

    ~ListNode()
    {
        cout << "dtor called for: " << this->val << endl;
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


// recursive appraoch
void addOne(ListNode* &head, ListNode* temp, int &carry)
{
    // base case 
    if(temp==NULL) return;

    // head recursion
    addOne(head, temp->next, carry);

    // solve one case
    int digit = temp->val + carry;
    if(digit<10){
        temp->val = digit;
        carry = 0;
    }
    else{
        temp->val = 0;
        carry = 1;
    }

    // at first node after computing the above steps, still carry is left
    if(carry!=0 && temp==head)
    {
        ListNode* newNode = new ListNode(carry);
        newNode->next = head;
        head = newNode;
    }
}


int main()
{
    // creating node
    ListNode* first = new ListNode(9);
    ListNode* second = new ListNode(9);
    ListNode* third = new ListNode(9);

    ListNode* head = first;
    first->next = second;
    second->next = third;

    printLL(head);

    int carry = 1;
    addOne(head, head, carry);

    printLL(head);

    
    delete head;
    delete first;
    delete second;
    delete third;
    
    return 0;
}

