/* -> 232

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:
    - void push(int x) Pushes element x to the back of the queue.
    - int pop() Removes the element from the front of the queue and returns it.
    - int peek() Returns the element at the front of the queue.
    - boolean empty() Returns true if the queue is empty, false otherwise.


Notes:
    1. You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.  
    2. Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/

/*
Approach:-
    -- Logic kya sochna hai:- Stack ak use kerke pattern ko reverse kaise ker sakte without recursion

    Method1:- using two stack but push operation in O(n) time
        :push(x):- O(n)
            - sabse pehle stack1 ke elements ko stack2 m push kerdo, 
            - stack1 khali ho chuka h then x ko stack1 m push kerdo,
            - ab stack2 ke elements ko stack1 m push kerdo, at the end stack1 will contain the element such that FIFO would occur.
        
        :front():- O(1)
            - return stack1 ka top 

        :pop():- O(1)
            - stack1 se pop ker dengen

    Method2:- using two stack but pop operation in O(n) time
        :push(x):- O(1)
            - x ko push kerdo stack1 m.

        :pop():- O(n)
            - if stack2 is not empty then pop stack2
            - else stack1 ke elements ko stack2 m push kerdo
            - and then stack2 se pop kerdo.

        :front():- O(n)
            - if stack2 is not empty then return stack2 ka top
            - else stack1 ka elements ko stack2 m push kerdo
            - and then return stack2 ka top
*/


#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// applying method 2
class MyQueue{
public:
    stack<int> s1, s2;

    MyQueue(){}

    void push(int x){
        s1.push(x);
    }

    int pop(){
        int pop = -1;
        if(!s2.empty()){
            pop = s2.top();
        }
        else{
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            pop = s2.top();
        }
        
        s2.pop();

        return pop;
    }

    int peek(){
        int front = -1;
        if(!s2.empty()){
            front = s2.top();
        }
        else{
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            front = s2.top();
        }

        return front;
    }

    bool empty(){
        return s1.empty() && s2.empty();
    }
};

int main()
{

    return 0;
}