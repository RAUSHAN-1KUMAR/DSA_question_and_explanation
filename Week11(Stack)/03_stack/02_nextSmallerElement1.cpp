/*

given an array, we have to return first next smaller element of each element, if not found then it will be -1,

Example:
    input: arr = [8,4,6,2,3]
    output: [4,2,2,-1,-1]

    input: arr = [2,1,4,6,3]
    output: [1,-1,3,3,-1]
*/

/*
Appraoch:- we will store index into stack
Array ke aage se traverse kro aur phir stack ka use kro:
    - initially top of stack will be empty and we will have an array next Smaller which intially filled with negative -1

    - if the top of the stack is greater than new element then uss top of the stack ke liye ye new element is the first next smaller element, So store it into next smaller array and pop the top other wise push the new element index into stack

So we can see that we have solve it from last to first traversal of the given array or from first to last traversal of the given array.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr)
{
    int n = arr.size();

    stack<int> st;
    vector<int> nextSmaller(n, -1);

    for(int i=0 ; i<n ; i++)
    {
        while (!st.empty() && arr[st.top()]>arr[i])
        {
            nextSmaller[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return nextSmaller;
}

int main()
{
    vector<int> arr = {8,4,6,2,3};

    vector<int> ans = nextSmallerElement(arr);

    for(int num:ans)
    {
        cout << num << " ";
    }

    return 0;
}