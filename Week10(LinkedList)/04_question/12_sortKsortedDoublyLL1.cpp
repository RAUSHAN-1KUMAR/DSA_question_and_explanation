/* GFG

Given a doubly linked list containing n nodes, each node is at most k-indices away from its target position. The problem is to sort the given doubly linked list. The distance can be assumed in either of the directions (left and right).

Examples:
    Input: DLL : 3 <-> 2 <-> 1 <-> 5 <-> 6 <-> 4 , k = 2
    Output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6


    Input: DLL: 5 <-> 6 <-> 7 <-> 3 <-> 4 <-> 4 , k = 3
    Output: 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7
*/

/*
Approach:
    -- applying insertion sort in DLL
        -- we can swap the node data,

Time Comp:- n*k -> TLE
Space Comp:- 1

optimal approach -> using minHeap(Heap Week3)
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


// solution(using insertion sort)
Node* sortKsortedDLL(Node* head, int k)
{
    // corner case(null or only one node)
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    
    Node* curr = head->next;
    Node* next = curr->next;

    while (curr!=NULL)
    {
        Node* currPrev = curr->prev; // currPrev will iterate back to find the exact location for curr node value

        int c = k;

        // currPrev is iterating back to find the curr's exact location within k
        while(currPrev!=NULL && currPrev->data > curr->data && c)
        {
            int data = curr->data;
            curr->data = currPrev->data;
            currPrev->data = data;

            curr = currPrev;
            currPrev = currPrev->prev;

            // check only k step back
            c--;
        }

        // change curr and next pointer
        curr = next;

        if(next != NULL)
            next = next->next;
    };

    return head;
}



int main()
{
    // creating node
    Node *first = new Node(3);
    Node *second = new Node(2);
    Node *third = new Node(1);
    Node *forth = new Node(5);
    Node *fifth = new Node(6);
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

    head = sortKsortedDLL(head, 1);

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


        // if(currPrev==NULL) cout << "NULL" << endl;
        // else cout << currPrev->data << endl;

        

        // // now checking that, will it be newhead or not
        // if(currPrev==NULL && currPrev->next!=curr)// our new head
        // {
        //     cout << "OK" << endl;
        //     Node* prev = curr->prev;

        //     prev->next = curr->next;

        //     if(curr->next!=NULL)
        //         curr->next->prev = prev;

        //     curr->next = newHead;
        //     curr->prev = newHead->prev;
        //     newHead->prev = curr;

        //     newHead = curr;
        // }
        // else if(currPrev->next!=curr && currPrev!=NULL)// replace node
        // {
        //     Node* front = currPrev->next;
        //     Node* prev = curr->prev;

        //     prev->next = curr->next;

        //     if(curr->next!=NULL)
        //         curr->next->prev = prev;  

        //     curr->next = front;
        //     curr->prev = currPrev;

        //     currPrev->next = curr;
        //     front->prev = curr;          
        // }


