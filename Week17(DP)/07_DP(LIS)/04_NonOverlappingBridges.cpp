/* GFG

we have a given pair: {
    {6,2},
    {4,3},
    {2,6},
    {1,5}
} 0th index represent north and 1th index represent south


    1   2   3   4   5   6  -> NORTH
      \   \
        \   \
          \   \
            \   \
              \   \
                \   \
                  \   \
    1   2   3   4   5   6  -> SOUTH

    Ouput-> 2

We have to return maximum number of non-overlapping bridges
*/

/*
Approach:- Sorting + LIS, DP se bhi solve ho jayega
    -- Logic: 
        Bridge not overlap: if north of prev is less than north of curr and also south of prev is less then south of curr:
        i.e, NORTH KO SORT KERDO AND BAS SOUTH P LIS LAGA DO

    Approach: pichle question m, non-overlapping intervals, given vector m 0th index value chota tha 1th index value se issliye hame bas 1th index ko sort kiya tha taaki pehle wo interval mile jo sabse pehle kahtam ho rha ho, but is case m aesa nhi h:
        - iss case m ham 0th index i.e., north ke basis p sort krengen and then phir apna logic bas south p lagayengen -> NORTH KO SORT KERDO AND BAS SOUTH P LIS LAGA DO

*/

#include<bits/stdc++.h>
using namespace std;


// using sorting
int maxBridges(vector<vector<int>> &bridges)
{
    // north ke basis p sort ho gya
    sort(bridges.begin(), bridges.end());

    // ab south p LIS ka binary search approach laga do
    vector<int> ans;

    //initial state
    ans.push_back(bridges[0][1]);

    for(int i=1 ; i<bridges.size() ; i++)
    {
        if(bridges[i][1] > ans.back()) // ager mere ans_vector ke last element(i.e, south) se mera aane wala bridge ka south bada h to no need to check just insert that south
        {
            ans.push_back(bridges[i][1]);  
        }
        else // ager chota hua to, find the index of just bada wala south i.e., lowerBound
        {
            int index = lower_bound(ans.begin(), ans.end(), bridges[i][1])-ans.begin();

            ans[index] = bridges[i][1];
        }
    }

    return ans.size();
}


int main()
{
    vector<vector<int>> bridges = {
        {8,1},
        {1,2},
        {4,3},
        {3,4},
        {5,5},
        {2,6},
        {6,7},
        {7,8},
    };

    cout << maxBridges(bridges) << endl;

    return 0;
}