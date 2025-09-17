/*

Given an array arr[ ] of integers, the task is to find the nearest greater element for each element of the array in order of their appearance in the array. Nearest greater element of an element in the array is the nearest element on the right or left which is greater than the current element.

If there does not exist nearest greater of current element, then nearest greater element for current element is -1. For example, nearest greater of the last element is always -1.


Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1], next greater elements

Input: arr[] = [6, 8, 0, 1, 3]
Output: [-1, -1, 8, 8, 8], prev greater elements

Input: arr[] = [50, 40, 30, 10]
Output: [-1, -1, -1, -1], next greater elements
*/

/*
We are going to code for nearest greater element to the left and right as well
*/

#include <bits/stdc++.h>
using namespace std;

// nearest greater element to left
vector<int> nextLargerElement(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    st.push(-1);

    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int num = arr[i];
        while (st.top() != -1 && num >= st.top())
            st.pop();

        ans[i] = st.top();

        st.push(num);
    }

    return ans;
}


// nearest greater element to right
vector<int> prevLargerElement(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    st.push(-1);

    vector<int> ans(n, 0);
    for (int i = 0; i<n; i++)
    {
        int num = arr[i];
        while (st.top() != -1 && num >= st.top())
            st.pop();

        ans[i] = st.top();

        st.push(num);
    }

    return ans;
}

int main()
{
    vector<int> arr = {1,3,2,4};
    vector<int> nextGreater = nextLargerElement(arr);
    vector<int> prevGreater = prevLargerElement(arr);

    for(int num:nextGreater)
        cout << num << " ";
    cout << endl;

    for(int num:prevGreater)
        cout << num << " ";
    cout << endl;

    return 0;
}