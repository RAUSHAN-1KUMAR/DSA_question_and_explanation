/*
Given an array arr[ ] of integers, the task is to find the nearest smaller element for each element of the array in order of their appearance in the array. Nearest smaller element of an element in the array is the nearest element on the right or left which is smaller than the current element.

If there does not exist nearest smaller of current element, then nearest smaller element for current element is -1. For example, nearest smaller of the last element is always -1.

Input: arr[] = [4, 2, 1, 5, 3]
Output: [2, 1, -1, 3, -1], next smaller element 

Input: arr[] = [5, 6, 2, 3, 1, 7]
Output: [-1, 5, -1, 2, -1, 1], prev smaller element

Input: arr[] = [50, 40, 30, 10]
Output: [-1, -1, -1, -1],  prev smaller element
*/

/*
We are going to code for nearest smaller element to the left and right as well
*/

#include <bits/stdc++.h>
using namespace std;

// nearest smaller element to left
vector<int> nextSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    stack<int> st;
    st.push(-1);

    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int num = arr[i];
        while (st.top() != -1 && num <= st.top())
            st.pop();

        ans[i] = st.top();

        st.push(num);
    }

    return ans;
}


// nearest smaller element to right
vector<int> prevSmallerElement(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    st.push(-1);

    vector<int> ans(n, 0);
    for (int i = 0; i<n; i++)
    {
        int num = arr[i];
        while (st.top() != -1 && num <= st.top())
            st.pop();

        ans[i] = st.top();

        st.push(num);
    }

    return ans;
}


int main()
{
    vector<int> arr = {1,3,2,4};
    vector<int> nextSmaller = nextSmallerElement(arr);
    vector<int> prevSmaller = prevSmallerElement(arr);
    
    for(int num:nextSmaller)
        cout << num << " ";
    cout << endl;

    for(int num:prevSmaller)
        cout << num << " ";
    cout << endl;

    return 0;
}