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
Approach:- Optimization 
    -- How can we Optimize it:
        -- we find previous smaller element by traversing from 0->n and we find next smaller element by traversing from n-1->0 but we can do find the next smaller element by traversing from 0->n also. So, that's where the optimization comes in, we can find the area for perticular index at one traversal only

TC:- O(2n)
SC:- O(n)
*/

#include<iostream>
#include<stack>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();

    stack<int> st;
    int maxArea = INT_MIN;

    // goal is to find prevSmaller element, and whenever we pop it means the next smaller for the top of stack is curr index and the prev smaller for the top of Stack is prev of top
    for(int i=0 ; i<heights.size() ; i++)
    {
        // top ko pop ker rhe means top ke liye next and prev smallest mil gya
        while (!st.empty() && heights[st.top()]>heights[i])
        {
            int topIndex = st.top();
            st.pop();

            int nextS = i;
            int prevS = st.empty() ? -1 : st.top();

            int width = nextS-prevS-1;
            int Area = heights[topIndex]*width;
            maxArea = max(maxArea, Area);
        }

        st.push(i);
    }

    // if still some index is left in stack
    while (!st.empty())
    {
        int topIndex = st.top();
        st.pop();

        int nextS = n; // for the nextS will be size of array
        int prevS = st.empty() ? -1 : st.top();

        int width = nextS-prevS -1;
        int Area = heights[topIndex]*width;
        maxArea = max(maxArea, Area);
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

