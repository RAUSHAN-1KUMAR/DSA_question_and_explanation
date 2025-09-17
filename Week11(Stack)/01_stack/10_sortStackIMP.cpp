
// using recursion:- to solve this problem we need the concept of inserting element In Sorted Stack. First we will pop the stack till the end and the while backtracking we will insert that popped element in to its sorted position

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

    if(temp<=element){
        st.push(element);
        return;
    }
    else{
        st.pop();
        insertInSortedStack(st, element);
        st.push(temp);
    }
}

void sortingStack(stack<int> &st)
{
    // base case
    if(st.empty())
    {
        return;
    }

    // solve one case
    int temp = st.top();
    st.pop();

    // RE
    sortingStack(st);

    // last se sort kerte aao
    insertInSortedStack(st, temp);

}


int main()
{
    stack<int> st;

    st.push(10);
    st.push(11);
    st.push(7);
    st.push(14);
    st.push(5);

    cout << "Before sorting: " << endl;
    displayStack(st);

    sortingStack(st);

    cout << "After sorting: " << endl;
    displayStack(st);
    
    return 0;
}

