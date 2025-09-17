
/* -> 148
Approach:-approach kuch mergeSort of array jaisa hoga, mid find kro, phir left and right ke liye call kro and then merge function call kro
    -- we will require two function
        1. jo hame mid nikal ke de
        2. final merge wala function
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

    ~ListNode(){
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


// merge function
ListNode* sortedMerge(ListNode* left, ListNode* right)
{
    // necessary case
    if(left == 0) return right;
    if(right == 0) return left;

    ListNode* ans = new ListNode(-1);
    ListNode* mptr = ans;

    while(left!=NULL && right!=NULL)
    {
        if(left->val < right->val)
        {
            mptr->next = left;
            mptr = left;
            left = left->next;
        }
        else
        {
            mptr->next = right;
            mptr = right;
            right = right->next;
        }
    }

    // if left bacha hua h
    if(left!=NULL)
    {
        mptr->next = left;
    }

    // if right bacha hua h
    if(right!=NULL)
    {
        mptr->next = right;
    }


    // deleting -1 node
    ListNode* temp = ans;
    ans = ans->next;
    temp->next = NULL;
    delete temp;

    return ans;
}

// mid nikalne wala function (tortoise algorithm)
ListNode* findMid(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head->next; // must

    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* sortList(ListNode* head)
{
    // necessary case
    if(head==0 || head->next == 0){
        return head;
    }

    // Break LL into two halves using mid node.
    ListNode* mid = findMid(head);
    ListNode* leftHead = head;
    ListNode* rightHead = mid->next;
    mid->next = NULL;// mid ko break ker rhe taaki sortedMerge wala function ache se kaam kre

    // recursive equation
    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    // merge both left and right
    return sortedMerge(leftHead, rightHead);
}


int main()
{
    ListNode* first = new ListNode(5);
    ListNode* second = new ListNode(10);
    ListNode* third = new ListNode(15);
    ListNode* forth = new ListNode(40);
    ListNode* fifth = new ListNode(2);
    ListNode* sixth = new ListNode(3);
    ListNode* seventh = new ListNode(20);


    ListNode* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    printLL(head);

    head = sortList(head);

    printLL(head);

    deleteAllNode(head);

    return 0;
}

