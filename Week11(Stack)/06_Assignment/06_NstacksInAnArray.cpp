/*
Implement N stacks in a single array
:- push and pop operation
*/

// explained in notecopy

#include<iostream>
using namespace std; 

class NStack
{
public:
    int *a;
    int *top;
    int *next;
    int n; // no. of stack
    int size; // size of main array
    int freeSpot; // tell free space position

    NStack(int _n, int _s):n(_n), size(_s){
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        // initialization of top and next array
        for(int i=0 ; i<n ; i++){
            top[i]  = -1;
        }

        for(int i=0 ; i<size ; i++){
            next[i] = i+1;
        }
        next[size-1] = -1;
    }


    bool push(int X, int m){
        if(freeSpot==-1){
            return false;//-> OVERFLOW
        }

        //find index
        int index = freeSpot;

        //update freeSpot
        freeSpot = next[index];

        //update next
        next[index] = top[m-1];

        //undate top
        top[m-1] = index;
        
        //insert
        a[index] = X;

        return true;
    }

    int pop(int m){
        if(top[m-1]==-1){
            return -1;// UNDERFLOW
        }

        //index of top for mth stack
        int index = top[m-1];

        //update top
        top[m-1] = next[index];

        //update next
        next[index] = freeSpot;

        //update freeSpot
        freeSpot = index;

        // return popped element
        return a[index];
    }

    // destructor
    ~NStack(){
        delete[]a;
        delete[]top;
        delete[]next;
    }
}; 


int main() 
{
    NStack st(3,6);// teen stack ek hi six size ke array m

    cout << st.push(10,1) << endl;
    cout << st.pop(1) << endl;

    return 0;
}

