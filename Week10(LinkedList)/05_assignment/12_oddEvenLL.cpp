/* -> 328

Given the 'head' of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.


Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/

/*
My Appraoch:- three pointer
*/


#include<iostream>
#include<vector>
#include<climits>
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

// solution from here
ListNode* oddEvenList(ListNode* &head)
{
    // corner base(till list contain 2 node )
    if(head==NULL) return NULL; 
    if(head->next == NULL) return head;
    if(head->next->next == NULL) return head;

    // if list contain more than two node
    ListNode* firstEvenPos = head;
    ListNode* firstOddPos = head->next;

    ListNode* prev = head;
    ListNode* curr = prev->next;
    ListNode* next = curr->next;

    while (curr!=NULL && next!=NULL)
    {
        prev->next = next;
        curr->next = next->next;
        
        next->next = firstOddPos;

        prev = prev->next;
        curr = curr->next;

        if(curr!=NULL) next = curr->next;
        else next = NULL;
    }

    return head;
}

int main()
{
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* forth = new ListNode(4);
    ListNode* fifth = new ListNode(5);
    ListNode* sixth = new ListNode(6);
    ListNode* seventh = new ListNode(7);
    ListNode* eight = new ListNode(8);

    ListNode* root = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;


    printLL(root);

    ListNode* ans = oddEvenList(root);

    printLL(ans);

    deleteAllNode(root);

    return 0;
}

