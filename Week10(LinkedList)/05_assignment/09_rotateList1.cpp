/* -> 61

Given the head of a linked list, rotate the list to the right by k places.

*/

/*
Appraoch:- without reverse approach
    -- janha se rotate kerna h wanha tak jayengen(n-k-1) iteratively, aur phir wo node mera new last node hoga aur uske baad wala node mera new head node hoga.
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


ListNode* rotateRight(ListNode* head, int k)
{   
    // base case
    if(head==NULL) return 0;

    // What if k is greater than the length of the LL. So, that's why pehle k aur length of the list ko sambhal rhe h
    int len = lengthLL(head);
    int actualRotateK = k%len;
    if(actualRotateK == 0) return head;

    // ab iteratively len-k-1 tak jayengen newLastNode ki talash m
    int newLastNodePos = len-actualRotateK-1;
    ListNode* newLastNode = head;
    for(int i=0; i<newLastNodePos ; i++){
        newLastNode = newLastNode->next;
    }
    ListNode* newHead = newLastNode->next; // so our now our new node will be next of new Last node
    newLastNode->next = NULL;

    // Now we are connecting the old last node to our old head
    ListNode* it = newHead;
    while (it->next != NULL)
    {
        it = it->next;
    }
    it->next = head;

    // returning new Head
    return newHead;
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

