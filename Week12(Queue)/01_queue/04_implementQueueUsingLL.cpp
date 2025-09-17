

#include<iostream>
using namespace std; 

class Node
{
public:
    int val;
    Node* next;

    Node(){}

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

class Queue
{
public:
    Node* front=NULL;
    Node* rear=NULL;
    int size=0;

    Queue(){}

    void push(int data)
    {
        Node* temp = new Node(data);

        if(front==NULL)
        {
            front=temp;
            rear=temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }

        size++;
    }

    int pop()
    {
        if(front==NULL)
        {
            cout << "Queue UNDERFLOW" << endl;
            return -1;
        }
        
        int ele = front->val;

        Node* temp = front;
        front = front->next;
        delete temp;

        size--;

        return ele;
    }

    bool isEmpty(){
        if(rear==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    int getFront(){
        if(front==NULL){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else 
            return front->val;
    }

    int getSize()
    {
        return size;
    }
};


int main()
{
    // creation
    Queue que;

    //operations push
    que.push(10);
    que.push(20);
    que.push(20);

    //operations pop
    cout << que.pop() << endl;
    cout << que.pop() << endl;
    cout << que.pop() << endl;
    cout << que.pop() << endl;

    return 0;
}

