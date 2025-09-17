/*
Reverse a given queue, reverse first k elements

We have a given queue:- 10,20,30,40,50,60 , k=3
                Output:- 30,20,10,40,50,60
*/

/*
Appraoch:- using stack, let say input: 10,20,30,40,50,60, k=3
    -- push first k element from queue to stack:
        stack: 10,20,30
        queue: 40,50,60
    -- push all element of stack to queue
        stack: empty
        queue: 40,50,60,30,20,10
    -- now queue ke starting se n-k element pop kerte jao and last me push kerto jao
        queue: 30,20,10,40,50,60
*/


#include<iostream>
#include<stack>
#include<queue>
using namespace std;

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

    // push all k element of stack into queue
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

    reverseKQueue(q,3);

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
