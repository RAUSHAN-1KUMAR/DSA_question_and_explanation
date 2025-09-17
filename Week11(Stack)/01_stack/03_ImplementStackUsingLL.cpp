
// Stack -> LIFO(last in first out)
// using array bounds us to fix the size of the array, so linked list will not

#include<iostream>
using namespace std; 

class Node
{
public:
    int val;
    Node* next;

    Node(){}

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

class Stack
{
public:
    Node* top=NULL;
    int size=0;

    Stack(){}

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = top;
        top=temp;

        size++;
    }

    int pop()
    {
        if(top==NULL)
        {
            cout << "Stack UNDERFLOW" << endl;
            return -1;
        }
        int ele = top->val;

        Node* temp = top;
        top = top->next;
        delete temp;
        
        size--;

        return ele;
    }

    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    int getTop(){
        if(top==NULL){
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else 
            return top->val;
    }

    int getSize(){
        return size;
    }
};


int main()
{
    // creation
    Stack st;

    //operations push
    st.push(10);
    st.push(20);
    st.push(20);

    //operations pop
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;

    return 0;
}

