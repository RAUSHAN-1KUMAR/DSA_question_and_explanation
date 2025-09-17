
/*
Approach:
    -- take two tops, one at -1 and one at size n:
    -- for stack1 move -1 wala top to the right
    -- for stack1 move n wala top to the left
*/

#include<iostream>
using namespace std; 

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        this->top1 = -1;
        this->top2 = size;
    }

    void push1(int data){
        if(top2-top1==1){
            cout << "OVERFLOW!" << endl;
        }
        else{
            top1++;
            arr[top1] = data;
        }
    }

    void push2(int data){
        if(top2-top1==1){
            cout << "OVERFLOW!" << endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop1(){
        if(top1==-1){
            cout << "UNDERFLOW!" << endl;
        }
        else{
            arr[top1] = 0;
            top1--;
        }
    }

    void pop2(){
        if(top2==size){
            cout << "UNDERFLOW!" << endl;
        }
        else{
            arr[top2] = 0;
            top2++;
        }
    }

    int getTop1(){
        if(top1==-1){
            cout << "Stack1 is Empty" << endl;
            return -1;
        }
        else return arr[top1];
    }

    int getTop2(){
        if(top2==size){
            cout << "Stack1 is Empty" << endl;
            return -1;
        }
        else return arr[top2];
    }

    int getSize1(){
        return top1+1;
    }

    int getSize2(){
        return size-top2;
    }

    void print(){
        cout << endl;
        cout << "Top1: " << top1 << endl;
        cout << "Top2: " << top2 << endl;
        cout << "Stack: ";
        for(int i=0 ; i<size ; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl << endl;
    }
}; 


int main()
{
    // creation
    Stack st(6);

    st.print();
 
    st.push1(10);
    st.print();

    st.push1(20);
    st.print();

    st.push2(20);
    st.print();

    st.push2(200);
    st.print();

    st.push2(56);
    st.print();

    return 0;
}

