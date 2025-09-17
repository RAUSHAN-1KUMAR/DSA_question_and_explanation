/* -> 2
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Example:
    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.

    Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    Output: [8,9,9,9,0,0,0,1]

*/

/*
Approach:- my appraoch
    -- ham koi extra space nhi le rhe h answer ko store kerne m, means ham diye gye list me se koi ek list ko chun ke usko modify ker rhe h
    -- let say i choosed list1(l1), to ab mai apne answer ko l1 m store kerte jaunga
    -- but to handle if list1 is smaller ro greater than list2-> mentioned within the code.

TC:- O(max(n, m))
SC:- O(1)
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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* temp1 = l1;
    ListNode* prev1 = NULL;
    ListNode* temp2 = l2;
    ListNode* prev2 = NULL;

    int carry = 0;
    while(temp1 != NULL || temp2 != NULL)
    {
        // ager temp1->NULL h to zero assume ker lenge
        int data1 = temp1!=NULL ? temp1->val : 0;

        // ager temp2->NULL h to zero assume ker lenge
        int data2 = temp2!=NULL ? temp2->val : 0;

        int digit = data1+data2+carry;
        carry = digit/10;
        
        // ham apne answer ko list1 m store ker rhe h, 
        if(temp1!=NULL){
            temp1->val = (digit%10);
        }
        else{ // ager list1 chota hoga tab list2 m store ker dengen
            temp2->val = (digit%10);
        }


        // ager list1->NULL nhi h means list1 m hi data store hua h
        if(temp1!=NULL){
            prev1 = temp1;
            temp1 = temp1->next;
        }// ager list1->NULL h to data list2 m store hua hoga, So prev1 ab list2 ke liye kaam krega
        else{
            prev1->next = temp2;
            prev1 = temp2;
            temp2 = temp2->next;
            continue;
        }

        // iss code tak tabhi ayengen jab list1->NULL nhi h, matlab list1 ya to bada h ya barabar h, ager aesa h to matlab data list1 m hi data store hua hoga, to thik h list2 ko agge badha denge only if list2->NULL nhi h.
        if(temp2!=NULL){
            prev2 = temp2;
            temp2 = temp2->next;
        }

    }


    // ager last m carry bachta h tab
    if(carry!=0)
    {
        ListNode* newNode = new ListNode(carry);
        prev1->next = newNode;
    }

    // for deallocation purpose
    prev2->next = NULL;
    deleteAllNode(l2);

    return l1;
}


int main()
{
    // creating node
    ListNode* first1 = new ListNode(9);
    ListNode* second1 = new ListNode(9);
    // ListNode* third1 = new ListNode(9);

    ListNode* first2 = new ListNode(9);
    ListNode* second2 = new ListNode(9);
    ListNode* third2 = new ListNode(9);

    ListNode* head1 = first1;
    first1->next = second1;
    // second1->next = third1;

    ListNode* head2 = first2;
    first2->next = second2;
    second2->next = third2;


    ListNode* newHead = addTwoNumbers(head1, head2);


    printLL(newHead);

    deleteAllNode(newHead);
    
    return 0;
}

