
#include<iostream>
#include<stack>
using namespace std; 

int main()
{
    string str = "BABBAR";

    stack<char> st;

    for(char ch:str)
    {
        st.push(ch);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;


    return 0;
}