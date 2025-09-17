/* -> 354

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:
    Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
    Output: 3
    Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).


Example 2:
    Input: envelopes = [[1,1],[1,1],[1,1]]
    Output: 1
*/

/*
Appraoch:- same code as we did in stackingCuboids, but a little change
    -- in question it is given that we can't rotate an envelope
    -- and we have only two elements in each index, so we can also apply BS approach in this question

But:- TLE so we are gonna solve it ussing binary search
*/

#include<bits/stdc++.h>
using namespace std;

bool check(vector<int> &curr, vector<int> &prev)
{
    // curr -> bada wala envelop
    // prev -> chotte wala envelop
    
    if(prev[0] < curr[0] && prev[1] < curr[1])
        return true;
    
    return false;
}

// space optimization
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end()); 


    int n = envelopes.size();
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);


    for(int curr_index=n-1 ; curr_index>=0 ; curr_index--)
    {
        for(int prev_index=curr_index-1 ; prev_index>=-1 ; prev_index--)
        {
            int include = 0;
            if(prev_index==-1 || check(envelopes[curr_index],envelopes[prev_index]))
            {
                // change3
                include = 1 + nextRow[curr_index+1];
            }

            int exclude = 0 + nextRow[prev_index+1]; 

            currRow[prev_index+1] = max(include, exclude);
        }

        // shifting
        nextRow = currRow;
    }

    return nextRow[0];
}

int main()
{
    vector<vector<int>> envelopes = {
        {2,100},
        {3,200},
        {4,300},
        {5,500},
        {5,400},
        {5,250},
        {6,370},
        {6,360},
        {7,380}
    };

    int ans = maxEnvelopes(envelopes);

    cout << ans << endl;

    return 0;
}