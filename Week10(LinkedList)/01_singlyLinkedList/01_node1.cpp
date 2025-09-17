/*
In this code, we are going to implement our LL by using array
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next=NULL;

    Node(){}

    Node(int data)
    {
        this->val = data;
    }
};

void printNodeOfLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// solution
Node* arrayToLL(vector<int> &nums)
{
    Node* head;
    Node* temp = new Node(nums[0]);// next
    head = temp;

    for(int i=1 ; i<nums.size() ; i++)
    {
        Node* newNode = new Node(nums[i]);
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}


int main()
{
    vector<int> nums = {5,10,15,6,21};

    Node* head = arrayToLL(nums);

    printNodeOfLL(head);


    return 0;
}




