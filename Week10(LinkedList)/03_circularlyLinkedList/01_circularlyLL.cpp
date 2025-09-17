/*
There will no head or tail
*/

#include<iostream>
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
};

void printCLL(Node* &first)
{
    Node *temp = first;

    while(temp->next != first)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int lengthCLL(Node* &first)
{   
    Node* temp = first;
    int count = 0;

    while (temp->next != first)
    {
        count++;
        temp = temp->next;
    }

    return count+1;
}



int main()
{
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* forth = new Node(40);
    Node* fifth = new Node(50);


    first->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = first;//-> last will point to first

    // but how to print the CLL, handle infinite loop
    cout << "Printing CLL: " << endl;
    printCLL(first);

    cout << "Printing length of CLL: ";
    cout << lengthCLL(first) << endl;

    delete first;
    delete second;
    delete third;
    delete forth;
    delete fifth;

    return 0;
}



