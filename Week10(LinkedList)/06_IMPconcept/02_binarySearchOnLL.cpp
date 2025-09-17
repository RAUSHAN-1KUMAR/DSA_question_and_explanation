/*
we are going to apply binary search on LL

*/

/*
Approach:-
    -- In case of array we had 'end' to check whether end condition for BS and also to find mid node.
    -- but now we only have 'head' pointer, then how we are going to find the mid node and also the end condition for BS

Note:- we can also apply the same code for BS on double LL.
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

void printNodeOfLL(Node *head);
Node* arrayToLL(vector<int> &nums);


// solution from here
Node* midNode(Node* start, Node* end)
{
    Node* slow = start;
    Node* fast = start;
    while (fast != end && fast->next != end) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* binary_searchLL(Node *head, int target)
{
    Node* start=head;
    Node* end=nullptr;
    while(start!=end)
    {
        Node* mid = midNode(start, end);
        
        if(mid->val == target){
            return mid;
        }
        else if(mid->val < target){
            start = mid->next;
        }
        else{
            end = mid;
        }
    }

    return nullptr;
}

int main()
{
    vector<int> nums = {5,10,15,25,30};

    Node* head = arrayToLL(nums);

    printNodeOfLL(head);
    
    if(binary_searchLL(head, 5))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    printNodeOfLL(head);

    return 0;
}



void printNodeOfLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

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