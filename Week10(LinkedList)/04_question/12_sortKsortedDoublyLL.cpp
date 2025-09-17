/* GFG

Given a doubly linked list containing n nodes, each node is at most k-indices away from its target position. The problem is to sort the given doubly linked list. The distance can be assumed in either of the directions (left and right).

Examples:
    Input: DLL : 3 <-> 2 <-> 1 <-> 5 <-> 6 <-> 4 , k = 2
    Output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6


    Input: DLL: 5 <-> 6 <-> 7 <-> 3 <-> 4 <-> 4 , k = 3
    Output: 3 <-> 4 <-> 4 <-> 5 <-> 6 <-> 7

*/

/*
Approach: extreme brute force
    -- for each node, i have called a function that form a vector by taking the next k node including the itself also, and then sort the vector, and then insert that sorted vector element into the DLL again

Time Comp:- n*(k^2)
Space Comp:- k

Better approach -> next solution
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


// solution
void sortHelper(Node* head, int k)
{
    vector<int> help;

    // storing the next k data into head
    int c=k+1;
    Node* temp = head;
    while (c && temp!=NULL)
    {
        help.push_back(temp->data);
        temp=temp->next;
        c--;
    }

    // lets sort the given array(bubble sort)
    for(int i=0 ; i<help.size()-1 ; i++)
    {
        for(int j=0 ; j<help.size()-i-1 ; j++)
        {
            if(help[j]>help[j+1])
            {
                swap(help[j], help[j+1]);
            }
        }
    }

    // now storing the sorted array in DLL
    temp = head;
    for(int num:help)
    {
        temp->data = num;
        temp=temp->next;
    }

}

Node* sortKsortedDLL(Node* head, int k)
{
    Node* temp = head;

    while (temp!=NULL)
    {
        sortHelper(temp, k);
        temp = temp->next;
    };

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