
// Using recursion: popped the stack till the top of stack become less than the element to be inserted, and pushed that element and then backTracked.

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

void insertInSortedStack(stack<int> &st, int element)
{
    // base case
    if(st.empty())
    {
        st.push(element);
        return;
    }

    // solve one case
    int temp = st.top();
    
    if(temp<=element)
    {
        st.push(element);
        return;
    }
    else
    {
        st.pop();
        insertInSortedStack(st, element);
        st.push(temp);
    }
}


int main()
{
    stack<int> st;

    st.push(1);
    st.push(7);
    st.push(10);

    cout << "Before Insertion: " << endl;
    displayStack(st);

    // Insertion at sorted Stack
    insertInSortedStack(st, 3);

    cout << "After Insertion: " << endl;
    displayStack(st);
    
    return 0;
}

