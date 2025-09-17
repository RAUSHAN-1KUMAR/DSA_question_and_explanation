/*
Implementing deque Using array
*/

#include<bits/stdc++.h>
using namespace std;

class dque{
public:
    int *arr;
    int front, back;
    int size;

    dque(int size){
        this->size = size;
        arr = new int[size];
        front = back = -1;
    }

    void push_back(int data){
        if(back==-1 && front==-1){
            front = back = 0;
            arr[back]=data;
            return;
        }

        if((back+1)%size == front){
            cout << "queue overflow" << endl;
            return;
        }

        back = (back+1)%size;
        arr[back]=data;
    }

    void pop_back(){
        if(front==-1 && back==-1){
            cout << "deque is already empty" << endl;
            return;
        }

        if(front==back){
            front=back=-1;
            return;
        }

        back = (back==0 ? size-1 : back-1);
    }

    void push_front(int data){
        if(back==-1 && front==-1){
            front = back = 0;
            arr[front]=data;
            return;
        }

        front = (front==0 ? size-1 : front-1);

        if(front==back){
            cout << "overflow" << endl;
            return;
        }

        arr[front]=data;
    }

    void pop_front(){
        if(front==-1 && back==-1){
            cout << "deque is already empty" << endl;
            return;
        }

        if(front==back){
            front=back=-1;
            return;
        }

        front = (front+1)%size;
    }

    bool isEmpty(){
        if(front==-1 && back==-1){
            return true;
        }
        else {
            return false;
        }
    }

    int getSize(){
        if(front==-1 && back==-1) return 0;

        if(front <= back){
            return back-front+1;
        }
        else{
            return size - (front-back-1);
        }
    }

    int getFront(){
        if(front==-1){
            cout << "deque is empty" << endl;
            return -1;
        }

        return arr[front];
    }

    int getBack(){
        if(back==-1){
            cout << "deque is empty" << endl;
            return -1;
        }
        return arr[back];
    }

    void print(){
        if(front==-1 && back==-1){
            cout << "deque is empty" << endl;
            return;
        }

        int f=front;
        while(f!=back){
            cout << arr[f] << " ";
            f = (f+1)%size;
        }
        cout << arr[f] << endl;
    }

    ~dque(){
        cout << "dtor called" << endl;
        delete[] arr;
    }
};


int main()
{
    dque dq(5);

    // back m push
    dq.push_back(10);
    cout << "size: " << dq.getSize() << endl;

    // front and back m push
    dq.push_front(7);
    dq.push_back(19);

    cout << dq.getFront() << " " << dq.getBack() << endl;
    cout << "size: " << dq.getSize() << endl;

    // front m pop
    dq.pop_front();
    cout << dq.getFront() << " " << dq.getBack() << endl;

    dq.print();

    return 0;
}



