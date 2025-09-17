/*
priority_queue is a stl heap
*/


#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main()
{
    // create min heap

    //vector<int> specifies to store the element as a vector 
    //greater<int> is a comparator function that tell how you would like to arrange the elements i.e,. the smallest element has the highest priority
    priority_queue<int, vector<int>, greater<int> > pq;

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



