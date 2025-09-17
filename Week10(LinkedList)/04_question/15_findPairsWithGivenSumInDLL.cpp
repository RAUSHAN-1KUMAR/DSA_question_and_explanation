/* GFG

Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

Example 1:
    Input: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9, target = 7
    Output: (1, 6), (2,5) 
    Explanation: We can see that there are two pairs 
    (1, 6) and (2,5) with sum 7.


    Input:  1 <-> 5 <-> 6, target = 6
    Output: (1,5) 
    Explanation: We can see that there is one pairs  (1, 5) with sum 6.
*/

/*
Approach:
    1. brute force:-
        -- itarate to each node(x), and apply BS to find a node(y) such that x+y=target

        TC:- O(nlogn)

    2. two pointer: 
        -- take one of the pointer at head and second to the tail, and then
            i) sum(head+tail) > target -> tail--
            ii) sum(head+tail) == target -> head++
            iii) sum(head+tail) < target -> head++

        TC:- O(n)

    3. extreme brute:- using two pointer and finding the other node for each node iteratively

        TC:- O(n^2)
*/  

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next=NULL;
    Node* prev=NULL;

    Node(){}

    Node(int data)
    {
        this->data = data;
    }

    ~Node(){cout << "dtor called for: " << this->data << endl;}
};

void printNodeOfLL(Node *head);
Node* arrayToLL(vector<int> &nums);


// solution 
Node* returnTail(Node *head)
{
    Node* temp=head;

    while(temp->next!=NULL)
        temp=temp->next;

    return temp;
}


vector<pair<int,int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int,int>> ans;

    Node *start = head;
    Node *end = returnTail(head);

    while (start->data<end->data)
    {
        int data1 = start->data;
        int data2 = end->data;

        if(data1+data2 == target)
        {
            ans.push_back({data1,data2});
            start=start->next;
            end=end->prev;
        }
        else if(data1+data2 > target)
        {
            end=end->prev;
        }
        else
        {
            start=start->next;
        }
    }
    

    return ans;
}

int main()
{
    vector<int> nums = {9,1,3,4,5,1,8,4};

    Node* head = arrayToLL(nums);

    printNodeOfLL(head);
    return 0;
}



void printNodeOfLL(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << "<->";
        head = head->next;
    }
    cout << head->data << "->";
    cout << "NULL" << endl;
}

Node* arrayToLL(vector<int> &nums)
{
    Node* head;
    Node* temp = new Node(nums[0]);// next, prev
    head = temp;// head is pointing the first node

    for(int i=1 ; i<nums.size() ; i++)
    {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        newNode->prev = temp;
        temp = newNode;
    }

    return head;
}

