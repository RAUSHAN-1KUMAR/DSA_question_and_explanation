/*
Return the kth node from the end, assuming 0 index position
*/

/*
Appraoch:- recursive approch
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(){
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Dtor called for:" << this->data << endl;
    }
};

void printLL(Node* &head)
{
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int lengthLL(Node* &head)
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

void deleteAllNode(Node* &head)
{
    Node* temp = head;

    while (head!=NULL)
    {
        head = temp->next;
        delete temp;
        temp = head;
    }
    
    delete temp;
}


// recursive approach
void fun(Node* head, int &position, int &ans)
{
    if(head==NULL) return;

    fun(head->next, position, ans);

    if(position==0) ans = head->data;

    position--;
}

int kthNodeFromEnd(Node* &head, int k)
{
    int ans = -1;
    
    fun(head, k, ans);


    return ans;
}

int main()
{
    Node* first = new Node(5);
    Node* second = new Node(10);
    Node* third = new Node(15);
    Node* forth = new Node(40);
    Node* fifth = new Node(2);
    Node* sixth = new Node(3);
    Node* seventh = new Node(20);

    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    int ans = kthNodeFromEnd(head,3);
    cout << ans << endl;

    deleteAllNode(head);;

    return 0;
}