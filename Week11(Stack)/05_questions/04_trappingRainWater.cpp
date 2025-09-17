/* -> 42

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


Example 1:
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.


Example 2:
    Input: height = [4,2,0,3,2,5]
    Output: 9
*/

/* MY LOGIC
Approach:- question is simililar to 'largest rectangle in histogram', there we have to find the prev and next smallest element's index, and here we have to find prev and next largest element's index.

TC:- O(n + n + nlogn)
SC:- O(n) + O(n)

Optimised solution -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;


vector<int> prevGreatestElement(int &n, vector<int> &height)
{
    stack<int> st;

    vector<int> ans(n, -1);

    for(int i=0 ; i<n; i++)
    {
        while (!st.empty() && height[i]>=height[st.top()])
        {
            st.pop();
        }

        ans[i] = st.empty() ? -1 : st.top(); 
        st.push(i);
    }

    return ans;
}

vector<int> nextGreatestElement(int &n, vector<int> &height)
{
    stack<int> st;

    vector<int> ans(n, -1);

    for(int i=0 ; i<n; i++)
    {
        while (!st.empty() && height[i]>height[st.top()])
        {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}

int trap(vector<int>& height)
{
    int n = height.size();

    if(n==1 || n==2) return 0;

    vector<int> prevGreatest = prevGreatestElement(n, height);
    vector<int> nextGreatest = nextGreatestElement(n, height);

    // now lets calculate the trapped water
    int area = 0;
    set<pair<int,int>> st; // to eliminate same prev and next to occur twice
    for(int i=0 ; i<n ; i++)
    {
        if(prevGreatest[i]!=-1 && nextGreatest[i]!=-1)
        {
            int next = nextGreatest[i];
            int prev = prevGreatest[i];

            auto it = st.find({next,prev});

            if(it==st.end())
            {
                int width = next-prev-1;
                int length = min(height[prev], height[next]) - height[i];

                area += width*length;

                st.insert({next, prev});
            }

        }
    }

    return area;
}

int main()
{
    vector<int> height = {4,2,0,3,2,5};

    cout << trap(height) << endl;
    return 0;
}
