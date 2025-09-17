/* -> 148
In this code, we are gonna sort a given LL using brute force
*/

/*
Approach:- brute force
    -- store the elements into a array, 
    -- sort the array
    -- now modify the data of LL w.r.t sorted array(using the given LL)
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

// solution from here
Node* sortLL(Node* head)
{
    vector<int> arr;

    // Step1:
    Node* temp = head;
    while(temp!=NULL)
    {
        arr.push_back(temp->val);
        temp = temp->next;
    }

    // Step2:
    sort(arr.begin(), arr.end());

    // Step3:
    int i=0;
    temp = head;
    while(temp!=NULL)
    {
        temp->val = arr[i];
        i++;
        temp=temp->next;
    }

    return head;
}

int main()
{
    vector<int> nums = {5,10,15,6,21};
    Node* head = arrayToLL(nums);

    head = sortLL(head);

    printNodeOfLL(head);


    return 0;
}