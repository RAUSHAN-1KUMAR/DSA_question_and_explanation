/*
Implement N Queues in an array
:- push and pop operation
*/

//explained in notecopy

/*
Logic ye h ki:
Push kerte waqt
    1. first time 'front' aage badhega
    2. 'rear' queue ke back ko store krega
    3. 'next' array, 'front' ke next ko store krega, kyunki jab pop kregen ko 'front' array update hoga 'next' array ka use kerke but yahi chiz N stack implementation m alag hoga, usme 'next' store krega 'rear' ke prev ko and jab pop krengen to 'rear' array update hoga 'next' array ka use kerke.

    
Pop kerte waqt: pop ka scene thoda easy h
    1. use hoga 'front' array ka, ki kon se index p starting elment push hua tha\
    2. then 'front' array ko update, using 'next' array
    3. so previously 'next' array was containing the next index for queue, but now it has been used so it will now used to store next free spot: next[index] = freespot.
    4. update freespot: freespot = index


Note:
    -- dhyan ye rakhna h ki kon pehle update hoga and kon baad m
*/

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
        for(int i=0 ; i<s ; i++) next[i] = i+1;

        next[s-1] = -1;  
    }


    bool push(int x, int qi){
        // overflow check
        if(freeSpot == -1) return false;

        // find free index
        int index = freeSpot;

        // update freeSpot
        freeSpot = next[index];

        // If the queue was empty, set its front to the new slot
        if(front[qi]==-1) {
            front[qi] = index;
        }
        else{// Otherwise, link the previous rear element to this new slot
            next[rear[qi]] = index; 
        }

        // Mark the end of the list for this new element
        next[index] = -1;

        // Update the rear of the queue to be this new slot
        rear[qi] = index;

        // Store the actual data item in the array
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


