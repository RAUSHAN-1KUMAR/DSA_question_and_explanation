/*
priority_queue is a stl heap
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    // create max heap
    priority_queue<int> pq;

    // insertion
    pq.push(10);
    pq.push(20);
    pq.push(50);
    pq.push(40);
    pq.push(30);

    // access  
    cout << "top element: " << pq.top() << endl;

    // pop
    pq.pop(); //-> deletion always root node
    cout << "top element after deletion: " << pq.top() << endl;


    // some common functions
    cout << "size of max heap: " << pq.size() << endl;
    cout << "empty of not " << pq.empty() << endl;



    return 0;
}



