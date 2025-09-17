/* GFG

Given a doubly linked list containing n nodes, each node is at most k-indices away from its target position. The problem is to sort the given doubly linked list. The distance can be assumed in either of the directions (left and right).

Examples:
    Input: DLL : 3 <-> 2 <-> 1 <-> 5 <-> 6 <-> 4 , k = 2
    Output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6


    Input: DLL: 5 <-> 6 <-> 7 <-> 3 <-> 4 <-> 4 , k = 3
    Output: 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7

*/

/*
Approach: minHeap
    -- similar to previous one, we are first take k element into heap and we will use top element to modify the DLL.

TC-> n*logk
SC-> k
*/

#include<bits/stdc++.h>
using namespace std;

// creating node
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(){
        this->next = NULL;
        this->prev = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printDLL(Node* &head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lengthDLL(Node* &head)
{
    Node *temp = head;

    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}


// solution(using minHeap)
Node* sortKsortedDLL(Node* head, int k)
{
    // corner case(null or only one node)
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    Node* temp=head;
    
    // min Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int c=k+1;
    while(c)
    {
        minHeap.push(temp->data);

        temp=temp->next;
        c--;
    }

    // after pushing the first k elements into minHeap now take one by one
    Node* tempBack = head;
    while(temp!=NULL||tempBack!=NULL)
    {
        int top=minHeap.top();
        minHeap.pop();

        tempBack->data = top;

        if(temp!=NULL)
        {
            minHeap.push(temp->data);
            temp=temp->next;
        }

        tempBack=tempBack->next;
    }

    return head;
}



int main()
{
    // creating node
    Node *first = new Node(5);
    Node *second = new Node(6);
    Node *third = new Node(7);
    Node *forth = new Node(3);
    Node *fifth = new Node(4);
    Node *sixth = new Node(4);

    // connection nodes
    Node *head = first;
    first->prev = NULL;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = forth;

    forth->prev = third;
    forth->next = fifth;

    fifth->prev=forth;
    fifth->next=sixth;

    sixth->prev=fifth;
    sixth->next=NULL;

    Node *tail = sixth;

    cout << "Printing DLL: " << endl;
    printDLL(head);

    head = sortKsortedDLL(head, 3);

    cout << "Printing DLL after sorting: " << endl;
    printDLL(head);

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;
    delete sixth;

    return 0;
}



