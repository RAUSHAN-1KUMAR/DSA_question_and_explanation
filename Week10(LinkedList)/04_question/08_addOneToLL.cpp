/* -> 369

Given a linked list:- [1,3,9], we have add 1 it will become-> [1,4,0]

*/

/*
Appraoch:-
    1. reverse the LL
    2. add 1 with carry carefully
    3. reverse again to make final list

TC:- O(n + n + n) -> O(3n) -> O(n)
SC:- O(1)

Is there any appraoch without reverse -> recursion(head recursion)-> see next solution
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

ListNode* reverseSLLiteratively(ListNode* &head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr!=NULL)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}


// solution from here
void addOne(ListNode* &head)
{
    // reverse
    head = reverseSLLiteratively(head);

    // add 1;
    int carry = 1;
    ListNode* temp = head;
    while (temp!=NULL)
    {
        temp->val = temp->val + carry;

        if(temp->val < 10)
        {
            carry=0;
            break;
        }
        else // adding one will always be equal to 10 if it is not < 10
        {
            temp->val = 0;
            carry=1;
        }

        temp = temp->next;
    }

    // if carry left
    if(carry!=0){
        ListNode* newNode = new ListNode(1);

        // again reverse
        head = reverseSLLiteratively(head);

        newNode->next = head;
        head=newNode;
    }
    
    // again reverse 
    head = reverseSLLiteratively(head);
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
    addOne(head);
    printLL(head);

    

    delete first;
    delete second;
    delete third;
    
    return 0;
}