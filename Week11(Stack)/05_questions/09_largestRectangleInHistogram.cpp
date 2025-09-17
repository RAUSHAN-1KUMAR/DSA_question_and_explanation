/* -> 84

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.


Example 1: 
    Input: heights = [2,1,5,6,2,3]
    Output: 10
    Explanation: The above is a histogram where width of each bar is 1.
    The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
    Input: heights = [2,4]
    Output: 4
*/

/*
Approach:- explained in notecopy
    -- applying next and prev smaller element appraoch

TC:- O(5n)
SC:- O(2n) + O(2n)

Optimised solution -> next solution
*/

#include<iostream>
#include<stack>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arrNext)
{
    int size = arrNext.size();
    vector<int> ans(arrNext.size());

    stack<int> st;
    st.push(-1);


    for(int i=size-1 ; i>=0 ; i--)
    {
        while(st.top()!=-1 && arrNext[st.top()]>=arrNext[i])
        {
            st.pop();
        }

        ans[i] = st.top(); 
        st.push(i);
    }

    return ans;
}

vector<int> prevSmallerElement(vector<int> &arrPrev)
{
    int size = arrPrev.size();
    vector<int> ans(arrPrev.size());

    stack<int> st;
    st.push(-1);


    for(int i=0 ; i<size ; i++)
    {
        while(st.top()!=-1 && arrPrev[st.top()]>=arrPrev[i])
        {
            st.pop();
        } 

        ans[i] = st.top(); 
        st.push(i);
    }


    return ans;
}

int largestRectangleArea(vector<int>& heights)
{
    // her ek element ke lie next aur prev index limit nikal rhe h
    vector<int> next = nextSmallerElement(heights);

    // make sure kerna ki next m koi bhi answer -1 na ho
    for(int i=0 ; i<next.size() ; i++){
        if(next[i]==-1) next[i] = heights.size();
    }

    vector<int> prev = prevSmallerElement(heights);

    int maxArea = INT_MIN;

    for(int i=0 ; i<next.size() ; i++)
    {
        int width = next[i]-prev[i]-1;
        int length = heights[i];
        int area = width*length;
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}


int main()
{
    vector<int> heights = {2,4};

    int ans = largestRectangleArea(heights);

    cout << ans << endl;

    return 0;
}

