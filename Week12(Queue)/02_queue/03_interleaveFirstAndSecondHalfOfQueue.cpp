/*
We have a given queue:-
    input: 10,20,30,40,50,60,70,80
    output:10,50,20,60,30,70,40,80
    Explanaion: first half(-> 10,20,30,40) is in between second half(-> 50,60,70,80) of queue

given that length of queue is even.
*/

/*
Appraoch:- 
    -- give queue ko half m tod do, todne ke liye ek aur queue banana hoga then usme first half element push kerna hoga
    -- ab do half m devide kerne ke baad, ek half ko lengen aur uske last m push krenge dusre half ka front then khud ka front then dusre ka front and then khud ka front and then....
*/

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interLeaveQueue(queue<int> &first)
{
    queue<int> second;

    // push first half of first queue into second queue
    int size = first.size();
    for(int i=0 ; i<size/2 ; i++)
    {
        int temp = first.front();
        first.pop();

        second.push(temp);
    }

    // merge both the half
    // into first queue
    for(int i=0 ; i<size/2 ; i++)
    {
        int temp = second.front();second.pop();

        first.push(temp);// push front element of second half

        temp = first.front();first.pop();

        first.push(temp);// push front element of own queue
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

    interLeaveQueue(q);

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