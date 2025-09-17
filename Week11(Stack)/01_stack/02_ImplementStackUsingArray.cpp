
// Stack -> LIFO(last in first out)
// using array bounds us to fix the size of the array

#include<iostream>
using namespace std; 

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data){
        if(top == size-1){
            cout << "Stack overflow" << endl;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    void pop(){
        if(top == -1){
            cout << "Stack underflow" << endl;
        }
        else top--;
    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int getTop(){
        if(top==-1){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else 
            return arr[top];
    }

    int getSize(){
        return top+1;
    }

    void print(){
        cout << "Top: " << top << endl;
        cout << "Top element: " << getTop() << endl;
        cout << "Stack: ";
        for(int i=0 ; i<getSize() ; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl << endl;
    }
};


int main()
{
    // creation
    Stack st(8);

    //operations push
    st.push(10);
    st.print();

    st.push(20);
    st.print();

    st.push(20);
    st.print();

    //operations pop
    st.pop();
    st.print();

    st.pop();
    st.print();

    st.pop();
    st.print();

    st.pop();

    return 0;
}

