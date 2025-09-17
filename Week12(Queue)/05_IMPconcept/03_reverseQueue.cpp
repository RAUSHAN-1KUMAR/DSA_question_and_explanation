/*
Reverse a given queue

We have a given queue:- 10,20,30,40,50,60
                Output:- 60,50,40,30,20,10
*/

/*
Appraoch:- 
    1. using stack
        -- queue se pop kerke stack m dale, and then stack se pop kerke queue m dalo
        -- but don't we are using some space by using stack-> no because queue se pop keeke stack m dal rhe h at the end queue ke size jitna hi space use ho rha h

    2. using recursion
*/

// what if they ask to reverse only first k

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// using stack, iterative appraoch
void reverseQueue(queue<int> &q)
{
    stack<int> s;

    // one by one queue se element lo and stack me daalo
    while(!q.empty())
    {
        int frontElement = q.front();
        q.pop();

        s.push(frontElement);
    }

    // one by one stack se lo and queue me push kerdo
    while (!s.empty())
    {
        int element = s.top();
        s.pop();

        q.push(element);
    }
    
}


// using recursion
void reverseQueueRec(queue<int> &q)
{
    // base case
    if(q.empty())
    {
        return;
    }


    int temp = q.front();
    q.pop();

    // RE(head recursion)
    reverseQueue(q);

    q.push(temp);
}


// what if they ask to reverse only first K elements
void reverseKQueue(queue<int> &q, int k)
{
    stack<int> st;

    // push first k element into stack
    for(int i=0 ; i<k ; i++)
    {
        int temp = q.front();
        q.pop();

        st.push(temp);
    }

    // push all k element from stack to queue
    while(!st.empty())
    {
        int temp = st.top();
        st.pop();

        q.push(temp);
    }

    // now push and pop first (n-k) element of queue
    for(int i=0 ; i<(q.size()-k) ; i++)
    {
        int temp = q.front();
        q.pop();

        q.push(temp); 
    }
}


int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    reverseQueue(q);

    cout << "Printing queue: " << endl;
    while(!q.empty())
    {
        int element = q.front();
        q.pop();
        cout << element << " ";
    }
    cout << endl;
    
    return 0;
}
