
/*
Queue-> FIFO(first in first out)

using array bounds us to fix the size of the array
*/

#include<iostream>
#include<queue>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        // check full
        if(rear == size-1){
            cout << "OVERFLOW" << endl;
            return;
        }

        // if first element is pushing
        if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        else 
        {
            rear++;
            arr[rear]=val;
        }
    }

    void pop(){
        if(front==-1 && rear == -1){
            cout << "UNDERFLOW" << endl;
            return;
        }

        // if only one element is in queue
        if(front == rear)
        {
            arr[front]=-1;
            front=-1;
            rear=-1;
        }   
        else
        {
            arr[front]=-1;
            front++;
        }
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
    q.pop();
    q.print();
    cout << "size of queue: " << q.getSize() << endl;

    // empty
    cout << "queue is empty or not: " << q.isEmpty() << endl;

    return 0;
}