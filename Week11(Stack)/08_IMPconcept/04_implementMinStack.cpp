/* -> 155

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:
    1. MinStack() initializes the stack object.
    2. void push(int val) pushes the element val onto the stack.
    3. void pop() removes the element on the top of the stack.
    4. int top() gets the top element of the stack.
    5. int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

*/

/*
Approach:-
    -- I am pushing pair<int,int> in stack -> (data, min), so that we can have the min element of each stack instance
*/

#include<iostream>
#include<vector>
using namespace std;


class MinStack
{
public:
    vector<pair<int,int>> st;

    MinStack(){}

    void push(int val)
    {
        if(st.empty()){
            // it means i am inserting first element
            pair<int,int> p = {val, val};
            st.push_back(p);
        }
        else{
            pair<int,int> p;
            p.first = val;
            int puranaMin = st.back().second;
            p.second = min(puranaMin, val);
            st.push_back(p);
        }
    }

    void pop()
    {
        st.pop_back();
    }

    int top()
    {
        pair<int,int> rightMostPair = st.back();
        return rightMostPair.first;
    }

    int getMin()
    {
        pair<int,int> rightMostPair = st.back();
        return rightMostPair.second;
    }
};


int main()
{

    return 0;
}