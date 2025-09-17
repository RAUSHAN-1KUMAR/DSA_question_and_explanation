
// Stack -> LIFO(last in first out)

#include<iostream>
#include<stack>
using namespace std; 

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "size of stack is: " << st.size() << endl;

    st.pop();

    if(st.empty()){
        cout << "stack is empty: " << endl;
    }
    else{
        cout << "stack is non empty: " << endl;
    }

    cout << st.top() << endl;

    return 0;
}
