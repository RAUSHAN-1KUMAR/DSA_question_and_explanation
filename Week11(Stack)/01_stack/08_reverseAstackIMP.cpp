
// using recursion: to solve this question we need to apply the logic of insertAtBottom of Stack, first we popped the stack till and then while returning call the insert at bottom function for each popped element

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

void reverseStack(stack<int> &st)
{
    // base case
    if(st.empty()) return;

    // ek case solve kro
    int temp = st.top(); st.pop();

    reverseStack(st);

    // wapas aate waqt 
    insertAtBottom(st, temp);
}


int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);


    displayStack(st);

    reverseStack(st);

    displayStack(st);
    
    return 0;
}

