/* -> 61

Given the head of a linked list, rotate the list to the right by k places.

*/

/*
Appraoch:- reverse appraoch as we did in array
    - reverse whole list
    - reverse till k
    - reverse form k to n
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

ListNode* reverseLL(ListNode* head)
{
    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr!=NULL)
    {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    
    return prev;
}

ListNode* rotateRight(ListNode* head, int k)
{
    // base case for 0 and 1 node
    if(head==NULL) return NULL;
    if(head->next == NULL) return head;
    if(k==0) return head;

    int len =  lengthLL(head);
    while(k>len) k-=len;

    //applying reverse approach
    // reverse whole list
    ListNode* newHead = reverseLL(head);

    // janha se rotate kerna h wanha se tod do
    ListNode* prev = NULL;
    ListNode* temp = newHead;
    while(k--){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;

    // todne ke bad, baki dono list ko reverse kerdo
    ListNode* secondHead = reverseLL(newHead);
    ListNode* thirdHead = reverseLL(temp);

    // connect bhi to kro
    newHead->next = thirdHead;

    return secondHead;
}

int main()
{
    ListNode* first = new ListNode(1);
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

    ListNode* rotatedHead = rotateRight(root, 10);

    printLL(rotatedHead);

    deleteAllNode(rotatedHead);

    return 0;
}

