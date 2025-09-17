
/*
Implementing circular queue Without modulus operator
*/

#include<iostream>
using namespace std;

class Cqueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Cqueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        if((front==0 && rear == size-1) || (rear == front-1))// overflow
        {
            cout << "OVERFLOW" << endl;
        }
        else if(front==-1 && rear ==-1)// first element
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else if(rear == size-1 && front!=0)// circular nature
        {
            rear = 0;
            arr[rear] = val;
        }
        else // normal flow
        {
            rear++;
            arr[rear] = val;
        }
    }

    void pop()
    {
        if(front==-1 && rear ==-1)//underflow
        {
            cout << "UNDERFLOW" << endl;
        }
        else if(front == rear)// single element in queue
        {
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(front==size-1)// circular case
        {
            arr[front] = -1;
            front = 0;
        }
        else//normal case
        {
            arr[front]=-1;
            front++;
        }
    }

    void print()
    {
        cout << "printing queue: ";
        for(int i=0 ; i<size ; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Cqueue q(5);
    q.print();

    q.push(10);
    q.print();

    q.push(20);
    q.print();

    q.push(30);
    q.print();

    q.push(40);
    q.print();

    q.push(50);
    q.print();

    q.push(60);//-> overflow
    q.print();

    // pop
    q.pop();
    q.pop();
    q.pop();
    q.print();

    q.push(50);
    q.print();

    q.push(110);
    q.print();

    q.push(220);
    q.print();

    return 0;
}