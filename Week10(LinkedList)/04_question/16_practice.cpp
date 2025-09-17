/* -> 25

we have a linked list with a given variable k, and we have to reverse group of list

    EX- input: [1,2,3,4,5,6,7] k=2,
        ouput: [2,1,4,3,6,5,7]
        explanation: reversed k k groups(matlab do do ke group ko reverse ker diye)
*/

/*
Appraoch:- recursion
    -- acha question h, phash sakte h to ache se dhiraj rakh ke solve kerna h

I SOLVED IT
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


// solution from here
int getLength(ListNode* head)
{
    ListNode* temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

ListNode* reverseKGroup(ListNode* head, int k)
{   
    if(head==NULL) return head;

    int len = getLength(head);
    if(len<k){
        return head;
    }

    ListNode* prev=NULL;
    ListNode* curr=head;
    int count=k;
    while (count)
    {
        ListNode* newCurr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=newCurr;

        count--; 
    }
    
    head->next = reverseKGroup(curr, k);

    return prev;
}


int main()
{
    // creating node
    ListNode* first = new ListNode(10);
    ListNode* second = new ListNode(20);
    ListNode* third = new ListNode(30);
    ListNode* forth = new ListNode(40);
    ListNode* fifth = new ListNode(50);

    ListNode* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    ListNode* newNode = reverseKGroup(head, 2);

    printLL(newNode);
    

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;
    
    return 0;
}

