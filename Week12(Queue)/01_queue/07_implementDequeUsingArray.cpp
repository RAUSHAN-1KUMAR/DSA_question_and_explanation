
/*
Implementing dequeue Using array
*/

#include<iostream>
#include<deque>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front;
    int rear;
    
    Deque(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushBack(int val)
    {
        if((front==0 && rear == size-1) || (rear == front-1))// overflow
        {
            cout << "OVERFLOW" << endl;
        }
        else if(front==-1 && rear ==-1)// first push
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else if(rear == size-1 && front!=0)// circular nature for rear
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


    void pushFront(int val)
    {
        if((front==0 && rear == size-1) || (rear == front-1))// overflow
        {
            cout << "OVERFLOW" << endl;
        }
        else if(front==-1 && rear == -1)// first push
        {
            front++;
            rear++;
            arr[front] = val;
        }
        else if(front==0 && rear != size-1) // circular nature for front
        {
            front = size-1;
            arr[front] = val;
        } 
        else// normal case
        {
            front--;
            arr[front] = val;
        }
    }

    void popFront()
    {
        if(front==-1 && rear == -1) //underflow
        {
            cout << "UNDERFLOW" << endl;
        }
        else if(front == rear) //single element
        {
            arr[front]=-1;
            front=-1;
            rear=-1;
        }   
        else if(front == size-1) // circular case for front
        {
            arr[front] = -1;
            front = 0;
        }
        else// normal case
        {
            arr[front]=-1;
            front++;
        }
    }

    void popBack()
    {
        if(front==-1 && rear==-1) // underflow
        {
            cout << "UNDERFLOW" << endl;
        }
        else if(front == rear)//single element
        {
            arr[rear]=-1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0)// circular case for rear
        {
            arr[rear] = -1;
            rear = size-1;
        }
        else // normal case
        {
            arr[rear] = -1;
            rear--;
        }
    }
};



int main()
{

    return 0;
}