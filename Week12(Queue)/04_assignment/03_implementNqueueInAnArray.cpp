/*
Implement N Queues in an array
:- push and pop operation
*/

//explained in notecopy

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class NQueue
{
public:
    int s, n, freeSpot;
    int *arr, *front, *rear, *next;

    NQueue(int _s, int _n) : s(_s), n(_n), freeSpot(0){
        arr = new int[s];
        next = new int[s];
        front = new int[n];
        rear = new int[n];

        // initializing front array
        for(int i=0 ; i<n ; i++) front[i] = -1;

        // initializing rear array
        for(int i=0 ; i<n ; i++) rear[i] = -1;

        // initializing next array
        for(int i=0 ; i<s ; i++)next[i] = i+1;
        next[s-1] = -1;  
    }


    bool push(int x, int qi){
        // overflow check
        if(freeSpot == -1) return false;

        // find free index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // if first element is being pushed
        if(front[qi]==-1) {
            front[qi] = index;
        }
        else{// link rearest index to new element's index 
            next[rear[qi]] = index; 
        }

        // update index
        next[index] = -1;

        // update rear
        rear[qi] = index;

        // push element
        arr[index]=x;

        return true; 
    }


    int pop(int qi){
        // underflow
        if(front[qi]==-1) return -1;

        // find index to pop
        int index = front[qi];

        // update front
        front[qi] = next[index];

        // manage freeSpot of next array
        next[index] = freeSpot;

        // update freeeSpot
        freeSpot = index;

        return arr[index];
    }

    ~NQueue(){
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main()
{
    NQueue Nq(8,3);

    cout << Nq.push(1,0) << endl;
    cout << Nq.push(2,0) << endl;
    cout << Nq.push(5,1) << endl;
    cout << Nq.push(3,0) << endl;
    
    cout << Nq.pop(1) << endl;

    return 0;
}


