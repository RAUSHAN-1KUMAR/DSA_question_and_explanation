/* -> 160

Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

*/

/*
Question type: observation type

Approach:- 
    1. Brute force:-
        -- we can check one by one:- iterating through one of the list for each node of another list

        TC:- O(N*M)

    2. Hashing:-    
        -- using map or set, insert all the node of one of the list, and then check each node for second list that it is present in set or not

        TC:- O(N + M)

    3. better approach:-
        -- Difference in length, find the length of both the list, and then find the  positive difference between these lengths.
        -- then move a pointer on the larger list by the difference achieved and then one by one move the pointers of both list

        TC:- O(max(N,M) + O(diff_achived) + O(min(N,M)))

    4. optimal approach:-
        -- take two pointer for each list
        -- iterate over the lists, if anyone becomes null, point them to the head of the opposite lists and continue iterating untill they collide
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

// applying optimal approach
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    ListNode *ptr1 = headA;
    ListNode *ptr2 = headB;

    // dono pointer ko ek ek ker ke aage badha rhe h
    while (ptr1!=NULL || ptr2!=NULL)
    {
        if(ptr1==ptr2) break;
        
        ptr1 = ptr1==NULL ? headB : ptr1->next;
        ptr2 = ptr2==NULL ? headA : ptr2->next;
    }

    return ptr1;
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
    
    ListNode* first1 = new ListNode(5);
    ListNode* second2 = new ListNode(10);
    ListNode* third3 = new ListNode(15);

    ListNode* head1 = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    ListNode* head2 = first1;
    first1->next = second2;
    second2->next = third3;
    third3->next = fifth;

    ListNode* head = getIntersectionNode(head1, head2);

    printLL(head);


    return 0;
}

