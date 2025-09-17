/* 85
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1
*/

/*
Appraoch:- histogram appraoch 
    -- pehle row m max rectangle using histogram approach, then pehle and dusre m then pehle, dusre and teesre row m,,.. kuch iss tarag appraoch krengen
    -- jab do ya do se jyada row lenge to, niche aur uper ke one ko addup ker ke ek single row bna denge, ager niche wale row m 0 hoga to add nhi krengen, then histogram appraoch to get max rectangle
    -- her bas max rectangle ko modify kerte rahengen on new max area
*/

#include<iostream>
#include<stack>
#include<climits>
#include<vector>
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
        int  curr = arrNext[i];

        // change2
        while(st.top()!=-1 && arrNext[st.top()]>=curr) st.pop();

        ans[i] = st.top(); 

        // value ke jagah index push ker rhe taki ans m index store ho
        st.push(i);//change1
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
        int  curr = arrPrev[i];

        // change2
        while(st.top()!=-1 && arrPrev[st.top()]>=curr) st.pop();

        ans[i] = st.top(); 

        st.push(i);// change1
    }


    return ans;
}

int largestRectangleArea(vector<int>& heights)
{
    // her ek element ke lie next aur prev index limit nikal rhe h
    vector<int> prev = prevSmallerElement(heights);

    vector<int> next = nextSmallerElement(heights);


    int maxArea = INT_MIN;
    int size = heights.size();

    for(int i=0 ; i<heights.size() ; i++)
    {
        int length = heights[i];

        if(next[i]==-1){
            next[i]=size;
        }

        int width = next[i]-prev[i]-1;

        int area = length*width;
        maxArea = max(maxArea, area);
    }
    
    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    // convertind 2D array of char into int
    vector<vector<int>> v;
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0 ; i<n ; i++)
    {
        vector<int> t;
        for(int j=0 ; j<m ; j++)
        {
            t.push_back(matrix[i][j]-'0');
        }
        v.push_back(t);
    }

    // pheli row ka max area
    int area = largestRectangleArea(v[0]);

    // so ab pehle aur dusre row then pehle, dusre and teesre row.. kuch iss tarah, SO, second ya third ya jo bhi ith row ko use kerne se pehle usne addup ker rhe usse pehle ke row ka 1.
    for(int i=1 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(v[i][j]){
                v[i][j] += v[i-1][j];
            }
            else{
                v[i][j] = 0;
            }
        }
        area = max(area, largestRectangleArea(v[i]));
    }

    return area;
}

int main()
{
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << maximalRectangle(matrix) << endl;

    return 0;
}