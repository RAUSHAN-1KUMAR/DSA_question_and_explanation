/* -> 1019

You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

Example 1:
Input: head = [2,1,5]
Output: [5,5,0]

Example 2:
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
*/

/*
Appraoch:- (stack m index store krengen)
    -- LL ko array m store ker lenge
    -- ab array m piche ke wajaye, starting se traverse krengen, aur condition kya hoga
        (i) ager element of array, top of the stack se bada hua, to pop kerte jao aur uss perticular top ke liye ans array wo elment store kerte jao
        (ii) ager element of array top of the stack se chota h tab push ker dengen wo index stack p
*/

#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        this->val = 0;
        this->next = nullptr;
    }

    ListNode(int x)
    {
        this->val = x;
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

// solution from here
vector<int> nextLargerNodes(ListNode* head)
{
    // storing data of LL in array ll
    vector<int> ll;
    while(head){
        ll.push_back(head->val);
        head = head->next;
    }

    // stack
    stack<int> st;
    vector<int> ans (ll.size());// init to 0

    for(int i=0 ; i<ll.size() ; i++)
    {
        // jab element of array is greater than top
        while(!st.empty() && ll[i]>ll[st.top()]){
            int kids = st.top();
            ans[kids] = ll[i];
            st.pop();
        }

        st.push(i);
    }

    return ans;
}

int main()
{
    ListNode* first = new ListNode(9);
    ListNode* second = new ListNode(1);
    ListNode* third = new ListNode(3);
    ListNode* forth = new ListNode(5);
    ListNode* fifth = new ListNode(9);
    ListNode* sixth = new ListNode(4);
    ListNode* seventh = new ListNode(10);
    ListNode* eighth = new ListNode(1);

    ListNode* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;

    printLL(head);

    vector<int> ans = nextLargerNodes(head);

    for(int num:ans)
    {
        cout << num << " ";
    }
    cout << endl;

    deleteAllNode(head);

    return 0;
}


