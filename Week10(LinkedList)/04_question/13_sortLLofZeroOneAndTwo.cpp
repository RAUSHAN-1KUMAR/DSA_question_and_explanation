/* GFG
Given a linked list where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.


Examples:
    Input: LinkedList: 1->2->2->1->2->0->2->2
    Output: 0->1->1->2->2->2->2->2
    Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
 

    Input: LinkedList: 2->2->0->1
    Output: 0->1->2->2
    Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.
*/

/*
Approach:-
    1. Brute force:
        -- traverse the LL and then count the occurance of 0, 1, 2 and store it in variable count0, count1, count2
        -- in second traversal of the LL, replace the data according to the occurance of 0, 1 and 2.

        TC:- O(2n)
        SC:- O(1)

    2. better approach: three pointer(for each 0 1 2)
        -- similar to question-> segregate odd and even position node of given LL, it means we are gonna use three pointer, one for 0 and one for 1 and another for 2 to align 0, 1 and 2 and then last we are join them

        TC:- O(n)
        SC:- O(1)
*/


#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printNodeOfLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

Node* arrayToLL(vector<int> &nums)
{
    Node* head;
    Node* temp = new Node(nums[0]);// next, prev

    head = temp;

    for(int i=1 ; i<nums.size() ; i++)
    {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}


// Brute force:- count0, count1, count2
Node* sortLL(Node* head)
{
    Node* temp = head;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    // storing the occurance of 0,1 and 2
    while(temp!=NULL)
    {
        int data = temp->val;

        if(data==0) count0++;
        else if(data==1) count1++;
        else count2++;

        temp=temp->next;
    }

    // now data replacement
    temp=head;
    while (temp!=NULL)
    {
        if(count0){
            temp->val=0;
            count0--;
        }
        else{
            if(count1){
                temp->val=1;
                count1--;
            }
            else{
                temp->val=2;
                count2--;
            }
        }

        temp=temp->next;
    }

    return head;
}


// Better approach:- three pointer
Node* sortLL1(Node* head)
{
    if(head==NULL || head->next == NULL ) return head;

    Node* forzero = new Node(-1);
    Node* zero = forzero;

    Node* forone = new Node(-1);
    Node* one = forone;

    Node* fortwo = new Node(-1);
    Node* two = fortwo;

    Node* temp=head;


    while(temp!=NULL)
    {
        if(temp->val==0){
            zero->next = temp; 
            zero = temp;
        }
        else if(temp->val==1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }

        temp=temp->next;
    }

    // joining them is little bit tricky;
    zero->next = (forone->next)?forone->next:fortwo->next;
    one->next = fortwo->next;
    two->next = NULL;

    Node* newHead = forzero->next;

    delete forzero;
    delete forone;
    delete fortwo;

    return newHead;
}

int main()
{
    vector<int> nums = {1,2,2,1,2,0,2,2};

    Node* head = arrayToLL(nums);

    printNodeOfLL(head);

    Node* newhead = sortLL1(head);

    printNodeOfLL(newhead);

    return 0;
}


