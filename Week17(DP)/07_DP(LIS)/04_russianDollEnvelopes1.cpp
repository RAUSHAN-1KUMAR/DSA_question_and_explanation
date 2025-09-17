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
Appraoch:- appraoch will be same as we did in non-overlapping Bridge problem
    -- the only difference is that, in question non-overlappingBridge we were also considering the case when the north equal succeeding north but in this case we just have to remove that one only

    So, WIDTH KO SORT KERDO AND BAS HEIGHT P LIS LAGA DO
*/

#include<bits/stdc++.h>
using namespace std;

// using sorting
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    // width ke basis p sort ho gya, but if 0th = 0th)next than we have to sort on 1th value in such a way that 1th > 1th)next
    sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }

        return a[0]<b[0];
    });

    // ab south p LIS ka binary search approach laga do
    vector<int> ans;

    //initial state
    ans.push_back(envelopes[0][1]);

    for(int i=1 ; i<envelopes.size() ; i++)
    {
        if(envelopes[i][1] > ans.back())
        {
            ans.push_back(envelopes[i][1]);  
        }
        else 
        {
            int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1])-ans.begin();

            ans[index] = envelopes[i][1];
        }
    }

    return ans.size();
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