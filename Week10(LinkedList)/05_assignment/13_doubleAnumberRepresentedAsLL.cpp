/* -> 2816

You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

 
Example 1:
Input: head = [1,8,9]
Output: [3,7,8]
Explanation: The figure above corresponds to the given linked list which represents the number 189. Hence, the returned linked list represents the number 189 * 2 = 378.

Example 2:
Input: head = [9,9,9]
Output: [1,9,9,8]
Explanation: The figure above corresponds to the given linked list which represents the number 999. Hence, the returned linked list reprersents the number 999 * 2 = 1998.
*/

/*
Approach:- recursion(head recursion)
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

void printLL(ListNode* &head);
int lengthLL(ListNode* &head);
void deleteAllNode(ListNode* &head);

// solution starts from here
void solve(ListNode* head, int &carry)
{
    // base case
    if(head==NULL) return;

    // RE(head recursion)
    solve(head->next, carry);

    // one case solve
    int pro = head->val * 2 + carry;
    head->val = pro % 10;
    carry = pro/10;
}

ListNode* doubleIt(ListNode* head)
{
    int carry = 0;

    solve(head, carry);

    if(carry != 0){
        ListNode* temp = new ListNode(carry);
        temp->next = head;
        head = temp;
    }

    return head;
}

int main()
{
    ListNode* first = new ListNode(9);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* forth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    ListNode* root = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    printLL(root);

    ListNode* ans = doubleIt(root);

    printLL(ans);

    deleteAllNode(ans);

    return 0;
}


//function definition starts here
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

