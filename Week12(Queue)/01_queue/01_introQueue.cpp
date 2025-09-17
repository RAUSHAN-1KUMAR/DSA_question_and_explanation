
// Queue -> FIFO(first in first out)

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int> q;

    q.push(5);

    cout << "SIze of queue: " << q.size() << endl;

    // empty check
    if(q.empty()) cout << "Queue is empty" << endl;
    else cout << "Quere is not empty" << endl;

    q.pop();

    cout << "SIze of queue: " << q.size() << endl;

    // empty check
    if(q.empty()) cout << "Queue is empty" << endl;
    else cout << "Quere is not empty" << endl;


    // more pusshing
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "front element: " << q.front() << endl;
    cout << "last element: " << q.back() << endl;

    return 0;
}