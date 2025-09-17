
// using recursion: popping stack till its half size and then at the base case of recursion returning the top(i.e., mid) element

#include<iostream>
#include<stack>
using namespace std; 

int solve(stack<int> &st, int &pos)
{
    // base case
    if(pos==1){
        return st.top();
    }


    // solve one case
    pos--;
    int temp = st.top();
    st.pop();

    // RE
    int ans = solve(st, pos);

    // backTrack
    st.push(temp);

    return ans;
}

int getMidElement(stack<int> &st)
{
    int size = st.size();

    if(st.empty())
    {
        cout << "Stack is Empty! " << endl;
        return -1;
    }
    else
    {
        int pos = 0;

        if(size&1) // if size if odd
        {
            pos = size/2 + 1;
        }
        else // if size is even
        {
            pos = size/2;
        }

        int ans = solve(st, pos);
        return ans;
    }
}

int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int mid = getMidElement(st);

    cout << "Mid element: " << mid << endl;


    return 0;
}

