
// using recursion: push till stack become empty and then at the end push the element

#include<iostream>
#include<stack>
using namespace std; 

void displayStack(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    
}

void insertAtBottom(stack<int> &st, int &element)
{
    // base case
    if(st.empty())
    {
        cout << "Pushed: " << element << endl;
        st.push(element);
        return;
    }

    // solve one case
    int temp = st.top();
    st.pop();

    insertAtBottom(st, element);

    // backTrack
    st.push(temp);
}


int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int element = 400;

    displayStack(st);

    insertAtBottom(st, element);

    displayStack(st);
    
    return 0;
}

