/*
Reverse a given queue

We have a given queue:- 10,20,30,40,50,60
                Output:- 60,50,40,30,20,10
*/

/*
Appraoch:- recursive
    -- pop kerte kerte last tak jao,, and last se push kerte kerte aao
*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q)
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
