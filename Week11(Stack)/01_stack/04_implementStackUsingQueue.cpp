/*
Implementing Stack using queue data structure -> LIFO(last in first out)

Implement the MyStack class:
    - void push(int x) Pushes element x to the top of the stack.
    - int pop() Removes the element on the top of the stack and returns it.
    - int top() Returns the element on the top of the stack.
    - boolean empty() Returns true if the stack is empty, false otherwise.

Notes:
    1. You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
    2 Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
*/

/*
Approach:-
    -- Logic kya sochna hai:- Queue ka use kerke pattern ko reverse kaise ker sakte without recursion

    Method1:- using two queue
        :push(x):- O(n)
            - pehle x ko push kerdo queue2 m,
            - push element of queue1 to queue2,
            - push element of queue2 to queue1,

        :pop():- O(1)
            - queue1 se pop ker dengen (queue ka front stack ka top)

        :top():- O(1)
            - queue1 ka front will be the top of the stack

    Method2:- using one queue
        :push(x):- O(n)
            - x ko push kerdo queue m (but ab ekhi queue h to stack ke liye queue ke top p acces kaise krengen for pop and top operation)
            - push kerne ke baad ek loop chalayengen for size-1 times and pop krengen then push krengen

        :pop():-
            - queue se pop kerdo (queue ka front stack ka top)

        :top():- O(1)
            - queue ka front will be the top of the stack
*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// applying method 2
class MyStack{
public:
    queue<int> q;

    MyStack(){}

    void push(int x){
        q.push(x);
        for(int i=0 ; i<q.size()-1 ; i++)
        {
            int front = q.front();

            q.pop();// pop from front

            q.push(front); // push it back
        }
    }

    int pop(){
        int top = q.front();
        q.pop();

        return top;
    }

    int top(){
        return q.front();
    }

    bool empty(){
        return q.empty();
    }
};

int main()
{

    return 0;
}