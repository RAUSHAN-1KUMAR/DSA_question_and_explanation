/*

given an array, we have to return first next smaller element of each element, if not found then it will be -1,

Example:
    input: arr = [8,4,6,2,3]
    output: [4,2,2,-1,-1]

    input: arr = [2,1,4,6,3]
    output: [1,-1,3,3,-1]
*/

/*
Appraoch:- 
    1. Brute force: her ek element ke liye last tak check kerle-> O(n^2) time

    2. Array ke piche se traverse kro aur phir stack ka use kro:
        - initially top of stack will be -1
        - if the top of the stack is greater than element than pop kerte jao, aur ager top of the stack is less then element aa jaye to uss element ke liye answer is that top element. So, usko store kerlo aur element ko phir stack m push kerdo

Lets solve it by traversing from array ke starting se -> see next solution
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr)
{
    int size = arr.size();
    vector<int> ans(arr.size(),0);

    //initializing stack
    stack<int> st;
    st.push(-1);


    for(int i=size-1 ; i>=0 ; i--)
    {
        int  curr = arr[i];

        // ager top bada h element se
        while(st.top()>=curr) st.pop();

        // loop ke bahar matlab top chota h element se, to usko store kerlo
        ans[i] = st.top(); 

        st.push(curr);
    }

    return ans;
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