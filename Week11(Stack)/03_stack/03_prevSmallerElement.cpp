/*

given an array, we have to return first previous smaller element of each element, if not found then it will be -1,

Example:
    input: arr = [8,4,6,2,3]
    output: [-1,-1,4,-1,2]

    input: arr = [2,1,4,6,3]
    output: [-1,-1,1,4,1]
*/

/*
Appraoch:- appraoch is similar to previous question
    1.Array ke starting se traverse kro aur phir stack ka use kro:
        - initially top of stack will be -1
        - if the top of the stack is greater than element than pop kerte jao, aur ager top of the stack is less then element aa jaye to uss element ke liye answer is that top element. So, usko store kerlo aur element ko phir stack m push kerdo

-- the one think is to notice that previosly we were reversing aur ans vector to get the answer in order but in this question no need to do reverse.


we can also it from last to first traversal of the given array just like we did for nextSmaller element question
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

vector<int> prevSmallerElement(vector<int> &arr)
{
    int size = arr.size();
    vector<int> ans;

    //initializing stack
    stack<int> st;
    st.push(-1);


    for(int i=0 ; i<size ; i++)
    {
        int  curr = arr[i];

        // ager top bada h element se
        while(st.top()>=curr) st.pop();

        // loop ke bahar matlab top chota h element se, to usko store kerlo
        ans.push_back(st.top()); 

        st.push(curr);
    }

    // reverse(ans.begin(), ans.end());-> NO NEED

    return ans;
}

int main()
{
    vector<int> arr = {8,4,6,2,3};

    vector<int> ans = prevSmallerElement(arr);

    for(int num:ans)
    {
        cout << num << " ";
    }

    return 0;
}