

#include<iostream>
#include<deque>
using namespace std;


int main()
{
    deque<int> dq;

    // back m push
    dq.push_back(10);
    cout << "size: " << dq.size() << endl;

    // front and back m push
    dq.push_front(7);
    dq.push_back(19);

    cout << dq.front() << " " << dq.back() << endl;
    cout << "size: " << dq.size() << endl;

    // front m pop
    dq.pop_front();
    cout << dq.front() << " " << dq.back() << endl;
    return 0;
}

