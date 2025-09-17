/*
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
    -- pehla row m max rectangle using histogram approach, then pehla and dusra m, then pehla dusra and teesra row m,,.. kuch iss tarah appraoch krengen
    -- jab do ya do se jyada row lenge to, niche aur uper ke one ko addup ker ke ek single row bna denge, ager niche wale row m 0 hoga to add nhi krengen, then histogram appraoch to get max rectangle
    -- her baar max rectangle ko modify kerte rahengen on new max area
*/

#include<iostream>
#include<stack>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

// used the optimised code of largestRectangleArea
int largestRectangleArea(vector<int>& heights)
{
    int n = heights.size();

    stack<int> st;
    int maxArea = INT_MIN;

    for(int i=0 ; i<heights.size() ; i++)
    {
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


int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // converting 2D array of char into int
    vector<vector<int>> dummyMatrix;
    for(int i=0 ; i<n ; i++)
    {
        vector<int> t;
        for(int j=0 ; j<m ; j++)
        {
            t.push_back(matrix[i][j]-'0');
        }
        dummyMatrix.push_back(t);
    }

    // pheli row ka max area
    int area = largestRectangleArea(dummyMatrix[0]);

    // so ab pehla aur dusra row then pehla, dusra and teesra row.. kuch iss tarah, SO, second ya third ya jo bhi ith row ko use kerne se pehle usne addup ker rhe usse pehle ke row ka 1.
    for(int i=1 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(dummyMatrix[i][j])
            {
                dummyMatrix[i][j] += dummyMatrix[i-1][j];
            }
        }

        area = max(area, largestRectangleArea(dummyMatrix[i]));
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



