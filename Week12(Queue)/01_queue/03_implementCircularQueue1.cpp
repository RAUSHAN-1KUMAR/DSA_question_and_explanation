
/*
Using modulo
*/

#include<iostream>
#include<queue>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int currSize;
    int front;
    int rear;

    Queue(int size)
    {
        this->arr = new int[size];
        this->size = size;
        this->currSize = 0;
        this->front = -1;
        this->rear = -1;
    }

    void push(int val)
    {
        // check full
        if(currSize==size){
            cout << "OVERFLOW" << endl;
            return;
        }

        if(currSize==0)
        {
            front++;
            rear++;
        }
        else 
        {
            rear = (rear+1)%size;
        }

        arr[rear]=val;
        currSize++;
    }

    int pop(){
        if(currSize==0){
            cout << "UNDERFLOW" << endl;
            return;
        }
        
        int ele = arr[front];

        if(currSize==1)
        {
            front = -1; 
            rear = -1;
        }
        else
        {
            front = (front+1)%size;
        }

        currSize--;

        return ele;
    }

    bool isEmpty(){
        if(front==-1 && rear ==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        if(front==-1 && rear ==-1) return 0;
        return rear-front+1;
    }

    int getFront()
    {
        if(front==-1){
            cout << "No element in queue" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getRear()
    {
        if(rear==-1){
            cout << "No element in queue" << endl;
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    void print()
    {
        if(rear==-1){
            cout << "Queue is empty! " << endl;
            return;
        }

        cout << "printing queue: ";
        for(int i=0 ; i<=rear ; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // creation
    Queue q(5);
    q.print();

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(7);
    q.print();

    q.push(11);
    q.print();

    q.push(23);
    q.print();

    // size
    cout << "size of queue: " << q.getSize() << endl;

    // pop
    int p = q.pop();
    q.print();
    cout << "size of queue: " << q.getSize() << endl;

    // empty
    cout << "queue is empty or not: " << q.isEmpty() << endl;

    return 0;
}