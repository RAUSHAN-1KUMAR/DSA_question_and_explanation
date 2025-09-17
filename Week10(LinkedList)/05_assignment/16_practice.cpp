
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


// mid nikalne wala function (tortoise algorithm)
ListNode* findMid(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    ListNode* first = new ListNode(5);
    ListNode* second = new ListNode(10);


    ListNode* head = first;
    first->next = second;

    printLL(head);

    ListNode* ans = findMid(head);
    cout << ans->val << endl;

    deleteAllNode(head);

    return 0;
}

